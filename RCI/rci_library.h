//
// Created by Oliver Epper on 09.03.22.
//

#ifndef RUNTIMECONEPTIDIOM_RCI_LIBRARY_H
#define RUNTIMECONEPTIDIOM_RCI_LIBRARY_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>void draw(const T&, ostream&, size_t);

class object_t {
public:
    template<typename T> object_t(T x) : self_(make_unique<model<T>>(move(x))) {}

    // copy ctor
    object_t(const object_t& x) : self_(x.self_->copy_()) {}

    // copy assignment
    object_t& operator=(const object_t& x) {
        return *this = object_t(x);
    }

    // move ctor
    object_t(object_t&&) = default;

    // move assignment
    object_t& operator=(object_t&&) noexcept = default;

    friend void draw(const object_t&, ostream&, size_t);
private:
    struct drawable_t {
        virtual ~drawable_t() = default;
        [[nodiscard]] virtual unique_ptr<drawable_t> copy_() const = 0;
        virtual void draw_(ostream&, size_t) const = 0;
    };

    template<typename T> struct model final: drawable_t {
        explicit model(T x) : data_(move(x)) {}
        void draw_(ostream& out, size_t position) const override {
            draw(data_, out, position);
        }
        [[nodiscard]] unique_ptr<drawable_t> copy_() const override {
            return make_unique<model>(*this);
        }
        T data_;
    };

    unique_ptr<drawable_t> self_;
};

using document_t = vector<object_t>;

template<typename T> void draw(const T& x, ostream& out, size_t position) {
    out << string(position, ' ') << x << endl;
}

void draw(const object_t& x, ostream& out, size_t position) {
    x.self_->draw_(out, position);
}

void draw(const document_t& x, ostream& out, size_t position) {
    out << string(position, ' ') << "<document>" << endl;
    for (const auto& e: x) draw(e, out, position + 2);
    out << string(position, ' ') << "</document>" << endl;
}

#endif //RUNTIMECONEPTIDIOM_RCI_LIBRARY_H
