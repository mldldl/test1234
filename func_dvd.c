//제작자 : 이제우
/*
DVD 관리에관한 함수모음
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
회원 ID와 DVD ISBN을 입력받아 DVD를 대여하기 위한 함수
반환형:void/ 매개변수:void
함수 원형: void Dvd_Rent();
*/
void Dvd_Rent()									//DVD 대여
{
	char tmp_id[20];							//대여할 ID
	char tmp_isbn[20];							//대여할 ISBN
	Rent *tmp = (Rent*)malloc(sizeof(Rent));	//대여 이력을 저장할 임시 Rent

	printf("대여하실 DVD의 ISBN을 입력하세요.");
	scanf("%s", tmp_isbn);

	for (int i = 0; i < dvd_cnt; i++)			//DVD 전체를 검색
	{
		if (!(strcmp(tmp_isbn, dvd[i]->isbn))) {//ISBN이 존재하는지 검색
			printf("대여가 가능합니다. 대여과정을 진행합니다.\n");
			printf("회원 ID를 입력하세요.");	//대여과정이 진행됨으로 고객 ID 입력받음
			scanf("%s", tmp_id);
			for (int j = 0; j < cus_cnt; j++)	//회원 전체를 검색하여 회원이 있는지 점검
			{
				if (!(strcmp(tmp_id, cus[j]->id))) {//회원이 존재할 경우 대여과정 계속 진행
					tmp->index_cus = j;			//rent에 고객 index 저장
					tmp->index_dvd = i;			//rent에 DVD index 저장
					printf("대여 날짜를 입력하세요.(월,일을 각각 두 자리로 입력하시오(월.일))");
					scanf("%s", tmp->date);		//대여 날짜 입력받음

					if ((dvd[i]->en) == 0) {	//DVD가 대여가능한지 판단
						printf("대여가 완료되었습니다.\n");
						dvd[i]->en = 1;			//가능하면 대여 진행
						rent[rent_cnt] = tmp;
						rent_cnt++;
						return;
					}
					else {						//가능하지 않으면 더이상 진행하지않고
						printf("대여중이라 대여가 불가능합니다.\n");//메시지 출력후 return
						free(tmp);
						return;
					}
				}
			}
			printf("회원에게만 대여 가능합니다.\n");	//회원이 아니면 아래메시지 출력후 return
			free(tmp);
			return;
		}
	}
	printf("ISBN이 없습니다.\n");				//DVD목록에서 검색이 되지 않으면 메시지 출력
	free(tmp);
}
/*
ISBN을 입력받아 DVD 반납을 위한 함수
반환형:void/ 매개변수:void
함수 원형: void DVD_Return();
*/
void Dvd_Return()				//DVD 반납
{
	char tmp[20];								//반납할 ISBN을 저장할 tmp
	printf("반납할 ISBN을 입력하세요.");
	scanf("%s", tmp);

	for (int i = 0; i < dvd_cnt; i++)			//DVD목록 전체를 검색
	{
		if (!strcmp(dvd[i]->isbn, tmp))			//목록의 DVD에서 일치하는 ISBN을 찾은 후
		{
			if (dvd[i]->en == 1) {				//en가 1이면 빌렸던 것이므로 반납 진행후 return
				dvd[i]->en = 0;
				printf("반납되었습니다.\n");
				return;
			}
			else {								//en이 0이면 대여하지 않은것이므로 아래 메시지 출력후 return
				printf("대여되지 않은 DVD입니다.\n");
				return;
			}
		}
	}
	printf("등록되지 않은 ISBN입니다.\n");		//DVD목록에 없으면 이 메시지가 출력되고 함수 종료
}
/*
ISBN을 입력받아 DVD rent이력을 출력하는 함수
반환형:void/ 매개변수:void
함수 원형: void Dvd_Stat();
*/
void Dvd_Stat()							//DVD 이력
{
	char tmp[20];						//검색할 ISBN이 저장될 tmp
	char flag = 0;						//이력 존재 유무를 확인할 flag
	printf("검색할 ISBN을 입력하시오.");
	scanf("%s", tmp);

	for (int i = 0; i < rent_cnt; i++)	//이력 전체를 검색하여
	{
		if (!strcmp(tmp, dvd[rent[i]->index_dvd]->isbn)) //일치하는 ISBN이 존재하면
		{
			printf("대여일 : %s\n", rent[i]->date);		//그에 대한 정보들을 출력
			Show_Cus(rent[i]->index_cus);
			printf("\n");
			flag = 1;									//플레그 변경하여 이력이 있다는것을 알림
		}
	}

	if (flag == 0) printf("이력이 존재하지 않습니다.\n");//플레그==0 -> 이력이 없으므로 이 메시지 출력후 함수 종료
}
/*
고객 ID와 기간을 입력받아 DVD rent 이력을 출력하는 함수
반환형:void/ 매개변수:void
함수 원형: void Cus_Dvd();
*/
void Cus_Dvd()							//대여 DVD 전체 조회(날짜 입력으로 조회)

{
	char tmp_id[21];					//회원 ID검색을 위한 임시 tmp_id
	char tmp_date_s[6];					//날짜 검색을 위한 시작일 저장 tmp_date_s
	char tmp_date_f[6];					//날짜 검색을 위한 종료일 저장 tmp_date_f
	char flag = 0;						//검색 성공유무를 판단할 flag
	int index;							//회원 index저장
	printf("고객 ID를 입력하세요.");
	scanf("%s", tmp_id);

	for (int i = 0; i < cus_cnt; i++)
	{
		if (!strcmp(tmp_id, cus[i]->id))
		{
			flag = 1;					//회원 검색에 성공하면 flag=1 실패시 0
			index = i;					//index에 고객의 index 저장
			break;						//검색완료했으므로 반복문을 빠져나온다.
		}
	}
	if (flag == 0) {					//회원 검색이 안됬으므로 아래 메시지 출력후 return
		printf("ID가 존재하지 않습니다.\n");
		return;
	}
	//이 시점이후 flag의 사용법이 변경됨
	//flag = 0이면 검색 성공(이력 존재)  flag=1 이면 검색실패(이력 없음)
	printf("조회 시작날짜를 입력하세요.(xx월.xx일)");
	scanf("%s", tmp_date_s);
	printf("조회 마지막날짜를 입력하세요.(xx월.xx일)");
	scanf("%s", tmp_date_f);

	for (int i = 0; i < rent_cnt; i++)	//이력 전체를 검색
	{
		if (index == rent[i]->index_cus)//이력중 회원이 존재하면 빌린날을 검색
		{
			if (strcmp(tmp_date_s, rent[i]->date) <= 0 && strcmp(tmp_date_f, rent[i]->date) >= 0)
			{							//입력받은 범위내에 빌린 이력이 있으면 출력
				printf("빌린 DVD의 ISBN : %s\n", dvd[rent[i]->index_dvd]->isbn);
				printf("대여일 : %s\n", rent[i]->date);
				flag = 0;				//이력이 있으므로 1->0으로 toggle
			}
		}
	}
	if (flag == 1)						//flag가 1이므로 이력이 없으므로 아래 메시지를 출력 함수 종료
		printf("이력이 존재하지 않습니다.\n");
}
