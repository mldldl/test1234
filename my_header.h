//제작자 : 이제우
/*
사용 함수 및 열거형 모음
*/
#ifndef _my_header_h_
#define _my_header_h_

#define CUS_MAX 100				//회원 최대 저장
#define DVD_MAX 100				//DVD 최대 저장
#define RENT_MAX 1000			//이력 최대 저장

enum { NEWCUS = 1, SEARCHCUS, NEWDVD, DVDSEARCH, DVDRENT, DVDRETURN, DVDSTAT, CUSDVD, EXIT };	//main 선택문
enum { ACTION = 1, COMIC, SF, ROMANTIC };														//장르 선택

/*정보 입력 함수*/
void Input_Cus();		//신규회원가입
void Input_Dvd();		//DVD등록

/*정보 검색 함수*/
void Search_Cus();		//회원 검색(ID 이용)
void Search_Dvd();		//DVD검색(ISBN 이용)

/*DVD관리 관련 함수*/
void Dvd_Rent();		//DVD 대여
void Dvd_Return();		//DVD 반납
void Dvd_Stat();		//DVD 대여 이력 조회
void Cus_Dvd();			//회원의 DVD 대여 이력 조회

/*정보 출력 함수*/
void Show_Cus(int i);	//회원 출력
void Show_Dvd(int i);	//DVD 출력
void Show_Menu();		//메뉴 출력

/*파일 저장 함수*/
void save_Cus_data();	//회원정보 파일저장
void save_Dvd_data();	//DVD정보 파일저장
void save_Rent_data();	//이력정보 파일저장

/*파일 오픈 함수*/
void open_Cus_data();	//파일에서 회원정보 로드
void open_Dvd_data();	//파일에서 DVD정보 로드
void open_Rent_data();	//파일에서 이력정보 로드

#endif // !_my_header_h_
