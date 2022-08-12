#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//test.c为了测试程序功能
// 需要实现的功能，测试驱动开发思维。
//1.存放多个成员信息。
//   存放信息包括： 姓名  性别  年龄  电话  住址
//2.添加成员信息。
//3.删除成员信息。
//4.查找成员信息。
//5.修改成员信息。
//6.打印成员信息。
//7.按照字母排序。
void menu()
{
	printf("**************************************\n");
	printf("******     1.add      2.del     ******\n");
	printf("******     3.search   4.modify  ******\n");
	printf("******     5.show     6.sort    ******\n");
	printf("******                0.exit    ******\n");
	printf("**************************************\n");
}//但是上下翻动写代码觉得有点麻烦，所以我们改为.h里用枚举列举出来。

int main()
{
	int input = 0;
	C con;//调整后，里面取消了1000成员的开辟，存储成了指针。
	//在.h文件中定义的contact已经包含了1000个成员，所以不需要结构体数组。
	//InitContact(con);//改进后这个做法作废，因为传参给函数需要结构体数组的地址才能对原数组内数据作出调整，而且节省空间。
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			//因为从堆区开辟的动态内存，使用完毕后，需要释放掉占用的内存，所以，我们要在退出的选项里写一个销毁数据(释放内存)的函数。
			DestroyContact(&con);
			printf("退出通讯录。\n");
			break;
		default:
			printf("选择错误！请重试。\n");
			break;
		}
	} while (input);
	return 0;
}