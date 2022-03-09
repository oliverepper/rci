//
// Created by Oliver Epper on 09.03.22.
//

#ifndef RUNTIMECONEPTIDIOM_CHAPTER0_LIBRARY_H
#define RUNTIMECONEPTIDIOM_CHAPTER0_LIBRARY_H

#include <iostream>
#include <vector>

using namespace std;

using object_t = int;
using document_t = vector<object_t>;

void draw(const object_t& x, ostream& out, size_t position) {
    out << string(position, ' ') << x << endl;
}

void draw(const document_t& x, ostream& out, size_t position) {
    out << string(position, ' ') << "<document>" << endl;
    for (const auto& e: x) draw(e, out, position + 2);
    out << string(position, ' ') << "</document>" << endl;
}
#endif //RUNTIMECONEPTIDIOM_CHAPTER0_LIBRARY_H
