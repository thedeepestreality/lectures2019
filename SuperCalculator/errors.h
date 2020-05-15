#pragma once
#include <string>

class Error {
public:
	virtual std::string what() const { return "Error"; }
};

class ErrorDivByZero : public Error {
public:
	std::string what() const override { return "Division by zero"; }
};

class ErrorBraketsOpen : public Error {
	const std::string& _str;
	int _idx;
public:
	ErrorBraketsOpen(const std::string& str, int idx) : _str(str), _idx(idx) {}
	std::string what() const {
		return std::string("Error with brackets. There are no ( for ) in '")
			+ _str
			+ std::string("' at position ") + std::to_string(_idx);
	}
};

//------------------------------------------------------------------
class ErrorBraketsClose : public Error {
	const std::string& _str;
	int _idx;
public:
	ErrorBraketsClose(const std::string& str, int idx) : _str(str), _idx(idx) {}
	std::string what() const {
		return std::string("Error with brackets. There are no ) for ( in '")
			+ _str
			+ std::string("' at position ") + std::to_string(_idx);
	}
};