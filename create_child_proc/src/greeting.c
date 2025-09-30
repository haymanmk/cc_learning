#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

void help_info() {
    printf("This is a simple greeting program.\n");
    printf("Usage: ./greeting <name> [times]\n");
    printf("It will print a greeting message to the specified name for the given number of times (optional).\n");
    printf("\n");
    printf("Show this help info: ./greeting -h || --help\n");
}

int main(int argc, char *argv[]) {
    uint8_t times = 1;

    if (argc == 1) {
        printf("No name provided!\n");
        help_info();
        return 1;
    }
    else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        help_info();
        return 0;
    }

    if (argc == 3) {
        times = (uint8_t)atoi(argv[2]);
    }

    // print PPID and PID
    printf("Greeting program started with PID: %d, PPID: %d\n", getpid(), getppid());

    for (uint8_t i = 0; i < times; i++) {
        printf("Hello, %s!\n", argv[1]);
        sleep(1);
    }

    exit(0);
}