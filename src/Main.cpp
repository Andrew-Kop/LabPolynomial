#include"Polynom.hpp"
#include <iostream>
#include <vector>

int main() {
    // Define variable names for polynomials
    std::vector<std::string> variables = { "x", "y", "z" };

    // Define monomials
    Monom<int> monom1(5, { 1, 2, 3 });
    Monom<int> monom2(3, { 2, 3, 4 });
    Monom<int> monom3(2, { 1, 1, 1 });

    // Create polynomials
    SingleLinkedList<Monom<int>> list1;
    list1.push_back(monom1);
    list1.push_back(monom2);

    SingleLinkedList<Monom<int>> list2;
    list2.push_back(monom2);
    list2.push_back(monom3);

    Polynom<int> poly1(list1, variables);
    Polynom<int> poly2(list2, variables);

    // Test printing polynomials
    std::cout << "Polynomial 1: " << poly1 << std::endl;
    std::cout << "Polynomial 2: " << poly2 << std::endl;

    // Test arithmetic operations
    Polynom<int> sum = poly1 + poly2;
    std::cout << "Sum: " << sum << std::endl;

    Polynom<int> difference = poly1 - poly2;
    std::cout << "Difference: " << difference << std::endl;

    Polynom<int> product = poly1 * poly2;
    std::cout << "Product: " << product << std::endl;

    return 0;
}



//
//int main() {
//    // Creating nodes
//    Node<int> node1(1);
//    Node<int> node2(2);
//	Node<int> node3(3);
//	Node<int> node4(4);
//
//    // Linking nodes
//    node1.Setptr(&node2);
//    node2.Setptr(&node3);
//	node3.Setptr(&node4);
//
//    // Creating an iterator starting at node1
//    Iterator<int> it(&node1); // 1 2 3 
//	
//	cout << (++it).Getindex()->GetData() << endl;
//	cout << (it++).Getindex()->GetData() << endl;
//	cout << (it + 2).Getindex()->GetData() << endl;
//
//
//    //// Iterating through the nodes
//    //for (Node<int>* current = it.Getindex(); current != nullptr; current = current->Getptr()) {
//    //    std::cout << "Node data: " << current->GetData() << std::endl;
//    //}
//
//    return 0;
//
//}


//int main()
//{
//
//	setlocale(LC_ALL, "ru");
//
//
//	SingleLinkedList<int> lst;
//	lst.push_front(5);
//	lst.push_front(7);
//	lst.push_front(101);
//
//	for (int i = 0; i < lst.GetSize(); i++)
//	{
//		cout << lst[i] << endl;
//	}
//
//	cout << endl << "pop_back " << endl << endl;
//
//	lst.pop_back();
//	lst.insert(5, 2);
//
//	for (int i = 0; i < lst.GetSize(); i++)
//	{
//		cout << lst[i] << endl;
//	}
//
//	return 0;
//}