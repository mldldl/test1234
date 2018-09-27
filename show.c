//������ : ������
/*
���� ��� �Լ� ����
*/
#include "std_header.h"
#include "my_struct.h"
#include "my_header.h"

extern Customer *cus[CUS_MAX];		//ȸ�������� ������ ����ü �迭
extern Dvd *dvd[DVD_MAX];			//DVD������ ������ ����ü �迭
/*
ȸ�� ������ ����ϱ� ���� �Լ�
��ȯ�� : void / �Ű����� : int i(ȸ�� index)
�Լ� ���� void Show_Cus(int i);
*/
void Show_Cus(int i)				//ȸ�� ���
{
	printf("�� ID : %s\n", cus[i]->id);
	printf("�� �̸� : %s\n", cus[i]->name);
	printf("�� ��ȭ��ȣ : %s\n", cus[i]->num);
}
/*
DVD���¸� ����ϱ� ���� �Լ� �Ű������� DVD�� index�� �Է��Ѵ�.
��ȯ��:void/ �Ű�����:int i(Dvd Index)
�Լ� ����: void Show_Dvd();
*/
void Show_Dvd(int i)				//DVD ���
{
	printf("DVD ISBN : %s\n", dvd[i]->isbn);
	printf("DVD ���� : %s\n", dvd[i]->title);
	switch (dvd[i]->genre) {		//�帣�� ���� ���switch
	case ACTION: printf("�帣 : �׼�\n"); break;
	case COMIC: printf("�帣 : �ڹ�\n"); break;
	case SF: printf("�帣 : SF\n"); break;
	case ROMANTIC: printf("�帣 : �θ�ƽ\n"); break;
	}
	if (dvd[i]->en == 1)			//�뿩 ���ɿ��� ���
		printf("�뿩���Դϴ�.\n");
	else
		printf("�뿩�����մϴ�.\n");
}
/*
�޴� ����� ���� �Լ�
��ȯ��:void/ �Ű�����:void
�Լ� ����: void Show_Menu();
*/
void Show_Menu()				//�޴� ���
{
	printf("-----------------�޴�---------------\n");
	printf("|    1. �ű�ȸ������               |\n");
	printf("|    2. ȸ���˻�                   |\n");
	printf("|    3. DVD���                    |\n");
	printf("|    4. DVD�˻�                    |\n");
	printf("|    5. DVD�뿩                    |\n");
	printf("|    6. DVD�ݳ�                    |\n");
	printf("|    7. DVD �뿩 �̷� ��ȸ         |\n");
	printf("|    8. ȸ���� DVD �뿩 �̷� ��ȸ  |\n");
	printf("|    9. ����                       |\n");
	printf("------------------------------------\n");
}