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
		printf("ͨѶ¼������\n");
	}
	else
	{
		printf("�������Ա����:>");
		scanf("%s", con->date[con->size].name);

		printf("������%s�Ա�:>",con->date[con->size].name);
		scanf("%s", con->date[con->size].sex);
		
		printf("������%s����:>", con->date[con->size].name);
		scanf("%d", &(con->date[con->size].age));
		
		printf("������%s�绰:>", con->date[con->size].name);
		scanf("%s", con->date[con->size].tele);
		
		printf("������%sסַ:>", con->date[con->size].name);
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
		int i = 0;
		for (i = 0; i < con->size; i++)
		{
			printf("������%s\n", con->date[i].name);
			printf("�Ա�%s\n", con->date[i].sex);
			printf("���䣺%d\n", con->date[i].age);
			printf("�绰��%s\n", con->date[i].tele);
			printf("סַ��%s\n\n", con->date[i].addr);
		}
	}
}

static int Findbyname(const C* con, char search_name[Max_name])
//�ú�����������Ҫ��������Ҫ����������
//��Ϊ.h�ļ��������ĺ�����������ʵ��ͨѶ¼��������Ҫ�ĺ��������ú����������Ǽ����������Ӻ�����
//��������ļ�ʹ���˸ú���������Ҳ�����ͻ��
{
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		if (strcmp(con->date[i].name, search_name) == 0)
		{
			//memset(con->date[i], 0, sizeof(con->date[i]));
			return i;//�ҵ������±�
		}
	}
	return -1;//�Ҳ�������-1
}

//ɾ���涨�����ĳ�Ա��Ϣ
void DelContact(C* con)
{
	char search_name[Max_name] = "0";
	printf("��������Ҫɾ���ĳ�Ա����:>");
	scanf("%s", search_name);
	//Ѱ��
	//���ڲ���ģ����޸�ģ�鶼���õ�����㷨���������ǿ��Խ����ģ������湫�á�
	int pos = Findbyname(con, search_name);
	//ɾ��
	if (pos == -1)
	{
		printf("ͨѶ¼�в����ڸó�Ա��\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < con->size - 1; j++)
		{
			con->date[j] = con->date[j + 1];
		}
		con->size--;
		printf("ɾ���ɹ���\n");
	}
}


//���ҳ�Ա
void SearchContact(const C* con)
{
	assert(con != NULL);
	printf("��ѡ����ҵĳ�Ա��:>");
	char search_name[Max_name];
	scanf("%d", search_name);
	int pos = Findbyname(con, search_name);
	if (-1 == pos)
	{
		printf("���ҵĳ�Ա�����ڣ�\n");
	}
	else
	{
		printf("������%s\n", con->date[pos].name);
		printf("�Ա�%s\n", con->date[pos].sex);
		printf("���䣺%d\n", con->date[pos].age);
		printf("�绰��%s\n", con->date[pos].tele);
		printf("סַ��%s\n\n", con->date[pos].addr);
	}
}


//�޸ĳ�Ա��Ϣ
void ModifyContact(C* con)
{
	char search_name[Max_name];
	printf("��������Ҫ�޸ĵĳ�Ա����:>");
	scanf("%s", search_name);
	int pos = Findbyname(con, search_name);
	if (-1 == pos)
	{
		printf("û���ҵ��ó�Ա��\n");
	}
	else
	{
		printf("��ѡ����Ҫ���޸���:>\n1.name  2.sex  3.age  4.tele  5.addr\n");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("��������Ҫ�޸ĵ�����:>");
			scanf("%s", con->date[pos].name);
			printf("�޸���ɡ�\n");
			break;
		case 2:
			printf("��������Ҫ�޸ĵ��Ա�:>");
			scanf("%s", con->date[pos].sex);
			printf("�޸���ɡ�\n");
			break;
		case 3:
			printf("��������Ҫ�޸ĵ�����:>");
			scanf("%d", &con->date[pos].age);
			printf("�޸���ɡ�\n");
			break;
		case 4:
			printf("��������Ҫ�޸ĵĵ绰:>");
			scanf("%s", con->date[pos].tele);
			printf("�޸���ɡ�\n");
			break;
		case 5:
			printf("��������Ҫ�޸ĵ�סַ:>");
			scanf("%s", con->date[pos].addr);
			printf("�޸���ɡ�\n");
			break;
		case 0:
			printf("�˳��޸ġ�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	}
}

//qsort�õĻص�����
static int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//Ӧ����������ĸ����
void SortContact(C* con)
{
	if (con->size < 1)
	{
		printf("ͨѶ¼Ϊ�գ����������塣\n");
	}
	else
	{
		qsort((void*)con, con->size, sizeof(con->date[0].name), cmp((void*)con->date[con->size - 1].name, (void*)con->date[con->size].name));
	}
	
}