//제작자 : 이제우
/*
검색을 위한 함수 모음
*/
#include "std_header.h"
#include "my_struct.h"
#include "my_header.h"

extern Customer *cus[CUS_MAX];	//회원정보를 저장할 구조체 배열
extern Dvd *dvd[DVD_MAX];		//DVD정보를 저장할 구조체 배열

extern int cus_cnt;				//회원 카운터
extern int dvd_cnt;				//DVD 카운터

/*
ID를 입력받아 회원을 검색하기 위한 함수
반환형:void/ 매개변수:void
함수 원형: void Search_Cus();
*/
void Search_Cus()						//회원 검색(ID이용)
{
	char tmp[21];						//검색용 임시 ID 저장
	printf("찾으실 ID를 입력하세요.");
	scanf("%s", tmp);

	for (int i = 0; i < cus_cnt; i++)	//회원 목록전체를 검색하여
	{
		if (!(strcmp(tmp, cus[i]->id)))	//회원아이디와 일치하면
		{
			Show_Cus(i);				//출력하고 return
			return;
		}
	}
	printf("고객 명단에 없습니다.\n");	//검색되지 않으면 나오는 message
}
/*
ISBN을 입력받아 DVD 정보를 출력하기 위한 함수
반환형:void/ 매개변수: void
함수 원형: void Search_Dvd();
*/
void Search_Dvd()							//DVD 검색(ISBN이용)
{
	char tmp[20];
	printf("찾으실 DVD의ISBN을 입력하세요.");
	scanf("%s", tmp);

	for (int i = 0; i < dvd_cnt; i++)		//DVD구조체 전체 검색
	{
		if (!(strcmp(tmp, dvd[i]->isbn)))	//ISBN을 검색하여 DVD목록에 있으면
		{
			Show_Dvd(i);					//그것을 출력하고 return
			return;
		}
	}
	printf("DVD 목록에 없습니다.\n");		//명단에 없으면 아래 메시지 출력
}