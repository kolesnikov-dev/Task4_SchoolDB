#include "My_Stack.h"

template <typename T>
void MyStack<T>::Print()
{
    for (auto i = 0; i < stackSize; ++i)
    {
        std::cout << stackPtr[i] << " ";
    }
}

template <typename T>
MyStack<T>::MyStack()
{
    stackPtr = nullptr;
    stackSize = 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
    if (stackPtr != nullptr)
        delete stackPtr;
}

template <typename T>
MyStack<T>::MyStack(const MyStack &stackToCopy)
{
    stackSize = stackToCopy.stackSize;

    stackPtr = new T[stackSize];

    for (auto i = 0; i < stackSize; ++i)
        stackPtr[i] = stackToCopy.stackPtr[i];
}

template <typename T>
MyStack<T> MyStack<T>::operator=(const MyStack &stackToCopy)
{
    if (stackSize != 0)
    {
        stackSize = 0;
        delete[] stackPtr;
    }

    stackSize = stackToCopy.stackSize;

    stackPtr = new T[stackSize];

    for (auto i = 0; i < stackSize; ++i)
        stackPtr[i] = stackToCopy.stackPtr[i];

    return *this;
}

template <typename T>
bool MyStack<T>::empty() const
{
    return (stackSize == 0);
}

template <typename T>
void MyStack<T>::pop()
{
    if (stackSize != 0)
        stackSize--;
}

template <typename T>
void MyStack<T>::push(T &value)
{
    ++stackSize;
    T *newStackPtr = new T[stackSize];

    for (auto i = 0; i < stackSize - 1; ++i)
        newStackPtr[i] = stackPtr[i];

    newStackPtr[stackSize - 1] = value;

    if (stackPtr != nullptr)
        delete stackPtr;

    stackPtr = newStackPtr;
}

template <typename T>
void MyStack<T>::push(T &&value)
{
    ++stackSize;
    T *newStackPtr = new T[stackSize];

    for (auto i = 0; i < stackSize - 1; ++i)
        newStackPtr[i] = stackPtr[i];

    newStackPtr[stackSize - 1] = value;

    if (stackPtr != nullptr)
        delete stackPtr;

    stackPtr = newStackPtr;
}

template <typename T>
size_t MyStack<T>::size() const
{
    return stackSize;
}

template <typename T>
T &MyStack<T>::top()
{
    if (stackSize != 0)
        return stackPtr[stackSize - 1];
    else
    {
        std::cerr << "Stack is empty, so there is no element on top" << std::endl;
        throw std::exception();
    }
}