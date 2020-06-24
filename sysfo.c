#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void info()
{
	fprintf(stdout, "Usage: sysinfo [FUNC]\n\n");
	fprintf(stdout, "sysinfo is a neofetch inspired idea written in C\n");
	fprintf(stdout, "sysinfo will display system information upon request\n\n");
	fprintf(stdout, "INFO:\n");
	fprintf(stdout, "\tkernel		Will display the kernel version\n");
	fprintf(stdout, "\thostname	Will display the system hostname\n");
	fprintf(stdout, "\tPATH		Will display the $PATH\n");
	fprintf(stdout, "\tEDITOR		Will display the $EDITOR\n");
	fprintf(stdout, "\tSHELL		Will display the $SHELL\n");
}
void startup()
{
	printf("Hello, type '--help' for more information\n");
}
void main(int argc, char *argv[])
{
	/* if(argc == "--help") { */
	/* 	printf("Usage: afetch [FUNC]\n\n"); */
	/* 	printf("Afetch is a neofetch inspired idea written in C\n"); */
	/* 	printf("Afetch will display system information apon request\n"); */
	/* 	printf(""); */
	/* } */

	const char *kernel = "uname -r";
	const char *hostname = "hostname";
	/* char *path = "echo $PATH"; */
	/* const char *editor = "echo $EDITOR"; */
	const char* PATH = getenv("PATH");
	const char* EDITOR = getenv("EDITOR");
	const char* SHELL = getenv("SHELL");

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
			printf("%s\n", PATH);
		else if(strcmp(argv[1], "shell") == 0)
			printf("%s\n", SHELL);
		else if(strcmp(argv[1], "editor") == 0) {
			if (EDITOR == NULL) 
				printf("You need to export an $EDITOR in your shell profile\n");
			else
				printf("%s\n", EDITOR);
		} else
			printf("Sorry, not a recognized command\n");
	} 
}
















