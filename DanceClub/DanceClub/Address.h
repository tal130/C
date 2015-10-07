#pragma once 

#ifndef __ADDRESS_H
#define __ADDRESS_H

class Address
{
	protected:
		char* city;
		char* street;
		int num;
		int zip;

	public:
		Address(const char* city, const char* street, int num, int zip);
		Address(const Address&);
		~Address();
		Address& operator=(const Address& other);
		
		void setCity(const char*);
		const char* getCity() const;
		void setStreet(const char*);
		const char* getStreet() const;
		void setNum(const int);
		int getNum() const;
		void setZip(const int);
		int getZip() const;
		friend ostream& operator<<(ostream& os, const Address&);
};
#endif //__ADDRESS_H