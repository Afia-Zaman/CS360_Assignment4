// 2. Generate a class called Rational to perform arithmetic with fractions. Write a program to
// test your class. Use integer variables to represent the private data of the class--the
// numerator and the denominator. Provide a constructor that enables an object of this
// class to be initialized when it’s declared. The constructor should contain default values
// in case no initializers are provided and should store the fraction in reduced form. For
// example, 2
// 4 , the fraction would be stored in the object as 1 in the numerator and 2 in the
// denominator. Provide public member functions that perform each of the following tasks:
// a. Adding two Rational numbers. The result should be stored in reduced form.
// b. Subtracting two Rational numbers. The result should be stored in reduced
// form.
// c. Multiplying two Rational numbers. The result should be stored in reduced
// form.
// d. Dividing two Rational numbers. The result should be stored in reduced form.
// e. Printing Rational numbers in the form a/b, where a is the numerator and b is
// the denominator.
// f. Printing Rational numbers in floating-point format.

// Answer:

#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int greatest_common_divisor = gcd(numerator, denominator);
        numerator /= greatest_common_divisor;
        denominator /= greatest_common_divisor;
    }

public:
    Rational(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        reduce();
    }

    Rational operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const {
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    void print() const {
        cout << numerator << "/" << denominator;
    }

    void printFloat() const {
        cout << static_cast<float>(numerator) / denominator;
    }
};

int main() {
    Rational r1(2, 4);
    Rational r2(3, 7);

    Rational sum = r1 + r2;
    Rational difference = r1 - r2;
    Rational product = r1 * r2;
    Rational quotient = r1 / r2;

    cout << "Rational 1: ";
    r1.print();
    cout << "\nRational 2: ";
    r2.print();
    
    cout << "\nSum: ";
    sum.print();
    
    cout << "\nDifference: ";
    difference.print();
    
    cout << "\nProduct: ";
    product.print();
    
    cout << "\nQuotient: ";
    quotient.print();
    
    cout << "\nRational 1 in float format: ";
    r1.printFloat();
    cout << endl;

    return 0;
}

// Output -

// Rational 1: 1/2
// Rational 2: 3/7
// Sum: 13/14
// Difference: 1/14
// Product: 3/14
// Quotient: 7/6
// Rational 1 in float format: 0.5
