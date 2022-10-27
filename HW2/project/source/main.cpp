#include <iostream>
#include "string.h"

int main() {
	String s1("Hello, ");
	s1.print();
	
	String s2(10, 'c');
	s2.print();

	String s3("world!");
	s1.append(s3);
	s1.print();
	
	String s4(s1);
	s4.print();
	
	s1 = s2;
	s1.print();
	
	return 0;
}