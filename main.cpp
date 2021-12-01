#include "LinkedList.h"

using namespace std;

int main(void) {

	Linked_List<int> TestIntList;

	Priority_Queue<int> TestPrio;

	cout << "Testing base Linked list" << endl;

	TestIntList.Pop();

	TestIntList.Push(20);

	cout << TestIntList.Front() << endl;

	TestIntList.Push(10);

	cout << TestIntList.Front() << endl;

	cout << TestIntList.Pop() << endl;
	cout << TestIntList.Pop() << endl;
	//this is testing the linked list part

	cout << "testing prio now." << endl;

	TestPrio.Pop();

	TestPrio.Push(10);

	TestPrio.Push(10, 10);

	cout << TestPrio.Front() << endl;

	TestPrio.Push(20, 5);

	cout << TestPrio.Front() << endl;

	TestPrio.Push(10, 7);

	cout << TestPrio.Front() << endl;

	TestPrio.Push(40, 5);

	cout << TestPrio.Front() << endl;

	while (TestPrio.GetSize() > 0) {
		cout << TestPrio.Pop() << endl;
	}



	system("PAUSE");

	return 0;
}