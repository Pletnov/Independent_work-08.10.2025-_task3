#pragma once
#include<iostream>
#include<string>
using namespace std;
class Overcoat
{
	string name;
	string type;
	int size;
	double price;
	int productNumber; 
	static int counter;
public:
	Overcoat() { name = "Undefined", type = "Undefined", size = 0, price = 0, productNumber = 0; };
	Overcoat(string name, string type, int size, double price) 
	{
		this->name = name;
		this->type = type;
		if (size % 2 == 0)
			this->size = size;
		else
			cout << "WRONG SIZE!!!";
			size = 0;
		this->price = price, productNumber = ++counter;};

	void setName(string n) { name = n; };
	void setType(string t) { type = t; };
	void setSize(int s) {
		if (s % 2 == 0) {
			size = s;
		}
		else cout << "WRONG SIZE!!!";
	};
	void setPrice(double p) { price = p; };
	string getName()const { return name; };
	string getType()const { return type; };
	int getSize()const { return size; };
	double getPrice()const { return price; };
	int getProductNumber()const { return productNumber; };

	bool operator==(const Overcoat& o)const { return this->type == o.type; };
	bool operator!=(const Overcoat& o)const { return!(*this == o); };

	bool operator>(const Overcoat& o)const { return this->price > o.price; };
	bool operator<(const Overcoat& o)const { return this->price < o.price; };
	bool operator>=(const Overcoat& o)const { return this->price >= o.price; };
	bool operator<=(const Overcoat& o)const { return this->price <= o.price; };

	Overcoat& operator++() {
		size += 2;
		return *this;
	};
	Overcoat operator++(int) {
		Overcoat temp = *this;
		size += 2;
		return temp;
	};
	Overcoat& operator--() {
		size -= 2;
		return *this;
	};
	Overcoat operator--(int) {
		Overcoat temp = *this;
		size -= 2;
		return temp;
	};

	friend ostream& operator<<(ostream& os, const Overcoat& o)
	{
		os << "Product #" << o.productNumber << "\n" << "Name: " << o.name << "\n" << "Type: " << o.type << "\n" << "Size: " << o.size << "\n"
			<< "Price: " << o.price << " UAH\n";
		return os;
	};

	friend istream& operator>>(istream& is, Overcoat& o)
	{
		cout << "Enter name: ";
		is.ignore();
		getline(is, o.name);
		cout << "Enter type (male/female/child): ";
		getline(is, o.type);
		do {
			cout << "Enter size (must be even): ";
			is >> o.size;
			if (o.size % 2 != 0)
				cout << "WRONG SIZE!!!\n";
		} while (o.size % 2 != 0);
		cout << "Enter price: ";
		is >> o.price;
		o.productNumber = ++counter;
		return is;
	};
};

