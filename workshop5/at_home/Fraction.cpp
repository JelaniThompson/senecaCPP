#include "Fraction.h"

using namespace std;

namespace sict {
    Fraction::Fraction() {
        denom = -1;              // safe empty state
    }

    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    {
        if (n >= 0 && d > 0) {
            num = n;
            denom = d;
            reduce();
        } else
            denom = -1;              // set to safe empty state
    }

    int Fraction::gcd()                                        // returns the greatest common divisor of num and denom
    {
        int mn = min();                                        // min of num and denom
        int mx = max();                                        // mX of num and denom

        for (int x = mn; x > 0; x--)                           // find the greatest common divisor
            if (mx % x == 0 && mn % x == 0)
                return x;
        return 1;

    }

    void Fraction::reduce()                                         // simplify the Fraction number
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max() {
        return (num >= denom) ? num : denom;
    }

    int Fraction::min() {
        return (num >= denom) ? denom : num;
    }

    // in_lab

    // TODO: write the implementation of display function HERE
    void Fraction::display() const {
        if (isEmpty()){
            cout << "Invalid Fraction Object!";
        }else if (denom == 1){
            cout << num;
        }else{
            cout << num << "/" << denom;
        }

        /*if (!this->isEmpty()) { cout << num << "/" << denom; }
        else if (denom == 1) { cout << num; }
        else { cout << "Invalid Fraction Object!"; }
    */}

        // Check if object is in safe empty state
        bool Fraction::isEmpty() const {
            if (denom == -1) { return true; }
            else { return false; }
        }

        // TODO: write the implementation of member operator+= function HERE
        Fraction Fraction::operator+=(Fraction PlusEqual) {
            *this = *this + PlusEqual;
            //*this.reduce();
            return *this;
        }

        // Check if operators are empty and if not, add the fractions
        Fraction Fraction::operator+(Fraction Plus) {
            Fraction plusResult;
            if (isEmpty() || Plus.isEmpty()) {
                return plusResult;
            }
            else {
                // a * d  + b * c / b * d
                plusResult.num = num * Plus.denom + denom * Plus.num;
                plusResult.denom = denom * Plus.denom;
            }
            plusResult.reduce();
            return plusResult;
        }

        // TODO: write the implementation of member operator* function HERE
        Fraction Fraction::operator*(Fraction Multiply) {
            Fraction multiplyResult;
            if (isEmpty() || Multiply.isEmpty()) {
                return multiplyResult;
            }
            else {
                // a * c / b * d
                multiplyResult.num = num * Multiply.num;
                multiplyResult.denom = denom * Multiply.denom;
            }
            multiplyResult.reduce();
            return multiplyResult;
        }

        // TODO: write the implementation of member operator== function HERE
        bool Fraction::operator==(Fraction EqualEqual) {
            if (isEmpty() || EqualEqual.isEmpty()) {
                return false;
            }
            else {
                // Check if a * d == b * c
                if (num == EqualEqual.num && denom == EqualEqual.denom) {
                    return true;
                } else { return false; }
            }
        }

        // Return true if a * d != b * c
        bool Fraction::operator!=(Fraction NotEqual) {
            if (isEmpty() || NotEqual.isEmpty()) {
                return false;
            }
            else {
                if(num == NotEqual.num && denom == NotEqual.denom) {
                    return false;
                } else {
                    return true;
                }
            }
        }

        Fraction::operator double() {
            double answer = (1.0 * this->num) / (1.0 * this->denom);
            if (isEmpty()) {
                return -1.0;
            } else {
                return answer;
            }
        }

        Fraction::operator int() {
            int result = (this->num / this->denom);
            if (denom == -1) {
                return -1;
            }
            return result;
        }
    }
