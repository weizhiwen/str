// 串的基本操作.cpp : 定义控制台应用程序的入口点。
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
	//测试复制函数
	StrAssign(t, s);

	//测试打印函数
	Print(s);
	Print(t);

	//测试比较函数
	t.ch = "qweerrt";
	t.length = 8;
	int j = StrCompare(s, t);
	if (j > 0)
		printf("s > t\n");
	else if (j < 0)
		printf("s < t\n");
	else
		printf("s = t\n");

	////测试连接函数
	String str = Concat(s, t);
	Print(str);

	////测试截取函数
	String sub = SubString(str, 1, 50);
	Print(sub);

	//测试插入函数
	StrInsert(s, t, 4);
	Print(s);

	//测试查找函数
	/*String temp = { "dfg", 3};
	int pos = Index(s, temp, 1);
	printf("找到的位置是：%d\n", pos);*/

	

	String r = { "dfgh", 4 };
	String v = { "1234", 4};
	//测试替换函数
	Replace(s, r, v);
	Print(s);

	//删除子串函数
	StrDelete(s, 2, 3);
	Print(s);

	system("pause");
    return 0;
}

