// Copyright 2019 dimakirol <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <exception>
#include <stdexcept>
#include <utility>

using std::out_of_range;
using std::length_error;

template <typename T>
class stack
{
public:
    explicit stack(const int Size)
    {
        bottom = new T [Size];
        top = bottom;
        size = Size;
    }

    explicit stack(stack&& object)
    {
        bottom = object.bottom;
        top = object.top;
        size = object.size;

        object.bottom = nullptr;
        object.top = nullptr;
        object.size = 0;
    }

    ~stack()
    {
        top = nullptr;
        size = 0;
        delete [] bottom;
    }

    void push(const T& value)
    {
        if ((top - bottom) >= size)
        {
            throw length_error("A");
        }
        *top = value;
        ++top;
    }

    void push(T&& value)
    {
        if ((top - bottom) >= size)
        {
            throw length_error("B");
        }
        *top = value;
        value = 0;
        ++top;
    }

    template <typename ... Args>
    void push_emplace(Args &&... value) {
        auto t = (std::forward<Args>(value) &&...);
        for (int i = 0; i < sizeof...(value); ++i)
        {
            push(t[i]);
        }
    }

    T pop(){
        if (((top - 1) < bottom) || ((top - 1) == nullptr))
        {
            throw out_of_range("A");
        }
        --top;
        return *top;
    }

    const T& head() const {
        if ((top - 1) == nullptr)
        {
            throw out_of_range("B");
        }
        return *(top - 1);
    }

private:
    explicit stack(const stack& object);
    stack();

private:
    T* top;
    T* bottom;
    unsigned size;
};

#endif // INCLUDE_HEADER_HPP_
