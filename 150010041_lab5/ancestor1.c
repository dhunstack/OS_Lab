#include "types.h"
#include "stat.h"
#include "user.h"

int main() 
{
	int ret = fork();
	if (ret == 0) 
	{
		int ret2 = fork();
		if (ret2 == 0)
		{
			printf(1, "\nchild: pid %d\n", getpid());
			printf(1, "child: parent pid %d\n", getppid());

			sleep(100);

			printf(1, "\nchild: pid %d\n", getpid());
			printf(1, "child: parent pid %d\n", getppid());

		}
		else
		{
			sleep(10);

			printf(1, "\nparent: pid %d\n", getpid());
			printf(1, "parent: parent pid %d \n", getppid());
			printf(1, "parent: child pid %d\n", ret2);			
		}
	}
	else 
	{
		sleep(200);

		printf(1, "\ngrandparent: pid %d\n", getpid());
		printf(1, "grandparent: parent pid %d \n", getppid());
		printf(1, "grandparent: child pid %d\n", ret);
	}
	
	exit();
}