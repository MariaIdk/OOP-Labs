#include <iostream>
#include "ClassPolynom.h"
using namespace std;


int main() {
    Polynomial poly1({ 1, -2, 3 });
    Polynomial poly2({ 0, 4, -1 });

    poly1.print();
    poly2.print();

    Polynomial sum = poly1.add(poly2);
    Polynomial diff = poly1.subtract(poly2);
    Polynomial product = poly1.multiply(poly2);

    cout << "Sum: ";
    sum.print();

    cout << "Difference: ";
    diff.print();

    cout << "Product: ";
    product.print();

    double x_value = 2.0;
    cout << "Evaluation at x = " << x_value << ": " << poly1.evaluate(x_value) << endl;

    return 0;
}