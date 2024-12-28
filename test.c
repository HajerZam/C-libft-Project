#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void print_test_result(const char *test_name, int success)
{
	if (success)
		printf("%s: \033[0;32mPASSED\033[0m\n", test_name);
	else
		printf("%s: \033[0;31mFAILED\033[0m\n", test_name);
}

void test_striteri_helper(unsigned int i, char *c)
{
	*c = *c + i;
}

char test_strmapi_helper(unsigned int i, char c)
{
	return (c + i);
}

int main()
{
	// ft_isalpha
	print_test_result("ft_isalpha", ft_isalpha('A') && ft_isalpha('z') && !ft_isalpha('1'));

	// ft_isdigit
	print_test_result("ft_isdigit", ft_isdigit('5') && !ft_isdigit('a'));

	// ft_isalnum
	print_test_result("ft_isalnum", ft_isalnum('A') && ft_isalnum('3') && !ft_isalnum('$'));

	// ft_isascii
	print_test_result("ft_isascii", ft_isascii(127) && ft_isascii(0) && !ft_isascii(-1));

	// ft_isprint
	print_test_result("ft_isprint", ft_isprint(' ') && ft_isprint('~') && !ft_isprint(127));

	// ft_strlen
	print_test_result("ft_strlen", ft_strlen("Hello") == 5);

	// ft_memset
	char buf1[10] = {0};
	ft_memset(buf1, 'A', 5);
	print_test_result("ft_memset", memcmp(buf1, "AAAAA\0\0\0\0\0", 10) == 0);

	// ft_bzero
	char buf2[10] = {0};
	ft_bzero(buf2, 5);
	print_test_result("ft_bzero", memcmp(buf2, "\0\0\0\0\0\0\0\0\0\0", 10) == 0);

	// ft_memcpy
	char buf3[10] = {0};
	ft_memcpy(buf3, "ABCDE", 5);
	print_test_result("ft_memcpy", memcmp(buf3, "ABCDE\0\0\0\0\0", 10) == 0);

	// ft_memmove
	char buf4[10] = "ABCDE";
	ft_memmove(buf4 + 2, buf4, 3);
	print_test_result("ft_memmove", memcmp(buf4, "ABABC", 5) == 0);

	// ft_strlcpy
	char dest1[10];
	size_t len1 = ft_strlcpy(dest1, "Hello", 10);
	print_test_result("ft_strlcpy", strcmp(dest1, "Hello") == 0 && len1 == 5);

	// ft_strlcat
	char dest2[10] = "Hi";
	size_t len2 = ft_strlcat(dest2, " there", 10);
	print_test_result("ft_strlcat", strcmp(dest2, "Hi there") == 0 && len2 == 8);

	// ft_toupper
	print_test_result("ft_toupper", ft_toupper('a') == 'A' && ft_toupper('Z') == 'Z');

	// ft_tolower
	print_test_result("ft_tolower", ft_tolower('A') == 'a' && ft_tolower('z') == 'z');

	// ft_strchr
	print_test_result("ft_strchr", ft_strchr("Hello", 'e') == strchr("Hello", 'e'));

	// ft_strrchr
	print_test_result("ft_strrchr", ft_strrchr("Hello", 'l') == strrchr("Hello", 'l'));

	// ft_strncmp
	print_test_result("ft_strncmp", ft_strncmp("abc", "abd", 2) == strncmp("abc", "abd", 2));

	// ft_memchr
	print_test_result("ft_memchr", ft_memchr("Hello", 'e', 5) == memchr("Hello", 'e', 5));

	// ft_memcmp
	print_test_result("ft_memcmp", ft_memcmp("abc", "abd", 3) == memcmp("abc", "abd", 3));

	// ft_strnstr
	print_test_result("ft_strnstr", ft_strnstr("Hello, world", "world", 12) == strstr("Hello, world", "world"));

	// ft_atoi
	print_test_result("ft_atoi", ft_atoi("42") == atoi("42") && ft_atoi("   -42") == atoi("   -42"));

	// ft_calloc
	int *calloc_test = (int *)ft_calloc(5, sizeof(int));
	int calloc_pass = 1;
	for (int i = 0; i < 5; i++)
		if (calloc_test[i] != 0)
			calloc_pass = 0;
	free(calloc_test);
	print_test_result("ft_calloc", calloc_pass);

	// ft_strdup
	char *dup_test = ft_strdup("Hello");
	print_test_result("ft_strdup", strcmp(dup_test, "Hello") == 0);
	free(dup_test);


	// ft_substr
	char *substr_test = ft_substr("Hello", 1, 3);
	print_test_result("ft_substr", strcmp(substr_test, "ell") == 0);
	free(substr_test);

	// ft_strjoin
	char *join_test = ft_strjoin("Hello", " world");
	print_test_result("ft_strjoin", strcmp(join_test, "Hello world") == 0);
	free(join_test);

	// ft_strtrim
	char *trim_test = ft_strtrim("  Hello  ", " ");
	print_test_result("ft_strtrim", strcmp(trim_test, "Hello") == 0);
	free(trim_test);

	// ft_split
	char **split_test = ft_split("a,b,c", ',');
	print_test_result("ft_split", strcmp(split_test[0], "a") == 0 && strcmp(split_test[1], "b") == 0 && strcmp(split_test[2], "c") == 0);
	for (int i = 0; split_test[i]; i++)
		free(split_test[i]);
	free(split_test);

	// ft_itoa
	char *itoa_test = ft_itoa(-123);
	print_test_result("ft_itoa", strcmp(itoa_test, "-123") == 0);
	free(itoa_test);

	// ft_strmapi
	char *mapi_test = ft_strmapi("abc", test_strmapi_helper);
	print_test_result("ft_strmapi", strcmp(mapi_test, "ace") == 0);
	free(mapi_test);

	// ft_striteri
	char iteri_test[] = "abc";
	ft_striteri(iteri_test, test_striteri_helper);
	print_test_result("ft_striteri", strcmp(iteri_test, "ace") == 0);

	return 0;
}
