#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


//contact.cʵ��ͨѶ¼�㷨
//���ýṹ������
void InitContact(C* con)
{
	memset(con->date, 0, sizeof(con->date));//�����ı����ṹ����ȫ��0
	con->size = 0;//��ʾ������������ֻ��0����Ա��
}

//��ӳ�Ա����
void AddContact(C* con)
{
	if (con->size == Max)
	{
		pirntf("ͨѶ¼������\n");
	}
	else
	{
		printf("�������Ա����:>\n");
		scanf("%s", con->date[con->size].name);

		printf("������%s�Ա�:>\n",con->date[con->size].sex);
		scanf("%s", con->date[con->size].sex);
		
		printf("������%s����:>\n", con->date[con->size].name);
		scanf("%d", &(con->date[con->size].age));
		
		printf("������%s�绰:>\n", con->date[con->size].name);
		scanf("%s", con->date[con->size].tele);
		
		printf("������%sסַ:>\n", con->date[con->size].name);
		scanf("%s", con->date[con->size].addr);

		con->size++;
		printf("��ӳɹ���\n");
	}
}

//�������ֻ��ʾ��ӳɹ�����������Ҫ��ӡһ�¡�
void ShowContact(const C* con)
{
	if (con->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
	}
	else
	{
		printf("������%s\n", con->date[con->size].name);
		printf("�Ա�%s\n", con->date[con->size].sex);
		printf("���䣺%d\n", con->date[con->size].age);
		printf("�绰��%s\n", con->date[con->size].tele);
		printf("סַ��%s\n", con->date[con->size].addr);
	}
}