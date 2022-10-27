#pragma once
#include <exception>
#include <iostream>

struct Node {
	int value_ = 0;
	Node* next_ = nullptr;
	Node* prev_ = nullptr;
};

struct List {
	void push_front(const int value);
	void push_back(const int value);
	void insert(const size_t index, const int value);

	void pop_front();
	void pop_back();
	void erase(const size_t position);
	void clear();

	void swap(size_t position_1, size_t position_2);

	int operator[](const size_t index);

	void display_forward();
	void display_reversed();

	size_t size();
	bool is_empty();

	/*
	int operator=(List list);

	void sort();*/
	
	//Fields of structures
	size_t size_ = 0;
	Node* first_ = nullptr;
	Node* last_ = nullptr;
};

