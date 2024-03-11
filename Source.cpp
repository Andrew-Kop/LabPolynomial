#include <iostream>
#include <string>
#include"LinkedList.hpp"
using namespace std;



template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}

	else {
		Node<T> *current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}

		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, size_t index)
{
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* previos = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T>* NewNode = new Node<T>(data, previos->pNext);
		previos->pNext = NewNode;
	}
	size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size) {
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter = index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


int main() {
	setlocale(LC_ALL, "ru");

	List<int> first;
	first.push_back(5);
	first.push_back(10);
	first.push_back(22);
	return 0;
}