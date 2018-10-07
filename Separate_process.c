// Creating a separate process using the UNIX frok() system call

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
	pid_t pid;
	// frok a child process
	pid = fork();
	if (pid < 0){
		fprintf(stderr, "Fork Faild\n");
		return 1;
	}
	else if (pid == 0){
		execlp("/bin/ls","ls",NULL);
	}else{
		wait(NULL);
		printf("Child Complete\n");
	}
	return 0;
}