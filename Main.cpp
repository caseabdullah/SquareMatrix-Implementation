
#include <iostream>
#include "SMatrix.h"
using namespace std;

int main()
{
    cout << "===== SMatrix Testing =====\n\n";

    // 1. Parameterized Constructor
    SMatrix A{3};

    A.at(1, 1) = 1;
    A.at(1, 2) = 2;
    A.at(1, 3) = 3;

    A.at(2, 1) = 4;
    A.at(2, 2) = 5;
    A.at(2, 3) = 6;

    A.at(3, 1) = 7;
    A.at(3, 2) = 8;
    A.at(3, 3) = 9;

    cout << "Matrix A:\n";
    A.display();

    // 2. Copy Constructor
    SMatrix B(A);

    cout << "\nCopied Matrix B:\n";
    B.display();

    // 3. Addition
    cout << "\nA + B:\n";
    SMatrix C {A.add(B)};
    C.display();

    // 4. Subtraction
    cout << "\nA - B:\n";
    SMatrix D{A.subtract(B)};
    D.display();

    // 5. Transpose
    cout << "\nTranspose of A:\n";
    SMatrix T = A.Transpose();
    T.display();

    // 6. Trace
    cout << "\nTrace of A: " << A.trace() << endl;

    // 7. AntiTrace
    cout << "AntiTrace of A: " << A.antiTrace() << endl;

    // 8. Equality
    cout << "\nA == B: " << (A.isEqual(B)) << endl;

    // 9. Identity Check
    cout << "Is A Identity? " << A.isIdentity() << endl;

    // 10. Symmetric Check
    cout << "Is A Symmetric? " << A.isSymmetric() << endl;

    // 11. Triangular Check
    cout << "Is A Upper Triangular? " << A.isUpperTriangular() << endl;
    cout << "Is A Lower Triangular? " << A.isLowerTriangular() << endl;

    return 0;
}
