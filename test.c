#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//test.cΪ�˲��Գ�����
// ��Ҫʵ�ֵĹ��ܣ�������������˼ά��
//1.��Ŷ����Ա��Ϣ��
//   �����Ϣ������ ����  �Ա�  ����  �绰  סַ
//2.��ӳ�Ա��Ϣ��
//3.ɾ����Ա��Ϣ��
//4.���ҳ�Ա��Ϣ��
//5.�޸ĳ�Ա��Ϣ��
//6.��ӡ��Ա��Ϣ��
//7.������ĸ����
void menu()
{
	printf("**************************************\n");
	printf("******     1.add      2.del     ******\n");
	printf("******     3.search   4.modify  ******\n");
	printf("******     5.show     6.sort    ******\n");
	printf("******                0.exit    ******\n");
	printf("**************************************\n");
}//�������·���д��������е��鷳���������Ǹ�Ϊ.h����ö���оٳ�����

int main()
{
	int input = 0;
	C con;//����������ȡ����1000��Ա�Ŀ��٣��洢����ָ�롣
	//��.h�ļ��ж����contact�Ѿ�������1000����Ա�����Բ���Ҫ�ṹ�����顣
	//InitContact(con);//�Ľ�������������ϣ���Ϊ���θ�������Ҫ�ṹ������ĵ�ַ���ܶ�ԭ�����������������������ҽ�ʡ�ռ䡣
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>\n");
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
			//��Ϊ�Ӷ������ٵĶ�̬�ڴ棬ʹ����Ϻ���Ҫ�ͷŵ�ռ�õ��ڴ棬���ԣ�����Ҫ���˳���ѡ����дһ����������(�ͷ��ڴ�)�ĺ�����
			DestroyContact(&con);
			printf("�˳�ͨѶ¼��\n");
			break;
		default:
			printf("ѡ����������ԡ�\n");
			break;
		}
	} while (input);
	return 0;
}