#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H
#pragma warning(disable: 4996)

#include <iostream>


using namespace std;
template <class ELEMENT>
class ArrayList{

public: 
	class Node{
	private:
		ELEMENT data;
		Node* next;
		private: 
			Node() : data(NULL), next(NULL){}
			Node(ELEMENT data) : data(data), next(NULL){}
			friend ArrayList;
		};

	ArrayList() : anchor(new Node()), last(anchor), size(0){}
	ArrayList(const ArrayList& list):size(list.size),anchor(new Node(list.anchor)){
		Node* d = anchor;
		Node other = *list.anchor;
		for (int i = 1; i < size; i++){
			*d.next = *other.next;
		}
	}
		~ArrayList(){
			RecursiveDeleteArray(anchor);
		}

		const ELEMENT operator [] (int num) const{
			return GetElement(num);
		}
		const ELEMENT GetElement(int index) const{
			if (index>size)
				throw std::out_of_range("Index out of range");
			else{
				const Node* d = anchor;
				for (int i = 0; i < index; i++)
					d = d->next;
				return d->next->data;
			}
		}
		void InsertElement(ELEMENT& element){
			/*if (size == 0){
				anchor =  new Node(element);
			}else
			if (index == 0 )
			{
				Node* d = new Node(*anchor);
				anchor->data = element;
				anchor->next = d;
			}
			else{
				Node* first = anchor;
				Node* second = anchor->next;
				while (second != NULL || index < size){
					first = first->next;
					second = second->next;
				}
				Node* d =new Node(element);
				*first->next = *d;
				d->next = second;

			}
			size++;

			*/

			last->next = new Node(element);
			last = last->next;
			size++;
		}
		
		void DeleteElement(int index){
			if (size == 0 || index > size)
				return;
			/*
				if (index == 0){
				Node* d = anchor;
				anchor = anchor->next;
				delete d;
				}else
			{
				Node* e= anchor;
				Node* e2 = e->next;
				while (e->next != NULL || index-- >= 0)
				{
					e = e->next;
					e2 = e2->next;
				}
				
				delete e;
				
			}
				size--;
			*/

			Node* e = anchor;
			Node* e2 = e->next;
			while (e->next != NULL && --index >= 0)
			{
				e = e->next;
				e2 = e2->next;
			}
			if (last == e2)
				last = e;
			else
			{
				e->next = e2->next;
			}
			delete e2;
			size--;
		}
		int Size() const{ return size; }

		 friend ostream& operator<<(ostream& os, const ArrayList& arraylist)
		 {
			 int size = arraylist.Size();
			 for (int i = 0; i < size; i++)
			 os << arraylist[i] <<" | ";
			 os << endl;
			 return os;
		 }
private:
	Node* anchor;
	Node* last = NULL;
	int size;

	void RecursiveDeleteArray(Node* node){
		if (node->next == NULL)
		{
			size = 0;
			delete node;
			return;
		}
		RecursiveDeleteArray(node->next);
		delete node;
	}
};
#endif // !ARRAYLIST
