#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include <stdio.h>

using namespace std;

//クラステンプレート
template<typename Type, typename Type2>
class TemplateClass {
public:
    // コンストラクタ（引数number1と2の値をメンバ変数Number1と2に退避）
    TemplateClass(Type number1, Type2 number2) :
        Number1(number1), Number2(number2) {
    }

    Type Min()
    {
        if (Number1 < Number2)
            return static_cast<Type>(Number1);
        else
            return static_cast<Type2>(Number2);
    }

private:
    Type Number1; // number1の値を格納する変数1
    Type2 Number2; // number2の値を格納する変数2
};



int main() {
    // テンプレートから6種類のクラスを定義
    TemplateClass<int, float> intFloatTemplate(100, 50.0f); //①
    TemplateClass<int, double> intDoubleTemplate(80, 20.0); //②
    TemplateClass<float, int> floatIntTemplate(2.0f, 18); //③
    TemplateClass<float, double> floatDoubleTemplate(11.0f, 3.5); //④
    TemplateClass<double, int> doubleIntTemplate(234.0, 123); //⑤
    TemplateClass<double, float> doubleFloatTemplate(400.1, 500.2f); //⑥

    std::cout << "int(100)とfloat(50.0f)を比べて小さい数字を返す：" << intFloatTemplate.Min() << std::endl;
    std::cout << "int(80)とdouble(20.0)を比べて小さい数字を返す：" << intDoubleTemplate.Min() << std::endl;
    std::cout << "float(2.0f)とint(18)を比べて小さい数字を返す：" << floatIntTemplate.Min() << std::endl;
    std::cout << "float(11.0f)とdouble(3.5)を比べて小さい数字を返す：" << floatDoubleTemplate.Min() << std::endl;
    std::cout << "double(234.0)とint(123)を比べて小さい数字を返す：" << doubleIntTemplate.Min() << std::endl;
    std::cout << "double(400.1)とfloat(500.2)を比べて小さい数字を返す：" << doubleFloatTemplate.Min() << std::endl;


    return 0;
}