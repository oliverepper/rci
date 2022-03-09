//
// Created by Oliver Epper on 09.03.22.
//

#include "chapter0_library.h"

int main() {
    document_t document;

    document.push_back(1);
    document.push_back(2);
    document.push_back(3);

    draw(document, cout, 0);

    return EXIT_SUCCESS;
}