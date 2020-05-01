#include <iostream>
#include <stack>
#include "formula_node.h"
#include <functional>
#include <map>

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
public:
	Formula(const std::string& postfix_str) { _root = from_postfix(postfix_str); }
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
	
	Formula f("23+4*52/-");
	try{
		std::cout << f.str() << " = " << f.calc() << std::endl;
	} catch (const Error& e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	system("pause");
	return 0;
}