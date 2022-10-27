#pragma once
#include <algorithm>
#include <iostream>
#include <cstring>

struct String {
    //Constructors and destructors
    String(const char* str = "");
    String(size_t n, char c);
    String(const String& other);
    ~String();
    
    //Asignment operator
    String& operator=(const String& other);

    //Useful methods
    void append(String& other);
    
    //IO manipulations
    void print();

private:
    size_t size_;
    char* str_;
};
