#include <fcntl.h>
#include<string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    const char *a1="touchfile.txt";
    int temp=open(a1,O_CREAT,S_IRUSR | S_IRWXG);
    if(temp==-1)
    {
        const char *str="Error Occured While Creating the file , Try Agian\n";
        write(2,str,200);
    }
    return 0;
}