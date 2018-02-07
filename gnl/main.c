#include "get_next_line.h"
#include <assert.h>
#include <libc.h>
#include "libft/libft.h"

/*
** MAIN
*/

///////////////////////
// 04 problem return //
///////////////////////


int main(void)
{
    char *line;
    int out;
    int p[2];
    int fd;
    int gnl_ret;

    out = dup(1);
    pipe(p);

    fd = 1;
    dup2(p[1], fd);
    write(fd, "abc\n\n", 5);
    close(p[1]);
    dup2(out, fd);

    // Read abc and new line //
    ft_putstr("Read abc and new line \ngnl must = 1\n");
    gnl_ret = get_next_line(p[0], &line);
    ft_putstr("gnl_ret : ");
    ft_putnbr(gnl_ret);
    ft_putstr("\n");
    assert(gnl_ret == 1);
	ft_putstr("line : ");
	ft_putstr(line);
	ft_putstr("\nshould be \"abc\"");
    assert(strcmp(line, "abc") == 0);

    // Read new line //
	gnl_ret = get_next_line(p[0], &line);
    ft_putstr("\nRead new line \ngnl must = 1\n");
    ft_putstr("gnl_ret : ");
    ft_putnbr(gnl_ret);
    ft_putstr("\n");
//	printf("%s\n", line);
	assert(gnl_ret == 1); //PROBLEME RETURN
	assert(line == NULL || *line == '\0');

    // Read again, but meet EOF //
	ft_putstr("\nRead again, but meet EOF \ngnl must = 0\n");
    gnl_ret = get_next_line(p[0], &line);
    ft_putstr("gnl_ret : ");
    ft_putnbr(gnl_ret);
    ft_putstr("\n");
//	ft_putstr("line : ");
//	printf("%s\n", line);
//	ft_putstr("\nshould be (null)");
	assert(gnl_ret == 0);
    assert(line == NULL || *line == '\0');

    // Let's do it once again //
	ft_putstr("\nLet's do it once again\ngnl must = 0\n");
    gnl_ret = get_next_line(p[0], &line);
    ft_putstr("gnl_ret : ");
    ft_putnbr(gnl_ret);
    ft_putstr("\n");
//	ft_putstr("line : ");
//	printf("%s\n", line);
//	ft_putstr("\nshould be (null)");
//	ft_putstr(line);
    assert(gnl_ret == 0);
    assert(line == NULL || *line == '\0');
    return (0);
	}
/*
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
        ft_putendl(line);
        line = ft_strnew(900);
    }
    ft_putnbr(get_next_line(fd, &line));
    return (0);
}
*/
//////////////////
// PRBLM return //
//////////////////
/*
    char *line;
    int out;
    int p[2];
    int fd;
    int ret;

    out = dup(1);
    pipe(p);

    fd = 1;
    dup2(p[1], fd);
    write(fd, "abcdefghijklmnop\n", 17);
    write(fd, "qrstuvwxyzabcdef\n", 17);
    close(p[1]);
    dup2(out, fd);
    get_next_line(p[0], &line);
    assert(strcmp(line, "abcdefghijklmnop") == 0);
    get_next_line(p[0], &line);
    assert(strcmp(line, "qrstuvwxyzabcdef") == 0);
    ret = get_next_line(p[0], &line);
    ft_putstr("\nline =");
    ft_putstr(line);
    ft_putstr("= line ");
    ft_putstr("ret :");
    ft_putnbr(ret);
    ft_putstr("\n");
    assert(ret == 0);
    return (0);
*/

////////////////////////
// DIFFICILE NOT OK   //
////////////////////////

/*
int main(int ac, char **av)
{
    char *line;
    int fd;
    int fd2;
    int fd3;
    int diff_file_size;

    system("mkdir -p sandbox");
    system("openssl rand -out sandbox/large_file.txt -base64 $((50 * 1000 * 3/4)) 2> /dev/null");

    fd = open("sandbox/large_file.txt", O_RDONLY);
    fd2 = open("sandbox/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

    while (get_next_line(fd, &line) == 1)
    {
        write(fd2, line, strlen(line));
        write(fd2, "\n", 1);
    }

    close(fd);
    close(fd2);

    system("diff sandbox/large_file.txt sandbox/large_file.txt.mine > sandbox/large_file.diff");
    fd3 = open("sandbox/large_file.diff", O_RDONLY);
    diff_file_size = read(fd3, NULL, 10);
    close(fd3);

    assert(diff_file_size == 0);
    return (0);
}
*/
