#include "../inc/vec_class_temp.hpp"

int main()
{
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    std::cout << "Vector size is: " << v.size() << std::endl;
    std::cout << "Vector capacity is: " << v.capacity() << std::endl;
 
    std::cout << "Vector elements is: ";
    v.print();
 
    v.push_back(100);
    std::cout << '\n';
    std::cout << "Vector elements is: ";
    v.print();
    
    v.pop_back(); 
    std::cout << "\nAfter deleting last element" << std::endl;
 
    std::cout << "Vector size is: " << v.size() << std::endl;
    std::cout << "Vector capacity is: " << v.capacity() << std::endl;
 
    std::cout << "Vector elements is: ";
    v.print();

 
    return 0;
}



