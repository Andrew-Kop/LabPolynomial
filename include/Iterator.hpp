#pragma once
#include<iostream>

template <typename T>
class Iterator;

template <typename T>
class Node {
private:
	Node* pNext;
	T data;
public:
	Node(const T data = T(), Node* pNext = nullptr) : data(data), pNext(pNext) {}
	Node& operator=(const Node& other);
	T& GetData() { return data; }
	void SetData(const T _data) { data = _data; }
	Node<T>* Getptr() {
		if (pNext != nullptr) { return pNext; }
		else {
			throw std::out_of_range("nullptr");
		}
	}
	void Setptr(Node* _ptr) { pNext = _ptr; } // интересно почему нельзя с const
	~Node() {}
};


template <typename T>
class Iterator {
private:
	Node<T>* index;
public:
	Node<T>* Getindex() const { return index; }
	void Setindex(const Node<T>* _index) { index = _index; }
	Iterator(Node<T>* _index = nullptr) : index(_index){}
	Iterator(const Iterator& other) {
		index = other.index;
	}
	~Iterator() { }
	Iterator& operator=(const Iterator& other) {
		index = other.index;
		return *this;
	}
	bool operator==(const Iterator& other) const {
		return index == other.index;
	}
	bool operator!=(const Iterator& other) const {
		return index != other.index;
	}
	Iterator<T>& operator++();
	Iterator<T> operator++(int); 
	T& operator*();
	const T& operator*() const;
	Iterator<T> operator+(size_t n) const; 
	
};


template <typename T> 
Node<T>& Node<T>::operator=(const Node<T>& other)
{
	pNext = other.pNext;
	data = other.data;
	return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
	if (index == nullptr) {
		throw std::out_of_range("Iterator is out of range");
	}

	index = index->Getptr();
	return *this;
}


template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator<T> tmp(*this);
	if (index == nullptr) {
		throw std::out_of_range("Iterator is out of range");
	}
	index = index->Getptr();
	return tmp;
}

template <typename T>
T& Iterator<T>::operator*() {
	if (index == nullptr) {
		throw std::out_of_range("Iterator is out of range");
	}
	return index->GetData();
}

template <typename T>
const T& Iterator<T>::operator*() const {
	if (index == nullptr) {
		throw std::out_of_range("Iterator is out of range");
	}
	return index->GetData();
}

template<typename T>
Iterator<T> Iterator<T>::operator+(size_t n) const
{
	Iterator<T> other(*this);
	if (other.index == nullptr) {
		throw std::out_of_range("Iterator is out of range");
	}
	for (size_t i = 0; i < n; i++) {
		if (other.index == nullptr) {
			throw std::out_of_range("Iterator is out of range");
		}
		other.index = other.index->Getptr();
	}
	return other;
}



