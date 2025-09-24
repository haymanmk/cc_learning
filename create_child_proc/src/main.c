#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_GREETINGS (uint8_t)30

void greeting(char *name, uint8_t times) {
    if (times == 0) times = NUM_GREETINGS;

    for (int i = 0; i < times; i++) {
        printf("Hello, %s!\n", name);
        // process ID
        printf("Process ID: %d\n", getpid());
        // parent process ID
        printf("Parent Process ID: %d\n", getppid());
        // print a new line for readability
        printf("\n");
        // sleep for a second
        sleep(1);
    }
}

int main() {
    pid_t pid = fork();

    switch (pid) {
        case -1:
            // Fork failed
            perror("Fork failed");
            return 1;
        case 0:
            // Child process
            greeting("Child", 0);
            break;
        default:
            // Parent process
            greeting("Parent", 1);

            // wait for child process to finish
            int status;
            if (waitpid(pid, &status, 0)) {
                if (WIFEXITED(status)) {
                    printf("Child process exited with status %d\n", WEXITSTATUS(status));
                } else {
                    printf("Child process did not terminate normally\n");
                }
            } else {
                perror("waitpid failed");
            }
            // pause here to allow time to use `ps` command to see the process tree
            printf("Press ENTER to exit...\n");
            getchar();

            break;
    }

    exit(EXIT_SUCCESS);
}