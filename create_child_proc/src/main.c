#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_GREETINGS (uint8_t)30
#define CHILD_PROC_EXEC "./greeting"

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
            char *const args[] = {CHILD_PROC_EXEC, "Child", "5", NULL};
            int retval = execve(CHILD_PROC_EXEC, args, NULL);
            if (retval == -1) {
                // stringify errno
                fprintf(stderr, "execve failed: %s\n", strerror(errno));
                _exit(EXIT_FAILURE);
            }
            _exit(EXIT_SUCCESS);
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