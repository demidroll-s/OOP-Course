#include "string.h"

String::String(const char* str) {
    this->size_ = strlen(str);
    this->str_ = new char[this->size_ + 1];
    strcpy(this->str_, str);
} //+

String::String(size_t n, char c) {
    this->size_ = n;
    this->str_ = new char[this->size_ + 1];
    for (size_t i = 0; i < this->size_; ++i) {
        this->str_[i] = c;
    }
    this->str_[n] = '\0';
}

String::String(const String& other) {
    this->size_ = other.size_;
    this->str_ = new char[this->size_ + 1];
    strcpy(this->str_, other.str_);
}

String::~String() {
    delete[] this->str_;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] this->str_;
        this->size_ = other.size_;
        this->str_ = new char[this->size_ + 1];
        strcpy(this->str_, other.str_);
    }
    return *this;
}

void String::append(String& other) {
    char* old_str = this->str_;
    char* tmp = other.str_;
    this->str_ = new char[this->size_ + other.size_ + 1];
    strcpy(this->str_, old_str);
    strcpy(this->str_ + this->size_, tmp);
    this->size_ += other.size_;
    delete[] old_str;
}

void String::print() {
    for (size_t i = 0; i < this->size_; ++i) {
        std::cout << this->str_[i];
    }
    std::cout << std::endl;
}