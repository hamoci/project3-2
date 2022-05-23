#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Node{
	private:
		std::string word;
		Node* next = NULL;
	public:
		Node(std::string str, Node* next) { word = str; this->next = next; }
		Node() {};
		std::string GetWord() { return word; }
		Node* GetNext() { return next; }
		void SetNext(Node* next) { this->next = next; }
};

class AlphabetInitial{
	private:
		char initial = 0;
		Node* head = NULL;
		Node* tail = NULL;
		AlphabetInitial* next = NULL;
		int size = 0;
	public:
		~AlphabetInitial();
		Node* GetHead() { return head; }
		Node* GetTail() { return tail; }
		char GetInitial() { return initial; }
		AlphabetInitial* GetNext() { return next; }
		void SetHead(Node* node) { this->head = node; }
		void SetTail(Node* node) { this->tail = node; }
		void SetInitial(char init) { initial = init; }
		void SetNext(AlphabetInitial* next) { this->next = next; }
		void AddSize() { size++; }
		void Print();
};

AlphabetInitial::~AlphabetInitial()
{
	if(size != 0)
	{
		Node* temp = head;
		Node* temp1;
		while(temp != NULL)
		{
			temp1 = temp->GetNext();
			delete temp;
			temp = temp1;
		}
	}
}

void AlphabetInitial::Print()
{
	Node* temp = head;
	while(temp != NULL)
	{
		std::cout << " -> " << temp->GetWord();
		temp = temp->GetNext();
	}
}

class List{
	private:
		int size = 0;
		AlphabetInitial* head = NULL;
		AlphabetInitial* tail = NULL;
	public:
		~List();
		void AddNode(std::string word, Node* next);
		void Print();
};

List::~List()
{
	AlphabetInitial* temp = head;
	AlphabetInitial* temp1;
	while(temp != NULL)
	{
		temp1 = temp->GetNext();
		delete temp;
		temp = temp1;
	}
}

void List::AddNode(std::string word, Node* next)
{
	Node* new_node = new Node(word, next);
	char temp = 0;

	if(word[0] >= 97 && word[0] <= 122)
		temp = word[0] - 32;
	else temp = word[0];

	if(size == 0)
	{
		AlphabetInitial* new_init = new AlphabetInitial;
		new_init->SetInitial(temp);
		new_init->SetHead(new_node);
		new_init->SetTail(new_node);
		new_init->AddSize();
		head = tail = new_init;
		size++;
		return;
	}
	if(tail->GetInitial() != temp)
	{
		AlphabetInitial* new_init = new AlphabetInitial;
		new_init->SetInitial(temp);
		new_init->SetHead(new_node);
		new_init->SetTail(new_node);
		new_init->AddSize();
		tail->SetNext(new_init);
		tail = new_init;
		size++;
		return;
	}
	else
	{
		tail->GetTail()->SetNext(new_node);
		tail->SetTail(new_node);
		tail->AddSize();
		return;
	}
}

void List::Print()
{
	AlphabetInitial* temp = head;
	while(temp != NULL)
	{
		std::cout << temp->GetInitial();
		temp->Print();
		std::cout << "\n";
		temp = temp->GetNext();
	}
}

int CompareString(const std::string str1, const std::string str2);

int main(void)
{
	std::ifstream file("Assignment.txt");
	std::vector<std::string> word_list;
	std::string word;
	List list;

	while(!file.eof())
	{
		std::getline(file, word);
		word_list.push_back(word);
	}
	file.close();
	sort(word_list.begin(), word_list.end(), CompareString);
	for(int i = 0; i < word_list.size(); i++)
	{
		//std::cout << word_list[i] << "\n";
		list.AddNode(word_list[i], NULL);
	}
	list.Print();
	return 0;
}

int CompareString(const std::string str1, const std::string str2)
{
	std::string lower_case1 = str1;
	std::string lower_case2 = str2;
	for(int i = 0; i < str1.length(); i++)
	{
		if(str1[i] >= 65 && str1[i] <= 90)
			lower_case1[i] += 32;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		if(str2[i] >= 65 && str2[i] <= 90)
			lower_case2[i] += 32;
	}
	return lower_case1 < lower_case2;
}
