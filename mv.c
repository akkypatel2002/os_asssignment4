#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argC, char const *argV[])
{
    char buffer[BUFSIZ] = {0};
    const char *a0 = "random.txt";
    const char *a1 = "new.txt";
    int temp1 = 0;
    if ((temp1 = open(a0, O_RDONLY)) == -1)
    {
        const char *str = "bruhhh\n";
        write(2, str, strlen(str));
        exit(1);
    }
    int temp2 = 0;
    if ((temp2 = open(a1, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
    {
        perror("Couldn't create file.");
        exit(1);
    }
    for (int err = read(temp1, buffer, BUFSIZ); err != -1;
         err = read(temp1, buffer, BUFSIZ))
    {
        if (err == 0)
        {
            break;
        }
        if (write(temp2, buffer, err) == -1)
        {
            perror("Don't able to write in the file.");
        }
    }
    unlink("random.txt");
    close(temp2);
    return 0;
}