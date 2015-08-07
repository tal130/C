#pragma once 
//#pragma warning(disable: 4996)

#ifndef __HUMAN_H
#define __HUMAN_H

class Human
{
	private:
		char* name;
		int age;

	public:
		Human();
		~Human();
		
		void setName(const char*);
		const char* getName() const;

		void toString() const;
};
#endif //__HUMAN_H