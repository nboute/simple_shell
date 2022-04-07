#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int		main(void)
{
	char	*args[] = {"/bin/ls", "-l", "/tmp", NULL};
	int		my_id = 1, i;

	for (i = 0; i < 5 && my_id; i++)
	{
		my_id = fork();
		if (my_id)
			wait(NULL);
	}
	if (!my_id)
		execve(args[0], args, NULL);
	printf("My Parent:%d | My id:%d\n", getppid(), getpid());
	return (0);
}
