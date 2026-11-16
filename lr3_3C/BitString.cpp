#include "BitString.h"

// =====================================================
// КОНСТРУКТОРИ
// =====================================================

// Конструктор без параметрів
BitString::BitString() : Object()
{
    High = 0;
    Low = 0;
}

// Конструктор з параметрами
BitString::BitString(long high, long low) : Object()
{
    High = high;
    Low = low;
}

// Конструктор копіювання
BitString::BitString(const BitString& obj) : Object(obj)
{
    High = obj.High;
    Low = obj.Low;
}


// =====================================================
// МЕТОДИ ДОСТУПУ
// =====================================================

// Отримання старшої частини
long BitString::GetHigh() const
{
    return High;
}

// Отримання молодшої частини
long BitString::GetLow() const
{
    return Low;
}

// Встановлення старшої частини
void BitString::SetHigh(long high)
{
    High = high;
}

// Встановлення молодшої частини
void BitString::SetLow(long low)
{
    Low = low;
}


// =====================================================
// ОСНОВНІ МЕТОДИ
// =====================================================

// Ініціалізація
void BitString::Init(long high, long low)
{
    SetHigh(high);
    SetLow(low);
}

// Введення
void BitString::Read()
{
    cout << "Введіть 64-бітовий рядок (64 символи 0 або 1): ";

    cin >> *this;

    if (!cin)
        cout << "Помилка введення!" << endl;
}

// Виведення
void BitString::Display() const
{
    cout << toString() << endl;
}

// Перетворення у двійковий рядок
string BitString::toString() const
{
    uint32_t h = static_cast<uint32_t>(High);
    uint32_t l = static_cast<uint32_t>(Low);

    string result;

    for (int i = 31; i >= 0; i--)
        result += ((h >> i) & 1) ? '1' : '0';

    for (int i = 31; i >= 0; i--)
        result += ((l >> i) & 1) ? '1' : '0';

    return result;
}

// Перетворення у string
BitString::operator string() const
{
    return toString();
}

// =====================================================
// ОПЕРАЦІЯ ПРИСВОЄННЯ
// =====================================================

BitString& BitString::operator=(const BitString& obj)
{
    if (this != &obj)
    {
        High = obj.High;
        Low = obj.Low;
    }

    return *this;
}


// =====================================================
// XOR
// =====================================================

BitString operator^(const BitString& a, const BitString& b)
{
    BitString result;

    uint32_t h1 = static_cast<uint32_t>(a.GetHigh());
    uint32_t l1 = static_cast<uint32_t>(a.GetLow());

    uint32_t h2 = static_cast<uint32_t>(b.GetHigh());
    uint32_t l2 = static_cast<uint32_t>(b.GetLow());

    result.SetHigh(static_cast<long>(h1 ^ h2));
    result.SetLow(static_cast<long>(l1 ^ l2));

    return result;
}


// =====================================================
// ЗСУВ ЛІВОРУЧ
// =====================================================

BitString BitString::shiftLeft(int count) const
{
    BitString result;

    uint32_t h = static_cast<uint32_t>(High);
    uint32_t l = static_cast<uint32_t>(Low);

    if (count <= 0)
        return *this;

    if (count >= 64)
        return result;

    if (count >= 32)
    {
        result.SetHigh(static_cast<long>(l << (count - 32)));
        result.SetLow(0);
    }
    else
    {
        result.SetHigh(static_cast<long>(
            (h << count) | (l >> (32 - count))
            ));

        result.SetLow(static_cast<long>(l << count));
    }

    return result;
}


// =====================================================
// ЗСУВ ПРАВОРУЧ
// =====================================================

BitString BitString::shiftRight(int count) const
{
    BitString result;

    uint32_t h = static_cast<uint32_t>(High);
    uint32_t l = static_cast<uint32_t>(Low);

    if (count <= 0)
        return *this;

    if (count >= 64)
        return result;

    if (count >= 32)
    {
        result.SetHigh(0);

        result.SetLow(static_cast<long>(
            h >> (count - 32)
            ));
    }
    else
    {
        result.SetHigh(static_cast<long>(h >> count));

        result.SetLow(static_cast<long>(
            (l >> count) | (h << (32 - count))
            ));
    }

    return result;
}


// =====================================================
// ІНКРЕМЕНТ
// =====================================================

// Префіксний
BitString& BitString::operator++()
{
    uint32_t h = static_cast<uint32_t>(High);
    uint32_t l = static_cast<uint32_t>(Low);

    l++;

    if (l == 0)
        h++;

    High = static_cast<long>(h);
    Low = static_cast<long>(l);

    return *this;
}

// Постфіксний
BitString BitString::operator++(int)
{
    BitString old = *this;

    ++(*this);

    return old;
}


// =====================================================
// ДЕКРЕМЕНТ
// =====================================================

// Префіксний
BitString& BitString::operator--()
{
    uint32_t h = static_cast<uint32_t>(High);
    uint32_t l = static_cast<uint32_t>(Low);

    if (l == 0)
        h--;

    l--;

    High = static_cast<long>(h);
    Low = static_cast<long>(l);

    return *this;
}

// Постфіксний
BitString BitString::operator--(int)
{
    BitString old = *this;

    --(*this);

    return old;
}


// =====================================================
// ВВЕДЕННЯ ТА ВИВЕДЕННЯ
// =====================================================

// Дружній оператор введення
istream& operator>>(istream& in, BitString& obj)
{
    string bits;

    if (!(in >> bits))
        return in;

    if (bits.length() != 64)
    {
        in.setstate(ios::failbit);
        return in;
    }

    uint32_t h = 0;
    uint32_t l = 0;

    for (int i = 0; i < 32; i++)
    {
        if (bits[i] != '0' && bits[i] != '1')
        {
            in.setstate(ios::failbit);
            return in;
        }

        h = (h << 1) | (bits[i] - '0');
    }

    for (int i = 32; i < 64; i++)
    {
        if (bits[i] != '0' && bits[i] != '1')
        {
            in.setstate(ios::failbit);
            return in;
        }

        l = (l << 1) | (bits[i] - '0');
    }

    obj.SetHigh(static_cast<long>(h));
    obj.SetLow(static_cast<long>(l));

    return in;
}

// Дружній оператор виведення
ostream& operator<<(ostream& out, const BitString& obj)
{
    out << obj.toString();

    return out;
}
