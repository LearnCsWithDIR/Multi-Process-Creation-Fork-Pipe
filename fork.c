#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    /* 1. The parent process creates two other processes (child processes).
       2. The parent prints "PARENT"
       3. One child prints "CHILD 1"
       4. The other child prints "CHILD 2"*/

    int id_1 = fork();

    if (id_1 < 0)
        printf("Error\n");
    else if (id_1 == 0)
        printf("CHILD 1\n");

    else
    {
        int id_2 = fork();

        if (id_2 < 0)
            printf("Error\n");
        else if (id_2 == 0)
            printf("CHILD 2\n");
        else
            printf("PARENT\n");
    }
}
