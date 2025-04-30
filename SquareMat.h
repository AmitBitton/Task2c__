//amiteste.bitton@msmail.ariel.ac.il
// Created by amit on 4/17/25.
//

#ifndef SQUAREMAT_H
#define SQUAREMAT_H
#include <stdexcept>
#include <iostream>

namespace matrix{

class SquareMat {
private:
    int size; // the size of the matrix
    double** data; // array to present the matrix

    double sumElemnts() const; //private helper function

    class RowProxy {
    private:
        double* row;
        int size;

    public:
        RowProxy(double* row, int size) : row(row), size(size) {}

        double& operator[](int col) {
            if (col < 0 || col >= size) {
                throw std::invalid_argument("Column index out of bounds");
            }
            return row[col];
        }

        const double& operator[](int col) const {
            if (col < 0 || col >= size) {
                throw std::invalid_argument("Column index out of bounds");
            }
            return row[col];
        }
    };

public:
    SquareMat(int n);
    SquareMat(const SquareMat& other); //copy constructor (the rule of free)
    ~SquareMat(); //deconstructor (the rule of free)
    SquareMat& operator=(const SquareMat& other); // opertor = (the rule of free)

    SquareMat operator+(const SquareMat& other) const; //add
    SquareMat operator-(const SquareMat& other) const; //sub
    SquareMat operator-() const; //unari -
    SquareMat operator*(const SquareMat& other) const; //multipication
    SquareMat operator*(double scalar) const; // matrix * scalar
    friend SquareMat operator*(double scalar, const SquareMat& mat); // scalar * matrix
    SquareMat operator%(const SquareMat& other) const; //element-wise multiplication
    SquareMat operator%(int scalar) const; //modolu by scalar
    SquareMat operator/(double scalar) const; //scalar division
    SquareMat operator^(int exponent) const; //power
    SquareMat& operator++(); //pre increment
    SquareMat& operator--(); //pre increment
    SquareMat operator++(int); //post increment
    SquareMat operator--(int); //post increment
    SquareMat operator~() const; //transpose
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator%=(int scalar);


    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat); // output


    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;
    RowProxy operator[](int row);
    const RowProxy operator[](int row) const;


    double operator!() const; //determinant
    int getSize() const;
};

};



#endif //SQUAREMAT_H
