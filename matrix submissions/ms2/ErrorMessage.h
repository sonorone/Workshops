// Final Project Milestone 2
// Version 1.0
// Date:    November 30, 2017
// Author:  MURAWIECKI, Damian
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason

#ifndef ERROR_MESSAGE_H
#define ERROR_MESSAGE_H
#include <iostream>
#include <string>

namespace sict {
    class ErrorMessage {
        /* 'addr' will store location of a c-style string
         * pointer since the size is yet to be defined
         */
        char* addr;
        void copyErrorMsg(const char* );
    public:
        explicit ErrorMessage(const char* errorMessage = nullptr);
        ErrorMessage(const ErrorMessage& em) = delete;
        ErrorMessage& operator=(const ErrorMessage& em) = delete;
        virtual ~ErrorMessage();
        void clear();
        bool isClear() const;
        void message(const char* str);
        const char* message() const;
        std::string getAddr() const;
    };
    std::ostream& operator<<(std::ostream&, const ErrorMessage&);
}
#endif
