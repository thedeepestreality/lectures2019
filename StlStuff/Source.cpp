#include <iostream>
#include <array>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <tuple>

void test(std::array<int,3> arr)
{

}

template <typename Type, size_t Size>
class Array {
	Type _arr[Size];
public:
	size_t size() { return Size; }
};

template <typename Type, template<typename> typename Container>
class Test
{
	void foo()
	{
		Container<Type> cont;
	}
};

std::map<std::string, int> dictionary =
{
	{"one", 1},
	{"two", 2}
};

std::multimap<std::string, int> multi_dict =
{
	{"one", 1},
	{"one", 2}
};

class ChildFree final
{
public:
	ChildFree() = default;
	ChildFree(int, double, std::string) {}
};

// compilation error
//class Child : public ChildFree
//{
//
//};

std::tuple<bool, int> find()
{
	return std::make_tuple(true, 1);
}

void foo(int x, double d, std::string s)
{
	std::cout << "CALL OF FOO" << std::endl;
	std::cout << x << std::endl;
	std::cout << d << std::endl;
	std::cout << s << std::endl;
}

int main()
{
	int x[3] = { 1,2,3 };
	std::array<int, 3> arr = { 1, 2, 3 };
	
	dictionary["three"] = 3;
	//dictionary.at("four"); //will throw exception
	std::pair<std::string, int> p("four", 4);
	dictionary.insert(p);
	dictionary.insert(std::make_pair("five",5));

	auto begin = multi_dict.lower_bound("one");
	auto end = multi_dict.upper_bound("one");
	while (begin != end)
		std::cout << (*(begin++)).second << std::endl;

	std::multiset<int> s = { 5,5,3,3,2,1,4,3,5,1,3,5,4 };
	for (auto it = s.begin(); it != s.end(); ++it)
		std::cout << *it << std::endl;
	if (s.find(1) != s.end()) std::cout << "exists!" << std::endl;
	std::cout << "there are " << s.count(5) << " elements '5'" << std::endl;

	std::priority_queue<int> pq;
	pq.push(1);
	pq.push(3);
	pq.push(8);
	pq.push(5);
	pq.push(6);
	pq.pop();
	std::cout << "pq top: " << pq.top() << std::endl;

	std::tuple<int, double, std::string> t(1, 2.0, "three");
	int t0 = std::get<0>(t);
	//std::make_tuple(1, 2.5, std::string("22"));
	std::apply(foo, std::make_tuple(1, 2.5, std::string("str")));
	auto obj = std::make_from_tuple<ChildFree>(t);

	
	system("pause");
	return 0;
}