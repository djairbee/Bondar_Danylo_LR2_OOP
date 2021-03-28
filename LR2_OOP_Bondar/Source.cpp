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
        cout << "������ ������������" << endl;
        coord = NULL;
        Set_coord(n);
    }

    ~Vector()
    {
        cout << "������ �����������" << endl;
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
        cout << "K���������� ���������" << endl;

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
        cout << endl << endl << "���� �������";
        Sum(*this, v2);

        cout << endl << endl << "г����� �������";
        difference(*this, v2);

        cout << endl << endl << "��������� ������� �������";
        scal_dob(*this, v2);
    }
};

int main()
{
    system("chcp 1251");
    int n = 3;
    srand(time(NULL));

    cout << "\n������ ��������� �����:" << endl;
    Vector a(n);

    cout << "���������� �������" << " : ";
    a.Print();

    cout << endl << "������� ������� ";
    a.lenght();
    cout << endl;

    Vector Ca(a);

    a.Set_coord(n);

    cout << "������ � � ������ ������������ : ";
    a.Print();
    cout << endl;

    cout << "���� ������� � �� ���� ��������� : ";
    Ca.Print();
    cout << endl;

    cout << endl << "������ ��������� �����:" << endl;
    Vector b(n);

    cout << "���������� �������" << " : ";
    b.Print();

    cout << endl << "������� ������� ";
    b.lenght();

    Ca.calcs(b);
    cout << endl << "\n����� ����������� �������� ����������� �� ��'���� �����." << endl;
    return 0;
}

/* �1
�������� ���� � ������ � ������ � ������� ������:
����� ����� ����� �� ������� ��������.
��������� �����������, ����������,
������� ��������� �������� �������,
���������� ������� �������, ���������, ��������, ���������� ������� �������.
����������� �������� ���'���.
*/

