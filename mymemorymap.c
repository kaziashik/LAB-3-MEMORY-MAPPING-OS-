#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <sys/mman.h> 
#include <fcntl.h> 
#include <unistd.h> 
 
int main(int argc, char *argv[]) 
{ 
 	int fd;  	struct stat mystat; 
 	void *pmap; 
 
 	fd = open("mytextfile.txt", O_RDWR); 
  
 	if(fd == -1) 
 	{ 
 	 	perror("Error opening input file!"); 
 	 	exit(1); 
 	} 
 
 	if(fstat(fd, &mystat) < 0) 
 	{ 
 	 	perror("fstat returns an error!");  	 	close(fd); 
 	 	exit(1); 
 	} 
 
 	pmap = mmap(0, mystat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); 
 
 	 
// continued on next page --> 
    if(pmap==MAP_FAILED) 
 	{ 
 	 	perror("mmap"); 
 	 	close(fd); 
 	} 
 
 	strncpy(pmap, "That", 4); 
 
 	close(fd); 
  	return 0; 
} 

