#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H
#pragma warning(disable: 4996)

#include <iostream>


using namespace std;
template <class ELEMENT>
class ArrayList{


public: class Node{
public:	ELEMENT data;
	Node* next;
public :Node() : data(NULL), next(NULL){};
public:	Node(ELEMENT data) :data(data), next(NULL){
		}

	};
public: Node* anchor;
		 int size;
public: ArrayList() :anchor(new Node()), size(0){}
public: ArrayList(const ArrayList& list):size(list.size),anchor(new Node(list.anchor)){
	Node* d = anchor;
	Node other = *list.anchor;
	for (int i = 1; i < size; i++){
		*d.next = *other.next;
	}

}
		~ArrayList(){
			RecursiveDeleteArray(anchor);
		}

		const ELEMENT operator [] (int num)const{
			return GetElement(num);
		}
		const ELEMENT GetElement(int index) const{
			if (index>size)
				throw std::out_of_range("Too much high in size");
			else{
				const Node* d = anchor;
				for (int i = 0; i < index; i++)
					d = d->next;
				return d->data;
			}
		}
		void InsertElement(ELEMENT& element, int index=0){
			if (size == 0){
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
		}
		
		void DeleteElement(int index){
			if (size == 0)
				return;
			
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
		}
		int Size()const{ return size; }
private: void RecursiveDeleteArray(Node* node){
	if (node->next == NULL)
		return;
	RecursiveDeleteArray(node->next);
	delete node;
	size = 0;
}
		 friend ostream& operator<<(ostream& os, const ArrayList& arraylist)
		 {
			 int size = arraylist.Size();
			 for (int i = 0; i < size; i++)
			 os << arraylist.GetElement(i) <<" | ";
			 os << endl;
			 return os;
		 }
};
#endif // !ARRAYLIST
