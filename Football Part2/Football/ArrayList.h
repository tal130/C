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
		ELEMENT* data; 
		Node* next;
		Node(ELEMENT data) :data(new ELEMENT(data)), next(NULL){}
		~Node()
		{
			delete data;
		}
	friend ArrayList;
};

	ArrayList() :anchor(NULL), size(0){}
	ArrayList(const ArrayList& list) :size(0), anchor(NULL){
		int length = list.size;
		for (int i = 0; i < length; i++)
			this->push(list.GetElement(i));
	}

		~ArrayList(){
			if (size > 0)
				RecursiveDeleteArray(anchor);
		}

		const ELEMENT operator [] (int num)const{
			return GetElement(num);
		}
		const ELEMENT GetElement(int index) const{
			if (index>size)
				throw std::out_of_range("index out of range");
			else{
				const Node* d = anchor;
				for (int i = 0; i < index; i++)
					d = d->next;
				return *d->data;
			}
		}
		void InsertElement(const ELEMENT& element, int index = 0){
			if (size == 0){
				anchor = new Node(element);
			}
			else
				if (index == 0)
				{
				Node* d = new Node(*anchor);
				*anchor->data = element;
				anchor->next = d;
				}
				else{
					Node* first = anchor;
					Node* second = anchor->next;
					while (second != NULL || index < size){
						first = first->next;
						second = second->next;
					}
					Node* d = new Node(element);
					first->next = d;
					d->next = second;

				}
				size++;
		}
		void push(const ELEMENT& element){
			InsertElement(element, size); 
		}
		void DeleteElement(int index){
			if (size == 0)
				return;

			if (index == 0){
				Node* d = anchor;
				anchor = anchor->next;
				delete d;
			}
			else
			{
				Node* e = anchor;
				Node* e2 = e->next;
				while (e->next != NULL && index-- > 1)
				{
					e = e->next;
					e2 = e2->next;
					index--;
				}

				e->next = e2->next;
				delete e2;

			}
			size--;
		}
		int Size()const{ return size; }
private:
	Node* anchor;
	int size; 
	
	void RecursiveDeleteArray(Node* node){
		if (node->next == NULL)
		{
			delete node;
			size = 0;
			return;
		}
		
	RecursiveDeleteArray(node->next);
	node->next = NULL;
	delete node;
}

friend ostream& operator<<(ostream& os, const ArrayList& arraylist)
		 {
			 int size = arraylist.Size();
			 if (!size)
				 return os;
			 for (int i = 0; i < size; i++){
				 os << arraylist.GetElement(i) << " | ";

			 }
				
			 os << endl;
			 return os;
		 }



};
#endif // !ARRAYLIST
