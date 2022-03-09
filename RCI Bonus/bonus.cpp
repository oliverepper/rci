//
// Created by Oliver Epper on 09.03.22.
//

#include "bonus_library.h"
#include <thread>
#include <future>

struct person_t {
    string name;
};

void draw(const person_t& x, ostream& out, size_t position) {
    out << string(position, ' ') << "Person<" << x.name << ">" << endl;
}

int main() {
    document_t document;

    history_t h(1);
    cout << "created" << endl;

    commit(h);
    cout << "committed" << endl;

    current(h).emplace_back(person_t{ .name = "Aaron"} );
    cout << "added Aaron" << endl;

    draw(current(h), cout, 0);

    auto saving = async([document = current(h)]() {
        this_thread::sleep_for(chrono::seconds(10));
        cout << "--- saved ---" << endl;
        draw(document, cout, 0);
        cout << "--- saved end ---" << endl;
    });

    undo(h);
    cout << "reverted changes" << endl;
    draw(current(h), cout, 0);

    return EXIT_SUCCESS;
}