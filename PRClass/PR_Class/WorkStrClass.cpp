#include "WorkStrClass.h"
#include <iostream>

WorkStrClass::WorkStrClass()
{
	LengthStr = 0;
	str = new char[1];
	str[0] = '\0';
}

WorkStrClass::~WorkStrClass()
{
	delete str;
}
WorkStrClass::WorkStrClass(const char* a)
{
	int i = 0;
	for (;; i++)
	{
		if (a[i] == '\0') break;
	}
	LengthStr = i;
	str = new char[LengthStr + 1];
	for (i = 0; i < LengthStr; i++)
	{
		str[i] = a[i];
	}
	str[LengthStr] = '\0';
}
int WorkStrClass::LengthStrok()
{
	return this->LengthStr;
};

WorkStrClass& WorkStrClass::operator=(const WorkStrClass& string)
{
	if (this != &string)
	{
		delete[] this->str;
		LengthStr = string.LengthStr;
		this->str = new char[LengthStr + 1];
		for (int i = 0; i <= LengthStr; i++) str[i] = string.str[i];
	}
	return *this;
};
WorkStrClass& WorkStrClass::operator+=(const WorkStrClass& string)
{
	int sz = this->LengthStrok() + string.LengthStr;
	char* ts = new char[sz + 1];
	for (int i = 0; i < this->LengthStrok(); i++)
	{
		ts[i] = this->str[i];
	}
	for (int ii = this->LengthStrok(), j = 0; ii <= sz; ii++, j++)
	{
		ts[ii] = string.str[j];
	}
	delete this->str;
	this->str = ts;
	this->LengthStr = sz;
	return *this;
};
WorkStrClass operator+(const WorkStrClass& string1, const WorkStrClass& string2)
{
	WorkStrClass* ts = new WorkStrClass;
	*ts = string1;
	return *ts += string2;
};

char& WorkStrClass::operator[](const int index)
{
	char* buf = new char[1];
	buf[0] = this->str[index];
	return *buf;
};
bool WorkStrClass::operator==(const WorkStrClass& string)
{
	bool Sq = false;
	int LS2 = string.LengthStr;
	if (LS2 == this->LengthStrok())
	{
		for (int i = 0; i < LS2; i++)
		{
			if (this->str[i] == string.str[i])
			{
				Sq = true;
			}
			else
			{
				Sq = false;
				break;
			}
		}
	}
	return Sq;
};
bool WorkStrClass::operator!=(const WorkStrClass& string)
{
	bool Sq = false;
	int LS2 = string.LengthStr;
	if (LS2 == this->LengthStrok())
	{
		for (int i = 0; i < LS2; i++)
		{
			if (this->str[i] == string.str[i])
			{
				Sq = true;
			}
			else
			{
				Sq = false;
				break;
			}
		}
	}
	if (Sq)
	{
		Sq = false;
	}
	else
	{
		Sq = true;
	}
	return Sq;
};
bool WorkStrClass::operator>(const WorkStrClass& string)
{
	bool Sq = false;
	int LS2 = string.LengthStr;
	int j = 0;
	if (LS2 <= this->LengthStrok())
	{
		j = LS2;
	}
	else
	{
		j = this->LengthStrok();
	}
		for (int i = 0; i < j; i++)
		{
			int kod1 = int(this->str[i]);
			int kod2 = int(string.str[i]);
			if (kod1 > kod2)
			{
				Sq = true;
			}
			else
			{
				Sq = false;
				break;
			}
		}
	return Sq;
};
bool WorkStrClass::operator<(const WorkStrClass& string)
{
	bool Sq = false;
	int LS2 = string.LengthStr;
	int j = 0;
	if (LS2 <= this->LengthStrok())
	{
		j = LS2;
	}
	else
	{
		j = this->LengthStrok();
	}
		for (int i = 0; i < j; i++)
		{
			int kod1 = int(this->str[i]);
			int kod2 = int(string.str[i]);
			if (kod1 < kod2)
			{
				Sq = true;
			}
			else
			{
				Sq = false;
				break;
			}
		}
	return Sq;
};
bool WorkStrClass::operator<=(const WorkStrClass& string)
{
	bool Sq = false;
	int LS2 = string.LengthStr;
	int i = 0;
	while (this->str[i] != '\0' || string.str[i] != '\0')
	{
		int kod1 = int(this->str[i]);
		int kod2 = int(string.str[i]);
		if (kod1 <= kod2)
		{
			Sq = true;
		}
		else
		{
			Sq = false;
			break;
		}
		i++;
	}
	if (Sq)
	{
		if (LS2 < this->LengthStrok())
		{
			Sq = false;
		}
	}
	return Sq;
};
bool WorkStrClass::operator>=(const WorkStrClass& string)
{
	bool Sq = false;
	int LS2 = string.LengthStr;
	int i = 0;
	while (this->str[i] != '\0' || string.str[i] != '\0')
	{
		int kod1 = int(this->str[i]);
		int kod2 = int(string.str[i]);
		if (kod1 >= kod2)
		{
			Sq = true;
		}
		else
		{
			Sq = false;
			break;
		}
		i++;
	}
	if (Sq)
	{
		if (LS2 > this->LengthStrok())
		{
			Sq = false;
		}
	}
	return Sq;
};
std::ostream& operator<<(std::ostream& os, const WorkStrClass& st)
{
	os << st.str;
	return os;

}
std::istream& operator>>(std::istream& is, WorkStrClass& st)
{
	char buff[2048];
	std::cin.getline(buff, sizeof buff);
	st = buff;
	return is;

}

WorkStrClass& WorkStrClass::CopySt(int b, int c)
{
	WorkStrClass* St = new WorkStrClass();
	c = (c < 0) ? 0 : c;
	b = (b < 0) ? 0 : b;
	c = (c + b > this->LengthStr) ? this->LengthStr : c;
	char* buf = new char[c + 1];
	for (int i = 0; i < c; i++)
	{
		buf[i] = this->str[i + b];
	}
	buf[c] = '\0';
	St->LengthStr = c;
	delete[] St->str;
	St->str = buf;
	return *St;
};
WorkStrClass& WorkStrClass::DeleteSt(int b, int c)
{
	WorkStrClass* St = new WorkStrClass();
	int LS;
	c = (c < 0) ? 0 : c;
	b = (b < 0) ? 0 : b;
	LS = (c + b > this->LengthStr) ? 0 : this->LengthStr - c;
	char* buf = new char[LS + 1];
	int i = 0;
	for (i = 0; i < b; i++)
	{
		buf[i] = this->str[i];
	}
	for (i = 0; i < c; i++)
	{
		buf[i] = this->str[i + c];
	}
	buf[LS] = '\0';
	St->LengthStr = LS;
	delete[] St->str;
	St->str = buf;
	return* St;
};
WorkStrClass& WorkStrClass::PasteSt(WorkStrClass& string, int b)
{
	WorkStrClass* St = new WorkStrClass();
	b = (b < 0) ? 0 : b;
	int LS = this->LengthStrok() + string.LengthStrok();
	char* buf = new char[LS + 1];
	int i = 0;
	int j = 0;
	int z = 0;
	for (i; i < b; i++)
	{
		buf[i] = this->str[i];
	}
	for (i; i < i + b; i++,j++)
	{
		buf[i] = string.str[j];
	}
	for (i; i < LS; i++)
	{
		buf[i] = this->str[b + z];
		z++;
	}
	buf[LS] = '\0';
	St->LengthStr = LS;
	delete St->str;
	St->str = buf;
	return *St;
};
int WorkStrClass::SearchSt(WorkStrClass& string)
{
	int i = 0;
	int j = 0;
	int zap = -1;
	for (i; i <= this->LengthStr; i++)
	{
		if (this->str[i] == string.str[j])
		{
			if (zap == -1)
			{
				zap = i;
			}
			j++;
			if (j == this->LengthStr)
			{
				break;
			}
		}
		else
		{
			if (zap != -1)
			{
				if (this->LengthStr - i < string.LengthStr && j != string.LengthStr)
				{
					zap = -1;
					break;
				}
				else
				{
					zap = -1;
				}
				i--;
			}
			j = 0;
		}
	}
	return zap;
};
int WorkStrClass::SearchStEnd(WorkStrClass& string)
{
	int i = 0;
	int j = 0;
	int k = 1;
	int zap = -1;
	int LS = this->LengthStr - string.LengthStr;
	for (i; i <= LS; i++)
	{
		if (this->str[LS - i] == string.str[j])
		{
			if (zap == -1)
			{
				zap = LS - i;
			}
			j++;
			for (k; k <string.LengthStr; k++)
			{
				if (this->str[LS - i + k] == string.str[j])
				{
					j++;
				}
				else
				{
					zap = -1;
					j = 0;
				}
			}
		}
		if (zap != -1)
		{
			break;
		}
	}
	return zap;
}
WorkStrClass& WorkStrClass::SubstitutionSt(WorkStrClass& string, WorkStrClass& string2)
{
	int Pozition_Stroka1 = 0;
	int zap = -1;
	int j = 0;
	int z = 0;
	int Pozition_Stroka4 = 0;
	WorkStrClass* St = new WorkStrClass();
	int LS = this->LengthStrok() + string2.LengthStrok();
	char* buf = new char[LS + 1];
	for (Pozition_Stroka1; Pozition_Stroka1 <= this->LengthStrok(); Pozition_Stroka1++)
	{
		if (this->str[Pozition_Stroka1] == string.str[j])
		{
			if (zap == -1)
			{
				zap = Pozition_Stroka1;
			}
			j++;
			if (j == string.LengthStrok())
			{
				int z = 0;
				Pozition_Stroka1++;
				while (string2.str[z] != '\0')
				{
					buf[Pozition_Stroka4] = string.str[z];
					Pozition_Stroka4++;
					z++;
				}
				while (this->str[Pozition_Stroka1] != '\0')
				{
					buf[Pozition_Stroka4] = this->str[Pozition_Stroka1];
					Pozition_Stroka4++;
					Pozition_Stroka1++;
				}
				break;
			}
		}
		else
		{
			if (zap != -1)
			{
				Pozition_Stroka1 = zap;
				buf[Pozition_Stroka4] = this->str[Pozition_Stroka1];
				Pozition_Stroka4++;
				zap = -1;
			}
			else
			{
				buf[Pozition_Stroka4] = this->str[Pozition_Stroka1];
				Pozition_Stroka4++;
			}
			j = 0;
		}
	}
	buf[Pozition_Stroka4] = '\0';
	St->LengthStr = Pozition_Stroka4;
	delete St->str;
	St->str = buf;
	return *St;
};
WorkStrClass& WorkStrClass::SubstitutionStAll(WorkStrClass& string1, WorkStrClass& string2)
{
	int Pozition_Stroka1 = 0;
	int zap = -1;
	int j = 0;
	int z = 0;
	int Pozition_Stroka4 = 0;
	WorkStrClass* St = new WorkStrClass();
	int LS = this->LengthStrok() + string2.LengthStrok();
	char* buf = new char[LS + 1];
	for (Pozition_Stroka1; Pozition_Stroka1 <= this->LengthStrok(); Pozition_Stroka1++)
	{
		if (this->str[Pozition_Stroka1] == string1.str[j])
		{
			if (zap == -1)
			{
				zap = Pozition_Stroka1;
			}
			j++;
			if (j == string1.LengthStrok())
			{
				int z = 0;
				while (string2.str[z] != '\0')
				{
					buf[Pozition_Stroka4] = string2.str[z];
					Pozition_Stroka4++;
					z++;
				}
				zap = -1;
				j = 0;
			}
		}
		else
		{
			if (zap != -1)
			{
				Pozition_Stroka1 = zap;
				buf[Pozition_Stroka4] = this->str[Pozition_Stroka1];
				Pozition_Stroka4++;
				zap = -1;
			}
			else
			{
				buf[Pozition_Stroka4] = this->str[Pozition_Stroka1];
				Pozition_Stroka4++;
			}
			j = 0;
		}
	}
	buf[Pozition_Stroka4] = '\0';
	St->LengthStr = Pozition_Stroka4;
	delete St->str;
	St->str = buf;
	return *St;
}
