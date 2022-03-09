//
// Created by Oliver Epper on 09.03.22.
//

#include "evil_library.h"

class my_class_t final: public object_t {
public:
    void draw(ostream& out, size_t position) const override {
        out << string(position, ' ') << "my_class_t" << endl;
    }
};


int main() {
    document_t document;

    document.emplace_back(new my_class_t()); // this is a bug!
    document.emplace_back(make_shared<my_class_t>());

    draw(document, cout, 0);
    
    return EXIT_SUCCESS;
}