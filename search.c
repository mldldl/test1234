//������ : ������
/*
�˻��� ���� �Լ� ����
*/
#include "std_header.h"
#include "my_struct.h"
#include "my_header.h"

extern Customer *cus[CUS_MAX];	//ȸ�������� ������ ����ü �迭
extern Dvd *dvd[DVD_MAX];		//DVD������ ������ ����ü �迭

extern int cus_cnt;				//ȸ�� ī����
extern int dvd_cnt;				//DVD ī����

/*
ID�� �Է¹޾� ȸ���� �˻��ϱ� ���� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void Search_Cus();
*/
void Search_Cus()						//ȸ�� �˻�(ID�̿�)
{
	char tmp[21];						//�˻��� �ӽ� ID ����
	printf("ã���� ID�� �Է��ϼ���.");
	scanf("%s", tmp);

	for (int i = 0; i < cus_cnt; i++)	//ȸ�� �����ü�� �˻��Ͽ�
	{
		if (!(strcmp(tmp, cus[i]->id)))	//ȸ�����̵�� ��ġ�ϸ�
		{
			Show_Cus(i);				//����ϰ� return
			return;
		}
	}
	printf("�� ��ܿ� �����ϴ�.\n");	//�˻����� ������ ������ message
}
/*
ISBN�� �Է¹޾� DVD ������ ����ϱ� ���� �Լ�
��ȯ��:void/ �Ű�����: void
�Լ� ����: void Search_Dvd();
*/
void Search_Dvd()							//DVD �˻�(ISBN�̿�)
{
	char tmp[20];
	printf("ã���� DVD��ISBN�� �Է��ϼ���.");
	scanf("%s", tmp);

	for (int i = 0; i < dvd_cnt; i++)		//DVD����ü ��ü �˻�
	{
		if (!(strcmp(tmp, dvd[i]->isbn)))	//ISBN�� �˻��Ͽ� DVD��Ͽ� ������
		{
			Show_Dvd(i);					//�װ��� ����ϰ� return
			return;
		}
	}
	printf("DVD ��Ͽ� �����ϴ�.\n");		//��ܿ� ������ �Ʒ� �޽��� ���
}