#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
int fd1;
char *myfifo="/tmp/myfifo";      //FIFO file path
mkfifo(myfifo,0666);             ////creating the named file fifo using mkfile(<pathname>,<permission>)
char str1[80],str2[80];
while(1)
{
	fd1=open(myfifo,O_RDONLY); //first open fifo for read only
	read(fd1,str1,80);
	printf("user1:%s\n",str1);  //print the read string and close
	close(fd1);
	fd1=open(myfifo,O_WRONLY);  //now open for write string
	fgets(str2,80,stdin);
	write(fd1,str2,strlen(str2)+1);
	close(fd1);
}
}

