#include <iostream>
#include <stack>
#include "formula_node.h"
#include <functional>
#include <map>
#include <sstream>

std::map<char, std::function<double(double, double)>> function_map = {
	{'+', std::plus<double>()},
	{'-', std::minus<double>()},
	{'*', std::multiplies<double>()},
	{'/', std::divides<double>()}
};

int calc_postfix(const std::string& formula_str){
	std::stack<int> container;
	for (char curr : formula_str){
		if (isdigit(curr)){
			container.push(curr - '0');
			continue;
		}
		char right = container.top(); container.pop();
		char left = container.top(); container.pop();
		container.push(function_map[curr](left,right));
	}

	return container.top();
}

const unsigned char ActionsTable[][6] = {
	//0 + - * / P
	{ 4,2,2,2,2,1},// 0
	{ 3,3,3,2,2,1},// +
	{ 3,3,3,2,2,1},// -
	{ 3,3,3,3,3,1},// *
	{ 3,3,3,3,3,1},// /
};

inline int ActionsRowNumber(char ch) {
	switch (ch) {
		case 0: return 0;
		case '+': return 1;
		case '-': return 2;
		case '*': return 3;
		case '/': return 4;
	}
	return 5;
}

inline int ActionsColNumber(char ch) {
	switch (ch) {
		case 0: return 0;
		case '+': return 1;
		case '-': return 2;
		case '*': return 3;
		case '/': return 4;
	}
	if (ch >= '0' && ch <= '9') return 5;
	return 5;
}

class Formula {
	FormulaNode* _root;
	std::map<char, std::function<FormulaNode*(FormulaNode*, FormulaNode*)>> function_map = {
		{'+', [](FormulaNode* l, FormulaNode* r) {return new PlusNode(l,r); }},
		{'-', [](FormulaNode* l, FormulaNode* r) {return new MinusNode(l,r); }},
		{'*', [](FormulaNode* l, FormulaNode* r) {return new MultNode(l,r); }},
		{'/', [](FormulaNode* l, FormulaNode* r) {return new DivNode(l,r); }}
	};
	FormulaNode* from_postfix(const std::string& postfix_str) {
		std::stack<FormulaNode*> nodes;
		for (char curr : postfix_str) {
			if (isdigit(curr)){
				nodes.push(new NumNode(curr - '0'));
					continue;
			}	
			auto right = nodes.top(); nodes.pop();
			auto left = nodes.top(); nodes.pop();		
			nodes.push(function_map[curr](left,right));
		}
		return nodes.top();
	}

	std::string ifx2pfx(const std::string& ifx_str){
		std::stringstream ss;
		int i = 0, j = 0; // i индекс instr, j индекс в строке outstr
		int row, col;
		unsigned char action;
		std::stack<char> S;
		do {
			col = ActionsColNumber(ifx_str[i]);
			row = S.empty() ? 0 : ActionsRowNumber(S.top());
			action = ActionsTable[row][col];
			switch (action) {
				case 1: ss << ifx_str[i++]; break;
				case 2: S.push(ifx_str[i]); ++i; break;
				case 3: ss << S.top(); S.pop(); break;
			}
		} while (action != 4);
		return ss.str();
	}
public:
	Formula(const std::string& infix_str) { 
		auto pfx_str = ifx2pfx(infix_str);
		std::cout << pfx_str << std::endl;
		_root = from_postfix(pfx_str);
	}
	double calc() const { return _root ? _root->calc() : 0; }
	std::string str() const { return _root ? _root->str() : ""; }
	~Formula() {
		if (_root) delete _root;
		_root = nullptr;
	}
};

int main() {
	//"2+2" <-> "22+"
	//"4*(2+3)-5/2" <-> "23+4*52/-"
	//"2+(3*4)" <-> "234*+" <-> "34*2+"
	//wrong translation: "23+4*"
	//"-2" <-> "02-"
	//std::cout << calc_postfix("23+4*52/-") << std::endl;
	
	//Formula f("23+4*52/-");
	Formula f("2+3*4");
	try{
		std::cout << f.str() << " = " << f.calc() << std::endl;
	} catch (const Error& e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	system("pause");
	return 0;
}