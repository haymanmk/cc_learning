#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <poll.h>

enum STDIN_FD {
    STDIN_FD_0,
    STDIN_FD_1,
    MAX_FDS
};

#define POLL_TIMEOUT 100

void main(void) {
    char name[100];
    int counter = 0;

    struct pollfd poll_fd[MAX_FDS] = {
        {STDIN_FD_0, POLLIN, 0},
        {STDIN_FD_1, POLLIN, 0}
    };

    // debug message
    printf("poll() example\n");
    printf("Type in your name [%d]:\n", STDIN_FD_0);
    printf("Type in your name [%d]:\n", STDIN_FD_1);

    while (1) {
        // Wait for input on stdin
        int poll_result = poll(poll_fd, MAX_FDS, POLL_TIMEOUT);

        if (poll_result > 0) {
            if (poll_fd[STDIN_FD_0].revents & POLLIN) {
                // Read from stdin
                read(STDIN_FD_0, name, sizeof(name));

                printf("Hello %s\n", name);
                printf("It takes %d ms to read from stdin\n", POLL_TIMEOUT * counter);
            }

            if (poll_fd[STDIN_FD_1].revents & POLLIN) {
                // Read from stdin
                read(STDIN_FD_1, name, sizeof(name));

                printf("Hello %s\n", name);
                printf("It takes %d ms to read from stdin\n", POLL_TIMEOUT * counter);
            }
            break;
        }
        else
            counter++;
    }
}