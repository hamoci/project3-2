#include <iostream>	//표준입출력기능이 있는 헤더 iostream 포함
#include <cstring>	//string과 관련된 함수가 있는 헤더 cstring 포함

class 대학 {	//class 대학 정의
	private:
		char U_Name[20];	//멤버변수 선언
		int year;			//멤버변수 선언
		char U_StuID[20];	//멤버변수 선언
	public:
		대학(const char* name, const int year, const char* stuid)	//생성자 정의
		{
			strcpy(U_Name, name);	//strcpy를 사용하여 문자열 대입
			this->year = year;
			strcpy(U_StuID, stuid);	//strcpy를 사용하여 문자열 대입
		}
		char* GetUnivName() { return U_Name; }	//대학교 이름 반환하는 메소드 정의
		int GetYear() { return year; }			//학년을 반환하는 메소드 정의
		char* GetUnivStuID() { return U_StuID; }//학번을 반환하는 메소드 정의
};

class 컴퓨터정보공학 : public 대학	//대학 class를 상속하는 컴퓨터정보공학 class 정의
{
	private:
		char Object_Oriented_Programming;	//멤버변수 선언
		char Digital_Logic_Circuit;			//멤버변수 선언
	public:
		컴퓨터정보공학(const char* name, const int year, const char* stuid, char oop, char dlc) : 대학(name, year, stuid)
																										  //부모 생성자에 인자 전달과 동시에 자신의 멤버변수를 초기화하는 생성자 정의
		{
			Object_Oriented_Programming = oop;
			Digital_Logic_Circuit = dlc;
		}
		char GetOOP() { return Object_Oriented_Programming; }	//OOP 학점 반환하는 메소드
		char GetDLC() { return Digital_Logic_Circuit; }			//DLC 학점 반환하는 메소드
};

class 학생정보 : public 컴퓨터정보공학	//컴퓨터정보공학 class를 상속하는 학생정보 class 정의
{
	private:
		char Name[10];	//멤버변수 선언
		int age;		//멤버변수 선언
	public:
		학생정보(const char* name, const int year, const char* stuid, char oop, char dlc, char* name2, int age) : 컴퓨터정보공학(name, year ,stuid, oop, dlc)
		//부모 생성자에 인자 전달과 동시에 자신의 멤버변수를 초기화하는 생성자 정의	
		{
			strcpy(Name, name2);	//strcpy를 사용하여 문자열 대입
			this->age = age;
		}
		char* GetName() { return Name; }	//이름을 반환하는 메소드 정의
		int GetAge() { return age; }		//나이를 반환하는 메소드 정의
};

int main(void)	//메인함수
{
	학생정보** student;	//학생정보를 관리할 이중포인터 student 선언
	std::string command;	//입력받은 커맨드를 저장할 변수 선언
	int count = 0;	//현재 몇개의 data가 있는지 저장할 변수 선언
	char univ_name[20];	//임시로 저장할 변수 선언
	int year;	//임시로 저장할 변수 선언
	char univ_ID[20];	//임시로 저장할 변수 선언
	char oop;	//임시로 저장할 변수 선언
	char dlc;	//임시로 저장할 변수 선언
	char student_name[10];	//임시로 저장할 변수 선언
	int age;	//임시로 저장할 변수 선언
	student = new 학생정보*[100];	//동적할당을 통해 최대 100개의 데이터 저장가능하도록 함

	while(1)	//무한루프
	{
		std::cin >> command;	//command 입력
		if(!command.compare("INSERT"))	//입력한 것이 INSERT라면
		{
			if(count > 99) 	//data가 100개이면 아래의 구문 실행
			{
				std::cout << "Can't Store Anymore.\n";	//문자열 출력
				continue;	//루프 스킵
			}
			std::cout << "학교 :";
			std::cin >> univ_name;	//학교이름 입력
			std::cout << "학번 :";
			std::cin >> univ_ID;	//학번 입력
			std::cout << "학년 :";
			std::cin >> year;	//학년 입력	
			std::cout << "객체지향프로그래밍 학점 :";
			std::cin >> oop;	//학점 입력
			std::cout << "디지털논리회로 학점 :";
			std::cin >> dlc;	//학점 입력
			std::cout << "이름 :";
			std::cin >> student_name;	//이름 입력
			std::cout << "나이 :";
			std::cin >> age;	//나이 입력
			student[count++] = new 학생정보(univ_name, year, univ_ID, oop, dlc, student_name, age);
			//동적할당 및 생성자 호출
		}
		else if(!command.compare("FIND"))	//입력한 것이 FIND라면 아래의 구문 실행
		{
			std::cin >> student_name >> univ_ID;	//이름, 학번입력
			for(int i = 0; i < count; i++)	//data의 개수만큼 탐색
			{
				if(!strcmp(student_name, student[i]->GetName()) && !strcmp(univ_ID, student[i]->GetUnivStuID()))
				//학번과 이름이 동일하다면 아래의 구문 실행
				{
					std::cout << "\n\n학교:" << student[i]->GetUnivName() <<"\n";
					std::cout << "학번:" << student[i]->GetUnivStuID() << "\n";
					std::cout << "학년:" << student[i]->GetYear() << "\n";
					std::cout << "객체지향프로그래밍 학점:" << student[i]->GetOOP() << "\n";
					std::cout << "디지털논리회로 학점:" << student[i]->GetDLC() << "\n";
					continue;	//루프 스킵
				}
			}
		}
		else if(!command.compare("EXIT"))	//입력한 커맨드가 EXIT라면 아래의 구문 실행
		{
			for(int i = 0; i < count; i++)
				delete student[i];	//학생정보를 저장하고 있는 공간 전부 해제
			delete[] student;	//학생정보* 배열을 삭제
			return 0;	//프로그램 정상 종료
		}
		else std::cout << "No Command Found.\n"; //일치하는 명령어가 없을 경우 문자열 출력
	}
	return 0;
}
