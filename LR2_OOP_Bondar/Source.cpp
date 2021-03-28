#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class Vector {
private:
    int* coord;
    int size;

public:

    Vector(int n)
    {
        cout << "Виклик конструктора" << endl;
        coord = NULL;
        Set_coord(n);
    }

    ~Vector()
    {
        cout << "Виклик деструктора" << endl;
        delete[] coord;
    }

    void Set_coord(int n)
    {
        Set_count(n);
        dyn_coord();
        Set_all_coord();
    }

    void Set_count(int n)
    {
        size = n;
    }

    void dyn_coord()
    {
        if (coord == NULL)
        {
            coord = new int[size];
        }
    }

    void Set_all_coord()
    {
        for (int i = 0; i < size; i++)
        {
            coord[i] = rand() % 25;
        }
    }

    void Print()
    {
        cout << "(";
        for (int i = 0; i < size; i++)
        {
            cout << " " << *(coord + i) << " ";
        }
        cout << ")";
    }

    void lenght()
    {
        double len, sq = 0;
        for (int i = 0; i < size; i++)
        {
            sq += (*(coord + i) * *(coord + i));
        }
        len = sqrt(sq);
        cout << "= " << "[" << len << "]" << endl;
    }

    Vector(const Vector& other)
    {
        this->size = other.size;
        this->coord = new int[other.size];
        cout << "Kонструктор копіювання" << endl;

        for (int i = 0; i < size; i++)
        {
            this->coord[i] = other.coord[i];
        }
    }

    void Sum(Vector& v1, Vector& v2)
    {
        cout << endl << "{";
        for (int i = 0, res = 0; i < size; i++)
        {
            res = (v1.coord[i] + v2.coord[i]);
            cout << " " << res << " ";
        }
        cout << "}";
    }

    void difference(Vector& v1, Vector& v2)
    {
        cout << endl << "{";
        for (int i = 0, res = 0; i < size; i++)
        {
            res = (v1.coord[i] - v2.coord[i]);
            cout << " " << res << " ";
        }
        cout << "}";
    }

    void scal_dob(Vector& v1, Vector& v2)
    {
        int sum = 0;
        for (int i = 0, res = 0; i < size; i++)
        {
            res = (v1.coord[i] * v2.coord[i]);
            sum += res;
        }
        cout << " = " << sum;
    }
    void calcs(Vector& v2)
    {
        cout << endl << endl << "Сума векторів";
        Sum(*this, v2);

        cout << endl << endl << "Різниця векторів";
        difference(*this, v2);

        cout << endl << endl << "Скалярний добуток векторів";
        scal_dob(*this, v2);
    }
};

int main()
{
    system("chcp 1251");
    int n = 3;
    srand(time(NULL));

    cout << "\nПерший екземпляр класу:" << endl;
    Vector a(n);

    cout << "Координати вектора" << " : ";
    a.Print();

    cout << endl << "Довжина вектора ";
    a.lenght();
    cout << endl;

    Vector Ca(a);

    a.Set_coord(n);

    cout << "Вектор а з новими координатами : ";
    a.Print();
    cout << endl;

    cout << "Копія вектора а до зміни координат : ";
    Ca.Print();
    cout << endl;

    cout << endl << "Другий екземпляр класу:" << endl;
    Vector b(n);

    cout << "Координати вектора" << " : ";
    b.Print();

    cout << endl << "Довжина вектора ";
    b.lenght();

    Ca.calcs(b);
    cout << endl << "\nПеред завершенням програми видаляються усі об'єкти класу." << endl;
    return 0;
}

/* №1
Створити клас – вектор з полями у закритій частині:
масив цілих чисел та кількість елементів.
Визначити конструктор, деструктор,
функції виведення елементів вектора,
обчислення довжини вектора, додавання, віднімання, скалярного добутку векторів.
Використати динамічну пам'ять.
*/

