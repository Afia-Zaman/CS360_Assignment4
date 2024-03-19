// 2. Develop class Polynomial. The internal representation of a Polynomial is an array of
// terms. Each term contains a coefficient and an exponent, e.g., the term 2𝑥4 has the
// coefficient 2 and the exponent 4. Develop a complete class containing proper
// constructor and destructor functions as well as set and get functions. The class should
// also provide the following overloaded operator capabilities:
// a. Overload the addition operator (+) to add two Polynomials.
// b. Overload the subtraction operator (-) to subtract two Polynomials.
// c. Overload the assignment operator to assign one Polynomial to another.
// d. Overload the multiplication operator (*) to multiply two Polynomials.
// e. Overload the addition assignment operator (+=), subtraction assignment
// operator (-=), and multiplication assignment operator (*=).

//Answer:

#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial {
public:
    // Term structure to store coefficients and exponents
    struct Term {
        int coefficient;
        int exponent;

        Term(int c, int e) : coefficient(c), exponent(e) {}
    };

    // Constructor
    Polynomial() {}

    // Destructor
    ~Polynomial() {}

    // Copy constructor for deep copying
    Polynomial(const Polynomial& other) {
        for (const auto& term : other.terms) {
            terms.push_back(term);
        }
    }

    // Assignment operator
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            terms.clear();
            for (const auto& term : other.terms) {
                terms.push_back(term);
            }
        }
        return *this;
    }

    // Addition operator
    Polynomial operator+(const Polynomial& other) const {
        Polynomial result;
        result.terms = terms;

        for (const auto& term : other.terms) {
            result.addTerm(term.coefficient, term.exponent);
        }

        return result;
    }

    // Subtraction operator
    Polynomial operator-(const Polynomial& other) const {
        Polynomial result;
        result.terms = terms;

        for (const auto& term : other.terms) {
            result.addTerm(-term.coefficient, term.exponent);
        }

        return result;
    }

    // Multiplication operator
    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;

        for (const auto& term1 : terms) {
            for (const auto& term2 : other.terms) {
                result.addTerm(term1.coefficient * term2.coefficient, term1.exponent + term2.exponent);
            }
        }

        return result;
    }

    // Addition assignment operator
    Polynomial& operator+=(const Polynomial& other) {
        *this = *this + other;
        return *this;
    }

    // Subtraction assignment operator
    Polynomial& operator-=(const Polynomial& other) {
        *this = *this - other;
        return *this;
    }

    // Multiplication assignment operator
    Polynomial& operator*=(const Polynomial& other) {
        *this = *this * other;
        return *this;
    }

    // Function to add a term to the polynomial
    void addTerm(int coefficient, int exponent) {
        for (auto& term : terms) {
            if (term.exponent == exponent) {
                term.coefficient += coefficient;
                return;
            }
        }
        terms.push_back(Term(coefficient, exponent));
    }

    // Function to display the polynomial
    void display() const {
        for (const auto& term : terms) {
            std::cout << term.coefficient << "x^" << term.exponent << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<Term> terms;
};

int main() {
    Polynomial p1;
    p1.addTerm(3, 2);
    p1.addTerm(1, 0);

    Polynomial p2;
    p2.addTerm(1, 2);
    p2.addTerm(2, 1);

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial product = p1 * p2;

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    diff.display();

    std::cout << "Product: ";
    product.display();

    return 0;
}
// Output -

// Sum: 4x^2 1x^0 2x^1 
// Difference: 2x^2 1x^0 -2x^1 
// Product: 3x^4 6x^3 1x^2 2x^1 
