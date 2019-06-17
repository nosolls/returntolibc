/* getbinsh.c */

#include <stdio.h>
#include <stdlb.h>

void main() {
	char* shell = getenv("MYSHELL");
	if (shell)
		printf("%x\n", (unsigned int)shell);
}
