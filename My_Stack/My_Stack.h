#pragma once

#include <iostream>

template <typename T>
class MyStack
{
public:
    MyStack();
    ~MyStack();
    MyStack(const MyStack &);
    MyStack operator=(const MyStack &);

    bool empty() const;
    void pop();
    void push(T &);
    void push(T &&);
    std::size_t size() const;
    T &top();

    void Print();

private:
    T *stackPtr;
    std::size_t stackSize;
};

#include "My_Stack.cpp"