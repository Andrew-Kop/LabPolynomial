#pragma once

template <typename T>
class List {
public:
	List();
	~List();
	void push_back(T data);
	void push_front(T data);
	void insert(T data, size_t index);
	void removeAt(size_t index);
	void pop_front();
	void pop_back();
	void clear();
	int GetSize() { return size; }
	T& operator[](const int index);
	ostream& operator<<(ostream& os, const List& list);
private:
	template <typename T>
	class Node {
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr) : data(data), pNext(pNext) {}

	};
	int size;
	Node<T>* head;
};
