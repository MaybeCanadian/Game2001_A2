#include "LinkedList.h"

using namespace std;

int main(void) {

	Linked_List<int> TestIntList;

	Priority_Queue<int> TestIntPrio;

	TestIntList.Pop();

	TestIntList.Push(20);

	cout << TestIntList.Front() << endl;

	TestIntList.Push(10);

	cout << TestIntList.Front() << endl;

	cout << TestIntList.Pop() << endl;
	cout << TestIntList.Pop() << endl;
	//this is testing the linked list part

	cout << "testing prio now." << endl;

	system("PAUSE");

	return 0;
}