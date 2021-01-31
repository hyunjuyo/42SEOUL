
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int 	fd;
	char	buf[100];

	fd = open("test2.txt", O_RDWR);
	read(fd, buf, 99);
	printf("%s\n", buf);
	printf("%c\n", buf[14]);
	return (0);
}
