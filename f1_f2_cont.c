#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define MAX 200
int main()
{
	int fd[2];
	char buff1[MAX]="i am file 1";
	char buff2[MAX]="i am file 2";
	char content[MAX];


	//creating new two files and copying text from file1 to file2
	fd[0] = open("newfile1.txt", O_RDWR | O_CREAT, 0666);
	fd[1] = open("newfile2.txt", O_WRONLY | O_CREAT, 0666);

	
	if(fd[0] != -1 && fd[1] !=-1)                                     
	{  
		//writing to file1
		write(fd[0],buff1,strlen(buff1));
		
		//reading from beginning of file1		
		lseek(fd[0],0,SEEK_SET);                 
		read(fd[0],content,strlen(buff1));
		close(fd[0]);
	 	
		//writing to file2 from buff2 
		write(fd[1],buff2,strlen(buff2));

		//writing to file2 from file1 without deleting file2 content
		lseek(fd[1],strlen(content),SEEK_SET);
		write(fd[1],content,strlen(content));
		close(fd[1]);
	}
}

	
	

	
