#pragma once

class String
{
	size_t _size;
	char* _data;
public:
	String(const char* str = "");
	String(int size);
	String(const String&);
	~String();

	int size() const;
	int length() const;
	const char* str() const;

	char& operator[](int idx) const;
	String& operator= (const String&);
	String& operator+=(const String&);
	String  operator+ (const String&) const;

	bool operator==(const String& X) const;
	bool operator!=(const String& X) const;
	bool operator< (const String& X) const;
	bool operator<=(const String& X) const;
	bool operator> (const String& X) const;
	bool operator>=(const String& X) const;
};

#include <iostream>
std::ostream& operator<< (std::ostream&, const String&);
