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
    ArrayList(const ArrayList& list) :size(list.size), anchor(new Node(list.anchor)){
	Node* d = anchor;
	Node other = *list.anchor;
	for (int i = 1; i < size; i++){
		*d.next = *other.next;
	}

}
		~ArrayList(){
			RecursiveDeleteArray(anchor);

			//for (int i = 0; i < size; i++)
			//	DeleteElement(0);// 0!!!!hhh
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
		void InsertElement(ELEMENT& element, int index = 0){
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
		void push(ELEMENT& element){
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
				while (e->next != NULL || index-- >= 0)
				{
					e = e->next;
					e2 = e2->next;
				}

				delete e;

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
			  ELEMENT element = arraylist.GetElement(0);
			// os << element << " | ";
			 for (int i = 0; i < size; i++){
				 element = arraylist.GetElement(i);
				 os <<"DA2" <<2<< " ";
			 }
				
			 os << endl;
			 return os;
		 }
};
#endif // !ARRAYLIST
