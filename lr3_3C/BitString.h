#pragma once
#include "Object.h"
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class BitString : public Object
{
private:
    long High;
    long Low;

public:

    // Конструктори
    BitString();
    BitString(long high, long low);
    BitString(const BitString& obj);

    // Методи доступу
    long GetHigh() const;
    long GetLow() const;

    void SetHigh(long high);
    void SetLow(long low);

    // Основні методи
    void Init(long high, long low);
    void Read();
    void Display() const;
    string toString() const;
    
    // Перетворення типу
    operator string() const;

    // Операції
    BitString& operator=(const BitString& obj);

    friend BitString operator^(const BitString& a, const BitString& b);

    BitString shiftLeft(int n) const;
    BitString shiftRight(int n) const;

    // Інкремент
    BitString& operator++();
    BitString operator++(int);

    // Декремент
    BitString& operator--();
    BitString operator--(int);


    // Введення та виведення
    friend istream& operator>>(istream& in, BitString& obj);
    friend ostream& operator<<(ostream& out, const BitString& obj);
};
