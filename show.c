//제작자 : 이제우
/*
정보 출력 함수 모음
*/
#include "std_header.h"
#include "my_struct.h"
#include "my_header.h"

extern Customer *cus[CUS_MAX];		//회원정보를 저장할 구조체 배열
extern Dvd *dvd[DVD_MAX];			//DVD정보를 저장할 구조체 배열
/*
회원 정보를 출력하기 위한 함수
반환형 : void / 매개변수 : int i(회원 index)
함수 원형 void Show_Cus(int i);
*/
void Show_Cus(int i)				//회원 출력
{
	printf("고객 ID : %s\n", cus[i]->id);
	printf("고객 이름 : %s\n", cus[i]->name);
	printf("고객 전화번호 : %s\n", cus[i]->num);
}
/*
DVD상태를 출력하기 위한 함수 매개변수로 DVD의 index를 입력한다.
반환형:void/ 매개변수:int i(Dvd Index)
함수 원형: void Show_Dvd();
*/
void Show_Dvd(int i)				//DVD 출력
{
	printf("DVD ISBN : %s\n", dvd[i]->isbn);
	printf("DVD 제목 : %s\n", dvd[i]->title);
	switch (dvd[i]->genre) {		//장르에 따른 출력switch
	case ACTION: printf("장르 : 액션\n"); break;
	case COMIC: printf("장르 : 코믹\n"); break;
	case SF: printf("장르 : SF\n"); break;
	case ROMANTIC: printf("장르 : 로맨틱\n"); break;
	}
	if (dvd[i]->en == 1)			//대여 가능여부 출력
		printf("대여중입니다.\n");
	else
		printf("대여가능합니다.\n");
}
/*
메뉴 출력을 위한 함수
반환형:void/ 매개변수:void
함수 원형: void Show_Menu();
*/
void Show_Menu()				//메뉴 출력
{
	printf("-----------------메뉴---------------\n");
	printf("|    1. 신규회원가입               |\n");
	printf("|    2. 회원검색                   |\n");
	printf("|    3. DVD등록                    |\n");
	printf("|    4. DVD검색                    |\n");
	printf("|    5. DVD대여                    |\n");
	printf("|    6. DVD반납                    |\n");
	printf("|    7. DVD 대여 이력 조회         |\n");
	printf("|    8. 회원의 DVD 대여 이력 조회  |\n");
	printf("|    9. 종료                       |\n");
	printf("------------------------------------\n");
}