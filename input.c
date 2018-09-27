//������ : ������
/*
��,DVD ������ �Է��ϴ� �Լ�����
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
�ű�ȸ�� ����� ���� �Լ�
ID/�̸�/��ȭ��ȣ ���� �Է¹޾� Cus����ü�� �����Ѵ�.
��ȯ��:void/ �Ű�����:void
�Լ� ����: void Input_Cus();
*/
void Input_Cus()
{
	Customer *tmp = (Customer*)malloc(sizeof(Customer));	//�ӽ� ȸ�� ����ü
	int flag = 1;											//�ߺ� IDȮ���� ���� flag
	printf("%d�� �Է°���\n", CUS_MAX - cus_cnt);

	while (flag != 0) {
		flag = 0;
		printf("ID �Է�:");
		scanf("%s", tmp->id);
		for (int i = 0; i < cus_cnt; i++)
			if (!(strcmp(tmp->id, cus[i]->id))) {			//ID �ߺ��� ���
				printf("�ߺ� ID�Դϴ�. �ٸ�ID�� �Է����ּ���.\n");
				flag = 1;
				break;
			}
		if (flag == 1) continue;							//ID�ߺ��� ��� ID ���Է¹���

		printf("�̸� �Է�:");								//�ߺ��� �ƴҰ�� ���� �Է�
		scanf("%s", tmp->name);
		printf("��ȭ��ȣ �Է�:");
		scanf("%s", tmp->num);

		cus[cus_cnt] = tmp;									//�ӽñ���ü�� cus����ü�� ����
		cus_cnt++;
		printf("��ϵǾ����ϴ�.\n");						//��� �Ϸ�޽��� ���
	}
}
/*
DVD ����� ���� �Լ�
ISBN/����/�帣 ���� �Է¹޾� Dvd����ü�� �����Ѵ�.
��ȯ��:void/ �Ű�����:void
�Լ� ����: void Input_Dvd();
*/
void Input_Dvd()
{
	Dvd *tmp = (Dvd*)malloc(sizeof(Dvd));				//�ӽ� ���� ����ü
	int flag = 1;										//�ߺ� ISBNȮ�� flag
	printf("%d�� �Է°���\n", DVD_MAX - dvd_cnt);

	while (flag != 0) {
		flag = 0;
		printf("ISBN �Է�:");
		scanf("%s", tmp->isbn);

		for (int i = 0; i < dvd_cnt; i++)
			if (!(strcmp(tmp->isbn, dvd[i]->isbn))) {
				printf("�ߺ� ISBN�Դϴ�. �ٸ�ISBN�� �Է����ּ���.\n");
				flag = 1;
				break;
			}
		if (flag == 1) continue;						//�ߺ� ISBN�ִ°�� ���Է� �ޱ����� ���ǹ�

		printf("���� �Է�:");
		fgetc(stdin);									//���๮�� ���� ����(�Է¹��� ����)
		fgets(tmp->title, sizeof(tmp->title), stdin);	//������ ��� ���Ⱑ �����Ƿ� fgets �Լ��� ���� ����
		tmp->title[strlen(tmp->title) - 1] = '\0';		//fgets�� ���� ���๮�� ���Ÿ� ����

		printf("�帣(�׼�:1, �ڹ�:2, SF:3, �θ�ƽ:4) :");
		scanf("%hd", &(tmp->genre));					//short int �̹Ƿ� ud�� �޴°� ����

		tmp->en = 0;
		dvd[dvd_cnt] = tmp;								//�ӽñ���ü�� dvd�� ����
		dvd_cnt++;
		printf("��ϵǾ����ϴ�.\n");					//��� �Ϸ�޽��� ���
	}
}