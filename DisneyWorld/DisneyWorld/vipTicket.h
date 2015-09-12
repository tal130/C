#ifndef __VIP_TICKET_H
#define __VIP_TICKET_H

#include <iostream>
#include "ticket.h"

class VIPTicket : public Ticket
{
public:
	enum VIPType
	{
		FIRST_CLASS,
		FAST_LINE
	};

	VIPTicket(const Ticket& ticket, VIPType theType);
	
	VIPType getType() const;
	void setType(VIPType type);

	//print
	friend std::ostream& operator<<(std::ostream& os, const VIPTicket& t)
	{
		os << "VIPTicket: No Implementation, Impl Here" << std::endl;
		return os;
	}

private:
	VIPType type;
};


#endif