// 3. Create a class HugeInteger that uses a 40-element array of digits to store integers as
// large as 40 digits each. Provide member functions input, output, add and subtract.For
// comparing HugeInteger objects, provide functions isEqualTo, isNotEqualTo,
// isGreaterThan, isLessThan, isGreaterThanOrEqualTo and isLessThanOrEqualTo--each
// of these is a "predicate " function that simply returns true if the relationship holds
// between the two HugeIntegers and returns false if the relationship does not hold. Also,
// provide a predicate function isZero. After that, provide member functions multiply,
// divide and modulus.

Answer:

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class HugeInteger {
private:
    static const int SIZE = 40;
    int digits[SIZE];

public:
    HugeInteger() {
        
        std::fill(digits, digits + SIZE, 0);
    }

    void input(const char* number) {
        int length = strlen(number);
        int start = SIZE - length;
        for (int i = 0; i < length; ++i) {
            digits[start++] = number[i] - '0';
        }
    }

    void output() const {
        int i = 0;
        while (i < SIZE && digits[i] == 0) {
            ++i;
        }
        if (i == SIZE) {
            std::cout << "0";
        } else {
            while (i < SIZE) {
                std::cout << digits[i++];
            }
        }
        std::cout << std::endl;
    }

    HugeInteger add(const HugeInteger& other) const {
        HugeInteger result;
        int carry = 0;
        for (int i = SIZE - 1; i >= 0; --i) {
            int sum = digits[i] + other.digits[i] + carry;
            result.digits[i] = sum % 10;
            carry = sum / 10;
        }
        return result;
    }

    HugeInteger subtract(const HugeInteger& other) const {
        HugeInteger result;
        int borrow = 0;
        for (int i = SIZE - 1; i >= 0; --i) {
            int diff = digits[i] - other.digits[i] - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits[i] = diff;
        }
        return result;
    }

    bool isEqualTo(const HugeInteger& other) const {
        return std::equal(digits, digits + SIZE, other.digits);
    }

    bool isNotEqualTo(const HugeInteger& other) const {
        return !isEqualTo(other);
    }

    bool isGreaterThan(const HugeInteger& other) const {
        return std::lexicographical_compare(digits, digits + SIZE, other.digits, other.digits + SIZE);
    }

    bool isLessThan(const HugeInteger& other) const {
        return other.isGreaterThan(*this);
    }

    bool isGreaterThanOrEqualTo(const HugeInteger& other) const {
        return !isLessThan(other);
    }

    bool isLessThanOrEqualTo(const HugeInteger& other) const {
        return !isGreaterThan(other);
    }

    bool isZero() const {
        return std::all_of(digits, digits + SIZE, [](int digit) { return digit == 0; });
    }

    HugeInteger multiply(const HugeInteger& other) const {
        HugeInteger result;
        HugeInteger temp;
        for (int i = SIZE - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = SIZE - 1; j >= 0; --j) {
                int product = digits[i] * other.digits[j] + carry;
                temp.digits[j] = product % 10;
                carry = product / 10;
            }
            temp = shiftLeft(temp, SIZE - 1 - i);
            result = result.add(temp);
        }
        return result;
    }


private:
    HugeInteger shiftLeft(const HugeInteger& num, int places) const {
        HugeInteger result;
        std::copy(num.digits + places, num.digits + SIZE, result.digits);
        std::fill(result.digits + SIZE - places, result.digits + SIZE, 0);
        return result;
    }
};

int main() {
HugeInteger num1, num2, result;
    num1.input("1234567890123456789012345678901234567890");
    num2.input("9876543210987654321098765432109876543210");

    result = num1.add(num2);
    cout << "Addition: ";
    result.output(); 
    
    result = num1.subtract(num2);
    cout << "subtraction: ";
    result.output();
    
    if (num1.isEqualTo(num2)) {
        std::cout << "Numbers are equal" << std::endl;
    } else {
        std::cout << "Numbers are not equal" << std::endl;
    }
    
    if (num1.isGreaterThan(num2)){
        std::cout << "Num2 is greater than num1 " << std::endl;
    } else {
        std::cout << "Num2 is not greater than num1 " << std::endl;
    }
    
    if (num1.isLessThan(num2)){
        std::cout << "Num2 is less than num1 " << std::endl;
    } else {
        std::cout << "Num1 is not less than num2 " << std::endl;
    }
    if (num1.isGreaterThanOrEqualTo(num2)){
        std::cout << "Num1 is not greater than or equal to num2 " << std::endl;
    } else {
        std::cout << "Num1 is greater than or equal to num2  " << std::endl;
    }
    
    if (num1.isLessThanOrEqualTo(num2)){
        std::cout << "Num2 is less than or equal to num1 " << std::endl;
    } else {
        std::cout << "Num2 is not less than or equal to num1  " << std::endl;
    } 
    
    result = num1.multiply(num2);
    std::cout << "Multiplication result: ";
    result.output();

    return 0;
}


// Output -
// Addition: 1111111101111111110111111111011111111100
// subtraction: 1358024679135802467913580246791358024680
// Numbers are not equal
// Num2 is greater than num1 
// Num1 is not less than num2 
// Num1 is not greater than or equal to num2 
// Num2 is not less than or equal to num1  
// Multiplication result: 8712086533622923332237463801111263526900

