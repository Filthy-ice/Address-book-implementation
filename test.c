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
}

int main()
{
	int input = 0;
	C con;
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
		case 1:
			AddContact(&con);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			ShowContact(&con);
			break;
		case 0:
			printf("�˳�ͨѶ¼��\n");
			break;
		default:
			printf("ѡ����������ԡ�\n");
			break;
		}
	} while (input);
	return 0;
}