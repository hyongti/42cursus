# include <string.h>
# include "libasm.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

void test_ft_strlen(char *str)
{
	printf("test_ft_strlen\n");
	printf("--------------\n");
	printf("%-10s: \"%s\"\n", "str", "");
	printf("%-10s: %zu\n", "strlen", strlen(""));
	printf("%-10s: %zu\n", "ft_strlen", ft_strlen(""));
	printf("\n");
	printf("%-10s: \"%s\"\n", "str", str);
	printf("%-10s: %zu\n", "strlen", strlen(str));
	printf("%-10s: %zu\n", "ft_strlen", ft_strlen(str));
	printf("\n");
}

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void test_ft_strcpy(char *str)
{
	char buffer[30];

	printf("test_ft_strcpy\n");
	printf("--------------\n");
	printf("%-10s: \"%s\"\n", "str", "");
	printf("%-10s: buffer[30]\n", "copy to");
	printf("%-10s: \"%s\"\n", "strcpy", strcpy(buffer, ""));
	clear_buffer(buffer, 30);
	printf("%-10s: \"%s\"\n", "ft_strcpy", ft_strcpy(buffer, ""));
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-10s: \"%s\"\n", "str", str);
	printf("%-10s: buffer[30]\n", "copy to");
	printf("%-10s: \"%s\"\n", "strcpy", strcpy(buffer, str));
	clear_buffer(buffer, 30);
	printf("%-10s: \"%s\"\n", "ft_strcpy", ft_strcpy(buffer, str));
	clear_buffer(buffer, 30);
	printf("\n");
}

void test_ft_strcmp(char *str, char *str2)
{
	printf("test_ft_strcmp\n\n");
	printf("--------------\n");
	printf("%-10s: \"%s\"\n", "str", str);
	printf("%-10s: \"%s\"\n", "str2", str2);
	printf("%-10s: \"%d\"\n", "strcmp", strcmp(str, str2));
	printf("%-10s: \"%d\"\n", "ft_strcmp", ft_strcmp(str, str2));
	printf("\n");
}

void test_ft_write()
{
	char	*str = "hyeonkim";
	int	ret;
	int	ft_ret;
	printf("write    :\n");
	ret = write(1, str, strlen(str));
	printf("\n");
	printf("write's return    : %d\n", ret);
	printf("ft_write :\n");
	ft_ret = ft_write(1, str, strlen(str));
	ft_write(1, str, strlen(str));
	printf("\n");
	printf("ft_write's return : %d\n", ft_ret);

	char	*str2 = "";
	int	ret_2;
	int	ft_ret_2;
	printf("write    :\n");
	ret_2 = write(1, str2, strlen(str2));
	printf("\n");
	printf("write's return    : %d\n", ret_2);
	printf("ft_write :\n");
	ft_ret_2 = ft_write(1, str2, strlen(str2));
	ft_write(1, str2, strlen(str2));
	printf("\n");
	printf("ft_write's return : %d\n", ft_ret_2);
}

void test_ft_read()
{
	int fd = open("hyeonkim", O_RDONLY);
	char buff1[891];
	int ret = 1;
	printf("\ntest_ft_read\n");
	printf("--------------\n");
	printf("file test0 | read\n");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n%s\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("hyeonkim", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("file test0 | read\n");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n%s\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("test", O_RDONLY);
	printf("file test1 | read\n");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n%s\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("test", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("file test1 | ft_read\n");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n%s\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("wrong", O_RDONLY);
	printf("%-10s: \n", "wrong | read ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n%s\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-10s: \n", "wrong | ft_read ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n%s\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);
}

void test_ft_strdup(char *str)
{

	char *save;
	char *save2;

	printf("test_ft_strdup\n");
	printf("--------------\n");
	printf("%-10s: \"%s\"\n", "str", str);
	save = strdup(str);
	printf("%-10s: \"%s\"\n", "strdup", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(str);
	printf("%-10s: \"%s\"\n", "ft_strdup", save2);
	free(save2);
	save2 = NULL;
	printf("\n");
}

int main()
{
	test_ft_strlen("hyeonkimsldkfjlskdjflskdjfkjsldkfjlskdjflskdjflksdjflksdjsdlkfjslkdjfslkdjflskdjflskd");
	test_ft_strcpy("hyeonkimsssdjdjdjdjdjddddddd");
	test_ft_strcmp("", "");
	test_ft_strcmp("", "sdfs");
	test_ft_strcmp("sdfsdf", "");
	test_ft_strcmp("sdd", "sdd");



	test_ft_strdup("hyeonkim");
	test_ft_strdup("");
	test_ft_strdup("sdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfhyeonkim");

	test_ft_write();
	test_ft_read();
}
