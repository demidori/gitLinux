//FIFO CHAT1
//Demitra P.M 6180725

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int fd;
	int num;
	
	char * myfifo = "/tmp/myfifo";
	
	mkfifo(myfifo, 0666);
	
	char arr1[90], arr2[90];
	
	printf("\nFifo1: ");
	
	while(1){
	fd = open(myfifo, O_WRONLY);
	fgets(arr2, 90, stdin);
	
	write(fd, arr2, strlen(arr2)+1);
	close(fd);
	
	fd = open(myfifo, O_RDONLY);
	
	read(fd, arr1, sizeof(arr1));
	
	printf("\nFifo2: %s\nFifo1:", arr1);
	}
	return 0;
		
}
	
	
	
