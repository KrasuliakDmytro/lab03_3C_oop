#include "Object.h"

int Object::objectCount = 0;

// Конструктор без аргументів
Object::Object()
{
    objectCount++;
}

// Конструктор копіювання
Object::Object(const Object& obj)
{
    objectCount++;
}

// Деструктор
Object::~Object()
{
}

// Отримання кількості створених об'єктів
int Object::GetObjectCount()
{
    return objectCount;
}
