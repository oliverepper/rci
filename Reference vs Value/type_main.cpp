//
// Created by Oliver Epper on 09.03.22.
//

#include "type_library.h"

int main() {
    reference_t r1(5);
    dump(r1);

    reference_t r2(r1);
    dump(r2);

    reference_t r3(0);
    r3 = r1;
    dump(r3);

    change(r2, 12); cout << "change" << endl;

    dump(r1);
    dump(r2);
    dump(r3);

    cout << endl;

    value_t v1(15);
    dump(v1);

    value_t v2(v1); // geht erstmal nicht!
    dump(v2);

    value_t v3(0); // geht erstmal nicht!
    v3 = v1;
    dump(v3);

    change(v2, 25); cout << "change" << endl;

    dump(v1);
    dump(v2);
    dump(v3);

    return EXIT_SUCCESS;
}