#include "shell.h"
void escoba_double(char **recogedor, int fallos)
{
	for (fallos; recogedor[fallos] && fallos >=0; fallos--)
	{
		free(recogedor[fallos]);
	}
	free(recogedor);
}
void valid_simple_free(char *recogedor, ssize_t line_chk, int exit1)
{
	if(line_chk == -1)
		free(recogedor);
	if((line_chk == -1) && exit1 == 1)
		exit(0);
}
