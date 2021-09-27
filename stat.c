#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    struct stat sf;
    const char *fileName = "new.txt";
    int temp = open(fileName, O_RDONLY);
    if (temp == -1)
    {
        perror("Error : Couldn't able to open");
        exit(EXIT_FAILURE);
    }
    if (stat(fileName, &sf) == -1)
    {
        perror("Error ");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("\nFile st_uid :%d ", sf.st_uid);
        printf("\nFile st_blksize :%ld ", sf.st_blksize);
        printf("\nFile st_gid :%d ", sf.st_gid);
        printf("\nFile st_blocks :%ld ", sf.st_blocks);
        printf("\nFile st_size :%ld ", sf.st_size);
        printf("\nFile st_nlink :%u :", (unsigned int)sf.st_nlink);
        printf("\nFile Permissions User:");
        printf((sf.st_mode & S_IRUSR) ? "r" : "-");
        printf((sf.st_mode & S_IWUSR) ? "w" : "-");
        printf((sf.st_mode & S_IXUSR) ? "x" : "-");
        printf("\nFile Permissions Group: ");
        printf((sf.st_mode & S_IRGRP) ? "r" : "-");
        printf((sf.st_mode & S_IWGRP) ? "w" : "-");
        printf((sf.st_mode & S_IXGRP) ? "x" : "-");
        printf("\nFile Permissions Other: ");
        printf((sf.st_mode & S_IROTH) ? "r" : "-");
        printf((sf.st_mode & S_IWOTH) ? "w" : "-");
        printf((sf.st_mode & S_IXOTH) ? "x" : "-");
    }
    printf("\nst_mode = %lo", sf.st_ino);
    return 0;
}