#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main(void)
{
	char	*args[] = {"/bin/ls", "-l", "/tmp", NULL};
	int		my_id = 1, i;

	for (i = 0; i < 5 && my_id; i++)
	{
		if (my_id)
			my_id = fork();
		wait();
	}
	if (!my_id)
		printf("Exec:%d\n", execve(args[0], args, NULL));
	printf("My Parent:%d | My id:%d\n", getppid(), getpid());
	return (0);
}
