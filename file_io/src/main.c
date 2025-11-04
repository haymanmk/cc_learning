#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void read_current_offset(int fd) {
    off_t offset = lseek(fd, 0, SEEK_CUR);
    if (offset == (off_t)-1) {
        perror("Error getting file offset");
    } else {
        printf("Current file offset: %ld\n", offset);
    }
}

int main(const int argc, const char *argv[]) {
    
    printf("Starting main function\n");

    // open target file with unix system call open(), which will create the file for us if it doesn't exist by using O_CREAT flag.
    const char *filename = "example.txt";
    int fd;
    if ((fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // write to the file using unix system call write()
    char *text = "Hello, World!xy";
    size_t text_len = strlen(text);
    if (write(fd, (const char *)text, text_len) != text_len) {
        perror("Error writing to file");
        close(fd);
        return EXIT_FAILURE;
    }

    // read from the file using unix system call read()
    // read current file offset
    read_current_offset(fd);

    // try to read at current file offset, which is at the end of the file after writing
    char buffer[text_len + 1]; // +1 for null terminator
    ssize_t bytesRead;
    if ((bytesRead = read(fd, buffer, 1)) == -1) { // try to read 1 byte
        perror("Error reading from file");
        close(fd);
        return EXIT_FAILURE;
    } else {
        buffer[1] = '\0'; // null terminate the string
        printf("Read %ld bytes from file: '%s'\n", bytesRead, buffer); // expect to read nothing as we are at the end of the file
    }
    /**
     * Note: The read call will increase the file offset by the number of bytes read.
     * So if we read 1 byte, the file offset will move forward by 1 byte.
     * If we are already at the end of the file, read will return 0 indicating EOF (End of File).
     * However, if the file we are reading from is not empty, the read call will increase the file offset.
     * In this context, we need to reset the file offset to the previous position before the read call to append new data correctly.
     */
    if (bytesRead > 0) {
        printf("Adjusting file offset back by %ld bytes\n", bytesRead);
        // Move the file offset back by the number of bytes read
        if (lseek(fd, -bytesRead, SEEK_CUR) == (off_t)-1) {
            perror("Error seeking back in file");
            close(fd);
            return EXIT_FAILURE;
        }
    }

    // read current file offset
    read_current_offset(fd);

    // append a new line to the file
    text = "\nHello Jenny!";
    text_len += strlen(text);
    if (write(fd, (const char *)text, strlen(text)) != strlen(text)) {
        perror("Error writing to file");
        close(fd);
        return EXIT_FAILURE;
    }

    // read current file offset
    read_current_offset(fd);

    // reset file offset to the beginning of the file using lseek()
    if (lseek(fd, 0, SEEK_SET) == (off_t)-1) {
        perror("Error seeking to beginning of file");
        close(fd);
        return EXIT_FAILURE;
    }
    // read again from the beginning of the file
    bytesRead = read(fd, buffer, text_len);
    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fd);
        return EXIT_FAILURE;
    }
    buffer[bytesRead] = '\0'; // null terminate the string
    printf("Read from file after seeking to beginning: '%s'\n", buffer);

    // close the file descriptor before exiting the program
    if (close(fd) == -1) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    printf("Exiting main function\n");
    return EXIT_SUCCESS;
}