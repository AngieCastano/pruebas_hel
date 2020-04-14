#include "shell.h"
//void control_c(int sig)
//{
//	printf("control c, sig: %i\n", sig);
//}
void sig_handler(int signo)
{
	if (signo == SIGINT)
		printf("received SIGINT\n");
}
