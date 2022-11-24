#include <iostream>

struct Rational {
    Rational();
    Rational(int numerator, int denominator);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    int get_numerator();
    int get_denominator();

    Rational& operator+=(const Rational& rational);
    Rational& operator-=(const Rational& rational);
    Rational& operator*=(const Rational& rational);
    Rational& operator/=(const Rational& rational);
    Rational operator-() const;
    Rational operator+() const;

    operator double() const {
        return this->to_double();
    }

    friend bool Rational::operator==(Rational const& left, Rational const& right) {
        return (left.numerator_ == right.numerator_) && (left.denominator_ == right.denominator_);
    }

    friend bool operator!=(Rational const& left, Rational const& right) {
        return !(left == right);
    }

    friend bool operator<(Rational const& left, Rational const& right) {
        return left.numerator_ * right.denominator_ < left.denominator_* right.numerator_;
    }

    friend bool operator>(Rational const& left, Rational const& right) {
        return right < left;
    }

    friend bool operator<=(Rational const& left, Rational const& right) {
        return !(left > right);
    }

    friend bool operator>=(Rational const& left, Rational const& right) {
        return !(left < right);
    }

    

private:
    int numerator_ = 0;
    unsigned denominator_ = 1;
};

Rational operator+(Rational r1, const Rational& r2);
Rational operator-(Rational r1, const Rational& r2);
Rational operator*(Rational r1, const Rational& r2);
Rational operator/(Rational r1, const Rational& r2);

std::ostream& operator<<(std::ostream& os, Rational& r);