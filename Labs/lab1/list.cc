#include <iostream>
using namespace std;
#include "list.h"

List::List() {
	this->first = nullptr;
	this->listSize = 0;
}

List::~List() {
	delete this->first;
}

bool List::exists(int d) const {
	Node* n = this->first;
	while(n != nullptr){
		if (n->value == d){
			return true;
		}
		n = n->next;
	}
	return false;
}

int List::size() const {
	return listSize;
}

bool List::empty() const {
	return listSize == 0;
}

void List::insertFirst(int d) {
	Node* n = new Node(d, this->first);
	this->first = n;
	listSize++;
}

void List::remove(int d, DeleteFlag df) {
	Node* prev = nullptr;
	Node* curr = this->first;
	switch(df) {
		case List::DeleteFlag::LESS: {
			while(curr != nullptr){
				if(curr->value < d){
					if(prev == nullptr){
						this->first = curr->next;
					} else{
						prev->next = curr->next;
					}
					curr->next = nullptr;
					delete curr;
					listSize--;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
			break;	
		}
		
		case List::DeleteFlag::EQUAL: {
			while(curr != nullptr){
				if(curr->value == d){
					cout << "\n6";
					if(prev == nullptr){
						this->first = curr->next;
					} else{
						prev->next = curr->next;
					}
					curr->next = nullptr;
					delete curr;
					listSize--;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
			break;
		}
		case List::DeleteFlag::GREATER: {
			while(curr != nullptr){
				if(curr->value > d){
					if(prev == nullptr){
						this->first = curr->next;
					}
					else{
						prev->next = curr->next;
					}
					curr->next = nullptr;
					delete curr;
					listSize--;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
			break;			
		}
						
	}
}

void List::print() const {
	int counter = 0;
	Node* n = this->first;
	while(n != nullptr){
		cout << "\n" << counter << ": Element value: " << n->value;
		n = n->next;
		counter++;
	}
}

