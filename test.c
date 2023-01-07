// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int spaces(char *line)
{
    int i = 0;
    for (; line[i] == ' '; i++);
    return (i);
}

int is_valid_map(char **map, int map_height)
{
    for (int i = 0; map[i]; i++)
	{
		if ((i == 0 || i == map_height - 1))
		{
			if (map[i][spaces(map[i])] != '1' || map[i][strlen(map[i]) - 1] != '1')
				return (0);
		}
		for (int j = 0; map[i][j]; j++)
		{
			if (map[i][j] == ' ')
			{
				if (
					j != 0
					&& (map[i - 1][j - 1] != '1' || map[i - 1][j + spaces(&map[i][j])] != '1'
					|| map[i][j - 1] != '1' || map[i][j + spaces(&map[i][j])] != '1')
				)
				{
					printf("%d\n", j);
					return (0);
				}
				else
					j += spaces(&map[i][j]);
			}
		}
	}
    return (1);
}

int main() {
    char *s[9] = {
		"     1111111111111111",
		"     1100011111100001",
		"     1100011111100001",
		"100011100011111100001",
		"100011100011111100001",
		"100011100011111100001",
		"10001 10001    100001",
		"11111 11111    111111",
		NULL
	};

    printf("%s\n", is_valid_map(s, 8) ? "YES" : "NO");

    return 0;
}