//
// Created by Oliver Epper on 09.03.22.
//

#ifndef RUNTIMECONEPTIDIOM_TYPE_LIBRARY_H
#define RUNTIMECONEPTIDIOM_TYPE_LIBRARY_H

#include <iostream>

using namespace std;

class reference_t {
public:
    reference_t(int x) : data(make_shared<int>(move(x))) {}

    friend void dump(const reference_t& x)
    { cout << *x.data << endl; }

    friend void change(const reference_t& x, int n)
    { *x.data = n; }
private:
    shared_ptr<int> data;
};

class value_t {
public:
    value_t(int x) : data(make_unique<int>(move(x))) {}

    // copy constructor, 2nd step necessary because of unique_ptr
    value_t(const value_t& x) : data(make_unique<int>(*x.data)) {}

    // copy assigment, 3rd step
    value_t& operator=(const value_t& x) {
        return *this = value_t(x);
    }

    // move constructor
    value_t(value_t&&) = default;

    // move assigment
    value_t& operator=(value_t&&) noexcept = default;

    friend void dump(const value_t& x)
    { cout << *x.data << endl; }

    friend void change(const value_t& x, int n)
    { *x.data = n; }
private:
    unique_ptr<int> data; // START HERE!
};

#endif //RUNTIMECONEPTIDIOM_TYPE_LIBRARY_H
