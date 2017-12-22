// Final Project Milestone 2
// Version 1.0
// Date:    November 30, 2017
// Author:  MURAWIECKI, Damian
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ErrorMessage.h"

namespace sict {
    /* explicit 1 param constructor */
    ErrorMessage::ErrorMessage(const char* errorMessage) {
        if (errorMessage == nullptr) {
            addr = nullptr;
        }
        else {
            copyErrorMsg(errorMessage);
        }
    }
    /* deallocates dynamic memory of an ErrorMessage object */
    ErrorMessage::~ErrorMessage() {
        delete [] addr;
    }
    /* clears the state of a current object and sets to an empty state */
    void ErrorMessage::clear() {
        delete [] addr;
        addr = nullptr;
    }
    /* reports the state: true is empty state */
    bool ErrorMessage::isClear() const {
        return (addr == nullptr) ? true : false;
    }
    /* inserts msg into the obj */
    void ErrorMessage::message(const char* str) {
        if (addr != nullptr) delete [] addr;
        copyErrorMsg(str);
    }
    /* returns message content */
    const char* ErrorMessage::message() const {
        return this->addr;
    }
    /* inserts error message to the output stream */
    std::ostream& operator<<(std::ostream& os, const ErrorMessage& er) {
        if (!er.isClear()) {
            std::string copy = er.getAddr();
            std::string s = "test";
            os << copy;
        }
        return os;
    }
    /* helper function for insertion operator */
    std::string ErrorMessage::getAddr() const {
        return addr;
    }
    /* copies message, warning: this func doesn't validate...
     * apply only after checking if in an empty state
     */
    void ErrorMessage::copyErrorMsg(const char* errorMessage) {
        std::string s(errorMessage);
        int size = (int)s.length();
        addr = new char[size];
        strncpy(addr, errorMessage, size-1);
        addr[size] = '\0';
    }
}
