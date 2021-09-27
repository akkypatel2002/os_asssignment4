#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
int i,charCount=0,lineCount=0, wordCount=0,temp;
char buffer [BUFSIZ];
temp = open("mock.c", O_RDONLY);
if (temp==-1)
{
perror("There is an error in opening the file"); 

}
else {
while(i=read(temp,buffer,1)>0)
{
if(buffer[0] == ' ') wordCount++;

if(buffer[0] == '\n') lineCount++;

}
}
return 0; 

}