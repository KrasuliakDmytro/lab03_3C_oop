#include <iostream>
#include <string>

#include "Object.h"
#include "BitString.h"

using namespace std;

int main()
{
    cout << "===== LABORATORNA ROBOTA =====" << endl;
    cout << "Klasy Object i BitString" << endl << endl;

    // 1. Створення об'єкта конструктором без аргументів
    cout << "1. Konstruktor bez argumentiv:" << endl;

    BitString a;
    a.Display();

    // 2. Створення об'єкта конструктором ініціалізації
    cout << "\n2. Konstruktor inicializacii:" << endl;

    BitString b(10, 25);
    b.Display();

    // 3. Створення об'єкта конструктором копіювання
    cout << "\n3. Konstruktor kopiyuvannya:" << endl;

    BitString c(b);
    c.Display();

    // 4. Присвоєння
    cout << "\n4. Operaciya prisvoyennya:" << endl;

    a = b;
    a.Display();

    // 5. Методи доступу
    cout << "\n5. Metodi dostupu:" << endl;

    cout << "High: " << b.GetHigh() << endl;
    cout << "Low: " << b.GetLow() << endl;

    // 6. Методи запису
    cout << "\n6. Metodi zapisu:" << endl;

    a.SetHigh(15);
    a.SetLow(30);

    a.Display();

    // 7. Метод Init
    cout << "\n7. Metod Init:" << endl;

    a.Init(100, 200);
    a.Display();

    // 8. Перетворення у string
    cout << "\n8. Peretvorennya u string:" << endl;

    string str = b;
    cout << str << endl;

    // 9. Операція XOR
    cout << "\n9. Operaciya XOR:" << endl;

    BitString xorResult = a ^ b;

    cout << "A: ";
    a.Display();

    cout << "B: ";
    b.Display();

    cout << "A XOR B: ";
    xorResult.Display();

    // 10. Зсув ліворуч
    cout << "\n10. Zsuv livoruch:" << endl;

    BitString left = b.shiftLeft(3);
    left.Display();

    // 11. Зсув праворуч
    cout << "\n11. Zsuv pravoruch:" << endl;

    BitString right = b.shiftRight(3);
    right.Display();

    // 12. Префіксний інкремент
    cout << "\n12. Prefiksniy inkrement:" << endl;

    ++b;
    b.Display();

    // 13. Постфіксний інкремент
    cout << "\n13. Postfiksniy inkrement:" << endl;

    b++;
    b.Display();

    // 14. Префіксний декремент
    cout << "\n14. Prefiksniy dekrement:" << endl;

    --b;
    b.Display();

    // 15. Постфіксний декремент
    cout << "\n15. Postfiksniy dekrement:" << endl;

    b--;
    b.Display();

    // 16. Створення масиву об'єктів
    cout << "\n16. Masiv ob'yektiv:" << endl;

    BitString arr[3] =
    {
        BitString(1, 2),
        BitString(3, 4),
        BitString(5, 6)
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "Element " << i + 1 << ": ";
        arr[i].Display();
    }

    // 17. Масив об'єктів із конструктором без аргументів
    cout << "\n17. Masiv z konstruktorom bez argumentiv:" << endl;

    BitString arr2[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Element " << i + 1 << ": ";
        arr2[i].Display();
    }

    // 18. Введення з клавіатури
    cout << "\n18. Vvedennya z klaviatury:" << endl;

    BitString input;
    input.Read();

    if (cin)
    {
        cout << "Vvedeniy ryadok: ";
        input.Display();
    }

    // 19. Оператор введення та виведення
    cout << "\n19. Operator vvedennya ta vivedennya:" << endl;

    BitString test;

    cout << "Vvedit 64 bity (0 ta 1): ";

    if (cin >> test)
    {
        cout << "Rezultat: " << test << endl;
    }
    else
    {
        cout << "Pomilka vvedennya!" << endl;
    }

    // 20. Лічильник створених об'єктів
    cout << "\n20. Kilkist stvorenih ob'yektiv:" << endl;

    cout << "Object count: "
        << Object::GetObjectCount() << endl;

    // 21. Розмір класу
    cout << "\n21. Rozmir klasiv:" << endl;

    cout << "BitString bez pack(1): "
        << sizeof(BitString) << " bait" << endl;

    // Звичайне розміщення двох полів
    struct NormalLayout
    {
        long High;
        long Low;
    };

    // Розміщення з pack(1)
#pragma pack(push, 1)

    struct PackedLayout
    {
        long High;
        long Low;
    };

#pragma pack(pop)

    cout << "Normal layout: "
        << sizeof(NormalLayout) << " bait" << endl;

    cout << "Layout z pack(1): "
        << sizeof(PackedLayout) << " bait" << endl;

    cout << "\n===== KINEC PROGRAMI =====" << endl;

    return 0;
}
