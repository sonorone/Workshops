//
//  NonPerishable.hpp
//  ms4
//
//  Created by Damian Murawiecki on 2017-12-14.
//  Copyright © 2017 Damian Murawiecki. All rights reserved.
//

#ifndef SICT_NONPERISHABLE_H
#define SICT_NONPERISHABLE_H

#include "Product.h"
#include "ErrorMessage.h"

namespace sict {
    
    const long max_sku_length = 7;
    const long long max_unit_length = 10;
    const int max_name_length = 75;
    const double tax = 0.13;
    
    class NonPerishable : public Product {
        char type;
        char sku[max_sku_length+1];
        char* pName;
        char unit[max_sku_length+1];
        int stockQty;
        bool isTaxed;
        double price;
        int needsQty;
        ErrorMessage errState;
        void init(const NonPerishable&);
        
    protected:
        void name(const char*);
        const char* name() const; // TO REVIEW *************************** in interface it's public
        double cost() const;
        void message(const char*);
        bool isClear() const;
        /* should be protected|private? */// TO REVIEW *******************
        void cpChars(char*, const char*, int);
        
    public:
        NonPerishable(char t = '\0');
        NonPerishable(const char* argSku, const char* argPName,
                      const char* argUnit, int argStockQty=0,
                      bool argTax=0, double argPrice=0, int argNeedsQty=0);
        NonPerishable(const NonPerishable& rhs);
        NonPerishable& operator=(const NonPerishable&);
        ~NonPerishable();
        std::fstream& store(std::fstream& file, bool newLine=true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        int operator+=(int);
        bool operator>(const Product&) const;
    };
    std::ostream& operator<<(std::ostream&, const Product&);
    std::istream& operator>>(std::istream&, Product&);
    double operator+=(double&, const Product&);
    Product* CreateProduct();
}

#endif /* SICT_NONPERISHABLE_H */
