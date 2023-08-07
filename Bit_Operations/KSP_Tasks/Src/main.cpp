#include <iostream>
#include "Tasks/Task1/KSP_task1.h"
#include "Tasks/Task2/KSP_task2.h"
#include "Tasks/Task3/KSP_task3.h"
#include "Tasks/Task4/KSP_task4.h"
#include "Tasks/Task5/KSP_task5.h"
#include "Tasks/Task6/KSP_reverse_vector.h"
#include "Tasks/Task7/KSP_task7.h"

int main(int argc, char* arv[]) {

	//-----------------------------------------------------TASK1------------------------------------------------------------//
	KSP_task1* task1 = new KSP_task1();
	task1->GetBitsFromUint32(0xABCD1234,2,12);
	task1->printout();

	//-----------------------------------------------------TASK2------------------------------------------------------------//
	KSP_task2* task2 = new KSP_task2();
	task2->GetBitsFromUint32(0xABCDEF12, 4, 12);
	task2->printout();

	//-----------------------------------------------------TASK3------------------------------------------------------------//
	KSP_task3* task3 = new KSP_task3();
	task3->GetBitsVector(6789);
	task3->printout();

	//-----------------------------------------------------TASK4/TASK5------------------------------------------------------------//
	std::cout << "-----------------TASK4/TASK5-----------------" << std::endl;

	Tree* root = new Tree("Tree name");
	Tree* galaz1 = root->AddSub("galaz 1"); // this function creates a child Tree object and returns pointer to it
	Tree* galaz2 = root->AddSub("galaz 2");
	Tree* galaz3 = root->AddSub("galaz 3");
	Tree* galaz1_1 = galaz1->AddSub("galaz 1.1");
	Tree* galaz2_1 = galaz2->AddSub("galaz 2.1");
	Tree* galaz2_2 = galaz2->AddSub("galaz 2.2");
	Tree* galaz2_3 = galaz2->AddSub("galaz 2.3");//
	Tree* galaz2_4 = galaz2->AddSub("galaz 2.4");//
	Tree* galaz2_5 = galaz2->AddSub("galaz 2.5");//
	Tree* galaz2_1_2 = galaz2_1->AddSub("galaz 2.1.2");

	root->print(6, true, "");

	uint32_t rootChildrenCnt = root->GetSubCount(); // result shall be 3
	uint32_t galaz1childrenCount = galaz2->GetSubCount(); // result shall be 1
	uint32_t countOfAllChildren = root->GetAllSubCount(); // result shall be 7 (recursive children counting)
	std::cout << std::endl;
	std::cout << std::dec << "Root children: " << rootChildrenCnt << std::endl;
	std::cout << std::dec << "Galaz2 children: "<< galaz1childrenCount << std::endl;
	std::cout <<std::dec<< "All children: "<< countOfAllChildren << std::endl;
	std::cout << std::endl;

	std::cout << "After deleting" << std::endl << std::endl;
	root->Del(1); // will remove galaz_2 with all it's children (recursive), so in a result only galaz_1 and galaz_3 will stay
	root->print(6, true,"");
	std::cout << std::endl;
	rootChildrenCnt = root->GetSubCount(); // result shall be 2
	countOfAllChildren = root->GetAllSubCount(); // result shall be 3 (recursive children counting)

	std::cout << "Root children: " << rootChildrenCnt << std::endl;
	std::cout << "All children: " << countOfAllChildren << std::endl << std::endl;

	delete(root); // deleting root shall remove all children (recursive) and clean memory

	//-----------------------------------------------------TASK6------------------------------------------------------------//
	std::cout << "-----------------TASK6-----------------" << std::endl;
	std::vector<char> v{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	std::cout << "Input vector:" << std::endl;
	for (auto& i : v) std::cout << i << " ";
	std::cout << std::endl;

	reverse_vector(v);
	std::cout << "Reversed vector:" << std::endl;
	for (auto& i : v) std::cout << i << " ";
	std::cout << std::endl;

	//-----------------------------------------------------TASK7------------------------------------------------------------//
	std::cout << "-----------------TASK7-----------------" << std::endl;

	BitStream* bs= new BitStream(5);

	int x = 5;
	bool y = true;
	float z = 3.14;
	double w = 2.71828;
	std::string s = "hello";

	bs->Add(sizeof(x) * 8, &x);
	bs->Add(sizeof(y) * 8, &y);
	bs->Add(sizeof(z) * 8, &z);
	bs->Add(sizeof(w) * 8, &w);
	bs->Add(s.length() * 8, &s[0]);

	size_t bufferLength = (bs->GetBitLength() + 7) / 8;
	std::vector<uint8_t> buffer(bufferLength);
	bs->GetData(&buffer[0], bs->GetBitLength());

	std::cout << "Variable Types: " << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << "bool: " << y << std::endl;
	std::cout << "float: " << z << std::endl;
	std::cout << "double: " << w << std::endl;
	std::cout << "string: " << s << std::endl;

	std::cout << std::endl << "Binary Representation: " << std::endl;
	for (auto byte : buffer) {
		std::bitset<8> bits(byte);
		std::cout << bits << " ";
	}

	std::cout << std::endl;

	return 0;

}