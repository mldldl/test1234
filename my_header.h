//������ : ������
/*
��� �Լ� �� ������ ����
*/
#ifndef _my_header_h_
#define _my_header_h_

#define CUS_MAX 100				//ȸ�� �ִ� ����
#define DVD_MAX 100				//DVD �ִ� ����
#define RENT_MAX 1000			//�̷� �ִ� ����

enum { NEWCUS = 1, SEARCHCUS, NEWDVD, DVDSEARCH, DVDRENT, DVDRETURN, DVDSTAT, CUSDVD, EXIT };	//main ���ù�
enum { ACTION = 1, COMIC, SF, ROMANTIC };														//�帣 ����

/*���� �Է� �Լ�*/
void Input_Cus();		//�ű�ȸ������
void Input_Dvd();		//DVD���

/*���� �˻� �Լ�*/
void Search_Cus();		//ȸ�� �˻�(ID �̿�)
void Search_Dvd();		//DVD�˻�(ISBN �̿�)

/*DVD���� ���� �Լ�*/
void Dvd_Rent();		//DVD �뿩
void Dvd_Return();		//DVD �ݳ�
void Dvd_Stat();		//DVD �뿩 �̷� ��ȸ
void Cus_Dvd();			//ȸ���� DVD �뿩 �̷� ��ȸ

/*���� ��� �Լ�*/
void Show_Cus(int i);	//ȸ�� ���
void Show_Dvd(int i);	//DVD ���
void Show_Menu();		//�޴� ���

/*���� ���� �Լ�*/
void save_Cus_data();	//ȸ������ ��������
void save_Dvd_data();	//DVD���� ��������
void save_Rent_data();	//�̷����� ��������

/*���� ���� �Լ�*/
void open_Cus_data();	//���Ͽ��� ȸ������ �ε�
void open_Dvd_data();	//���Ͽ��� DVD���� �ε�
void open_Rent_data();	//���Ͽ��� �̷����� �ε�

#endif // !_my_header_h_
