#pragma once

#include <iostream>
using std::cout;
using std::endl;


class DownBase
{
public:
	virtual void print() = 0;
};


class DownDerived1 : public DownBase
{
public:
	virtual void print()
	{
		cout << "I am a DownDerived1 class." << endl;
	}
	void DownDerived1Function()
	{
		cout << "I am a special function that only the DownDerived1 class has." << endl;
	}
};

class DownDerived2 : public DownBase
{
public:
	virtual void print()
	{
		cout << "I am a DownDerived2 class." << endl;
	}
	void DownDerived2Function()
	{
		cout << "I am a special function that only the DownDerived2 class has." << endl;
	}
};

class DownDerived3 : public DownBase
{
public:
	virtual void print()
	{
		cout << "I am a DownDerived3 class." << endl;
	}
	void DownDerived3Function()
	{
		cout << "I am a special function that only the DownDerived3 class has." << endl;
	}
};
