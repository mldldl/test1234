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
����(.txt)�� ȸ�������� �����ϴ� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void save_Cus_data();
*/
void save_Cus_data()
{
	fopen_s(&Cus_fp, "Cus_data.txt", "w+");		//ȸ������ ������ ���� Cus_data.txt������ ������� ����

	for (int i = 0; i < cus_cnt; i++)
	{											//ȸ�������� Cus_data.txt���Ͽ� ����
		fprintf(Cus_fp, "%s %s %s\n", cus[i]->id, cus[i]->name, cus[i]->num);
		free(cus[i]);							//�����Ҵ� ��ȯ
	}
	fclose(Cus_fp);								//������ ���� �� �޽������ �� ����
	printf("%d���� �������� �����Ͽ����ϴ�.\n",cus_cnt);
}
/*
����(.txt)�� DVD������ �����ϴ� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void save_Dvd_data();
*/
void save_Dvd_data()
{
	fopen_s(&Dvd_fp, "Dvd_data.txt", "w+");		//DVD���� ������ ���� Dvd_data.txt������ ������� ����

	for (int i = 0; i < dvd_cnt; i++)
	{											//DVD ������ Dvd_data.txt���Ͽ� ����
		fprintf(Dvd_fp, "%s %d %d %s\n", dvd[i]->isbn, dvd[i]->genre, dvd[i]->en, dvd[i]->title);
		free(dvd[i]);							//�����Ҵ� ��ȯ
	}
	fclose(Dvd_fp);								//������ ���� �� �޽������ �� ����
	printf("%d���� DVD������ �����Ͽ����ϴ�.\n",dvd_cnt);
}
/*
����(.txt)�� �̷������� �����ϴ� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void save_Rent_data();
*/
void save_Rent_data()
{
	fopen_s(&Rent_fp, "Rent_data.txt", "w+");	//�̷����� ������ ���� Rent_data.txt������ ������� ����

	for (int i = 0; i < rent_cnt; i++)
	{											//�̷� ������ Rent_data.txt���Ͽ� ����
		fprintf(Rent_fp, "%s %d %d\n", rent[i]->date, rent[i]->index_cus, rent[i]->index_dvd);
		free(rent[i]);							//�����Ҵ� ��ȯ
	}
	fclose(Rent_fp);							//������ ���� �� �޽������ �� ����
	printf("%d���� �̷������� �����Ͽ����ϴ�.\n",rent_cnt);
}