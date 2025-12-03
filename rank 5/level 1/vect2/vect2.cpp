#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}

vect2::vect2(int num1, int num2) : _x(num1), _y(num2) {}

vect2::vect2(const vect2 &other) : _x(other._x), _y(other._y) {}

vect2 &vect2::operator=(const vect2 &other) {
    if (this != &other)
    {
        _x = other._x;
        _y = other._y;
    }
    return (*this);
}

vect2::~vect2() {}

int vect2::getX() const {
    return _x;
}

int vect2::getY() const {
    return _y;
}

std::ostream &operator<<(std::ostream &output, const vect2 &object) {
    output << "{" << object.getX() << ", " << object.getY() << "}";
    return output;
}

int vect2::operator[](int num) const {
    if (num == 0)
        return _x;
    else
        return _y;
}

int &vect2::operator[](int num) {
    if(num == 0)
        return _x;
    else
        return _y;
}


vect2 &vect2::operator++() {
    _x += 1;
    _y += 1;
    return (*this);
}

vect2 vect2::operator++(int) {
    vect2 temp = *this;
    ++_x;
    ++_y;
    return (temp);
}

vect2 &vect2::operator--() {
    _x -= 1;
    _y -= 1;
    return *this;
}

vect2 vect2::operator--(int) {
    vect2 temp = *this;
    --_x;
    --_y;
    return (temp);
}

vect2 &vect2::operator+=(const vect2 &other) {
    _x += other._x;
    _y += other._y;
    return *this;
}

vect2 &vect2::operator-=(const vect2 &other) {
    _x -= other._x;
    _y -= other._y;
    return *this;
}

vect2 vect2::operator+(const vect2 &other) const {
    vect2 temp = *this;
    temp += other;
    return (temp);
}

vect2 vect2::operator-(const vect2 &other) const {
    vect2 temp = *this;
    temp -= other;
    return (temp);
}

vect2 &vect2::operator*=(int value) {
    _x *= value;
    _y *= value;
    return *this;
}

vect2 vect2::operator*(int value) const {
    vect2 temp = *this;
    temp *= value;
    return (temp);
}

// vect2 vect2::operator*(int value) {
//     vect2 temp = *this;
//     temp *= ;
//     return (temp);
// }

vect2 &vect2::operator-() {
    _x *= -1;
    _y *= -1;
    return *this;
}

// int &vect2::operator=(int value) {
//     if (this[1] != value)
//         this[1] = value;
//     return (this[1]);
// }

bool vect2::operator==(const vect2 &other) const {
    if (_x == other._x && _y == other._y)
        return true;
    return false;
}

bool vect2::operator!=(const vect2 &other) const {
    return !(*this == other);
}

vect2 operator*(int num, const vect2 &other) {
    vect2 temp(other);
    temp *= num;
    return (temp);
}
