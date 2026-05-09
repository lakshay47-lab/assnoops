//q1
#include <iostream>

using namespace std;

class Polygon
{
protected:
    int width;
    int height;

public:
    void set_value(int w, int h)
    {
        width = w;
        height = h;
    }

    virtual void calculate_area() = 0;
};

class Rectangle : public Polygon
{
public:
    void calculate_area()
    {
        cout << "Rectangle Area = " << width * height << endl;
    }
};

class Triangle : public Polygon
{
public:
    void calculate_area()
    {
        cout << "Triangle Area = " << (width * height) / 2 << endl;
    }
};

int main()
{
    Polygon *ptr;

    Rectangle r;
    r.set_value(10, 5);

    Triangle t;
    t.set_value(8, 6);

    ptr = &r;
    ptr->calculate_area();

    ptr = &t;
    ptr->calculate_area();

    return 0;
}

//q2
#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void area() = 0;
    virtual void display() = 0;
};

class Circle : public Shape
{
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    void area()
    {
        cout << "Area = " << 3.14 * radius * radius << endl;
    }

    void display()
    {
        cout << "Shape : Circle\n";
    }
};

class Rectangle : public Shape
{
    int length;
    int breadth;

public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    void area()
    {
        cout << "Area = " << length * breadth << endl;
    }

    void display()
    {
        cout << "Shape : Rectangle\n";
    }
};

class Triangle : public Shape
{
    int base;
    int height;

public:
    Triangle(int b, int h)
    {
        base = b;
        height = h;
    }

    void area()
    {
        cout << "Area = " << 0.5 * base * height << endl;
    }

    void display()
    {
        cout << "Shape : Triangle\n";
    }
};

int main()
{
    Circle c(7);
    Rectangle r(10, 4);
    Triangle t(8, 5);

    c.display();
    c.area();

    r.display();
    r.area();

    t.display();
    t.area();

    return 0;
}


//q3
#include <iostream>
#include <cmath>

using namespace std;

class TriangleArea
{
public:
    void area(float base, float height)
    {
        cout << "Right Angle Triangle Area = "
             << 0.5 * base * height << endl;
    }

    void area(float side)
    {
        cout << "Equilateral Triangle Area = "
             << (1.732 / 4) * side * side << endl;
    }

    void area(float equalSide, float base, bool)
    {
        float h = sqrt((equalSide * equalSide) - ((base * base) / 4));

        cout << "Isosceles Triangle Area = "
             << 0.5 * base * h << endl;
    }
};

int main()
{
    TriangleArea t;

    t.area(6.0f, 8.0f);
    t.area(5.0f);
    t.area(5.0f, 6.0f, true);

    return 0;
}


//q4
#include <iostream>

using namespace std;

class Student
{
public:
    virtual void show() = 0;
};

class Engineering : public Student
{
public:
    void show()
    {
        cout << "Engineering Student\n";
    }
};

class Medicine : public Student
{
public:
    void show()
    {
        cout << "Medicine Student\n";
    }
};

class Science : public Student
{
public:
    void show()
    {
        cout << "Science Student\n";
    }
};

int main()
{
    Student *arr[3];

    Engineering e;
    Medicine m;
    Science s;

    arr[0] = &e;
    arr[1] = &m;
    arr[2] = &s;

    for (int i = 0; i < 3; i++)
    {
        arr[i]->show();
    }

    return 0;
}


//q5
#include <iostream>

using namespace std;

class Time
{
    int h;
    int m;
    int s;

public:
    Time(int hh = 0, int mm = 0, int ss = 0)
    {
        h = hh;
        m = mm;
        s = ss;
    }

    Time operator+(Time t)
    {
        Time temp;

        temp.s = s + t.s;
        temp.m = m + t.m + temp.s / 60;
        temp.s %= 60;

        temp.h = h + t.h + temp.m / 60;
        temp.m %= 60;

        return temp;
    }

    void show()
    {
        cout << h << ":" << m << ":" << s << endl;
    }
};

int main()
{
    Time t1(5, 15, 34);
    Time t2(9, 53, 58);

    Time t3;

    t3 = t1 + t2;

    t3.show();

    return 0;
}


//q6
#include <iostream>
#include <cstring>

using namespace std;

class STRING
{
    char str[100];

public:
    STRING(char s[] = "")
    {
        strcpy(str, s);
    }

    bool operator==(STRING s)
    {
        return strcmp(str, s.str) == 0;
    }

    STRING operator+(STRING s)
    {
        STRING temp;

        strcpy(temp.str, str);
        strcat(temp.str, s.str);

        return temp;
    }

    void display()
    {
        cout << str << endl;
    }
};

int main()
{
    STRING s1("Hello ");
    STRING s2("World");

    STRING s3 = s1 + s2;

    s3.display();

    if (s1 == s2)
    {
        cout << "Strings equal\n";
    }
    else
    {
        cout << "Strings  not Equal\n";
    }

    return 0;
}


//q7
#include <iostream>

using namespace std;

class Matrix
{
    int a[2][2];

public:
    void input()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    friend Matrix operator*(Matrix, Matrix);

    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << a[i][j] << " ";
            }

            cout << endl;
        }
    }
};

Matrix operator*(Matrix x, Matrix y)
{
    Matrix temp;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            temp.a[i][j] = 0;

            for (int k = 0; k < 2; k++)
            {
                temp.a[i][j] += x.a[i][k] * y.a[k][j];
            }
        }
    }

    return temp;
}

int main()
{
    Matrix m1, m2, m3;

    m1.input();
    m2.input();

    m3 = m1 * m2;

    m3.display();

    return 0;
}


//q8
#include <iostream>

using namespace std;

class Array
{
    int arr[5];

public:
    Array()
    {
        for (int i = 0; i < 5; i++)
        {
            arr[i] = i + 1;
        }
    }

    int operator[](int index)
    {
        if (index < 0 || index >= 5)
        {
            cout << "index Out of bound";
            return -1;
        }

        return arr[index];
    }
};

int main()
{
    Array a;

    cout << a[2] << endl;
    cout << a[8] << endl;

    return 0;
}



//q9
#include <iostream>

using namespace std;

class Input
{
public:
    void operator()(int a, int b, int c)
    {
        cout << "Values : "
             << a << " "
             << b << " "
             << c << endl;
    }
};

int main()
{
    Input obj;

    obj(10, 20, 30);

    return 0;
}



//q10
#include <iostream>

using namespace std;

class Student
{
    int roll;
    string name;

public:
    friend istream &operator>>(istream &in, Student &s);
    friend ostream &operator<<(ostream &out, Student &s);
};

istream &operator>>(istream &in, Student &s)
{
    in >> s.roll >> s.name;
    return in;
}

ostream &operator<<(ostream &out, Student &s)
{
    out << "Roll : " << s.roll << endl;
    out << "Name : " << s.name << endl;

    return out;
}

int main()
{
    Student s;

    cin >> s;

    cout << s;

    return 0;
}



//q11
#include <iostream>

using namespace std;

class Test
{
    float value;

public:
    Test(float x)
    {
        value = x;
    }

    void display()
    {
        cout << "Value = " << value << endl;
    }
};

int main()
{
    float num = 12.5;

    Test t = num;

    t.display();

    return 0;
}


//q12
#include <iostream>

using namespace std;

class Test
{
    float value;

public:
    Test(float x)
    {
        value = x;
    }

    operator float()
    {
        return value;
    }
};

int main()
{
    Test t(25.7);

    float x;

    x = t;

    cout << "Float Value = " << x << endl;

    return 0;
}


//q13
#include <iostream>
#include <cmath>

using namespace std;

class Cartesian;

class Polar
{
    float radius;
    float angle;

public:
    Polar(float r, float a)
    {
        radius = r;
        angle = a;
    }

    operator Cartesian();
};

class Cartesian
{
    float x;
    float y;

public:
    Cartesian(float a = 0, float b = 0)
    {
        x = a;
        y = b;
    }

    void show()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

Polar::operator Cartesian()
{
    float x = radius * cos(angle);
    float y = radius * sin(angle);

    return Cartesian(x, y);
}

int main()
{
    Polar p(10, 5);

    Cartesian c = p;

    c.show();

    return 0;
}


