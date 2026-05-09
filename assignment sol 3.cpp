//q1
#include <iostream>
using namespace std;

class Student
{
    int roll;

public:
    void setRoll(int roll)
    {
        this->roll = roll;   
    }

    void showRoll()
    {
        cout << "Roll No: " << roll << endl;
    }
};

int main()
{
    Student s;         
    Student *ptr;       

    ptr = &s;

    s.setRoll(10);     
    s.showRoll();

    ptr->setRoll(20);   
    ptr->showRoll();

    return 0;
}

//q2
#include <iostream>
using namespace std;

class B;   // forward 

class A
{
    int x;
public:
    A(int a) { x = a; }
    friend void swap(A &, B &);
};

class B
{
    int y;
public:
    B(int b) { y = b; }
    friend void swap(A &, B &);
};

void swap(A &a, B &b)
{
    int temp = a.x;
    a.x = b.y;
    b.y = temp;
}

int main()
{
    A obj1(10);
    B obj2(20);

    swap(obj1, obj2);
    cout << "Values swapped " << endl;

    return 0;
}

//q3
using namespace std;

class B;

class A
{
    int x;
public:
    A(int a) { x = a; }
    friend int add(A, B);
};

class B
{
    int y;
public:
    B(int b) { y = b; }
    friend int add(A, B);
};

int add(A a, B b)
{
    return (a.x + b.y);
}

int main()
{
    A obj1(15);
    B obj2(25);

    cout << "Sum = " << add(obj1, obj2) << endl;
    return 0;
}

//q4
#include <iostream>
using namespace std;

class B;   // forward 

class A
{
private:
    int x = 50;
    friend class B;
};

class B
{
public:
    void show(A obj)
    {
        cout << "Private data of class A: " << obj.x << endl;
    }
};

int main()
{
    A a;
    B b;
    b.show(a);
    return 0;
}


//q5
#include <iostream>
using namespace std;

class Rectangle
{
    int length, breadth;

public:
    void setData(int l, int b)
    {
        length = l;
        breadth = b;
    }

    void area()
    {
        cout << "Area = " << length * breadth << endl;
    }
};

int main()
{
    Rectangle r[3];

    for(int i = 0; i < 3; i++)
    {
        r[i].setData(i + 2, i + 3);
        r[i].area();
    }

    return 0;
}

//q6
#include <iostream>
using namespace std;

inline int cube(int x)
{
    return x * x * x;
}

int main()
{
    int n = 3;
    cout << "Cube = " << cube(n) << endl;
    return 0;
}

//q7a
#include <iostream>
using namespace std;

class Number
{
public:
    int x;

    Number(int a = 0)
    {
        x = a;
    }

    Number add(Number n)
    {
        Number temp;
        temp.x = x + n.x;
        return temp;
    }
};

int main()
{
    Number n1(10), n2(20), n3;
    n3 = n1.add(n2);

    cout << "Sum = " << n3.x << endl;
    return 0;
}


//q7b
using namespace std;

class Number
{
public:
    int x;

    void set(int a)
    {
        x = a;
    }

    Number add(Number *n)
    {
        Number temp;
        temp.x = x + n->x;
        return temp;
    }
};

int main()
{
    Number n1, n2, n3;
    n1.set(30);
    n2.set(40);

    n3 = n1.add(&n2);

    cout << "Sum = " << n3.x << endl;
    return 0;
}
