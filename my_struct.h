//������ : ������
/*
��� ����ü ����
*/
#ifndef _my_struct_h_
#define _my_struct_h_
/*
����ü Customer ����
�ɹ�
ID : id
�̸� : name
��ȭ��ȣ : num
*/
typedef struct {
	char id[21];		//ȸ�� ID
	char name[20];		//ȸ�� �̸�
	char num[14];		//ȸ�� ��ȭ��ȣ xxx-xxxx-xxxx\0 < 14�ڸ�
}Customer;
/*
����ü Dvd ����
�ɹ�
���� : title
ISBN : isbn
�帣 : genre
�뿩���� : en
*/
typedef struct {
	char title[30];		//����
	char isbn[20];		//ISBN
	short int genre;	//�帣
	short int en;		//�뿩���� ����
}Dvd;
/*
����ü Rent ����
�ɹ�
��¥ : date
����ȣ : index_cus
DVD��ȣ : index_dvd
*/
typedef struct {
	char date[6];		//xx.xx\0 < 6�ڸ�
	int index_cus;		//ȸ�� index
	int index_dvd;		//DVD index
}Rent;

#endif // !_my_struct_h_
