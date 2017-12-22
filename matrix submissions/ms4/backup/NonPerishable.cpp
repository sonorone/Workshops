//
//  NonPerishable.cpp
//  ms4
//
//  Created by Damian Murawiecki on 2017-12-14.
//  Copyright © 2017 Damian Murawiecki. All rights reserved.
//

#include <cstring>
#include <fstream>
#include "NonPerishable.h"

namespace sict {
    /* REGION with public functions */
    /* default constructor with optional param which defines product type ("t").
     */
    NonPerishable::NonPerishable(char t) {
        type = t;
        sku[0] = '\0';
        pName = nullptr;
        unit[0] = '\0';
        stockQty = -1;
        isTaxed = false;
        price = -1.0;
        needsQty = -1;
    }
    /* 7 param constructor:
     *      argSku - product sku
     *      argPName - product name
     *      argUnit - product unit
     *      argStockQty - quantity on hand
     *      argTax - is taxable?
     *      argNeedsQty - quantity needed
     *      argStockQty - on hand product quantity (defaults to zero).
     */
    NonPerishable::NonPerishable(const char* argSku, const char* argPName,
                                 const char* argUnit, int argStockQty,
                                 bool argTax, double argPrice, int argNeedsQty) {
        *this = NonPerishable();
        strncpy(sku, argSku, max_sku_length);
        sku[max_sku_length] = '\0';
        name(argPName);
        strncpy(unit, argUnit, max_sku_length);
        unit[max_sku_length] = '\0';
        stockQty = argStockQty;
        isTaxed = argTax;
        price = argPrice;
        needsQty = argNeedsQty;
    }
    /* copy constructor.
     */
    NonPerishable::NonPerishable(const NonPerishable& src) {
        pName = nullptr;
        *this = src;
    }
    /* copy assignment operator.
     */
    NonPerishable& NonPerishable::operator=(const NonPerishable& rhs) {
        if (this != &rhs) {
            if (rhs.pName != nullptr)
                delete [] pName;
            init(rhs);
        }
        return *this;
    }
    /* Destructor.
     */
    NonPerishable::~NonPerishable() {
        delete [] pName;
    }
    /* query that store obj's data into file // TO REVIEW **********************
     */
    std::fstream& NonPerishable::store(std::fstream& file, bool newLine) const {
        if (!file.is_open()) {
            // TODO: REVIEW ****************************************************
        }
        else {
            if (!isEmpty()){
                file.open("Product.txt", std::ios::out);
                file << sku << ',' << name() << ',' << quantity() << ','
                << qtyNeeded() << ',' << isTaxed << ',' << price << std::endl;
                file.clear();
                file.close();
            }
        }
        return file;
    }
    std::fstream& NonPerishable::load(std::fstream& file) {
        file.open("Product.txt", std::ios::in);
        file >> sku;
        file >> pName;
        file >> stockQty;
        file >> needsQty;
        file >> isTaxed;
        file >> price;
        file.clear();
        file.close();
        return file;
    }
    std::ostream& NonPerishable::write(std::ostream& os, bool linear) const {
        if (!isEmpty() && linear) {
            os << std::ios::fixed
            << os.width(max_sku_length) << sku << "|"
            << os.width(20) << name() << "|"
            << os.width(7) << os.precision(2) << total_cost() << "|"
            << os.width(4) << quantity() << "|"
            << os.width(10) << unit << "|"
            << os.width(4) << qtyNeeded();
        }
        else if (!isEmpty() && !linear) {
            os << std::ios::fixed
            << "Sku: " << os.width(max_sku_length) << sku << std::endl
            << "Name: " << os.width(20) << name() << std::endl
            << "Price: " << os.width(7) << os.precision(2) << cost() << std::endl;
            if (isTaxed) os << "Price after tax: " << price * (tax+1) << std::endl;
            else os << "N/A" << std::endl;
            os << os.width(4) << quantity() << std::endl
            << os.width(10) << unit << std::endl
            << os.width(4) << qtyNeeded() << std::endl;
        }
        return os;
    }
    std::istream& NonPerishable::read(std::istream& is) {
        char taxed;
        int keepreading = 1;
        
        std::cout << " Sku: ";
        is >> sku;
        std::cout << " Name: ";
        is >> pName;
        std::cout << " Unit: ";
        is >> unit;
        
        do {
            std::cout << " Taxed? (y/n): ";
            is >> taxed;
            if (taxed == ('y'|'Y')) {
                isTaxed = true;
                keepreading = 0;
            }
            else if (taxed == ('n'|'N')) {
                isTaxed = false;
                keepreading = 0;
            }
            else if (is.fail()) {
                is.setstate(std::ios::failbit);
                is.clear();
                is.ignore(2000, '\n');
                errState.message("Only (Y)es or (N)o are acceptable");
            }
        } while (keepreading == 1);
        
        std::cout << " Price: ";
        is >> price;
        std::cout << " Quantity on hand: ";
        is >> stockQty;
        std::cout << " Quantity Needed: ";
        is >> needsQty;
        return is;
    }
    /* checks if the sku on the lhs matches rhs.
     */
    bool NonPerishable::operator==(const char* rhs) const {
        // return (std::strcmp(sku, rhs) == 0) ? true : false;
        bool isEqual = false;
        std::string left(sku);
        std::string right(rhs);
        for (int i = 0; left.length() == right.length() && i < (int)left.length(); ++i) {
            isEqual = (sku[i] == rhs[i]);
        }
        return isEqual;
    }
    /* returns the total cost of all items on hand.
     */
    double NonPerishable::total_cost() const {
        return isTaxed ? price * stockQty * (1+tax) : price * stockQty;
    }
    /* modifies the number of units of the product.
     */
    void NonPerishable::quantity(int q) {
        stockQty = q;
    }
    /* checks error state.    // TO REVIEW *************************************
     */
    bool NonPerishable::isEmpty() const {
        bool clear = errState.isClear() ? true : false;
        clear = (type == '\0' && sku[0] == '\0' && pName == nullptr);
        return clear;
    }
    /* returns the number of units of the current obj that are needed.
     */
    int NonPerishable::qtyNeeded() const {
        return needsQty;
    }
    /* returns the number of units on hand.
     */
    int NonPerishable::quantity() const {
        return stockQty;
    }
    /* compare string with sku.
     */
    bool NonPerishable::operator>(const char* src) const {
        return (strcmp(sku, src) > 0) ? true : false;
    }
    /* modifies units of the product and returns updated quantity.
     */
    int NonPerishable::operator+=(int i) {
        if (i > 0)
            stockQty += i;
        return stockQty;
    }
    /* queries name of current obj and rhs obj and returns true if lhs is greater.
     */
    bool NonPerishable::operator>(const Product& rhs) const {
        return (strcmp(pName, rhs.name())) ? true : false;
    }
    /* END of REGION (public functions) */
    
    
    /* REGION with 'protected' member functions */
    /* Receives the name of the product and stores it in dynamic memory.
     * If param is nullptr, removes the name of the product from memory.
     */
    void NonPerishable::name(const char* name) {
        if (name != nullptr) {
            std::string s(name);
            int ss = (int)s.length();
            delete [] pName;
            pName = new char[ss];
            strncpy(pName, name, ss);
            pName[ss] = '\0';
        }
        else {
            delete [] pName;
            pName = nullptr;
        }
    }
    /* returns name of the product.
     */
    const char* NonPerishable::name() const { return pName; }
    /* returns price with taxes, if any.
     */
    double NonPerishable::cost() const { return isTaxed ? price * (tax+1) : price; }
    /* passes an error text to ErrorMessage variable in the current obj.
     */
    void NonPerishable::message(const char* msg) {
        errState.message(msg);
    }
    /* checks if errState is empty.
     */
    bool NonPerishable::isClear() const { return errState.isClear(); }
    /* END of REGION with 'protected' member functions */
    
    
    /* REGION with localized code */
    /* copies array of chars from/to static memory.
     */
    void NonPerishable::cpChars(char* dest, const char* src, int limit) {
        std::string s(src);
        int ss = (int)s.length();
        limit = (limit < ss) ? limit : ss;
        strncpy(dest, src, limit);
        dest[limit] = '\0';
    }
    /* init() copies all data members.
     */
    void NonPerishable::init(const NonPerishable& rhs) {
        
        // shallow copies
        type = rhs.type;
        cpChars(sku, rhs.sku, max_sku_length);
        cpChars(unit, rhs.unit, max_sku_length);
        stockQty = rhs.stockQty;
        isTaxed = rhs.isTaxed;
        price = rhs.price;
        needsQty = rhs.needsQty;
        errState.clear(); // TO REVIEW ***************************************
        
        // allocate new dynamic memory, if needed
        if (rhs.pName != nullptr) {
            std::string s(rhs.pName);
            int ss = (int)s.length();
            pName = new char[s.length()];
            cpChars(pName, rhs.pName, ss);
        }
        else {
            pName = nullptr;
        }
    }
    /* END of REGION (localization) */
    
    
    /* REGION with helper functions */
    std::ostream& operator<<(std::ostream& fout, const Product& prod) {
        prod.write(fout, true);
        return fout;
    }
    std::istream& operator>>(std::istream& fin, Product& prod) {
        prod.read(fin);
        return fin;
    }
    double operator+=(double& lhs, const Product& rhs) {
        lhs += rhs.total_cost();
        return lhs;
    }
    Product* CreateProduct() {
        Product* p = new NonPerishable();
        return p;
    }
    /* END of REGION (helper functions) */
}
