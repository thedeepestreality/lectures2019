#include <iostream>
#include <stack>
#include "formula_node.h"
#include <map>
#include <functional>

std::map<char, std::function<double(double, double) >> operator_map =
{
	{'+', std::plus<double>()},
	{'-', std::minus<double>()},
	{'*', std::multiplies<double>()},
	{'/', std::divides<double>()}
};

double calc_postfix(const std::string& formula_str){
	std::stack<double> container;
	for (char curr : formula_str){
		if (isdigit(curr)) {
			container.push(curr - '0');
			continue;
		}
		double right = container.top(); container.pop();
		double left = container.top(); container.pop();
		container.push(operator_map[curr](left,right));
	}
	return container.top();
}

class Formula {
	FormulaNode* _root;
	FormulaNode* from_postfix(const std::string& postfix_str) {
		std::stack<FormulaNode*> nodes;
		for (char curr : postfix_str) {
			FormulaNode* node;
			switch (curr) {
				case '+':
				{
					auto right = nodes.top(); nodes.pop();
					auto left = nodes.top(); nodes.pop();
					node = new PlusNode(left, right);
					break;
				}
				case '-':
				{
					auto right = nodes.top(); nodes.pop();
					auto left = nodes.top(); nodes.pop();
					node = new MinusNode(left, right);
					break;
				}
				case '*':
				{
					auto right = nodes.top(); nodes.pop();
					auto left = nodes.top(); nodes.pop();
					node = new MultNode(left, right);
					break;
				}
				case '/':
				{
					auto right = nodes.top(); nodes.pop();
					auto left = nodes.top(); nodes.pop();
					node = new DivNode(left, right);
					break;
				}
				default:
					if (isdigit(curr)) node = new NumNode(curr - '0');
			}
			nodes.push(node);
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
	setlocale(LC_ALL, "Rus");
	//"2+2" <-> "22+"
	//"4*(2+3)-5/2" <-> "23+4*52/-"
	//"2+(3*4)" <-> "234*+" <-> "34*2+"
	//wrong translation: "23+4*"
	//"-2" <-> "02-"

	std::cout << calc_postfix("23+4*50/-") << std::endl;
	//double x = 0;
	//std::cout << 1. / x << std::endl;
	/*Formula f("23+4*52/-");
	try{
		std::cout << f.str() << " = " << f.calc() << std::endl;
	} catch (const Error& e){
		std::cout << "Error: " << e.what() << std::endl;
	}*/

	system("pause");
	return 0;
}
