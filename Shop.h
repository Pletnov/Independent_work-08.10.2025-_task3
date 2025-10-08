#pragma once
#include"Overcoat.h"
#include<vector>
class Shop
{
	vector<Overcoat>shop;
public:
	void add(Overcoat& o) { shop.push_back(o), cout << "Added: " << o.getName(); };
	void remove(Overcoat& o) { 
		if (!shop.empty()) {
			cout << "Removed" << endl;
			shop.pop_back();
		}
		else {
			cout << "The shop is empty, nothing to remove!\n";
		}
	};
	void editSize(int index, bool increase) {
		if (index >= 0 && index < (int)shop.size()) {
			if (increase)
				++shop[index];
			else
				--shop[index];
			cout << "New size: " << shop[index].getSize() << endl;
		}
		else {
			cout << "Invalid index!\n";
		}
	}
	void findByType(const string& type)const {
		bool found = false;
		for (int i = 0; i < shop.size(); i++) {
			if (shop[i].getType() == type) {
				cout << shop[i] << endl;
				found = true;
			}
		}
		if (!found)
			cout << "No items of type " << type << " found\n";
	}
	void sortByPrice() {
		for (int i = 0; i < shop.size(); i++) {
			for (int j = 0; j < shop.size() - i - 1; j++) {
				if (shop[j].getPrice() > shop[j + 1].getPrice()) {
					Overcoat temp = shop[j];
					shop[j] = shop[j + 1];
					shop[j + 1] = temp;
				}
			}
		}
		cout << "Sorted by price\n";
	}
	void showAll() const {
		if (shop.empty()) {
			cout << "The shop is empty.\n";
			return;
		}

		for (int i = 0; i < shop.size(); ++i) {
			cout << "#" << shop[i].getProductNumber() << " " << shop[i].getName() << endl;
			cout << "   Type: " << shop[i].getType() << endl;
			cout << "   Size: " << shop[i].getSize() << endl;
			cout << "   Price: " << shop[i].getPrice() << " UAH" << endl;
			cout << "---------------------------------------\n";
		}
	}
};

