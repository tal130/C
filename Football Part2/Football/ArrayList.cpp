#pragma warning(disable: 4996)

#include <iostream>

#include "ArrayList.h"

using namespace std;
template <class ELEMENT>
class ArrayList{
	class Node{
		Node() : data(NULL), next(NULL){};
		Node(ELEMENT data):data(data),next(NULL){
		}
		const Node operator = (Node node){
			delete data;
			this.data = node.data;
			this.next = node.next;
		}
		~Node(){
			delete data;
		}
	};

public: ArrayList() :anchor(Node()), size(0);
public: ArrayList(const ArrayList& list);
		~ArrayList(){
			RecursiveDeleteArray(anchor);
		}

		const ELEMENT operator [] (int num)const;
		const ELEMENT GetElement(int index) const;
		void SetElement(ELEMENT& element, int index);
		void DeleteElement(int index);
		int Size();
private: RecursiveDeleteArray(Node& node){
	if (node == NULL)
		return;
	RecursiveDeleteArray(node.next);
	delete node;
}
};