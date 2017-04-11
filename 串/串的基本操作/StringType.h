#pragma once
#include <iostream>
using namespace std;

typedef struct String {
	char *ch;
	int length;
}String;

//复制字符串函数
void StrAssign(String &t, String s)
{
	if (t.ch)
		t.ch = NULL;//释放t原有的空间
	char *c = s.ch;
	int n = s.length;
	if (!n)
	{
		t.ch = NULL;
		t.length = 0;
	}
	else
	{
		if (!(t.ch = (char *)malloc(n * sizeof(char))))
		{
			printf("内存空间不够！\a");
			exit(-2);
		}
		for (int i = 0; i < n; i++)
			t.ch[i] = s.ch[i];
		t.length = n;
	}
}

void StrAssign(String &t, char *ch)
{
	if (t.ch)
		t.ch = NULL;//释放t原有的空间
	int i;
	char *n = ch;
	for (i = 0; *n; i++, n++);
	if (!i)
	{
		t.ch = NULL;
		t.length = 0;
	}
	else
	{
		if (!(t.ch = (char *)malloc(i * sizeof(char))))
		{
			printf("内存空间不够！\a");
			exit(-2);
		}
		for (int j = 0; j < i; j++)
			t.ch[j] = ch[j];
		t.length = i;
	}
}

//字符串比较函数
int StrCompare(String s, String t)
{
	for (int i = 0; i < s.length && i < t.length; i++)
		if (s.ch[i] != t.ch[i])
			return s.ch[i] - t.ch[i];
	return s.length - t.length;
}

//字符串的长度
int StrLength(String s)
{
	return s.length;
}

//字符串的连接函数
String Concat(String s, String t)
{
	String str;
	str.ch = NULL;
	str.length = s.length + t.length;
	if (!(str.ch = (char *)malloc((str.length) * sizeof(char))))
	{
		printf("内存空间不够！\a");
		exit(-2);
	}
	//复制第一个字符串里面的内容
	for (int i = 0; i < s.length; i++)
		str.ch[i] = s.ch[i];
	//复制第二个字符串里面的内容
	for (int i = 0; i < t.length; i++)
		str.ch[s.length + i] = t.ch[i];
	return str;
}

//字符串截取函数
String SubString(String s, int start, int len)
{
	if (start < 1 || start > s.length)
	{
		printf("不合理的起始位置！");
		return{"1", 1};
	}
	if (len < 0 || len > s.length - start + 1)
	{
		printf("不合理的字符串截取长度！");
		return{ "1", 1 };
	}
	String str;
	str.ch = NULL;
	str.length = 0;
	if (!len)
	{
		str.ch = NULL;
		str.length = 0;
	}
	else
	{
		str.ch = (char *)malloc(len * sizeof(char));
		for (int i = 0; i < len; i++)
			str.ch[i] = s.ch[i + start -1];
		str.length = len;
	}
	return str;
}

//打印字符串内容函数
void Print(String s)
{
	for(int i = 0; i < s.length; i++)
	{
		printf("%c", s.ch[i]);
	}
	printf("\n");
}

//字符串插入函数
int StrInsert(String &s, String t, int pos)
{
	if (pos < 1 || pos > s.length + 1)
	{
		printf("不合理的插入位置！");
		return 0;
	}
	if (t.length != 0)
	{
		//realloc安全的使用方式
		void *temp = realloc(s.ch, (s.length + t.length) * sizeof(char));
		if (!temp)
		{
			printf("内存操作失败！");
			exit(-2);
		}
		s.ch = (char *)temp;
		//调整原字符串的字符位置，从后往前
		for (int i = s.length - 1; i >= pos - 1; i--)
			s.ch[i + t.length] = s.ch[i];
		for (int i = 0; i < t.length; i++)
			s.ch[pos - 1 + i] = t.ch[i];
		s.length += t.length;
	}
	return 0;
}

//字符串查找函数
int Index(String s, String t, int pos)
{
	if (pos < 1 || pos > s.length)
	{
		printf("不合理的查找位置！");
		return 0;
	}
	String str = {"", 0};
	int i = pos;
	int n = StrLength(s);
	int m = StrLength(t);
	while (i < n - m + 1)
	{
		str = SubString(s, i, m);
		if (StrCompare(str, t) != 0)
			i++;
		else
			return i;
	}
	return 0;
}

//删除子串函数
int StrDelete(String &s, int pos, int len) {
	int m = s.length;
	if (pos < 1 || pos + len - 1 > m)
	{
		printf("不合理的删除位置！");
		return 0;
	}
	for (int j = pos - 1; j < (m - len); j++)
	{
		s.ch[j] = s.ch[j + len];
	}
	s.length = m - len;
	
	s.ch[m - len] = NULL;
	return 0;
}

//字符串替换函数
void Replace(String &s, String t, String v) //此函数与串的存储结构无关 
{
	int i = 1; //从串S的第一个字符起查找串T
	if (t.length == 0) // T是空串
	{
		printf("替换的子串为空串");
		exit(0);
	}
	while (i)
	{
		i = Index(s, t, i); // i为从上一个i之后找到的子串T的位置
		if (i) // 串S中存在串T
		{
			StrDelete(s, i, StrLength(t)); // 删除该串T
			StrInsert(s, v, i); // 在原串T的位置插入串V 
			i += StrLength(v); // 在插入的串V后面继续查找串T
		}
	}
}