#pragma once

#include "String.h"

class DictPair {
	String _word;
	String _translate;
public:
	DictPair(const String& w = "", const String& t = "");

	const String& word() const;
	const String& translate() const;

	bool operator< (const DictPair&) const;
	bool operator<=(const DictPair&) const;
	bool operator> (const DictPair&) const;
	bool operator>=(const DictPair&) const;
	bool operator==(const DictPair&) const;
	bool operator!=(const DictPair&) const;

};