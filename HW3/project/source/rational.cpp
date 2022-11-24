#include "rational.h"

Rational::Rational()
    : numerator_(0), denominator_(1) {}

Rational::Rational(int numerator, int denominator)
    : numerator_(numerator), denominator_(denominator) {}

void Rational::add(Rational rational) {
    numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
    denominator_ *= rational.denominator_;
}

void Rational::sub(Rational rational) {
    numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
    denominator_ *= rational.denominator_;
}

void Rational::mul(Rational rational) {
    numerator_ *= rational.numerator_;
    denominator_ *= rational.denominator_;
}

void Rational::div(Rational rational) {
    numerator_ *= rational.denominator_;
    denominator_ *= rational.numerator_;
}

void Rational::neg() {
    numerator_ = - numerator_;
};

void Rational::inv() {
    if (numerator_ != 0) {
        int tmp = numerator_;
        numerator_ = denominator_;
        denominator_ = tmp;
    }
    else {
        throw "Error: can't find it is impossible to reverse zero!";
    }
}

double Rational::to_double() const {
    return static_cast<double>(numerator_) / static_cast<double>(denominator_);
}

int Rational::get_numerator() {
    return numerator_;
}

int Rational::get_denominator() {
    return denominator_;
}

Rational& Rational::operator+=(const Rational& rational) {
    this->add(rational);
    return *this;
}

Rational& Rational::operator-=(const Rational& rational) {
    this->sub(rational);
    return *this;
}

Rational& Rational::operator*=(const Rational& rational) {
    this->mul(rational);
    return *this;
} 

Rational& Rational::operator/=(const Rational& rational) {
    this->div(rational);
    return *this;
}

Rational Rational::operator-() const {
    Rational r(numerator_, denominator_);
    r.neg();
    return r;
}

Rational Rational::operator+() const {
    Rational r(numerator_, denominator_);
    return r;
}

Rational operator+(Rational r1, const Rational& r2) {
    return r1 += r2;
}

Rational operator-(Rational r1, const Rational& r2) {
    return r1 -= r2;
}

Rational operator*(Rational r1, const Rational& r2) {
    return r1 *= r2;
}

Rational operator/(Rational r1, const Rational& r2) {
    return r1 /= r2;
}

std::ostream& operator<<(std::ostream& os, Rational& r) {
    int n = r.get_numerator();
    int d = r.get_denominator();
    os << n << "/" << d;
    return os;
}
