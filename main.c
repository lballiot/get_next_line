#include "get_next_line.h"
#include <assert.h>
#include <libc.h>
#include "libft/libft.h"

/*
** MAIN
*/

 /////////////////////////
 // MY MAIN             //
 /////////////////////////

int main(int ac, char **av)
{
	int i;
    char *line;
    int fd;
	
    (void) ac;
    fd = open(av[1], O_RDONLY);
    line = ft_strnew(120);
    while (get_next_line(fd, &line) == 1)
    {
//      ft_putstr("\nFIN\n");
		if (line)
			ft_putendl(line);
        line = ft_strnew(900);
    }
//    ft_putnbr(get_next_line(fd, &line));
    return (0);
	}

////////////////////////
// multi_fd 30        //
////////////////////////
/*
int main(void)
{
	char *line_fd0;
	int p_fd0[2];
	int fd0 = 0;
	int out_fd0 = dup(fd0);

	char *line_fd1;
	int p_fd1[2];
	int fd1 = 1;
	int out_fd1 = dup(fd1);

	char *line_fd2;
	int p_fd2[2];
	int fd2 = 2;
	int out_fd2 = dup(fd2);

	char *line_fd3;
	int p_fd3[2];
	int fd3 = 3;
	int out_fd3 = dup(fd3);

	pipe(p_fd0);
	dup2(p_fd0[1], fd0);
	write(fd0, "aaa\nbbb\n", 8);
	dup2(out_fd0, fd0);
	close(p_fd0[1]);

	pipe(p_fd1);
	dup2(p_fd1[1], fd1);
	write(fd1, "111\n222\n", 8);
	dup2(out_fd1, fd1);
	close(p_fd1[1]);

	pipe(p_fd2);
	dup2(p_fd2[1], fd2);
	write(fd2, "www\nzzz\n", 8);
	dup2(out_fd2, fd2);
	close(p_fd2[1]);

	pipe(p_fd3);
	dup2(p_fd3[1], fd3);
	write(fd3, "888\n999\n", 8);
	dup2(out_fd3, fd3);
	close(p_fd3[1]);

	get_next_line(p_fd0[0], &line_fd0);
	assert(strcmp(line_fd0, "aaa") == 0);

	get_next_line(p_fd1[0], &line_fd1);
	assert(strcmp(line_fd1, "111") == 0);

	get_next_line(p_fd2[0], &line_fd2);
	assert(strcmp(line_fd2, "www") == 0);

	get_next_line(p_fd3[0], &line_fd3);
	assert(strcmp(line_fd3, "888") == 0);

	get_next_line(p_fd0[0], &line_fd0);
	assert(strcmp(line_fd0, "bbb") == 0);

	get_next_line(p_fd1[0], &line_fd1);
	assert(strcmp(line_fd1, "222") == 0);

	get_next_line(p_fd2[0], &line_fd2);
	assert(strcmp(line_fd2, "zzz") == 0);

	get_next_line(p_fd3[0], &line_fd3);
	assert(strcmp(line_fd3, "999") == 0);
}
*/
 ///////////////////////
 //42 not OK multi_fd //
 ///////////////////////
  /*
int main(void)
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	int diff_file_size;

    system("mkdir -p sandbox");
	system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
	system("echo '\n' >> sandbox/one_big_fat_line.txt");

	fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr("toto\n");
		if (line)
		{
			write(fd2, line, strlen(line));
			write(fd2, "\n", 1);
		}
	}
	if (line)
		write(fd2, line, strlen(line));
	close(fd);
	close(fd2);

	system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);

	assert(diff_file_size == 0);
}
  */
