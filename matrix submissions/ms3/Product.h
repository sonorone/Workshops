//
//  Product.h
//  ms3
//
//  Created by Damian Murawiecki on 2017-12-05.
//  Copyright © 2017 Damian Murawiecki. All rights reserved.
//

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include <iostream>
#include <fstream>
using namespace std;

namespace sict {
    class Product {
    public:
        virtual fstream& store(fstream& file, bool newLine=true) const = 0;
        virtual fstream& load(fstream& file) = 0;
        virtual ostream& write(ostream& os, bool linear) const = 0;
        virtual istream& read(istream& is) = 0;
        virtual bool operator==(const char*) const = 0;
        virtual double total_cost() const = 0;
        virtual const char* name() const = 0;
        virtual void quantity(int) = 0;
        virtual int qtyNeeded() const = 0;
        virtual int quantity() const = 0;
        virtual int operator+=(int) = 0;
        virtual bool operator>(const Product&) const = 0;
    };
    ostream& operator<<(ostream&, const Product&);
    istream& operator>>(istream&, Product&);
    double operator+=(double&, const Product&);
    Product* CreateProduct();
    Product* CreatePerishable();
}

#endif /* SICT_PRODUCT_H */
