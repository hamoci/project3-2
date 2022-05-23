#include <iostream>	//표준입출력기능이 있는 헤더 iostream 포함
#include <string>	//string STL이 있는 헤더 string 포함

class item{	//class item에 대한 정의
	private:
		int price;		//멤버변수 선언
		int stock;		//멤버변수 선언
		int discount;	//멤버변수 선언
	public:
		item(int price, int stock) { this->price = price; this->stock = stock; discount = 0; }	//생성자 정의
		int getprice() { return price; }	//가격을 반환하는 메소드 정의
		int getstock() { return stock; }	//재고를 반환하는 메소드 정의
		int getdiscount() { return discount; }	//할인율을 반환하는 메소드 정의
		void addstock(int num) { this->stock += num; }	//재고를 추가하는 메소드 정의
		void sell_item(int num) { this->stock -= num; }	//물건을 판매하는 메소드 정의
		void setdiscount(int num) { discount = num; }	//할인율을 설정하는 메소드 정의
};

class Pen : public item {	//class item을 상속하는 class Pen 정의
	public:
		Pen(int price, int stock) : item(price, stock) {};	//부모 생성자 인자 전달 및 생성자 정의
};

class Pencil : public item {	//class item을 상속하는 class Pencil 정의
	public:
		Pencil(int price, int stock) : item(price, stock) {};	//부모생성자 인자 전달 및 생성자 정의
};

class Eraser : public item {	//class item을 상속하는 class Eraser 정의
	public:
		Eraser(int price, int stock) : item(price, stock) {};	//부모생성자 인자 전달 및 생성자 정의
};

int main(void)
{
	int command;	//command 입력받을 변수 선언
	std::string name;	//물건이름을 저장할 string형 변수 선언
	int num = 0;	//임시로 int형 값을 저장할 변수 선언
	Pen pen(200*3, 100);	//pen 선언 및 생성자 호출
	Pencil pencil(100*12, 100);	//pencil 선언 및 생성자 호출
	Eraser eraser(500, 100);	//eraser 선언 및 생성자 호출
	int sales = 0;	//전체 매출을 저장할 변수 sales 선언

	//문자열 출력
	std::cout << "======================\n"
			  << "---------Pen----------\n";
	std::cout << "Price : " << pen.getprice() << "\n";
	std::cout << "Stock : " << pen.getstock() << "\n";
	std::cout << "Discount : " << pen.getdiscount() << "%\n";
	std::cout << "----------------------\n"
			  << "---------Pencil-------\n";
	std::cout << "Price : " << pencil.getprice() << "\n";
	std::cout << "Stock : " << pencil.getstock() << "\n";
	std::cout << "Discount : " << pencil.getdiscount() << "%\n";
	std::cout << "----------------------\n";
	std::cout << "---------Eraser-------\n";
	std::cout << "Price : " << eraser.getprice() << "\n";
	std::cout << "Stock : " << eraser.getstock() << "\n";
	std::cout << "Discount : " << eraser.getdiscount() << "%\n";
	std::cout << "----------------------\n";
	while(1)	//무한루프
	{
		std::cout << "Enter Any Command(0 : Sell, 1 : AddStock, 2 : Discount, 3 : Print, 4 : Quit) :";
		std::cin >> command;	//command 입력
		switch(command)
		{
			case 0:
				std::cin >> name >> num;	//물건이름, 개수 입력
				if(!name.compare("Pen"))	//물건이 Pen이면 실행
				{
					if(pen.getstock() < 3 * num)	//남은 개수가 더 적으면 안됨
					{	
						std::cout << "Not enough Pen stock.\n";
						break;
					}
					sales += 3 * 200 * num * (1 - pen.getdiscount() * 0.01); //할인율을 반영하여 매출 계산
					pen.sell_item(num * 3); //판 만큼 재고 감소
				}
				else if (!name.compare("Pencil"))	//물건이 Pencil이면 실행
				{
					if(pencil.getstock() < 12 * num)	//남은 개수가 더 적으면 안됨
					{
						std::cout << "Not enough Pencil stock.\n";
						break;
					}
					sales += 12 * 100 * num * (1 - pencil.getdiscount() * 0.01); //할인율을 반영하여 매출 계산
					pencil.sell_item(12 * num); //판 만큼 재고 감소
				}
				else if (!name.compare("Eraser"))	//물건이 Eraser이면 실행
				{
					if(eraser.getstock() < num) //남은 개수가 더 적으면 안됨
					{
						std::cout << "Not enough Eraser stock.\n";
						break;
					}
					sales += 500 * num * (1 - pen.getdiscount() * 0.01);//할인율을 반영하여 매출 계산
					eraser.sell_item(num);//판 만큼 재고 감소
				}
				break;
			case 1:
				std::cin >> name >> num;
				if(!name.compare("Pen"))
					pen.addstock(num);	//재고 추가
				else if (!name.compare("Pencil"))
					pencil.addstock(num);	//재고 추가
				else if (!name.compare("Eraser"))
					eraser.addstock(num); //재고 추가
				else std::cout << "Can't find item.\n";
				break;
			case 2:
				std::cin >> name >> num;
				if(!name.compare("Pen"))
					pen.setdiscount(num);	//할인율 설정
				else if (!name.compare("Pencil"))
					pencil.setdiscount(num);//할인율 설정
				else if (!name.compare("Eraser"))
					eraser.setdiscount(num);//할인율 설정
				else std::cout << "Can't find item.\n";
				break;
			case 3:
				//문자열 출력
				std::cout << "======================\n"
						  << "---------Pen----------\n";
				std::cout << "Price : " << pen.getprice() << "\n";
				std::cout << "Stock : " << pen.getstock() << "\n";
				std::cout << "Discount : " << pen.getdiscount() << "%\n";
				std::cout << "----------------------\n"
						  << "---------Pencil-------\n";
				std::cout << "Price : " << pencil.getprice() << "\n";
				std::cout << "Stock : " << pencil.getstock() << "\n";
				std::cout << "Discount : " << pencil.getdiscount() << "%\n";
				std::cout << "----------------------\n";
				std::cout << "---------Eraser-------\n";
				std::cout << "Price : " << eraser.getprice() << "\n";
				std::cout << "Stock : " << eraser.getstock() << "\n";
				std::cout << "Discount : " << eraser.getdiscount() << "%\n";
				std::cout << "----------------------\n";
				std::cout << "======================\n";
				break;
			case 4:
				return 0; //프로그램 정상 종료
				break;
			default:
				break;
		}
		//문자열 출력
		std::cout << "======================\n";
		std::cout << "Sales : " << sales << "\n";
		std::cout << "======================\n";
	}

	return 0; //프로그램 정상 종료
}
