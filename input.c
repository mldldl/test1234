//제작자 : 이제우
/*
고객,DVD 정보를 입력하는 함수모음
*/
#include "std_header.h"
#include "my_struct.h"
#include "my_header.h"

extern Customer *cus[CUS_MAX];	//회원정보를 저장할 구조체 배열
extern Dvd *dvd[DVD_MAX];		//DVD정보를 저장할 구조체 배열
extern Rent *rent[RENT_MAX];	//이력을 저장할 구조체 배열

extern int cus_cnt;				//회원 카운터
extern int dvd_cnt;				//DVD 카운터
extern int rent_cnt;			//이력 카운터

/*
신규회원 등록을 위한 함수
ID/이름/전화번호 등을 입력받아 Cus구조체에 저장한다.
반환형:void/ 매개변수:void
함수 원형: void Input_Cus();
*/
void Input_Cus()
{
	Customer *tmp = (Customer*)malloc(sizeof(Customer));	//임시 회원 구조체
	int flag = 1;											//중복 ID확인을 위한 flag
	printf("%d명 입력가능\n", CUS_MAX - cus_cnt);

	while (flag != 0) {
		flag = 0;
		printf("ID 입력:");
		scanf("%s", tmp->id);
		for (int i = 0; i < cus_cnt; i++)
			if (!(strcmp(tmp->id, cus[i]->id))) {			//ID 중복일 경우
				printf("중복 ID입니다. 다른ID를 입력해주세요.\n");
				flag = 1;
				break;
			}
		if (flag == 1) continue;							//ID중복일 경우 ID 재입력받음

		printf("이름 입력:");								//중복이 아닐경우 정보 입력
		scanf("%s", tmp->name);
		printf("전화번호 입력:");
		scanf("%s", tmp->num);

		cus[cus_cnt] = tmp;									//임시구조체를 cus구조체에 저장
		cus_cnt++;
		printf("등록되었습니다.\n");						//등록 완료메시지 출력
	}
}
/*
DVD 등록을 위한 함수
ISBN/제목/장르 등을 입력받아 Dvd구조체에 저장한다.
반환형:void/ 매개변수:void
함수 원형: void Input_Dvd();
*/
void Input_Dvd()
{
	Dvd *tmp = (Dvd*)malloc(sizeof(Dvd));				//임시 저장 구조체
	int flag = 1;										//중복 ISBN확인 flag
	printf("%d개 입력가능\n", DVD_MAX - dvd_cnt);

	while (flag != 0) {
		flag = 0;
		printf("ISBN 입력:");
		scanf("%s", tmp->isbn);

		for (int i = 0; i < dvd_cnt; i++)
			if (!(strcmp(tmp->isbn, dvd[i]->isbn))) {
				printf("중복 ISBN입니다. 다른ISBN를 입력해주세요.\n");
				flag = 1;
				break;
			}
		if (flag == 1) continue;						//중복 ISBN있는경우 재입력 받기위한 조건문

		printf("제목 입력:");
		fgetc(stdin);									//개행문자 제거 위함(입력버퍼 비우기)
		fgets(tmp->title, sizeof(tmp->title), stdin);	//제목의 경우 띄어쓰기가 있으므로 fgets 함수를 통해 받음
		tmp->title[strlen(tmp->title) - 1] = '\0';		//fgets로 받은 개행문자 제거를 위함

		printf("장르(액션:1, 코믹:2, SF:3, 로맨틱:4) :");
		scanf("%hd", &(tmp->genre));					//short int 이므로 ud로 받는게 안전

		tmp->en = 0;
		dvd[dvd_cnt] = tmp;								//임시구조체를 dvd에 저장
		dvd_cnt++;
		printf("등록되었습니다.\n");					//등록 완료메시지 출력
	}
}