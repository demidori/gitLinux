//FIFO CHAT2
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
	int fd1;
	char * myfifo = "/tmp/myfifo";
	
	char str1[90], str2[90];
	while(1)
	{
		fd1 = open(myfifo,O_RDONLY);
		read(fd1, str1, 90);
		
		printf("Fifo1:%s\nFifo2:", str1);
		close(fd1);

		fd1 = open (myfifo, O_WRONLY);
		fgets(str2, 90, stdin);
		write(fd1, str2, strlen(str2)+1);
		close(fd1);
	}
	return 0;
}
