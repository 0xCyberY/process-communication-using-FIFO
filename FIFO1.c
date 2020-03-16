#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
int fd;
char *myfifo="/tmp/myfifo";   //FIFO file path
mkfifo(myfifo,0666);          //creating the named file fifo using mkfile(<pathname>,<permission>)
char arr1[80],arr2[80];
while(1)
{
	fd=open(myfifo,O_WRONLY);         //open fifo for write only
	fgets(arr2,80,stdin);             //take an input arr2 from user 80 is MAX length
	write(fd,arr2,strlen(arr2)+1);    //write the input arr2 on fifo and close
	close(fd);
	fd=open(myfifo,O_RDONLY);         //open fifo for read only
	read(fd,arr1,sizeof(arr1));       //read from FIFO
	printf("user2:%s\n",arr1);
	close(fd);
}
return 0;
}

