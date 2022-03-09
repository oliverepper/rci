//
// Created by Oliver Epper on 09.03.22.
//

#ifndef RUNTIMECONEPTIDIOM_EVIL_LIBRARY_H
#define RUNTIMECONEPTIDIOM_EVIL_LIBRARY_H

#include <iostream>
#include <vector>

using namespace std;

class object_t {
public:
    virtual ~object_t() = default;
    virtual void draw(ostream&, size_t) const = 0;
};

using document_t = vector<shared_ptr<object_t>>; // this is really bad!

void draw(const document_t& x, ostream& out, size_t position) {
    out << string(position, ' ') << "<document>" << endl;
    for (const auto& e: x) e->draw(out, position + 2);
    out << string(position, ' ') << "</document>" << endl;
}
#endif //RUNTIMECONEPTIDIOM_EVIL_LIBRARY_H
