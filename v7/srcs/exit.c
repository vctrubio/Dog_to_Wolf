#include "../include/header.h"

void	ft_exit(char *msg)
{
	printf("Error: ");
	printf("%s", msg);
	printf("\n");
	//freefunction CALL;
	exit(1);
};
