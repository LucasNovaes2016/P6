#include <iostream>
#include <string>

using namespace std;

class visible {
public:
	visible(string&& msg) : msg_{move(msg)} {cout << msg_ << '\n'; }
	string const& msg() const { return msg_; }
private:
	string msg_;
};

class base1 : virtual public visible {
public:
	base1(int x) : visible{"base1 constructed"}, value_{x} {}
	int value() const { return value_;}
private:
	int value_;
};

class base2 : virtual public visible {
public:
	base2(string const& str) : visible{"base2{" + str + "} constructed"} {}

};

class base3 : virtual public visible {
public:
	base3() : visible{"base3 constructed"} {} 
	int value() const { return 42; }
};

class derived : public base1, public base2, public base3 {
public:
	derived(int i, string const& str)
	: base3{}, base2{str}, base1{}, visible{"derived"}
	{}
	int value() const { return base1::value() + base3::value(); } 

	string msg() const {
		return base1::msg() + "\n" + base2::msg() + "\n" + base3::msg();
	}
};

int main () {
	derived d{42, "example"};
	cout << d.value() << '\n' << d.msg() << '\n';
}
