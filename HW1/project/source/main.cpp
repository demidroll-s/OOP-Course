#include <iostream>
#include "list.h"

int main() {
	{
		std::cout << "Test push_front" << std::endl;
		List list;

		list.push_front(4);
		list.push_front(3);
		list.push_front(5);

		list.display_forward();

		std::cout << list.last_->value_ << std::endl;
		std::cout << list.size() << std::endl;
	}

	{
		std::cout << "Test push_back" << std::endl;

		List list;

		list.push_back(4);
		list.push_back(3);
		list.push_back(5);

		list.display_forward();

		std::cout << list.first_->value_ << std::endl;
		std::cout << list.size() << std::endl;
	}

	{
		std::cout << "Test pop_front and pop_back" << std::endl;

		List list;

		list.push_front(4);
		list.push_front(3);
		list.display_forward();

		list.pop_front();
		list.pop_front();
		list.display_forward();

		list.push_back(5);
		list.push_back(6);
		list.display_forward();

		list.pop_back();
		list.display_forward();

		list.pop_back();

		list.display_forward();
	}

	{
		std::cout << "Test clear" << std::endl;

		List list;

		list.push_front(4);
		list.push_front(3);
		
		list.display_forward();
		
		list.clear();

		list.display_forward();
	}

	{
		std::cout << "Test operator[]" << std::endl;

		List list;

		list.push_front(4);
		list.push_front(3);

		for (size_t i = 0; i < list.size(); ++i) {
			std::cout << list[i] << " ";
		}
		std::cout << std::endl;
	}

	{
		std::cout << "Test operator[]" << std::endl;

		List list;

		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);
		list.display_forward();

		list.swap(0, 1);
		list.display_forward();
	}

	{
		std::cout << "Test insert" << std::endl;

		List list;

		list.insert(0, 1);
		list.insert(1, 2);
		list.insert(1, 3);
		list.display_forward();
	}

	{
		std::cout << "Test erase" << std::endl;

		List list;

		list.insert(0, 1);
		list.insert(1, 2);
		list.insert(1, 3);
		list.display_forward();
		
		list.erase(1);
		list.display_forward();

		list.erase(1);
		list.display_forward();

		list.erase(0);
		list.display_forward();
	}

	return 0;
}