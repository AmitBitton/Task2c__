//amiteste.bitton@msmail.ariel.ac.il
// Created by amit on 4/24/25.
//
#include "SquareMat.h"
#include <iostream>

using namespace matrix;

int main() {

  SquareMat A(3);
  SquareMat B(3);

  int number1 = 1;
  int number2 = 2;

  for (int row = 0; row < A.getSize() ; row++) {
    for (int col = 0; col < A.getSize() ; col++) {
      A[row][col] = number1;
      B[row][col] = number2;
      number1++;
    }
  }

  std::cout << "Matrix A:\n\n" << A << "\n\n";

  std::cout << "Matrix B:\n\n" << B << "\n\n";

  std::cout << "A + B:\n\n" << (A + B) << "\n\n";

  std::cout << "A - B:\n\n" << (A - B) << "\n\n";

  std::cout << "-A:\n\n" << (-A) << "\n\n";

  std::cout << "A * B:\n\n" << (A * B) << "\n\n";

  std::cout << "A * 2:\n\n" << (A*2) << "\n\n";

  std::cout << "2 * A:\n\n" << (2*A) << "\n\n";

  std::cout << "A % B:\n\n" << (A%B) << "\n\n";

  std::cout << "A % 2:\n\n" << (A%2) << "\n\n";

  std::cout << "B % 2:\n\n" << (B%2) << "\n\n";

  std::cout << "A / 2:\n\n" << (A/2) << "\n\n";

  std::cout << "B / 2:\n\n" << (B/2) << "\n\n";

  std::cout << "A ^ 2:\n\n" << (A^2) <<"\n\n";

  std::cout << "B ^ 2:\n\n" << (B^2) << "\n\n";

  std::cout << "++A:\n\n" << (++A) << "\n\n";

  std::cout << "A++:\n\n" << (A++) << "\n\n";

  std::cout << "--A:\n\n" << (--A) << "\n\n";

  std::cout << "A--:\n\n" << (A--) << "\n\n";

  std::cout << "B--:\n\n" << (B--) << "\n\n";

  std::cout << "--B:\n\n" << (--B) << "\n\n";

  std::cout << "~A (transpose):\n\n" << (~A) << "\n\n";

  std::cout << "~B (transpose):\n\n" << (~B) << "\n\n";

  std::cout << "A == B: " << (A == B) << "\n\n";

  std::cout << "A != B: " << (A != B) << "\n\n";

  std::cout << "A < B: " << (A < B) << "\n\n";

  std::cout << "A <= B: " << (A <= B) << "\n\n";

  std::cout << "A > B: " << (A > B) << "\n\n";

  std::cout << "A >= B: " << (A >= B) << "\n\n";

  std::cout << "Determinant of A: " << !A << "\n\n";

  std::cout << "Determinant of B: " << !B << "\n\n";

  A += B;
  std::cout << "A += B:\n\n" << A << "\n\n";

  A -= B;
  std::cout << "A -= B:\n\n" << A << "\n\n";

  A *= 2;
  std::cout << "A *= 2:\n\n" << A << "\n\n";

  A /= 2;
  std::cout << "A /= 2:\n\n" << A << "\n\n";

  A %= 5;
  std::cout << "A %= 5:\n\n" << A << "\n\n";

  A %= B;
  std::cout << "A %= B:\n\n" << A << "\n\n";


  std::cout << "A[1][1] before = " << A[1][1] << "\n\n";
  A[1][1] = 114;
  std::cout << "A[1][1] after = " << A[1][1] << "\n\n";
  std::cout << "Matrix A:\n" << A << std::endl;


return 0;
}
