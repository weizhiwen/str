// ���Ļ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "StringType.h"
using namespace std;

int main()
{
	String s, t;
//	s.ch = "asadada";
//	s.length = 7;
	char *ch = "asdfghjkl";
	StrAssign(s, ch);
	//���Ը��ƺ���
	StrAssign(t, s);

	//���Դ�ӡ����
	Print(s);
	Print(t);

	//���ԱȽϺ���
	t.ch = "qweerrt";
	t.length = 8;
	int j = StrCompare(s, t);
	if (j > 0)
		printf("s > t\n");
	else if (j < 0)
		printf("s < t\n");
	else
		printf("s = t\n");

	////�������Ӻ���
	String str = Concat(s, t);
	Print(str);

	////���Խ�ȡ����
	String sub = SubString(str, 1, 50);
	Print(sub);

	//���Բ��뺯��
	StrInsert(s, t, 4);
	Print(s);

	//���Բ��Һ���
	/*String temp = { "dfg", 3};
	int pos = Index(s, temp, 1);
	printf("�ҵ���λ���ǣ�%d\n", pos);*/

	

	String r = { "dfgh", 4 };
	String v = { "1234", 4};
	//�����滻����
	Replace(s, r, v);
	Print(s);

	//ɾ���Ӵ�����
	StrDelete(s, 2, 3);
	Print(s);

	system("pause");
    return 0;
}

