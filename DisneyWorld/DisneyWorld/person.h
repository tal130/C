#ifndef __PERSON_H
#define __PERSON_H

class Person
{
public:
	Person(const char* name, int age, float height);
	Person(const Person& other);
	virtual ~Person();
	const Person& operator=(const Person& other);

	//getters
	const char* getName() const;
	int getAge() const;
	float getHeight() const;

	//setters
	void setName(const char* name);
	void setAge(int age);
	void setHeight(float height);

	//print
	friend std::ostream& operator<<(std::ostream& os, const Person& p)
	{
		os << "Person: No Implementation, Impl Here" << std::endl;
		return os;
	}

private:
	char* name;
	int age;
	float height;
};


#endif