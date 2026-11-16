#pragma once

class Object
{
protected:
    static int objectCount;

public:
    Object();
    Object(const Object& obj);
    ~Object();

    static int GetObjectCount();
};
