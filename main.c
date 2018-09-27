//������ : ������
/*//////////////////////////////////////////////////////////
DVD �뿩 ���� ���α׷�
Ver. 1.0
C��� ǥ��
Creator Lee
Remake 2018-05-21
//////////////////////////////////////////////////////////*/
#include "std_header.h"
#include "my_header.h"
#include "my_struct.h"

FILE *Cus_fp;			//ȸ�� ���� ���� ������
FILE *Dvd_fp;			//DVD ���� ���� ������
FILE *Rent_fp;			//�̷� ���� ���� ������

Customer *cus[CUS_MAX];	//ȸ�������� ������ ����ü �迭
Dvd *dvd[DVD_MAX];		//DVD������ ������ ����ü �迭
Rent *rent[RENT_MAX];	//�̷��� ������ ����ü �迭

int cus_cnt;			//ȸ�� ī����
int dvd_cnt;			//DVD ī����
int rent_cnt;			//�̷� ī����

int main(void)
{
	short int ss = 0;
	open_Cus_data();
	open_Dvd_data();
	open_Rent_data();
	while (1)				//���α׷� ����
	{
		Show_Menu();		//�޴� ���
		printf("����>> �����ϼ��� : ");
		scanf("%d", &ss);	//���ù�

		switch (ss) {		//Switch������ ��� ����

		case NEWCUS:		//�ű� ȸ�����
			Input_Cus();
			break;
		case SEARCHCUS:		//ȸ�� �˻�
			Search_Cus();
			break;
		case NEWDVD:		//DVD ���
			Input_Dvd();
			break;
		case DVDSEARCH:		//DVD �˻�
			Search_Dvd();
			break;
		case DVDRENT:		//DVD ����
			Dvd_Rent();
			break;
		case DVDRETURN:		//DVD �ݳ�
			Dvd_Return();
			break;
		case DVDSTAT:		//DVD �̷�
			Dvd_Stat();
			break;
		case CUSDVD:		//ȸ�� DVD �̷�
			Cus_Dvd();
			break;
		case EXIT:			//���α׷� ����
			save_Cus_data();
			save_Dvd_data();
			save_Rent_data();
			system("pause");
			exit(1);
		}
	}
	return 0;
}