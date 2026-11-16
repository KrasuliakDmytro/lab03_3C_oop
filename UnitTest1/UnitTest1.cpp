#include "pch.h"
#include "CppUnitTest.h"
#include "../lr3_3C/BitString.h"
#include "../lr3_3C/Object.h"

#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(BitStringTests)
    {
    public:

        // =========================================
        // МЕТОДИ ДОСТУПУ
        // =========================================

        // Перевірка GetHigh і GetLow
        TEST_METHOD(TestGetters)
        {
            BitString obj(100, 200);

            Assert::AreEqual(100L, obj.GetHigh());
            Assert::AreEqual(200L, obj.GetLow());
        }

        // Перевірка SetHigh і SetLow
        TEST_METHOD(TestSetters)
        {
            BitString obj;

            obj.SetHigh(50);
            obj.SetLow(60);

            Assert::AreEqual(50L, obj.GetHigh());
            Assert::AreEqual(60L, obj.GetLow());
        }

        // =========================================
        // ОПЕРАЦІЯ ПРИСВОЄННЯ
        // =========================================

        TEST_METHOD(TestAssignment)
        {
            BitString obj1(10, 20);
            BitString obj2;

            obj2 = obj1;

            Assert::AreEqual(10L, obj2.GetHigh());
            Assert::AreEqual(20L, obj2.GetLow());
        }

        // =========================================
        // ОПЕРАЦІЯ XOR
        // =========================================

        TEST_METHOD(TestXOR)
        {
            BitString obj1(5, 10);
            BitString obj2(3, 12);

            BitString result = obj1 ^ obj2;

            Assert::AreEqual(6L, result.GetHigh());
            Assert::AreEqual(6L, result.GetLow());
        }

        // =========================================
        // ЗСУВ ЛІВОРУЧ
        // =========================================

        // Зсув на 1 біт
        TEST_METHOD(TestShiftLeftOne)
        {
            BitString obj(0, 1);

            BitString result = obj.shiftLeft(1);

            Assert::AreEqual(0L, result.GetHigh());
            Assert::AreEqual(2L, result.GetLow());
        }

        // Зсув на 32 біти
        TEST_METHOD(TestShiftLeft32)
        {
            BitString obj(0, 1);

            BitString result = obj.shiftLeft(32);

            Assert::AreEqual(1L, result.GetHigh());
            Assert::AreEqual(0L, result.GetLow());
        }

        // Зсув на 64 біти
        TEST_METHOD(TestShiftLeft64)
        {
            BitString obj(10, 20);

            BitString result = obj.shiftLeft(64);

            Assert::AreEqual(0L, result.GetHigh());
            Assert::AreEqual(0L, result.GetLow());
        }

        // =========================================
        // ЗСУВ ПРАВОРУЧ
        // =========================================

        // Зсув на 1 біт
        TEST_METHOD(TestShiftRightOne)
        {
            BitString obj(0, 2);

            BitString result = obj.shiftRight(1);

            Assert::AreEqual(0L, result.GetHigh());
            Assert::AreEqual(1L, result.GetLow());
        }

        // Перенесення біта зі старшої частини
        TEST_METHOD(TestShiftRight32)
        {
            BitString obj(1, 0);

            BitString result = obj.shiftRight(32);

            Assert::AreEqual(0L, result.GetHigh());

            string expected =
                string(31, '0') + "1";

            Assert::AreEqual(expected, result.toString().substr(32, 32));
        }

        // Зсув на 64 біти
        TEST_METHOD(TestShiftRight64)
        {
            BitString obj(10, 20);

            BitString result = obj.shiftRight(64);

            Assert::AreEqual(0L, result.GetHigh());
            Assert::AreEqual(0L, result.GetLow());
        }

        // =========================================
        // ІНКРЕМЕНТ
        // =========================================

        // Префіксний ++
        TEST_METHOD(TestPrefixIncrement)
        {
            BitString obj(0, 5);

            ++obj;

            Assert::AreEqual(0L, obj.GetHigh());
            Assert::AreEqual(6L, obj.GetLow());
        }

        // Постфіксний ++
        TEST_METHOD(TestPostfixIncrement)
        {
            BitString obj(0, 5);

            BitString old = obj++;

            Assert::AreEqual(5L, old.GetLow());
            Assert::AreEqual(6L, obj.GetLow());
        }

        // Переповнення молодшої частини
        TEST_METHOD(TestIncrementCarry)
        {
            BitString obj(0, -1);

            ++obj;

            Assert::AreEqual(1L, obj.GetHigh());
            Assert::AreEqual(0L, obj.GetLow());
        }

        // =========================================
        // ДЕКРЕМЕНТ
        // =========================================

        // Префіксний --
        TEST_METHOD(TestPrefixDecrement)
        {
            BitString obj(0, 5);

            --obj;

            Assert::AreEqual(0L, obj.GetHigh());
            Assert::AreEqual(4L, obj.GetLow());
        }

        // Постфіксний --
        TEST_METHOD(TestPostfixDecrement)
        {
            BitString obj(0, 5);

            BitString old = obj--;

            Assert::AreEqual(5L, old.GetLow());
            Assert::AreEqual(4L, obj.GetLow());
        }

        // =========================================
        // ЛІЧИЛЬНИК ОБ'ЄКТІВ
        // =========================================

        TEST_METHOD(TestObjectCounter)
        {
            int before = Object::GetObjectCount();

            {
                BitString obj;
            }

            int after = Object::GetObjectCount();

            Assert::AreEqual(before + 1, after);
        }
    };
}
