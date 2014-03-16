#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/prctl.h>
#ifndef PR_SET_NO_NEW_PRIVS
# define PR_SET_NO_NEW_PRIVS 38
#endif

#define WRITE(fd, str) write(fd, str, strlen(str))

int main(int argc, char * argv[])
{
        if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
                perror("prctl(NO_NEW_PRIVS)");
                return EXIT_FAILURE;
        }
        if (argc <= 1) {
            WRITE(STDERR_FILENO, "nnp: missing operand\n");
            return EXIT_FAILURE;
        }
        return execvp(argv[1], &argv[1]);
}
