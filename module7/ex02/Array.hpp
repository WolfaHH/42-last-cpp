#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
public:
    Array();
    Array(unsigned int n);
    Array(const Array &copy);
    ~Array();
    Array &operator=(const Array &copy);
    T &operator[](unsigned int index);
    unsigned int size() const;

private:
    T *_array;
    unsigned int _size;

    class OutOfRangeException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Out of range";
        }
    };
};

template <typename T>
Array<T>::Array()
{
    _array = NULL;
    _size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _array = new T[n];
    _size = n;
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    _array = new T[copy._size];
    _size = copy._size;
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array()
{
    if (_array)
        delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (_array)
        delete[] _array;
    _array = new T[copy._size];
    _size = copy._size;
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = copy._array[i];
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfRangeException();
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

#endif