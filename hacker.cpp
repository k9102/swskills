
#include "pch.h""
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[100000 + 10];//�ʱ� ���ڿ�
char cmd[500000 + 10];//��ɾ� ���ڿ�

void InputData() {
	cin >> str;
	cin >> cmd;
}

int main() {
	InputData();//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���

	int len = strlen(str);
	char  *pcmd = cmd;
	int cur = len;


	while (*pcmd != 0)
	{
		if (*pcmd >= 'a' && *pcmd <= 'z')
		{
			memmove(str + cur + 1, str + cur, len - cur);
			str[cur] = *pcmd;
			len++;
			cur++;
		}
		else
		{
			switch (*pcmd)
			{
			case 'L':
				cur = max(0, cur - 1);
				break;
			case 'R':
				cur = min(len, cur + 1);
				break;
			case 'B':
				if (cur != 0)
				{
					memmove(str + cur - 1, str + cur, len - cur);
					len--;
					cur--;
				}
				break;
			}
		}

		pcmd++;
	}
	str[len] = '\0';
	cout << str;
	return 0;
}
