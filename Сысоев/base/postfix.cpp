﻿#include "postfix.h"
#include "stack.h"
#include <iostream>
#define max_size 50

string TPostfix::ToPostfix()
{
	int  len = GetSizeInfix();
	char result[max_size];
	TStack<char> stack(len);
	int count = 0;
	int i = 0;
	int flag = 0;
	while (i < len)
	{
		if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '(' && infix[i] != ')')
		{
			flag = 0;
			while ((infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '(' && infix[i] != ')') && i < len)
			{
				if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
					flag = 0;
				else flag = 1;
				result[count++] = infix[i++];
			}
			if (flag == 1)
				result[count++] = ' ';
		}

		if (infix[i] == '(')
			stack.Push(infix[i]);
		if (infix[i] == ')')
		{
			while (stack.Top() != '(')
				result[count++] = stack.Pop();
			stack.Pop();
		}
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			if (stack.IsEmpty() || stack.Top() == '(')
				stack.Push(infix[i]);
			else if (Sign(infix[i]) > Sign(stack.Top()))
				stack.Push(infix[i]);
			else
			{
				while (!stack.IsEmpty() && Sign(infix[i]) <= (stack.Top()))
					result[count++] = stack.Pop();
				stack.Push(infix[i]);
			}
		}
		i++;
	}
	while (stack.IsEmpty() != true)
		result[count++] = stack.Pop();
	result[count] = '\0';
	postfix = result;
	return postfix;
}

double TPostfix::Calculate()
{
	int len = postfix.length();
	TStack<double> stack(len);
	double c, c1;
	double k;
	double tmp[max_size];
	char tmp1[max_size];
	int flag;
	int i = 0;

	while (i < len)
	{
		if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
		{
			if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
			{
				flag = 0;
				tmp1[i] = postfix[i];
				for (int j = 0; j < i; j++)
					if (postfix[i] == tmp1[j])
					{
						flag = 1;
						stack.Push(tmp[j]);
						break;
					}

				if (flag == 0)
				{
					cout << postfix[i] << "=" << " ";
					cin >> k;
					tmp[i] = k;
					stack.Push(k);
				}
			}
			else
			{
				int tmp = 0;
				while (postfix[i] != ' ')
				{
					while (postfix[i] >= 0x30 && postfix[i] <= 0x39)
					{
						tmp = tmp + (postfix[i] & 0x0F);
						tmp = tmp * 10;
						i++;
					}
				}
				tmp = tmp / 10;

				stack.Push(tmp);
			}
		}
		else
		{
			if (postfix[i] == '+')
			{
				c = stack.Pop();
				c1 = stack.Pop();
				stack.Push(c1 + c);
			}
			if (postfix[i] == '-')
			{
				c = stack.Pop();
				c1 = stack.Pop();
				stack.Push(c1 - c);
			}
			if (postfix[i] == '/')
			{
				c = stack.Pop();
				c1 = stack.Pop();
				stack.Push(c1 / c);
			}
			if (postfix[i] == '*')
			{
				c = stack.Pop();
				c1 = stack.Pop();
				stack.Push(c1*c);
			}
		}
		i++;
	}
	return stack.Pop();
}

int TPostfix::Sign(char c)
{
	if ((c == '/') || (c == '*')) return 2;
	if ((c == '+') || (c == '-')) return 1;
	if (c == '(') return 0;
	return -1;
}
