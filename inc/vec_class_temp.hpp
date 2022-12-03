#include <iostream>

template <typename T> 
class Vector
{
    private:
        T* m_arr;
        int m_size;
        int m_capacity;
    public:
        void push_back(T);
        T pop_back();
        T top();
        
        void clear();
        void print();
        int size();
        int capacity();
        bool Empty();
        T &operator[](unsigned int);
        Vector &operator=(const Vector<T> &);
        bool operator==(const Vector<T> &);
        
        Vector(): m_arr(new T[m_size]), m_capacity(0), m_size(0)
        {}
    
        ~Vector()
        {
            delete [] m_arr;
        }
};

template <typename T>
void Vector<T>::clear()
{
    delete [] m_arr;
    m_arr = new T[m_capacity];
    m_size = 0;
}

template <typename T>
int Vector<T>::size()
{
    return m_size;
}

template <typename T>
bool Vector<T>::Empty()
{
    return size() == 0;
}

template <typename T>
int Vector<T>::capacity()
{
    return m_capacity;
}

template <typename T>
void Vector<T>::push_back(T elem)
{
    if (m_size == m_capacity)
    {
        if (m_capacity == 0)
        {
            m_capacity = 1;
        }
        T* temp = new T[m_capacity * 2];
        for (int i = 0; i < m_capacity; i++)
        {
            temp[i] = m_arr[i];
        }
        delete [] m_arr;
        m_capacity *= 2;
        m_arr = temp;
    }
    m_arr[m_size] = elem;
    ++m_size;
    std::cout << "Inserting element is: " << elem << '\n';
}

template <typename T>
T Vector<T>::pop_back()
{
    if(Empty())
    {
        std::cout << "Vector is empty\n";
        exit(EXIT_FAILURE);
    }
    std::cout << "Removing element is: " << m_arr[--m_size] << '\n';
    return m_arr[--m_size];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
    if(this != other)
    {
        delete [] m_arr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_arr = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            m_arr[i] = other.m_arr[i];
        }
    }
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &other)
{
    if (this == other)
    {
        return true;
    }
    if (m_size != other.m_size)
    {
        return false;
    }
    for (int i = 0; i < m_size; i++)
    {
        if (m_arr[i] != other.m_arr[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
T &Vector<T>::operator[](unsigned int index)
{
    if (index < 0 || index >= m_size)
    {
        std::cout << "Please enter the valid size of array!\n";
    }
    return m_arr[index];
}

template <typename T>
void Vector<T>::print()
{
    for (int i = 0; i < m_size; i++) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}
