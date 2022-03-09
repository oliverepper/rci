//
// Created by Oliver Epper on 09.03.22.
//

#include <iostream>

using namespace std;

class riddle_t {
public:
    riddle_t(int x) : data(make_unique<int>(move(x))) {
//        cout << "ctor" << endl;
    }
private:
    unique_ptr<int> data;
};

riddle_t func(int x) {
    riddle_t r(x);
    return r;
}

int main() {
    riddle_t r = func(0);

    return EXIT_SUCCESS;
}