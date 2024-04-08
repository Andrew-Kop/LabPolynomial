#pragma once
#include"Iterator.hpp"
#include <iostream>
using namespace std;

template <typename T>

class SingleLinkedList {
private:
	size_t size;
	Node<T>* head;
public:
	SingleLinkedList(size_t size = 0, Node<T>* head = nullptr) : size(size), head(head){}
	SingleLinkedList(const SingleLinkedList& other);
	SingleLinkedList(const T& data);
	~SingleLinkedList() { 
		clear();
	}

	void pop_front(); //удаление первого элемента в списке

	void push_back(T data); //добавление элемента в конец списка

	void clear(); // очистить список

	int GetSize() { return size; } // получить количество элементов в списке

	T& operator[](const int index); // перегруженный оператор [] 

	void push_front(T data); //добавление элемента в начало списка

	void insert(T data, int index); //добавление элемента в список по указанному индексу

	void removeAt(int index); //удаление элемента в списке по указанному индексу

	void pop_back(); 	//удаление последнего элемента в списке

	bool operator==(const SingleLinkedList<T>& other) const;

	Iterator<T> begin() const {
		return Iterator<T>(head);
	}
	Iterator<T> end() const {
		return Iterator<T>();
	}
	Iterator<T> tail() const {
		for (size_t i = 0; i < size; i++) {
			head = head->Getptr();
		}
		return Iterator<T>(head);
	}

};


template<typename T>
T& SingleLinkedList<T>::operator[](const int index)
{
	Iterator<T> iter(head);
	for (int i = 0; i < index; i++)
	{
		++iter; 
	}

	return iter.Getindex()->GetData();
}


template<typename T>
SingleLinkedList<T>::SingleLinkedList(const T& data)
{
	push_back(data);
}

template<typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& other) {
	Node<T>* current = other.head;
	while (current != nullptr) {
		push_back(current->GetData());
		current = current->Getptr();
	}
}

template<typename T>
void SingleLinkedList<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->Getptr();

	delete temp;

	size--;

}


template<typename T>
void SingleLinkedList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->Getptr() != nullptr)
		{
			current = current->Getptr();
		}
		current->Setptr(new Node<T>(data));

	}

	size++;
}

template<typename T>
void SingleLinkedList<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}



template<typename T>
void SingleLinkedList<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void SingleLinkedList<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Iterator<T> iter(head);
		for (int i = 0; i < index - 1; i++)
		{
			++iter;
		}

		Node<T>* temp = iter.Getindex()->Getptr();

		iter.Getindex()->Setptr(new Node<T>(data, temp));

		size++;
	}

}

template<typename T>
void SingleLinkedList<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Iterator<T> iter(head);
		for (int i = 0; i < index - 1; i++)
		{
			++iter;
		}


		Node<T>* toDelete = iter.Getindex()->Getptr();

		iter.Getindex()->Setptr(toDelete->Getptr());

		delete toDelete;

		size--;
	}

}

template<typename T>
void SingleLinkedList<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
inline bool SingleLinkedList<T>::operator==(const SingleLinkedList<T>& other) const
{
	if (size != other.size) {
		return false;
	}
	Iterator<T> iter1 = begin();
	Iterator<T> iter2 = other.begin();
	while (iter1 != end() && iter2 != other.end()) {
		if (*iter1 != *iter2) {
			return false;
		}
		++iter1;
		++iter2;
	}
	return (iter1 == end() && iter2 == other.end());
}



