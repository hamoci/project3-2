#include <iostream>	//표준 입출력 기능이 있는 헤더 iostream 포함

class TwoPoint {	//class TwoPoint에 대한 정의
	private:
		double x1;	//멤버변수 x1 선언
		double y1;	//멤버변수 y1 선언
		double x2;	//멤버변수 x2 선언
		double y2;	//멤버변수 y2 선언
	public:
		TwoPoint(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {} //생성자 선언 및 초기화
		virtual void print()	//print함수 virtual로 정의
		{	//출력할때 noshowbase manipulator를 사용하여 소수점이 없으면 표시하지 않음
			std::cout << "Point 1 : " << std::noshowbase << x1 << "," << y1 << "\n";
			std::cout << "Point 2 : " << std::noshowbase << x2 << "," << y2 << "\n";
		}
};

class Equation : public TwoPoint {	//class Equation 정의 및 TwoPoint 선언
	private:
		double a = 0;	//멤버변수 a 선언	
		double b = 0;	//멤버변수 b 선언
	public:
		Equation(double x1, double y1, double x2, double y2) : TwoPoint(x1, y1, x2, y2)
		{	//상속 class의 생성자 사용하면서, 동시에 자신의 멤버변수 초기화
			a = (y2 - y1) / (x2 - x1);
			b = (-x1) * a + y1;
		}
		void print()	//override를 사용한 print함수 정의
		{	//noshowbase를 사용하여 소수점없으면 소수점 표시하지 않음
			std::cout << "Equation : y = " << std::noshowbase << a << "x + " << b << "\n";
		}
};


int main(void)
{
	//동적할당 및 생성자호출
	class TwoPoint *A = new TwoPoint(2, 4, 7, 8);
	class TwoPoint *B = new Equation(2, 4, 7, 8);
	A->print();	//메소드호출
	B->print();	//메소드호출
	delete A;	//동적할당 해제
	delete B;	//동적할당 해제
	return 0;	//프로그램 정상 종료
}
