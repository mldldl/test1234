//제작자 : 이제우
/*
사용 구조체 모음
*/
#ifndef _my_struct_h_
#define _my_struct_h_
/*
구조체 Customer 선언
맴버
ID : id
이름 : name
전화번호 : num
*/
typedef struct {
	char id[21];		//회원 ID
	char name[20];		//회원 이름
	char num[14];		//회원 전화번호 xxx-xxxx-xxxx\0 < 14자리
}Customer;
/*
구조체 Dvd 선언
맴버
제목 : title
ISBN : isbn
장르 : genre
대여가능 : en
*/
typedef struct {
	char title[30];		//제목
	char isbn[20];		//ISBN
	short int genre;	//장르
	short int en;		//대여가능 여부
}Dvd;
/*
구조체 Rent 선언
맴버
날짜 : date
고객번호 : index_cus
DVD번호 : index_dvd
*/
typedef struct {
	char date[6];		//xx.xx\0 < 6자리
	int index_cus;		//회원 index
	int index_dvd;		//DVD index
}Rent;

#endif // !_my_struct_h_
