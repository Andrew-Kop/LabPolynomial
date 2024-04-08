#pragma once
#include <vector>
#include <stdexcept>

using namespace std;
template <typename T>
class Monom {
private:
	vector<int> degrees;
	T coef;
public:
	Monom(const T coef = T(), vector<int> degrees = nullptr): coef(coef), degrees(degrees){}
	Monom(const Monom<T>& other) {
		this->degrees = other.degrees;
		this->coef = other.coef;
	}
	std::vector<int> GetDegrees() {
		return degrees;
	}
	int GetDegree(size_t index) {
		return degrees[index];
	}
	T& GetCoef() {
		return coef;
	}
	void SetDegrees(const vector<int> degrees) {
		this->degrees = degrees;
	}
	void SetCoef(const T& coef)  {
		this->coef = coef;
	}
	bool IsEqualDegrees(const vector<int>& degrees) const; 
	bool IsEqualDegrees(const Monom<T>& monom) const;
	int operator[](const size_t index);
	Monom<T> operator+(const Monom<T>& other) const;
	Monom<T> operator-(const Monom<T>& other) const;
	Monom<T> operator*(const Monom<T>& other) const;
	Monom<T> operator*(const T& coef) const;
	Monom<T> operator/(const T& coef) const;
	bool operator==(const Monom<T>& other);
	bool operator!=(const Monom<T>& other);
	void operator=(const Monom<T>& other);
	friend Monom<T> operator*(const T& konst, Monom<T>& other);
	friend Monom<T> operator/(const T& konst, Monom<T>& other);
};




template<typename T>
bool Monom<T>::IsEqualDegrees(const vector<int>& degrees) const
{
	if (this->degrees.size() != degrees.size()) {
		return 0;
	}
	for (size_t i = 0; i < degrees.size(); i++) {
		if (this->degrees[i] != degrees[i]) {
			return 0;
		}
	}
	return 1;
}

template<typename T>
bool Monom<T>::IsEqualDegrees(const Monom<T>& monom) const
{
	return IsEqualDegrees(monom.degrees);
}

template<typename T>
inline int Monom<T>::operator[](const size_t index)
{
	return degrees[index];
}

template<typename T>
Monom<T> Monom<T>::operator+(const Monom<T>& other) const
{
	if (!IsEqualDegrees(other)) {
		throw invalid_argument("You can't sum monoms with different degrees");
	}
	return Monom<T>(this->coef + other.coef, degrees);
}

template<typename T>
Monom<T> Monom<T>::operator-(const Monom<T>& other) const
{
	if (!IsEqualDegrees(other)) {
		throw invalid_argument("You can't sub monoms with different degrees");
	}
	return Monom<T>(this->coef - other.coef, degrees);
}

template<typename T>
Monom<T> Monom<T>::operator*(const Monom<T>& other) const
{
	size_t max_degree_size = degrees.size() > other.degrees.size() ? degrees.size() : other.degrees.size();
	size_t min_degree_size = degrees.size() < other.degrees.size() ? degrees.size() : other.degrees.size();
	vector<int> new_degree(max_degree_size);
	for (size_t i = 0; i < min_degree_size; i++) {
		new_degree[i] = degrees[i] + other.degrees[i];
	}
	if (degrees.size() < other.degrees.size()) {
		for (size_t i = degrees.size() - 1; i < max_degree_size; i++) {
			new_degree[i] = other.degrees[i];
		}
	}
	else {
		for (size_t i = other.degrees.size() - 1; i < max_degree_size; i++) {
			new_degree[i] = degrees[i];
		}
	}
	return Monom<T>(coef * other.coef, new_degree);
}

template<typename T>
Monom<T> Monom<T>::operator*(const T& coef) const
{
	return Monom<T>(coef * this->coef, degrees);
}

template<typename T>
Monom<T> Monom<T>::operator/(const T& coef) const
{
	return Monom<T>(this->coef / coef, degrees);
}

template<typename T>
bool Monom<T>::operator==(const Monom<T>& other)
{
	return IsEqualDegrees(other) && degrees.size() == other.degrees.size();
}

template<typename T>
bool Monom<T>::operator!=(const Monom<T>& other)
{
	return !(IsEqualDegrees(other) && degrees.size() == other.degrees.size());
}

template<typename T>
void Monom<T>::operator=(const Monom<T>& other)
{
	coef = other.coef;
	degrees = other.degrees;
}

template <typename T>
Monom<T> operator*(const T& konst, Monom<T>& other)
{
	return Monom<T>(other->GetCoef() * konst, other->GetDegrees());
}
template <typename T>
Monom<T> operator/(const T& konst, Monom<T>& other)
{
	return Monom<T>(other->GetCoef() / konst, other->GetDegrees());
}
