//제작자 : 이제우
/*
파일 오픈을 위한 함수모음
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
파일(.txt)에서 회원정보를 읽어오는 함수
반환형:void/ 매개변수:void
함수 원형: void open_Cus_data();
*/
void open_Cus_data()
{
	int res;										//파일의 끝을 판단할 변수
	fopen_s(&Cus_fp, "Cus_data.txt", "r+");			//Cus_data.txt 파일 읽기모드로 열기

	if (Cus_fp == NULL)								//파일이 존재하지 않으면
	{
		fopen_s(&Cus_fp, "Cus_data.txt", "w+");		//파일을 생성한 후 닫은 뒤 리턴
		printf("회원 정보파일이 없어서 생성하였습니다.\n");
		fclose(Cus_fp);
		return;
	}

	while (1)
	{
		cus[cus_cnt] = (Customer*)malloc(sizeof(Customer));	//회원정보를 저장할 구조체 동적할당
		res = fscanf_s(Cus_fp, "%s %s %s", cus[cus_cnt]->id, sizeof(cus[cus_cnt]->id), cus[cus_cnt]->name
			, sizeof(cus[cus_cnt]->name), cus[cus_cnt]->num, sizeof(cus[cus_cnt]->num));   //파일에서 정보를 읽어온다
		if (res == EOF)								//파일의 끝인경우
		{
			break;									//반복종료
		}
		cus_cnt++;									//고객 카운트 증가
	}
	printf("%d명의 정보를 읽어왔습니다.\n", cus_cnt);
	fclose(Cus_fp);									//파일 닫음
}
/*
파일(.txt)에서 DVD정보를 읽어오는 함수
반환형:void/ 매개변수:void
함수 원형: void open_dvd_data();
*/
void open_Dvd_data()
{
	int res;										//파일의 끝을 판단할 변수
	fopen_s(&Dvd_fp, "Dvd_data.txt", "r+");			//Dvd_data.txt 파일 읽기모드로 열기

	if (Dvd_fp == NULL)								//파일이 존재하지 않으면
	{
		fopen_s(&Dvd_fp, "Dvd_data.txt", "w+");		//파일을 생성한 후 닫은 뒤 리턴
		printf("DVD 정보파일이 없어서 생성하였습니다.\n");
		fclose(Dvd_fp);
		return;
	}

	while (1)
	{
		Dvd *tmp = (Dvd*)malloc(sizeof(Dvd));		//임시 저장 구조체

		res = fscanf_s(Dvd_fp, "%s %hd %hd", tmp->isbn, sizeof(tmp->isbn), &(tmp->genre), &(tmp->en));
		//%hd로 받는이유 = 선언을 short int로 했기때문에 hd로 받아야 동적할당 반환할 시 에러가 생기지 않는다.
		if (res == EOF)	
		{
			break;									//파일의 끝이면 반복문종료
		}
		fgetc(Dvd_fp);								//입력버퍼 제거(공백 제거)
		fgets(tmp->title, sizeof(tmp->title), Dvd_fp);	//제목 입력받음
		tmp->title[strlen(tmp->title) - 1] = '\0';	//fgets로 받은 개행문자 제거를 위함
		dvd[dvd_cnt] = tmp;							//dvd구조체에 임시구조체 저장
		dvd_cnt++;									//dvd카운터 증가
	}
	printf("%d개의 DVD정보를 읽어왔습니다.\n", dvd_cnt);
	fclose(Dvd_fp);									//파일 닫음
}
/*
파일(.txt)에서 이력정보를 읽어오는 함수
반환형:void/ 매개변수:void
함수 원형: void open_Rent_data();
*/
void open_Rent_data()
{
	int res;										//파일의 끝을 판단할 변수
	fopen_s(&Rent_fp, "Rent_data.txt", "r+");		//Rent_data.txt파일을 읽기모드로 열기

	if (Rent_fp == NULL)							//파일이 존재하지 않으면
	{
		fopen_s(&Rent_fp, "Rent_data.txt", "w+");	//파일을 생성한 후 닫은 뒤 리턴
		printf("이력 정보파일이 없어서 생성하였습니다.\n");
		fclose(Rent_fp);
		return;
	}

	while (1)
	{
		rent[rent_cnt] = (Rent*)malloc(sizeof(Rent));
		res = fscanf_s(Cus_fp, "%s %d %d", rent[rent_cnt]->date, sizeof(rent[rent_cnt]->date), &rent[rent_cnt]->index_cus, &rent[rent_cnt]->index_dvd);
		if (res == EOF)
		{
			break;
		}
		rent_cnt++;
	}
	printf("%d개의 이력정보를 읽어왔습니다.\n", rent_cnt);
	fclose(Rent_fp);
}