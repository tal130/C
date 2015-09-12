#ifndef __TICKET_H
#define __TICKET_H

class Ticket
{
public:
	Ticket(const char* date, float price);
	virtual ~Ticket();

	//getters
	float getPrice() const;
	const char* getDate() const;

	//setters
	void setPrice(float price);
	void setDate(const char* date);

	//print
	friend std::ostream& operator<<(std::ostream& os, const Ticket& t)
	{
		os << "Ticket: No Implementation, Impl Here" << std::endl;
		return os;
	}

private:
	float price;
	char date[11]; //  (dd/mm/yyyy) + '/0' [e.g -  "24/08/2015"]
};

#endif // !__TICKET_H
