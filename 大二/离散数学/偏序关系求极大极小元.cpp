#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool min[50],max[50],alphabet[50];

int judge(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	return 0;
}

void output(bool which[])
{
	int count = 0;
	while (!alphabet[count] || !which[count])
		count++;
	printf("%c", count + 'a');
	for (count++; count < 26; count++)
		if (alphabet[count] && which[count])
			printf(",%c", count + 'a');
	printf("\n");
}

int main()
{
	char c;
	memset(alphabet, false, sizeof(alphabet));
	memset(max, true, sizeof(max));
	memset(min, true, sizeof(min));
	while ((c = getchar()) != '\n')
		if (judge(c))
			alphabet[c - 'a'] = true;
	c = getchar();
	while (c != '\n')
	{
		while (!(judge(c)))
			c = getchar();
		max[c - 'a'] = false;
		c = getchar();
		while (!(judge(c)))
			c = getchar();
		min[c - 'a'] = false;
		c = getchar();
		while (c != '\n' && (!judge(c)))
			c = getchar();
	}
	output(min);
	output(max);
}