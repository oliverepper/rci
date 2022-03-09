//
// Created by Oliver Epper on 09.03.22.
//

#include "rci_library.h"

struct person_t {
    string name;
};

void draw(const person_t& x, ostream& out, size_t position) {
    out << string(position, ' ') << x.name << endl;
}

int main() {
    document_t document;

    document.push_back(1);
    document.push_back("Zwei");
    document.push_back(person_t{.name = "Oliver"});

    draw(document, cout, 0);
    return EXIT_SUCCESS;
}