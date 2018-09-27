//������ : ������
/*
���� ������ ���� �Լ�����
*/
#include "std_header.h"
#include "my_struct.h"
#include "my_header.h"

extern FILE *Cus_fp;			//ȸ�� ���� ���� ������
extern FILE *Dvd_fp;			//DVD ���� ���� ������
extern FILE *Rent_fp;			//�̷� ���� ���� ������

extern Customer *cus[CUS_MAX];	//ȸ�������� ������ ����ü �迭
extern Dvd *dvd[DVD_MAX];		//DVD������ ������ ����ü �迭
extern Rent *rent[RENT_MAX];	//�̷��� ������ ����ü �迭

extern int cus_cnt;				//ȸ�� ī����
extern int dvd_cnt;				//DVD ī����
extern int rent_cnt;			//�̷� ī����

/*
����(.txt)���� ȸ�������� �о���� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void open_Cus_data();
*/
void open_Cus_data()
{
	int res;										//������ ���� �Ǵ��� ����
	fopen_s(&Cus_fp, "Cus_data.txt", "r+");			//Cus_data.txt ���� �б���� ����

	if (Cus_fp == NULL)								//������ �������� ������
	{
		fopen_s(&Cus_fp, "Cus_data.txt", "w+");		//������ ������ �� ���� �� ����
		printf("ȸ�� ���������� ��� �����Ͽ����ϴ�.\n");
		fclose(Cus_fp);
		return;
	}

	while (1)
	{
		cus[cus_cnt] = (Customer*)malloc(sizeof(Customer));	//ȸ�������� ������ ����ü �����Ҵ�
		res = fscanf_s(Cus_fp, "%s %s %s", cus[cus_cnt]->id, sizeof(cus[cus_cnt]->id), cus[cus_cnt]->name
			, sizeof(cus[cus_cnt]->name), cus[cus_cnt]->num, sizeof(cus[cus_cnt]->num));   //���Ͽ��� ������ �о�´�
		if (res == EOF)								//������ ���ΰ��
		{
			break;									//�ݺ�����
		}
		cus_cnt++;									//�� ī��Ʈ ����
	}
	printf("%d���� ������ �о�Խ��ϴ�.\n", cus_cnt);
	fclose(Cus_fp);									//���� ����
}
/*
����(.txt)���� DVD������ �о���� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void open_dvd_data();
*/
void open_Dvd_data()
{
	int res;										//������ ���� �Ǵ��� ����
	fopen_s(&Dvd_fp, "Dvd_data.txt", "r+");			//Dvd_data.txt ���� �б���� ����

	if (Dvd_fp == NULL)								//������ �������� ������
	{
		fopen_s(&Dvd_fp, "Dvd_data.txt", "w+");		//������ ������ �� ���� �� ����
		printf("DVD ���������� ��� �����Ͽ����ϴ�.\n");
		fclose(Dvd_fp);
		return;
	}

	while (1)
	{
		Dvd *tmp = (Dvd*)malloc(sizeof(Dvd));		//�ӽ� ���� ����ü

		res = fscanf_s(Dvd_fp, "%s %hd %hd", tmp->isbn, sizeof(tmp->isbn), &(tmp->genre), &(tmp->en));
		//%hd�� �޴����� = ������ short int�� �߱⶧���� hd�� �޾ƾ� �����Ҵ� ��ȯ�� �� ������ ������ �ʴ´�.
		if (res == EOF)	
		{
			break;									//������ ���̸� �ݺ�������
		}
		fgetc(Dvd_fp);								//�Է¹��� ����(���� ����)
		fgets(tmp->title, sizeof(tmp->title), Dvd_fp);	//���� �Է¹���
		tmp->title[strlen(tmp->title) - 1] = '\0';	//fgets�� ���� ���๮�� ���Ÿ� ����
		dvd[dvd_cnt] = tmp;							//dvd����ü�� �ӽñ���ü ����
		dvd_cnt++;									//dvdī���� ����
	}
	printf("%d���� DVD������ �о�Խ��ϴ�.\n", dvd_cnt);
	fclose(Dvd_fp);									//���� ����
}
/*
����(.txt)���� �̷������� �о���� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void open_Rent_data();
*/
void open_Rent_data()
{
	int res;										//������ ���� �Ǵ��� ����
	fopen_s(&Rent_fp, "Rent_data.txt", "r+");		//Rent_data.txt������ �б���� ����

	if (Rent_fp == NULL)							//������ �������� ������
	{
		fopen_s(&Rent_fp, "Rent_data.txt", "w+");	//������ ������ �� ���� �� ����
		printf("�̷� ���������� ��� �����Ͽ����ϴ�.\n");
		fclose(Rent_fp);
		return;
	}

	while (1)
	{
		rent[rent_cnt] = (Rent*)malloc(sizeof(Rent));
		res = fscanf_s(Cus_fp, "%s %d %d", rent[rent_cnt]->date, sizeof(rent[rent_cnt]->date), &rent[rent_cnt]->index_cus, &rent[rent_cnt]->index_dvd);
		if (res == EOF)
		{
			break;
		}
		rent_cnt++;
	}
	printf("%d���� �̷������� �о�Խ��ϴ�.\n", rent_cnt);
	fclose(Rent_fp);
}