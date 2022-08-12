#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


//contact.cʵ��ͨѶ¼�㷨
//���ýṹ������
void InitContact(C* con)
{
	//֮ǰʹ�õ���ջ�����ٿռ䣬����ʹ�ö�̬�ڴ濪�ٿռ䡣
	//memset(con->date, 0, sizeof(con->date));//�����ı����ṹ����ȫ��0
	//con->size = 0;//��ʾ������������ֻ��0����Ա��
	con->date = (P*)malloc(DEFAULT_sz * sizeof(P));
	//��̬�ڴ濪�ٱ����ж��Ƿ񿪱ٳɹ�������Ұָ��ĳ��֡�
	if (con->date == NULL)
	{
		return;
	}
	con->size = 0;
	con->capacity = DEFAULT_sz;
}

static void CheckCapacity(C* con)
{
	if (con->size == con->capacity)
	{
		//����
		P* ptr = (P*)realloc(con->date, (con->capacity + 2) * sizeof(P));
		if (ptr != NULL)
		{
			con->date = ptr;
			con->capacity += 2;
			printf("���ݳɹ���\n");
		}
		else
		{
			printf("����ʧ�ܡ�\n");
		}
	}
}

//��ӳ�Ա����
void AddContact(C* con)
{
	//��������ֻ��DEFAULT_sz�ǲ�������ɳ���ġ����ԣ���Ҫһ�������������ӿ��ٵ��ڴ�������
	CheckCapacity(con);//��⵱ǰͨѶ¼��������1.������ˣ����ӿռ䣻2.���û�����޲�����
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
	//��Ϊ��Ϊ��̬�����ڴ棬��������������Ρ�
	//if (con->size == Max)
	//{
	//	printf("ͨѶ¼������\n");
	//}
	//else
	//{
	//	printf("�������Ա����:>");
	//	scanf("%s", con->date[con->size].name);

	//	printf("������%s�Ա�:>",con->date[con->size].name);
	//	scanf("%s", con->date[con->size].sex);
	//	
	//	printf("������%s����:>", con->date[con->size].name);
	//	scanf("%d", &(con->date[con->size].age));
	//	
	//	printf("������%s�绰:>", con->date[con->size].name);
	//	scanf("%s", con->date[con->size].tele);
	//	
	//	printf("������%sסַ:>", con->date[con->size].name);
	//	scanf("%s", con->date[con->size].addr);

	//	con->size++;
	//	printf("��ӳɹ���\n");
	//}
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
static int cmp_struct(const void* e1, const void* e2)
{
	return strcmp(((C*)e1)->date->name, ((C*)e2)->date->name);
}
//Ӧ����������ĸ����
void SortContact(C* con)
{
	if (con->size < 1)
	{
		printf("��Ա̫�� �� ͨѶ¼Ϊ�գ����������塣\n");
	}
	else
	{
		qsort(con, con->size, sizeof(con->date[0]), cmp_struct);
		printf("������ɡ�\n");
	}
	
}


//�˳�������ͨѶ¼��
void DestroyContact(C* con)
{
	free(con->date);
	con->date = NULL;
}