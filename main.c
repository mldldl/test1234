//제작자 : 이제우
/*//////////////////////////////////////////////////////////
DVD 대여 관리 프로그램
Ver. 1.0
C언어 표준
Creator Lee
Remake 2018-05-21
//////////////////////////////////////////////////////////*/
#include "std_header.h"
#include "my_header.h"
#include "my_struct.h"

FILE *Cus_fp;			//회원 정보 파일 포인터
FILE *Dvd_fp;			//DVD 정보 파일 포인터
FILE *Rent_fp;			//이력 정보 파일 포인터

Customer *cus[CUS_MAX];	//회원정보를 저장할 구조체 배열
Dvd *dvd[DVD_MAX];		//DVD정보를 저장할 구조체 배열
Rent *rent[RENT_MAX];	//이력을 저장할 구조체 배열

int cus_cnt;			//회원 카운터
int dvd_cnt;			//DVD 카운터
int rent_cnt;			//이력 카운터

int main(void)
{
	short int ss = 0;
	open_Cus_data();
	open_Dvd_data();
	open_Rent_data();
	while (1)				//프로그램 시작
	{
		Show_Menu();		//메뉴 출력
		printf("선택>> 선택하세요 : ");
		scanf("%d", &ss);	//선택문

		switch (ss) {		//Switch문으로 기능 선택

		case NEWCUS:		//신규 회원등록
			Input_Cus();
			break;
		case SEARCHCUS:		//회원 검색
			Search_Cus();
			break;
		case NEWDVD:		//DVD 등록
			Input_Dvd();
			break;
		case DVDSEARCH:		//DVD 검색
			Search_Dvd();
			break;
		case DVDRENT:		//DVD 빌림
			Dvd_Rent();
			break;
		case DVDRETURN:		//DVD 반납
			Dvd_Return();
			break;
		case DVDSTAT:		//DVD 이력
			Dvd_Stat();
			break;
		case CUSDVD:		//회원 DVD 이력
			Cus_Dvd();
			break;
		case EXIT:			//프로그램 종료
			save_Cus_data();
			save_Dvd_data();
			save_Rent_data();
			system("pause");
			exit(1);
		}
	}
	return 0;
}