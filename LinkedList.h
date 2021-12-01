#pragma once
#include <iostream>

using namespace std;

template <class T> 
class Node {

private:
	Node* Next;
	Node* Previous;
	T Data;
	int Priority;
public:
	Node(T inputData, int inputprio, Node* inputNext) { //overload with just Next pointer
		Previous = nullptr;
		Next = inputNext;
		Data = inputData;
		Priority = inputprio;
	};
	Node(T inputData, int inputprio, Node* inputNext, Node* inputPrev) { //overload with both next and previous
		Previous = inputNext;
		Next = nullptr;
		Data = inputData;
		Priority = inputprio;
	};
	Node (T inputData, int inputPrio) { //overload with no pointers
		Previous = nullptr;
		Next = nullptr;
		Data = inputData;
		Priority = inputPrio;
	};
	Node(T inputData, Node* inputNext) { //overload with no priority but next node
		Data = inputData;
		Previous = nullptr;
		Next = inputNext;
		Priority = 0;
	};
	Node(T inputData, Node* inputNext, Node* inputPrev) { //poverload with no prio but next and previous
		Data = inputData;
		Previous = inputPrev;
		Next = inputNext;
		Priority = 0;
	};

	Node(T inputData) {
		Data = inputData;
		Previous = nullptr;
		Next = nullptr;
		Priority = 0;
	}
		
	Node* GetNext() {
		return Next;
	};
	Node* GetPrevious() {
		return Previous;
	};
	T GetData() {
		return Data;
	};
	int GetPriority() {
		return Priority;
	};
	void SetNext(Node* input) {
		Next = input;
	};
	void SetPrev(Node* input) {
		Previous = input;
	};
	void SetData(T input) {
		Data = input;
	};
	void SetPriority(int input) {
		Priority = input;
	};

	~Node() {
		Next = nullptr;
		Previous = nullptr;
	};
};

template <class T>
class Iter {
private:
	T* Current;
	int pos;
public:
	Iter() {
		Current = nullptr;
		pos = 0;
	};
	T* GetCurrent() {
		return Current;
	};
	void SetCurrent(T* newCurrent) {
		Current = newCurrent;
	};
	int GetPosition() {
		return pos;
	};
	void SetPosition(int newPos) {
		pos = newPos;
	};
	void Iterate(T* newNode) {
		Current = newNode;
		pos++;
	};
	void IterateBack(T* newNode) {
		Current = newNode;
		pos--;
	};
	~Iter() {};
};

template <class T>
class Linked_List {
protected:
	int size;
	Node<T>* First; //stores first Node in linked list
	Node<T>* Last; //stores last node in linked list -- used in doubley linked list
	Iter<Node<T>> it;
public:
	Linked_List() {
		size = 0;
		First = nullptr;
		Last = nullptr;
	};
	~Linked_List() {
		while (size > 0) { // delete them nodes
			Pop();
		}
	};

	const Iter<T>* GetIterator() {
		return &it;
	};

	void Push(T newData) {
		Node<T>* newNode;
		if (size == 0) {
			newNode = new Node<T>(newData);
			First = newNode;
			size++;
		}
		else {
			newNode = new Node<T>(newData, First);
			First->SetPrev(newNode);
			First = newNode;
			size++;
		}
	};

	T Pop() { //this removes the first item of the list, it will also output the value
		if (size > 0) {
			T tempData = First->GetData();

			if (First->GetNext() != nullptr) {
				Node<T>* TempFirst = First->GetNext();
				delete First;
				First = TempFirst;
				TempFirst = nullptr;
			}
			else {
				delete First;
				First = nullptr;
			}

			size--;
			return tempData;
		}
		else {
			cout << "error, list is empty, nothing to pop." << endl;
		}
	};

	T Front() {
		if (size > 0) {
			return First->GetData();
		}
	};

};

template <class T> 
class Priority_Queue : Linked_List<T> {

	Priority_Queue() {
		this.First = nullptr;
		this.Last = nullptr;
		this.size = 0;
	};
	~Priority_Queue() {
		while (this.size > 0) { // delete them nodes
			this.Pop();
		}
	};

	void Push(T newData, int prio) {
		if (this.size == 0) {
			this.First = new Node<T>(newData, prio);
			size++;
		}
		else {

		}
	};
};
