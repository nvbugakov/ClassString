#pragma once
#include <iostream>

class WorkStrClass
{
private:
	char* str;
	int LengthStr;
public:
	WorkStrClass();
	WorkStrClass(const char* a);
	~WorkStrClass();

	WorkStrClass& operator=(const WorkStrClass&);
	friend WorkStrClass operator+(const WorkStrClass&, const WorkStrClass&);
	WorkStrClass& operator+=(const WorkStrClass&);
    char& operator[](const int index);
	bool operator==(const WorkStrClass&);
	bool operator!=(const WorkStrClass&);
	bool operator>(const WorkStrClass&);
	bool operator<(const WorkStrClass&);
	bool operator<=(const WorkStrClass&);
	bool operator>=(const WorkStrClass&);
	friend std::ostream& operator<<(std::ostream&, const WorkStrClass&);
	friend std::istream& operator>>(std::istream&, WorkStrClass&);


	int LengthStrok();
	WorkStrClass& CopySt(int b, int c);
	WorkStrClass& DeleteSt(int b, int c);
	WorkStrClass& PasteSt(WorkStrClass& string, int b);
	int SearchSt(WorkStrClass&);
	int SearchStEnd(WorkStrClass&);
	WorkStrClass& SubstitutionSt(WorkStrClass& string, WorkStrClass& string2);
	WorkStrClass& SubstitutionStAll(WorkStrClass& string, WorkStrClass& string2);
};

