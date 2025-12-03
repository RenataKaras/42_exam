#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>

class vect2
{
    private:
        int _x;
        int _y;
    
    public:
        vect2();
        vect2(int num1, int num2);
        vect2(const vect2 &other);
        vect2 &operator=(const vect2 &other);
        ~vect2();

        int getX() const;
        int getY() const;
        
        int operator[](int num) const;
        int &operator[](int num);

        vect2 &operator++(); //++a
        vect2 operator++(int); //a++
        vect2 &operator--(); //--a
        vect2 operator--(int); //a--
        vect2 &operator+=(const vect2 &other);
        vect2 &operator-=(const vect2 &other);
        vect2 operator+(const vect2 &other) const;
        vect2 operator-(const vect2 &other) const;
        vect2 &operator*=(int);
        vect2 operator*(int) const;
        // vect2 operator*(int);
        vect2 &operator-();
        // int &operator=(int);
        bool operator==(const vect2 &other) const;
        bool operator!=(const vect2 &other) const;
};

std::ostream &operator<<(std::ostream &output, const vect2 &object);
vect2 operator*(int num, const vect2 &other);

#endif