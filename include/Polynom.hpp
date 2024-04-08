#pragma once
#include "Monom.hpp"
#include "SingleLinkedList.hpp"
#include <string>
#include <algorithm>
#include <stdexcept>

bool EqualNames(const std::vector<std::string> name1, const std::vector<std::string> name2) {
	if (name1.size() == name2.size()) {
		int size = name1.size();
		for (size_t i = 0; i < size; i++) {
			if (name1[i] != name2[i]) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

template <typename T>
class Polynom {
private:
	SingleLinkedList<Monom<T>> list_of_monoms;
	std::vector<std::string> diff_names;
public:
	Iterator<Monom<T>> begin() {
		return list_of_monoms[0];
	};
	Iterator<Monom<T>> tail() {
		return list_of_monoms[list_of_monoms.GetSize() - 1];
	};
	Iterator<Monom<T>> end() {
		return Iterator<Monom<T>>();
	};
	
	Polynom<T>(const Polynom<Monom<T>>& other) : diff_names(other.diff_names()){
		for (size_t i = 0; i < other->list_of_monoms.GetSize(); i++) {
			list_of_monoms[i] = other->list_of_monoms[i];
		}
	}
	std::vector<std::string> GetDiffNames() const
	{
		return diff_names;
	}
	int position(const std::string& name); Polynom<T>(const SingleLinkedList<Monom<T>>& monoms, const std::vector<std::string>& variables) : list_of_monoms(monoms)
	{
		diff_names = variables;
		std::sort(diff_names.begin(), diff_names.end());
	}
	int MonomDegree(const Monom<T>& monom, const std::string& word);
	bool operator==(const Polynom<T>& other) {
		return (list_of_monoms == other.list_of_monoms) && (diff_names == other.diff_names);
	}
	bool operator!=(const Polynom<T>& other) {
		return !((list_of_monoms == other.list_of_monoms) && (diff_names == other.diff_names));
	}
	friend Polynom<T> operator* (const Monom<T>& monom, const Polynom<T>& polynom)
	{
		return polynom * monom;
	}
	friend Polynom<T> operator* (const T& scalar, const Polynom<T>& polynom)
	{
		return polynom * scalar;
	}
	friend std::ostream& operator<<(std::ostream& stream, const Polynom<T>& other) {
		for (Iterator<Monom<T>> it = other.list_of_monoms.begin(); it != other.list_of_monoms.end(); it++)
		{
			auto degrees = (*it).GetDegrees();
			if ((*it).GetCoef() >= 0)
				stream << "+" << (*it).GetCoef();
			else
				stream << (*it).GetCoef();
			for (size_t i = 0; i < degrees.size(); i++)
			{
				stream << other.diff_names[i] << '^' << degrees[i];
			}
		}
		return stream;
	}
	Polynom<T> operator*(const Polynom<T>& other) const;
	Polynom<T> operator+(const Polynom<T>& other) const;
	Polynom<T> operator*(const Monom<T>& monom) const;
	Polynom<T> operator+(const Monom<T>& monom) const;
	Polynom<T> operator*(const T& koef) const;
	Polynom<T> operator/(const T& koef) const;
	Polynom<T> operator-(const Polynom<T>& polynom) const;
	Polynom<T> operator-(const Monom<T>& monom) const;
	int MaxDegree(size_t index);
	int MinDegree(size_t index);
};

template<typename T>
inline int Polynom<T>::position(const std::string& word)
{
	for (size_t i = 0; i < word.size(); i++) {
		if (diff_names[i] == word) {
			return i;
		}
	}
	return -1;
}

template<typename T>
inline int Polynom<T>::MonomDegree(const Monom<T>& monom, const std::string& word){
	int pos = position(word);
	if (pos > -1) {
		return monom[pos];
	}
	throw std::out_of_range("This symbol does not exist in this monom");
}


template<typename T>
inline Polynom<T> Polynom<T>::operator*(const Polynom<T>& other) const{
	SingleLinkedList<Monom<T>> new_list;
	for (Iterator<Monom<T>> Iter1 = list_of_monoms.begin(); Iter1 != list_of_monoms.end(); ++Iter1) {
		for (Iterator<Monom<T>> Iter2 = other.list_of_monoms.begin(); Iter2 != other.list_of_monoms.end(); ++Iter2) {
			new_list.push_back(*Iter1 * (*Iter2));
		}
	}
	return Polynom(new_list, diff_names);
}

template<typename T>
inline Polynom<T> Polynom<T>::operator+(const Polynom<T>& other) const
{
	if (!EqualNames(diff_names, other.GetDiffNames())) {
		throw invalid_argument("Polynoms have different order of variable");
	}
	SingleLinkedList<Monom<T>> new_list;
	SingleLinkedList<Monom<T>> copy_of_polynom(other.list_of_monoms);
	for (Iterator<Monom<T>> it1 = list_of_monoms.begin(); it1 != list_of_monoms.end(); it1++) {
		bool flag = 0;
		for (Iterator<Monom<T>> it2 = copy_of_polynom.begin(); it2 != copy_of_polynom.end(); ) {
			if ((*it1).IsEqualDegrees(*it2)) {
				new_list.push_back((*it1) + (*it2));
				copy_of_polynom.pop_front();
				flag = 1;
				break;
			}
			else {
				it2++;
			}
		}
		if (!flag) {
			new_list.push_back(*it1);
		}
	}
	for (Iterator<Monom<T>> it2 = copy_of_polynom.begin(); it2 != copy_of_polynom.end(); it2++) {
		new_list.push_back(*it2);
	}
	return Polynom(new_list, diff_names);

	
}

template<typename T>
inline Polynom<T> Polynom<T>::operator*(const Monom<T>& monom) const
{
	SingleLinkedList<Monom<T>> new_list;
	for (Iterator<Monom<T>> Iter1 = list_of_monoms.begin(); Iter1 != list_of_monoms.end(); ++Iter1) {
		new_list.push_front(*Iter1 * (monom)); 
	}
	return Polynom<T>(new_list, diff_names);
}

template<typename T>
inline Polynom<T> Polynom<T>::operator+(const Monom<T>& monom) const
{
	SingleLinkedList<Monom<T>> new_list(*this);
	new_list.push_front(monom);
	return Polynom<T>(new_list, diff_names);
}

template<typename T>
inline Polynom<T> Polynom<T>::operator*(const T& koef) const
{
	SingleLinkedList<Monom<T>> new_list;
	for (Iterator<Monom<T>> Iter1 = list_of_monoms.begin(); Iter1 != list_of_monoms.end(); ++Iter1) {
		new_list.push_front(*Iter1 * koef);
	}
	return Polynom<T>(new_list, diff_names);
}

template<typename T>
inline Polynom<T> Polynom<T>::operator/(const T& koef) const
{
	SingleLinkedList<Monom<T>> new_list;
	for (Iterator<Monom<T>> Iter1 = list_of_monoms.begin(); Iter1 != list_of_monoms.end(); ++Iter1) {
		new_list.push_front(*Iter1 / koef);
	}
	return Polynom<T>(new_list, diff_names);
}

template<typename T>
inline Polynom<T> Polynom<T>::operator-(const Polynom<T>& other) const
{
	if (!EqualNames(diff_names, other.GetDiffNames())) {
		throw invalid_argument("Polynoms have different order of variable");
	}
	SingleLinkedList<Monom<T>> new_list;
	SingleLinkedList<Monom<T>> copy_of_polynom(other.list_of_monoms);
	for (Iterator<Monom<T>> it1 = list_of_monoms.begin(); it1 != list_of_monoms.end(); it1++) {
		bool flag = 0;
		for (Iterator<Monom<T>> it2 = copy_of_polynom.begin(); it2 != copy_of_polynom.end(); ) {
			if ((*it1).IsEqualDegrees(*it2)) {
				new_list.push_back((*it1) - (*it2));
				copy_of_polynom.pop_front();
				flag = 1;
				break;
			}
			else {
				it2++;
			}
		}
		if (!flag) {
			new_list.push_back(*it1);
		}
	}
	for (Iterator<Monom<T>> it2 = copy_of_polynom.begin(); it2 != copy_of_polynom.end(); it2++) {
		new_list.push_back(*it2 *T(-1));
	}
	return Polynom(new_list, diff_names);

}

template<typename T>
inline Polynom<T> Polynom<T>::operator-(const Monom<T>& monom) const
{
	SingleLinkedList<Monom<T>> new_list(*this);
	new_list.push_front(monom * (-1));
	return Polynom<T>(new_list, diff_names);
}

template<typename T>
inline int Polynom<T>::MaxDegree(size_t index) 
{
	int max = INT_MIN;
	for (Iterator<Monom<T>> Iter1 = list_of_monoms; Iter1 != list_of_monoms.end(); Iter1++) {
		int Degree = (*Iter1).GetDegree(index);
		if (max < Degree) {
			max = Degree;
		}
	}
	return max;
}

template<typename T>
inline int Polynom<T>::MinDegree(size_t index)
{	
	int min = INT_MAX;
	for (Iterator<Monom<T>> Iter1 = list_of_monoms; Iter1 != list_of_monoms.end(); Iter1++) {
		int Degree = (*Iter1).GetDegree(index);
		if (min > Degree) {
			min = Degree;
		}
	}
	return min;
}






