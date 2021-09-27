#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

void _ls(const char *dirName, int n, int m)
{
    struct dirent *d;
    DIR *directory = opendir(dirName);
    if (!directory)
    {
        if (errno == ENOENT)
        {
            perror("Required directory doesn't exist");
        }
        else
        {
            perror("Unable to read required directory");
        }
        exit(EXIT_FAILURE);
    }
    while ((d = readdir(directory)) != NULL)
    {
        if (!n && d->d_name[0] == '.')
            continue;
        printf("\n%s ", d->d_name);
    }
}

int main(int argC, const char *argV[])
{
    if (argC == 1)
        _ls(".", 0, 0);
    else if (argC == 2)
    {
        if (argV[1][0] == '-')
        {
            int n = 0, m = 0;
            char *p = (char *)(argV[1] + 1);

            _ls(".", n, m);
        }
    }
    return 0;
}