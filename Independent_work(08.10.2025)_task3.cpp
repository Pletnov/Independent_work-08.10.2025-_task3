#include <iostream>
#include"Overcoat.h"
#include"Shop.h"
int Overcoat::counter = 0;
int main()
{
Shop store;

    Overcoat c1("Winter Coat", "male", 52, 3000);
    Overcoat c2("Autumn Coat", "female", 46, 1800);
    Overcoat c3("Kids Jacket", "child", 32, 900);
    store.add(c1);
    store.add(c2);
    store.add(c3);

    store.showAll();

    store.findByType("female");

    store.sortByPrice();
    store.showAll();

    store.editSize(1, true);
    store.showAll();

    return 0;
}

