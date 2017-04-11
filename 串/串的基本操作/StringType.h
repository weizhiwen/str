#pragma once
#include <iostream>
using namespace std;

typedef struct String {
	char *ch;
	int length;
}String;

//�����ַ�������
void StrAssign(String &t, String s)
{
	if (t.ch)
		t.ch = NULL;//�ͷ�tԭ�еĿռ�
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
			printf("�ڴ�ռ䲻����\a");
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
		t.ch = NULL;//�ͷ�tԭ�еĿռ�
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
			printf("�ڴ�ռ䲻����\a");
			exit(-2);
		}
		for (int j = 0; j < i; j++)
			t.ch[j] = ch[j];
		t.length = i;
	}
}

//�ַ����ȽϺ���
int StrCompare(String s, String t)
{
	for (int i = 0; i < s.length && i < t.length; i++)
		if (s.ch[i] != t.ch[i])
			return s.ch[i] - t.ch[i];
	return s.length - t.length;
}

//�ַ����ĳ���
int StrLength(String s)
{
	return s.length;
}

//�ַ��������Ӻ���
String Concat(String s, String t)
{
	String str;
	str.ch = NULL;
	str.length = s.length + t.length;
	if (!(str.ch = (char *)malloc((str.length) * sizeof(char))))
	{
		printf("�ڴ�ռ䲻����\a");
		exit(-2);
	}
	//���Ƶ�һ���ַ������������
	for (int i = 0; i < s.length; i++)
		str.ch[i] = s.ch[i];
	//���Ƶڶ����ַ������������
	for (int i = 0; i < t.length; i++)
		str.ch[s.length + i] = t.ch[i];
	return str;
}

//�ַ�����ȡ����
String SubString(String s, int start, int len)
{
	if (start < 1 || start > s.length)
	{
		printf("���������ʼλ�ã�");
		return{"1", 1};
	}
	if (len < 0 || len > s.length - start + 1)
	{
		printf("��������ַ�����ȡ���ȣ�");
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

//��ӡ�ַ������ݺ���
void Print(String s)
{
	for(int i = 0; i < s.length; i++)
	{
		printf("%c", s.ch[i]);
	}
	printf("\n");
}

//�ַ������뺯��
int StrInsert(String &s, String t, int pos)
{
	if (pos < 1 || pos > s.length + 1)
	{
		printf("������Ĳ���λ�ã�");
		return 0;
	}
	if (t.length != 0)
	{
		//realloc��ȫ��ʹ�÷�ʽ
		void *temp = realloc(s.ch, (s.length + t.length) * sizeof(char));
		if (!temp)
		{
			printf("�ڴ����ʧ�ܣ�");
			exit(-2);
		}
		s.ch = (char *)temp;
		//����ԭ�ַ������ַ�λ�ã��Ӻ���ǰ
		for (int i = s.length - 1; i >= pos - 1; i--)
			s.ch[i + t.length] = s.ch[i];
		for (int i = 0; i < t.length; i++)
			s.ch[pos - 1 + i] = t.ch[i];
		s.length += t.length;
	}
	return 0;
}

//�ַ������Һ���
int Index(String s, String t, int pos)
{
	if (pos < 1 || pos > s.length)
	{
		printf("������Ĳ���λ�ã�");
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

//ɾ���Ӵ�����
int StrDelete(String &s, int pos, int len) {
	int m = s.length;
	if (pos < 1 || pos + len - 1 > m)
	{
		printf("�������ɾ��λ�ã�");
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

//�ַ����滻����
void Replace(String &s, String t, String v) //�˺����봮�Ĵ洢�ṹ�޹� 
{
	int i = 1; //�Ӵ�S�ĵ�һ���ַ�����Ҵ�T
	if (t.length == 0) // T�ǿմ�
	{
		printf("�滻���Ӵ�Ϊ�մ�");
		exit(0);
	}
	while (i)
	{
		i = Index(s, t, i); // iΪ����һ��i֮���ҵ����Ӵ�T��λ��
		if (i) // ��S�д��ڴ�T
		{
			StrDelete(s, i, StrLength(t)); // ɾ���ô�T
			StrInsert(s, v, i); // ��ԭ��T��λ�ò��봮V 
			i += StrLength(v); // �ڲ���Ĵ�V����������Ҵ�T
		}
	}
}