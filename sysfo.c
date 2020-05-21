#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void info()
{
	printf("Usage: sysinfo [FUNC]\n\n");
	printf("sysinfo is a neofetch inspired idea written in C\n");
	printf("sysinfo will display system information upon request\n\n");
	printf("INFO:\n");
	printf("\tkernel		Will display the kernel version\n");
	printf("\thostname	Will display the system hostname\n");
}
void startup()
{
	printf("Hello, type '--help' for more information\r\n");
}



void main(int argc, char *argv[])
{
	/* if(argc == "--help") { */
	/* 	printf("Usage: afetch [FUNC]\n\n"); */
	/* 	printf("Afetch is a neofetch inspired idea written in C\n"); */
	/* 	printf("Afetch will display system information apon request\n"); */
	/* 	printf(""); */
	/* } */

	char *kernel = "uname -r";
	char *hostname = "hostname";
	char *path = "echo $PATH";
	char *editor = "echo $EDITOR";
	char *error = "echo 'Sorry, not a recognized command'";

	if(argc == 1)
		startup();

	if(argc == 2)
	{
		if(strcmp(argv[1], "--help") == 0)
			info();
		else if(strcmp(argv[1], "kernel") == 0)
			system(kernel);
		else if(strcmp(argv[1], "hostname") == 0)
			system(hostname);
		else if(strcmp(argv[1], "path") == 0)
			system(path);
		else if(strcmp(argv[1], "editor") == 0)
			system(editor);
		else
			system(error);

	} 
}
















