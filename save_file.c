//제작자 : 이제우
/*
파일 저장을 위한 함수모음
*/
#include "std_header.h"
#include "my_struct.h"
#include "my_header.h"

extern FILE *Cus_fp;			//회원 정보 파일 포인터
extern FILE *Dvd_fp;			//DVD 정보 파일 포인터
extern FILE *Rent_fp;			//이력 정보 파일 포인터

extern Customer *cus[CUS_MAX];	//회원정보를 저장할 구조체 배열
extern Dvd *dvd[DVD_MAX];		//DVD정보를 저장할 구조체 배열
extern Rent *rent[RENT_MAX];	//이력을 저장할 구조체 배열

extern int cus_cnt;				//회원 카운터
extern int dvd_cnt;				//DVD 카운터
extern int rent_cnt;			//이력 카운터

/*
파일(.txt)에 회원정보를 저장하는 함수
반환형:void/ 매개변수:void
함수 원형: void save_Cus_data();
*/
void save_Cus_data()
{
	fopen_s(&Cus_fp, "Cus_data.txt", "w+");		//회원정보 저장을 위해 Cus_data.txt파일을 쓰기모드로 열기

	for (int i = 0; i < cus_cnt; i++)
	{											//회원정보를 Cus_data.txt파일에 저장
		fprintf(Cus_fp, "%s %s %s\n", cus[i]->id, cus[i]->name, cus[i]->num);
		free(cus[i]);							//동적할당 반환
	}
	fclose(Cus_fp);								//파일을 닫은 뒤 메시지출력 후 종료
	printf("%d명의 고객정보를 저장하였습니다.\n",cus_cnt);
}
/*
파일(.txt)에 DVD정보를 저장하는 함수
반환형:void/ 매개변수:void
함수 원형: void save_Dvd_data();
*/
void save_Dvd_data()
{
	fopen_s(&Dvd_fp, "Dvd_data.txt", "w+");		//DVD정보 저장을 위해 Dvd_data.txt파일을 쓰기모드로 열기

	for (int i = 0; i < dvd_cnt; i++)
	{											//DVD 정보를 Dvd_data.txt파일에 저장
		fprintf(Dvd_fp, "%s %d %d %s\n", dvd[i]->isbn, dvd[i]->genre, dvd[i]->en, dvd[i]->title);
		free(dvd[i]);							//동적할당 반환
	}
	fclose(Dvd_fp);								//파일을 닫은 뒤 메시지출력 후 종료
	printf("%d개의 DVD정보를 저장하였습니다.\n",dvd_cnt);
}
/*
파일(.txt)에 이력정보를 저장하는 함수
반환형:void/ 매개변수:void
함수 원형: void save_Rent_data();
*/
void save_Rent_data()
{
	fopen_s(&Rent_fp, "Rent_data.txt", "w+");	//이력정보 저장을 위해 Rent_data.txt파일을 쓰기모드로 열기

	for (int i = 0; i < rent_cnt; i++)
	{											//이력 정보를 Rent_data.txt파일에 저장
		fprintf(Rent_fp, "%s %d %d\n", rent[i]->date, rent[i]->index_cus, rent[i]->index_dvd);
		free(rent[i]);							//동적할당 반환
	}
	fclose(Rent_fp);							//파일을 닫은 뒤 메시지출력 후 종료
	printf("%d개의 이력정보를 저장하였습니다.\n",rent_cnt);
}