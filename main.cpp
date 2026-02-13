#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <cstdio>

using namespace std;

class ANIMAL {
public:
    // 鳴く関数（純粋仮想関数）
    virtual void sound() const = 0;
};


class DOG : public ANIMAL {
public:
    void sound() const override {
        printf("イヌ鳴き声：ワン\n");
    }
};


class CAT : public ANIMAL {
public:
    void sound() const override {
        printf("ネコ鳴き声:ニャー\n");
    }
};


class BABY : public ANIMAL {
public:
    void sound() const override {
        printf("赤ちゃんの鳴き声:おギャー\n");
    }
};
int main() {

    ANIMAL* animal1 = new DOG();
    ANIMAL* animal2 = new CAT();
    ANIMAL* animal3 = new BABY();

    animal1->sound();
    animal2->sound();
    animal3->sound();

    delete animal1;
    delete animal2;

    return 0;
}