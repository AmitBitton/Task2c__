//amiteste.bitton@msmail.ariel.ac.il
// Created by amit on 4/17/25.
//

#include "SquareMat.h"
#include <cmath>
#include <iostream>

namespace matrix {

SquareMat::SquareMat(int n) :size(n) {
 if (n<=0) {
  throw std::invalid_argument("SquareMat::SquareMat n must be positive");
 }
 data = new double*[size];
 for (int i = 0; i < size; i++) {
  data[i] = new double[size];
   for (int j = 0; j < size; j++) {
    data[i][j] = 0.0;
  }
 }
}


SquareMat::SquareMat(const SquareMat &other) : size(other.size) {
 data = new double*[size];
  for (int i = 0; i < size; i++) {
   data[i] = new double[size];
    for (int j = 0; j < size; j++) {
      data[i][j] = other.data[i][j];
  }
 }
}


SquareMat::~SquareMat() {
 if (data != nullptr) {
  for (int i = 0; i < size; i++) {
   delete[] data[i];
  }
  delete[] data;
 }
}


SquareMat& SquareMat:: operator=(const SquareMat &other) {
 if (this == &other) {
  return *this;
 }
 for (int i = 0; i < size; i++) {
  delete[] data[i];
 }
 delete[] data;
 size = other.size;
 data = new double*[size];
 for (int i = 0; i < size ; i++) {
  data[i] = new double[size];
  for (int j = 0; j < size; j++) {
   data[i][j] = other.data[i][j];
  }
 }
 return *this;
}



 int SquareMat::getSize() const {
 return size;
}


SquareMat SquareMat::operator+(const SquareMat &other) const {
if (size!=other.size) {
 throw std::invalid_argument("Matrix sizes must be equal for add action");
}
 SquareMat result(size);
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   result.data[i][j] = this->data[i][j] + other.data[i][j];
  }
 }
 return result;
}


SquareMat SquareMat::operator-(const SquareMat &other) const {
 if (size!=other.size) {
  throw std::invalid_argument("Matrix sizes must be equal for subtraction");
 }
 SquareMat result(size);
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   result.data[i][j] = this->data[i][j] - other.data[i][j];
  }
 }
 return result;
}


 SquareMat SquareMat::operator-() const {
 SquareMat result(size);
 for (int i = 0; i < size ; ++i) {
  for (int j = 0; j < size; ++j) {
   result.data[i][j] = -data[i][j];
  }
 }
 return result;
}


SquareMat SquareMat::operator*(const SquareMat &other) const {
if (size!=other.size) {
 throw std::invalid_argument("Matrix sizes must be equal for multiplication");
}
 SquareMat result(size);
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   result.data[i][j] = 0;
   for (int k = 0; k < size; ++k) {
    result.data[i][j] += data[i][k] * other.data[k][j];
   }
  }
 }
 return result;
}


 SquareMat SquareMat::operator*(double scalar) const {
 SquareMat result(size);
 for (int i = 0; i < size ; ++i) {
  for (int j = 0; j < size; ++j) {
   result.data[i][j] = this->data[i][j] * scalar;
  }
 }
 return result;
}


 SquareMat operator*(double scalar, const SquareMat& mat) {
 return mat * scalar;
}


SquareMat SquareMat::operator%(const SquareMat& other) const {
if (size!=other.size) {
 throw std::invalid_argument("Matrix sizes must be equal for element-wise multiplication");
}
SquareMat result(size);
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   result.data[i][j] = this->data[i][j] * other.data[i][j];
  }
 }
return result;
}


SquareMat SquareMat::operator%(int scalar) const {
 if (scalar == 0) {
  throw std::invalid_argument("Modulo by zero is undefined");
 }
 SquareMat result(size);
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   result.data[i][j] = std::fmod(data[i][j], scalar);
  }
 }
 return result;
}


SquareMat SquareMat::operator/(double scalar) const {
 if (scalar == 0) {
  throw std::invalid_argument("Divide by zero is undefined");
 }
 SquareMat result(size);
 for (int i = 0; i < size ; ++i) {
  for (int j = 0; j < size; ++j) {
   result.data[i][j] = this->data[i][j] / scalar;
  }
 }
 return result;
}


SquareMat SquareMat::operator^(int exponent) const {
 if (exponent < 0) { //לא כל מטריצה היא בהכרח הפיכה אז אי אפשר לעשות חזקה שלילית אלא אם נבדוק הפיכות  ולכן שמתי בדיקת חריגה
  throw std::invalid_argument("Negative exponents not supported");
 }

 SquareMat result(size);
 for (int i = 0; i < size; ++i) { //identify matrix
  result.data[i][i]=1.0;
 }

if (exponent == 0) {
 return result;
}

SquareMat base(*this);
 while (exponent > 0) {
  if (exponent % 2 == 1) {
   result = result * base;
  }
  base = base * base;
  exponent /= 2;
 }

 return result;
}

//pre increment
SquareMat& SquareMat::operator++() {
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   data[i][j] = data[i][j] + 1.0;
  }
 }
 return *this;
}


//post increment
SquareMat SquareMat::operator++(int ) {
 SquareMat copy(*this);
++(*this);
 return copy;
}

//pre increment
SquareMat& SquareMat::operator--() {
for (int i = 0; i < size; ++i) {
 for (int j = 0; j < size; ++j) {
  data[i][j] = data[i][j] - 1.0;
 }
}
return *this;
}

 //post increment
SquareMat SquareMat::operator--(int) {
 SquareMat copy(*this);
 --(*this);
 return copy;
}



SquareMat SquareMat::operator~() const {
 SquareMat transposed(size);
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   transposed.data[j][i] = this->data[i][j];
  }
 }
 return transposed;
}


 SquareMat::RowProxy SquareMat::operator[](int row) {
  if (row < 0 || row >= size) {
   throw std::invalid_argument("Row index out of bounds");
  }
  return RowProxy(data[row], size);
}



 const SquareMat::RowProxy SquareMat::operator[](int row) const {
  if (row < 0 || row >= size) {
   throw std::invalid_argument("Row index out of bounds");
  }
  return RowProxy(data[row], size);
}



double SquareMat::sumElemnts() const {
 double sum = 0.0;
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   sum = sum + data[i][j];
  }
 }
 return sum;
}


 bool SquareMat::operator==(const SquareMat& other) const {
   return this->sumElemnts() == other.sumElemnts();
}



 bool SquareMat::operator!=(const SquareMat& other) const {
  return !(*this == other);
}


bool SquareMat::operator<(const SquareMat& other) const {
 return this->sumElemnts() < other.sumElemnts();
}


 bool SquareMat::operator<=(const SquareMat& other) const {
  return !(other<*this);
}


 bool SquareMat::operator>(const SquareMat& other) const {
  return other < *this;
}


 bool SquareMat::operator>=(const SquareMat& other) const {
  return !(*this < other);
}



double SquareMat::operator!() const {

 //first case : 1X1 matrix
 if ( size == 1) {
  return data[0][0];
 }

 //second case : 2X2 matrix
 if (size == 2) {
  return data[0][0] * data[1][1] - data[0][1] * data[1][0];
 }

 //third case nXn matrix
 double determinant = 0.0;
 for (int j = 0; j < size; ++j) {
   SquareMat minor(size-1);

  for (int row = 1; row < size; ++row) {
   int colIndex =0 ;
    for (int col = 0; col < size; ++col) {
      if (col == j) continue;
      minor[row-1][colIndex] = data[row][col];
      colIndex++;
   }
  }

 double cofactor = ((j%2 == 0) ? 1.0 : -1.0) * data[0][j];
  determinant += cofactor * !minor;
 }
 return determinant;
}



SquareMat& SquareMat::operator+=(const SquareMat& other) {
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   this->data[i][j] += other.data[i][j];
  }
 }
 return *this;
}


 SquareMat& SquareMat::operator-=(const SquareMat& other) {
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   this->data[i][j] -= other.data[i][j];
  }
 }
 return *this;
}



SquareMat& SquareMat::operator*=(double scalar) {
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   this->data[i][j] *= scalar;
  }
 }
 return *this;
}



 SquareMat& SquareMat::operator*=(const SquareMat& other) {
 if (size != other.size) {
  throw std::invalid_argument("Matrix sizes must be equal for multiplication");
 }
 *this = *this * other;
 return *this;

}

 SquareMat& SquareMat::operator/=(double scalar) {
 if (scalar == 0.0) {
  throw std::invalid_argument("Divide by zero is undefined");
 }
 for (int i = 0; i < size; ++i) {
   for (int j = 0; j < size; ++j) {
    this->data[i][j] /= scalar;
   }
 }
return *this;
}




 SquareMat& SquareMat::operator%=(const SquareMat& other) {
if (size != other.size) {
 throw std::invalid_argument("Matrix sizes must be equal for multiplication");
}
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   this->data[i][j] *= other.data[i][j];
  }
 }
 return *this;
}



 SquareMat& SquareMat::operator%=(int scalar) {
 if (scalar == 0) {
  throw std::invalid_argument("Modulo by zero is undefined");
 }
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   this->data[i][j] = std::fmod(this->data[i][j], scalar);
  }
 }
 return *this;
}


 std::ostream& operator<<(std::ostream &os, const SquareMat &mat) {
  for (int i =0 ; i<mat.size ; ++i ) {
   os <<"[";
   for (int j = 0; j < mat.size ; ++j) {
    os << mat.data[i][j] << " ";
    if (j < mat.size - 1) {
     os << " ";
    }
   }
   os << "] ";
   if (i < mat.size - 1) {
    os << std::endl;
   }
  }
 return os;
 }

}