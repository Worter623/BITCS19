#include <cstdio>
#include <cstring>
#include <cmath>

char input[1000];
int table[30], sum = 0, value[10000000], record[30];

int GetPriority(char x)
{
	switch (x)
	{
		case '#': return -1;
		case '(': return 0;
		case '+': return 1;
		case '-': return 2;
		case '|': return 3;
		case '&': return 4;
		case '!': return 5;
		default: return 0;
	}
}
void ConvertToPostfix()
{
	char post[1000] = { '\0' },stack[1000] = { '#' };
	int size_post = -1, size_stack = 0,length = strlen(input);
	for (int i = 0; i < length; i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			post[++size_post] = input[i];
			continue;
		}
		if (input[i] == '!' || input[i] == '&' || input[i] == '|' || input[i] == '-' || input[i] == '+')
		{
			while (GetPriority(input[i]) <= GetPriority(stack[size_stack]))
				post[++size_post] = stack[size_stack--];
			stack[++size_stack] = input[i];
			continue;
		}
		if (input[i] == '(')
		{
			stack[++size_stack] = input[i];
			continue;
		}
		if (input[i] == ')')
		{
			while (stack[size_stack] != '(') post[++size_post] = stack[size_stack--];
			size_stack--;
			continue;
		}
	}
	while (size_stack) post[++size_post] = stack[size_stack--];
	strcpy(input, post);
}

void Table()
{
	memset(table, 0, sizeof(table));
	int length = strlen(input);
	for (int i = 0; i < length; i++)
	{
		if (input[i] >= 'a' && input[i] < 'z')
			table[input[i] - 'a'] = 1;
	}
	for (int i = 0; i < 26; i++)
		if (table[i])
			sum++;
	sum = pow(2, sum);
}

int GetPlace()
{
	int ans = 0, weight = 1;
	for (int i = 25; i >= 0; i--)
		if (table[i])
		{
			if (record[i])
				ans += weight;
			weight *= 2;
		}
	return ans;
}

int Operate(int a, int b, char op)
{
	switch (op)
	{
		case '&':
			return a * b;
		case '|':
			if (a + b)	return 1;
			else  return 0;
		case '-':
			if (a == 1 && b == 0) return 0;
			else return 1;
		case '+':
			return !((a + b) & 1);
	}
}

int GetValue()
{
	int stack[1000], size_stack = -1,length = strlen(input);
	for (int i = 0; i < length; i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			stack[++size_stack] = record[input[i] - 'a'];
			continue;
		}
		if (input[i] == '!')
		{
			stack[size_stack] = (stack[size_stack] + 1) & 1;
			continue;
		}
		int ans = Operate(stack[size_stack - 1], stack[size_stack], input[i]);
		stack[--size_stack] = ans;
	}
	return stack[0];
}

void Calculate(char c)
{
	int place, ans;
	while (c <= 'z' && table[c - 'a'] == 0)
		c++;
	if (c > 'z')
	{
		place= GetPlace();
		ans = GetValue();
		value[place] = ans;
		return;
	}
	record[c - 'a'] = 0;
	Calculate(c + 1);
	record[c - 'a'] = 1;
	Calculate(c + 1);
}

void Output()
{
	int i = 0;
	while (i < sum && !value[i]) i++;
	if (i >= sum)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main()
{
	scanf("%s", input);
	ConvertToPostfix();
	Table();
	memset(value, 0, sizeof(value));
	memset(record, 0, sizeof(record));
	Calculate('a');
	Output();
}