#include "list.h"

void List::push_front(const int value) {
	Node* new_node = new Node;

	new_node->value_ = value;
	new_node->next_ = this->first_;
	new_node->prev_ = nullptr;

	if (this->first_ != nullptr) {
		this->first_->prev_ = new_node;
	}
	this->first_ = new_node;

	if (this->last_ == nullptr) {
		this->last_ = new_node;
	}

	this->size_++;
}

void List::push_back(const int value) {
	Node* new_node = new Node;

	new_node->value_ = value;
	new_node->prev_ = this->last_;
	new_node->next_ = nullptr;

	if (this->last_ != nullptr) {
		this->last_->next_ = new_node;
	}
	this->last_ = new_node;

	if (this->first_ == nullptr) {
		this->first_ = new_node;
	}

	this->size_++;
}

void List::insert(const size_t index, const int value) {
	if (index <= this->size_) {
		if (index == 0) {
			push_front(value);
			return;
		}
		if (index == this->size_) {
			push_back(value);
			return;
		}
		//в данной ситуации будут узлы справа и слева от нового узла
		Node* curr_node = this->first_;
		size_t counter = 0;
		while (counter < index) {
			curr_node = curr_node->next_;
			counter++;
		}

		Node* new_node = new Node;

		new_node->value_ = value;
		new_node->next_ = curr_node;
		new_node->prev_ = curr_node->prev_;

		curr_node->prev_->next_ = new_node;
		curr_node->prev_ = curr_node;

		this->size_++;
	}
	else {
		std::cout << "Can't insert element in list: index > size" << std::endl;
	}
}


void List::pop_front() {
	if (this->first_ != nullptr) {
		Node* tmp_node = this->first_->next_;
		delete this->first_;
		this->first_ = tmp_node;

		this->size_--;
		if (this->size_ == 0) {
			this->last_ = nullptr;
		}
	}
}

void List::pop_back() {
	if (this->last_ != nullptr) {
		Node* tmp_node = this->last_->prev_;
		delete this->last_;
		this->last_ = tmp_node;
		
		this->size_--;
		if (this->size_ == 0) {
			this->first_ = nullptr;
		}
	}
}

void List::erase(const size_t index) {
	if (index < this->size_) {
		if (index == 0) {
			pop_front();
			return;
		}
		if (index == this->size_ - 1) {
			pop_back();
			return;
		}
		//в данной ситуации будут узлы справа и слева от нового узла
		Node* curr_node = this->first_;
		size_t counter = 0;
		while (counter < index) {
			curr_node = curr_node->next_;
			counter++;
		}
		//curr_node - узел, который необходимо удалить
		//std::cout << curr_node->value_ << std::endl;
		curr_node->next_->prev_ = curr_node->prev_;
		curr_node->prev_->next_ = curr_node->next_;

		delete curr_node;

		this->size_--;
	}
	else {
		std::cout << "Can't erase element in list: index >= size" << std::endl;
	}
}

void List::clear() {
	while (this->size_ != 0) {
		this->pop_back();
	}
}

/*void List::insert(const size_t position, const int value) {
	if (position > this->size_) {
		std::cout << "Can't insert element in list: position > size" << std::endl;
	}
	else {

	}
}*/

int List::operator[](const size_t index) {
	if (index <= this->size_ && this->size_ != 0) {
		size_t counter = 0;
		Node* curr_node = this->first_;
		while (counter < index) {
			curr_node = curr_node->next_;
			counter++;
		}
		return curr_node->value_;
	}
	else {
		std::cout << "Can't receive element in list by index: index > size" << std::endl;
		return -1;
	}
}

void List::swap(const size_t index1, const size_t index2) {
	if (index1 <= this->size_ && index2 <= this->size_) {
		size_t counter1 = 0;
		Node* curr_node1 = this->first_;
		while (counter1 < index1) {
			curr_node1 = curr_node1->next_;
			counter1++;
		}
		size_t counter2 = 0;
		Node* curr_node2 = this->first_;
		while (counter2 < index2) {
			curr_node2 = curr_node2->next_;
			counter2++;
		}
		int tmp = curr_node1->value_;
		curr_node1->value_ = curr_node2->value_;
		curr_node2->value_ = tmp;
	}
	else {
		std::cout << "Can't swap elements in list by indeces: index1 > size or index2 > size" << std::endl;
	}
}

size_t List::size() {
	return this->size_;
}

bool List::is_empty() {
	return (this->size_ == 0);
}

void List::display_forward() {
	Node* curr_node = this->first_;
	std::cout << "Size=" << this->size_ << std::endl;
	while (curr_node != nullptr) {
		std::cout << curr_node->value_ << " ";
		curr_node = curr_node->next_;
	}
	std::cout << std::endl;
}

void List::display_reversed() {
	Node* curr_node = this->last_;
	std::cout << "Size=" << this->size_ << std::endl;
	while (curr_node != nullptr) {
		std::cout << curr_node->value_ << " ";
		curr_node = curr_node->prev_;
	}
	std::cout << std::endl;
}