#include "include.h"


/*
Создать иерархию классов
Жидкость<-Напиток
Жидкость<-Топливо
Жидкость<-Реагент
Жидкость - абстрактный класс? инкапсулирует свойства цвет, название, температура замерзания/кипения и т.д.,
а также виртуальный метод Boil. Классы Напиток, Топливо, Реагент реализуют метод Boil
*/


class Aqua //создаём базовый класс от которого у нас и начнется иерархия классов
{
private://можно использовать public(результат не меняется)
    string m_name;
    string m_color;
    double m_boiling_point;
    double m_freezing_point;
public:
    Aqua(const string& name, const string& color, double boiling, double freezing) : m_name(name), m_color(color),
        m_boiling_point(boiling), m_freezing_point(freezing) {}
    string getName() const { return m_name; }
    string getColor() const { return m_color; }
    double getBoilingPoint() const { return m_boiling_point; }
    double getFreezingPoint() const { return m_freezing_point; }
    virtual string boil() const = 0;
    virtual ~Aqua() {}
};

class Drink : public Aqua//класс наследник [0]
{
public:
    Drink(const string& name, const string& color, double boiling, double freezing) : Aqua(name, color, boiling, freezing) {}
    virtual string boil() const { return "Many boubles..."; }
};

class Fuel : public Aqua //класс наследник [1]
{
public:
    Fuel(const string& name, const string& color, double boiling, double freezing) : Aqua(name, color, boiling, freezing) {}
    virtual string boil() const { return "CRUSH AND BURN!!!"; }
};

class Reagent : public Aqua//класс наследник [2]
{
public:
    Reagent(const string& name, const string& color, double boiling, double freezing) : Aqua(name, color, boiling, freezing) {}
    virtual string boil() const { return "So strange smell here..."; }
};

int main() 
{
    Aqua* examples[3];
    examples[0] = new Drink("Clear water", "Limpid", 100.0, 0.0);
    examples[1] = new Fuel("Gazoline", "Brown", 90.0, -30.0);
    examples[2] = new Reagent("Lakmus", "Green", 120.0, -10.0);

    for (int i = 0; i < 3; ++i)
        cout << "Object #" << (i + 1) << "\nName: " << examples[i]->getName() << "\nColor: " << examples[i]->getColor()
        << "\nBoiling poing: " << examples[i]->getBoilingPoint() << "\nFreezing point: " << examples[i]->getFreezingPoint()
        << "\nWhen boil: " << examples[i]->boil() <<endl;

    for (int i = 0; i < 3; ++i)
        delete examples[i];

    return 0;
}