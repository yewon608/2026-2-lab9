#pragma once
#include "student.h"

namespace kimyewon2649007{
    class studentPtr{
        student* sPtr;
    public:
        studentPtr(const student& s = student{"name", 1234567, 0})
        :sPtr{new student{s}}{
            std::cout << "constructor\n";
        }
        ~studentPtr(){delete sPtr;}

        studentPtr(const studentPtr& copy){
            std::cout << "copy constructor\n";
            sPtr = copy.sPtr ? new student{*copy.sPtr} : nullptr;
        }

        studentPtr(studentPtr&& move) noexcept{
            std::cout << "move constructor\n";
            sPtr = move.sPtr;
            move.sPtr = nullptr;
        }
        
        studentPtr& operator=(const studentPtr& copy){
            std::cout << "copy operator=\n";
            if (this != &copy){
                delete sPtr;
                sPtr = copy.sPtr ? new student{*copy.sPtr} : nullptr;
            }
            return *this;
        }
        studentPtr& operator=(studentPtr&& move){
            std::cout << "move operator=\n";
             if (this != &move){
                delete sPtr;
                sPtr = move.sPtr;
                move.sPtr = nullptr;
            }
            return *this;
        }

        void print() const{
            if (sPtr) std::cout << *sPtr;
            else std::cout<<"no data(nullptr)\n";
        }
    };
}
