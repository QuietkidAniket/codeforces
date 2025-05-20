#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t data = fork();
    if (data == 0) {
        sleep(2);
        printf("Orphan Child, Parent PID: %d\n", getppid());
    } else {
        printf("Parent Process Exiting\n");
    }
    return 0;
}
