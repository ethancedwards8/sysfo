#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void info()
{
	printf("Usage: sysfo [FUNC]\n\n"
	"sysfo is a neofetch inspired idea written in C\n"
	"sysfo will display system information upon request\n\n"
	"INFO:\n"
	"\tkernel		Will display the kernel version\n"
	"\thostname	Will display the system hostname\n"
	"\tPATH		Will display the $PATH\n"
	"\tEDITOR		Will display the $EDITOR\n"
	"\tSHELL		Will display the $SHELL\n");
}
int main(int argc, char *argv[])
{
	const char *kernel = "uname -r";
	const char *hostname = "hostname";
	const char* PATH = getenv("PATH");
	const char* EDITOR = getenv("EDITOR");
	const char* SHELL = getenv("SHELL");

	if(argc == 1 || argc >= 3)
		info();

	if(argc == 2)
	{
        /* ooof */
		if(strcmp(argv[1], "--help") == 0)
			info();
		else if(strcmp(argv[1], "-V") == 0)
			printf("1.0\n");
		else if(strcmp(argv[1], "--version") == 0)
			printf("1.0\n");
		else if(strcmp(argv[1], "kernel") == 0)
			system(kernel);
		else if(strcmp(argv[1], "hostname") == 0)
			system(hostname);
		else if(strcmp(argv[1], "path") == 0)
			printf("%s\n", PATH);
		else if(strcmp(argv[1], "shell") == 0)
			printf("%s\n", SHELL);
		else if(strcmp(argv[1], "editor") == 0) {
			if (EDITOR == NULL) {
				fprintf(stderr, "You need to export an $EDITOR in your shell profile\n");
				return -1;
			} else
				printf("%s\n", EDITOR);
		} else {
			fprintf(stderr, "Sorry, not a recognized command\n");
			return -1;
		}
	}
}
