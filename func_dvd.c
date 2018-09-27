//������ : ������
/*
DVD ���������� �Լ�����
*/
#include "std_header.h"
#include "my_struct.h"
#include "my_header.h"

extern Customer *cus[CUS_MAX];	//ȸ�������� ������ ����ü �迭
extern Dvd *dvd[DVD_MAX];		//DVD������ ������ ����ü �迭
extern Rent *rent[RENT_MAX];	//�̷��� ������ ����ü �迭

extern int cus_cnt;				//ȸ�� ī����
extern int dvd_cnt;				//DVD ī����
extern int rent_cnt;			//�̷� ī����

/*
ȸ�� ID�� DVD ISBN�� �Է¹޾� DVD�� �뿩�ϱ� ���� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void Dvd_Rent();
*/
void Dvd_Rent()									//DVD �뿩
{
	char tmp_id[20];							//�뿩�� ID
	char tmp_isbn[20];							//�뿩�� ISBN
	Rent *tmp = (Rent*)malloc(sizeof(Rent));	//�뿩 �̷��� ������ �ӽ� Rent

	printf("�뿩�Ͻ� DVD�� ISBN�� �Է��ϼ���.");
	scanf("%s", tmp_isbn);

	for (int i = 0; i < dvd_cnt; i++)			//DVD ��ü�� �˻�
	{
		if (!(strcmp(tmp_isbn, dvd[i]->isbn))) {//ISBN�� �����ϴ��� �˻�
			printf("�뿩�� �����մϴ�. �뿩������ �����մϴ�.\n");
			printf("ȸ�� ID�� �Է��ϼ���.");	//�뿩������ ��������� �� ID �Է¹���
			scanf("%s", tmp_id);
			for (int j = 0; j < cus_cnt; j++)	//ȸ�� ��ü�� �˻��Ͽ� ȸ���� �ִ��� ����
			{
				if (!(strcmp(tmp_id, cus[j]->id))) {//ȸ���� ������ ��� �뿩���� ��� ����
					tmp->index_cus = j;			//rent�� �� index ����
					tmp->index_dvd = i;			//rent�� DVD index ����
					printf("�뿩 ��¥�� �Է��ϼ���.(��,���� ���� �� �ڸ��� �Է��Ͻÿ�(��.��))");
					scanf("%s", tmp->date);		//�뿩 ��¥ �Է¹���

					if ((dvd[i]->en) == 0) {	//DVD�� �뿩�������� �Ǵ�
						printf("�뿩�� �Ϸ�Ǿ����ϴ�.\n");
						dvd[i]->en = 1;			//�����ϸ� �뿩 ����
						rent[rent_cnt] = tmp;
						rent_cnt++;
						return;
					}
					else {						//�������� ������ ���̻� ���������ʰ�
						printf("�뿩���̶� �뿩�� �Ұ����մϴ�.\n");//�޽��� ����� return
						free(tmp);
						return;
					}
				}
			}
			printf("ȸ�����Ը� �뿩 �����մϴ�.\n");	//ȸ���� �ƴϸ� �Ʒ��޽��� ����� return
			free(tmp);
			return;
		}
	}
	printf("ISBN�� �����ϴ�.\n");				//DVD��Ͽ��� �˻��� ���� ������ �޽��� ���
	free(tmp);
}
/*
ISBN�� �Է¹޾� DVD �ݳ��� ���� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void DVD_Return();
*/
void Dvd_Return()				//DVD �ݳ�
{
	char tmp[20];								//�ݳ��� ISBN�� ������ tmp
	printf("�ݳ��� ISBN�� �Է��ϼ���.");
	scanf("%s", tmp);

	for (int i = 0; i < dvd_cnt; i++)			//DVD��� ��ü�� �˻�
	{
		if (!strcmp(dvd[i]->isbn, tmp))			//����� DVD���� ��ġ�ϴ� ISBN�� ã�� ��
		{
			if (dvd[i]->en == 1) {				//en�� 1�̸� ���ȴ� ���̹Ƿ� �ݳ� ������ return
				dvd[i]->en = 0;
				printf("�ݳ��Ǿ����ϴ�.\n");
				return;
			}
			else {								//en�� 0�̸� �뿩���� �������̹Ƿ� �Ʒ� �޽��� ����� return
				printf("�뿩���� ���� DVD�Դϴ�.\n");
				return;
			}
		}
	}
	printf("��ϵ��� ���� ISBN�Դϴ�.\n");		//DVD��Ͽ� ������ �� �޽����� ��µǰ� �Լ� ����
}
/*
ISBN�� �Է¹޾� DVD rent�̷��� ����ϴ� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void Dvd_Stat();
*/
void Dvd_Stat()							//DVD �̷�
{
	char tmp[20];						//�˻��� ISBN�� ����� tmp
	char flag = 0;						//�̷� ���� ������ Ȯ���� flag
	printf("�˻��� ISBN�� �Է��Ͻÿ�.");
	scanf("%s", tmp);

	for (int i = 0; i < rent_cnt; i++)	//�̷� ��ü�� �˻��Ͽ�
	{
		if (!strcmp(tmp, dvd[rent[i]->index_dvd]->isbn)) //��ġ�ϴ� ISBN�� �����ϸ�
		{
			printf("�뿩�� : %s\n", rent[i]->date);		//�׿� ���� �������� ���
			Show_Cus(rent[i]->index_cus);
			printf("\n");
			flag = 1;									//�÷��� �����Ͽ� �̷��� �ִٴ°��� �˸�
		}
	}

	if (flag == 0) printf("�̷��� �������� �ʽ��ϴ�.\n");//�÷���==0 -> �̷��� �����Ƿ� �� �޽��� ����� �Լ� ����
}
/*
�� ID�� �Ⱓ�� �Է¹޾� DVD rent �̷��� ����ϴ� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void Cus_Dvd();
*/
void Cus_Dvd()							//�뿩 DVD ��ü ��ȸ(��¥ �Է����� ��ȸ)

{
	char tmp_id[21];					//ȸ�� ID�˻��� ���� �ӽ� tmp_id
	char tmp_date_s[6];					//��¥ �˻��� ���� ������ ���� tmp_date_s
	char tmp_date_f[6];					//��¥ �˻��� ���� ������ ���� tmp_date_f
	char flag = 0;						//�˻� ���������� �Ǵ��� flag
	int index;							//ȸ�� index����
	printf("�� ID�� �Է��ϼ���.");
	scanf("%s", tmp_id);

	for (int i = 0; i < cus_cnt; i++)
	{
		if (!strcmp(tmp_id, cus[i]->id))
		{
			flag = 1;					//ȸ�� �˻��� �����ϸ� flag=1 ���н� 0
			index = i;					//index�� ���� index ����
			break;						//�˻��Ϸ������Ƿ� �ݺ����� �������´�.
		}
	}
	if (flag == 0) {					//ȸ�� �˻��� �ȉ����Ƿ� �Ʒ� �޽��� ����� return
		printf("ID�� �������� �ʽ��ϴ�.\n");
		return;
	}
	//�� �������� flag�� ������ �����
	//flag = 0�̸� �˻� ����(�̷� ����)  flag=1 �̸� �˻�����(�̷� ����)
	printf("��ȸ ���۳�¥�� �Է��ϼ���.(xx��.xx��)");
	scanf("%s", tmp_date_s);
	printf("��ȸ ��������¥�� �Է��ϼ���.(xx��.xx��)");
	scanf("%s", tmp_date_f);

	for (int i = 0; i < rent_cnt; i++)	//�̷� ��ü�� �˻�
	{
		if (index == rent[i]->index_cus)//�̷��� ȸ���� �����ϸ� �������� �˻�
		{
			if (strcmp(tmp_date_s, rent[i]->date) <= 0 && strcmp(tmp_date_f, rent[i]->date) >= 0)
			{							//�Է¹��� �������� ���� �̷��� ������ ���
				printf("���� DVD�� ISBN : %s\n", dvd[rent[i]->index_dvd]->isbn);
				printf("�뿩�� : %s\n", rent[i]->date);
				flag = 0;				//�̷��� �����Ƿ� 1->0���� toggle
			}
		}
	}
	if (flag == 1)						//flag�� 1�̹Ƿ� �̷��� �����Ƿ� �Ʒ� �޽����� ��� �Լ� ����
		printf("�̷��� �������� �ʽ��ϴ�.\n");
}
