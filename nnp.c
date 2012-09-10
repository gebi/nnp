#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>
#ifndef PR_SET_NO_NEW_PRIVS
# define PR_SET_NO_NEW_PRIVS 38
#endif

int main(int argc, char * argv[])
{
        if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
                perror("prctl(NO_NEW_PRIVS)");
                return 1;
        }

        return execvp(argv[1], &argv[1]);
}
