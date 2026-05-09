//q1
#include <iostream>
using namespace std;

class Animal
{
public:
    void sound()
    {
        cout << "Animal makes sound";
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "Dog barks\n";
    }
};

int main()
{
    Animal a;
    Dog d;

    a.sound();

    d.sound();
    d.bark();

    return 0;
}



//q2
#include <iostream>
using namespace std;

class Parent
{
protected:
    int number;

public:
    Parent()
    {
        number = 50;
    }
};

class Child : public Parent
{
public:
    void display()
    {
        cout << "Protected value = " << number << endl;
    }
};

int main()
{
    Child obj;
    obj.display();

    return 0;
}

//q3
#include <iostream>
using namespace std;

class Base
{
public:
    int x = 10;
};

class PublicDerived : public Base
{
public:
    void show()
    {
        cout << x << endl;
    }
};

class ProtectedDerived : protected Base
{
public:
    void show()
    {
        cout << x << endl;
    }
};

class PrivateDerived : private Base
{
public:
    void show()
    {
        cout << x << endl;
    }
};

int main()
{
    PublicDerived p1;
    p1.show();

    ProtectedDerived p2;
    p2.show();

    PrivateDerived p3;
    p3.show();

    return 0;
}

//q4(single inheritance)
#include <iostream>
using namespace std;

class A
{
public:
    void displayA()
    {
        cout << "Class A\n";
    }
};

class B : public A
{
public:
    void displayB()
    {
        cout << "Class B\n";
    }
};

int main()
{
    B obj;

    obj.displayA();
    obj.displayB();

    return 0;
}

//q4(multiple inheritance)
#include <iostream>
using namespace std;

class A
{
public:
    void showA()
    {
        cout << "Class A\n";
    }
};

class B
{
public:
    void showB()
    {
        cout << "Class B\n";
    }
};

class C : public A, public B
{
};

int main()
{
    C obj;

    obj.showA();
    obj.showB();

    return 0;
}

//q4(multilevel inheritance)
#include <iostream>
using namespace std;

class A
{
public:
    void first()
    {
        cout << "First Level\n";
    }
};

class B : public A
{
public:
    void second()
    {
        cout << "Second Level\n";
    }
};

class C : public B
{
public:
    void third()
    {
        cout << "Third Level\n";
    }
};

int main()
{
    C obj;

    obj.first();
    obj.second();
    obj.third();

    return 0;
}


//q4(hierarchical inheritance)
#include <iostream>
using namespace std;

class Parent
{
public:
    void common()
    {
        cout << "Parent Class\n";
    }
};

class Child1 : public Parent
{
};

class Child2 : public Parent
{
};

int main()
{
    Child1 a;
    Child2 b;

    a.common();
    b.common();

    return 0;
}



//q4(hybrid inheritance)
#include <iostream>
using namespace std;

class A
{
public:
    void showA()
    {
        cout << "Class A\n";
    }
};

class B : public A
{
};

class C
{
public:
    void showC()
    {
        cout << "Class C\n";
    }
};

class D : public B, public C
{
};

int main()
{
    D obj;

    obj.showA();
    obj.showC();

    return 0;
}


//q5
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base Constructor\n";
    }

    ~Base()
    {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived Constructor\n";
    }

    ~Derived()
    {
        cout << "Derived Destructor\n";
    }
};

int main()
{
    Derived obj;

    return 0;
}


//q6
#include <iostream>
using namespace std;

class Book
{
protected:
    string title;
    string author;
    float price;

public:
    Book(string t, string a, float p)
    {
        title = t;
        author = a;
        price = p;
    }

    void showBook()
    {
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Price  : " << price << endl;
    }
};

class Textbook : public Book
{
    string subject;

public:
    Textbook(string t, string a, float p, string s)
        : Book(t, a, p)
    {
        subject = s;
    }

    void display()
    {
        showBook();
        cout << "Subject: " << subject << endl;
    }
};

int main()
{
    Textbook tb("Physics", "HC Verma", 450, "Science");

    tb.display();

    return 0;
}

//q7
#include <iostream>
using namespace std;

class Speedometer
{
protected:
    int speed;

public:
    Speedometer(int s)
    {
        speed = s;
    }
};

class FuelGauge
{
protected:
    int fuel;

public:
    FuelGauge(int f)
    {
        fuel = f;
    }
};

class Thermometer
{
protected:
    int temperature;

public:
    Thermometer(int t)
    {
        temperature = t;
    }
};

class CarDashboard : public Speedometer, public FuelGauge, public Thermometer
{
public:
    CarDashboard(int s, int f, int t)
        : Speedometer(s), FuelGauge(f), Thermometer(t)
    {
    }

    void display()
    {
        cout << "Speed       : " << speed << " km/h\n";
        cout << "Fuel Level  : " << fuel << "%\n";
        cout << "Temperature : " << temperature << " C\n";
    }
};

int main()
{
    CarDashboard car(90, 70, 35);

    car.display();

    return 0;
}


//q8
#include <iostream>
using namespace std;

class LibraryUser
{
protected:
    string name;
    int id;
    string contact;

public:
    LibraryUser(string n, int i, string c)
    {
        name = n;
        id = i;
        contact = c;
    }
};

class Student : public LibraryUser
{
    int grade;

public:
    Student(string n, int i, string c, int g)
        : LibraryUser(n, i, c)
    {
        grade = g;
    }

    void display()
    {
        cout << "Student: " << name << endl;
        cout << "Grade  : " << grade << endl;
    }
};

class Teacher : public LibraryUser
{
    string department;

public:
    Teacher(string n, int i, string c, string d)
        : LibraryUser(n, i, c)
    {
        department = d;
    }

    void display()
    {
        cout << "Teacher    : " << name << endl;
        cout << "Department : " << department << endl;
    }
};

int main()
{
    Student s("Rahul", 101, "9999999999", 12);
    Teacher t("Mehta", 201, "8888888888", "Mathematics");

    s.display();
    cout << endl;
    t.display();

    return 0;
}



//q9
#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(string mk, string md, int y)
    {
        make = mk;
        model = md;
        year = y;
    }
};

class Truck : public Vehicle
{
protected:
    int loadCapacity;

public:
    Truck(string mk, string md, int y, int lc)
        : Vehicle(mk, md, y)
    {
        loadCapacity = lc;
    }
};

class RefrigeratedTruck : public Truck
{
    int temperatureControl;

public:
    RefrigeratedTruck(string mk, string md, int y, int lc, int tc)
        : Truck(mk, md, y, lc)
    {
        temperatureControl = tc;
    }

    void display()
    {
        cout << "Make              : " << make << endl;
        cout << "Model             : " << model << endl;
        cout << "Year              : " << year << endl;
        cout << "Load Capacity     : " << loadCapacity << endl;
        cout << "Temperature Limit : " << temperatureControl << " C\n";
    }
};

int main()
{
    RefrigeratedTruck rt("Tata", "Ultra", 2024, 5000, -10);

    rt.display();

    return 0;
}


//q10
#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    string address;

public:
    Person(string n, string a)
    {
        name = n;
        address = a;
    }
};

class Staff : virtual public Person
{
protected:
    int employeeId;
    string department;

public:
    Staff(string n, string a, int e, string d)
        : Person(n, a)
    {
        employeeId = e;
        department = d;
    }
};

class Student : virtual public Person
{
protected:
    int studentId;
    char grade;

public:
    Student(string n, string a, int s, char g)
        : Person(n, a)
    {
        studentId = s;
        grade = g;
    }
};

class TeachingAssistant : public Staff, public Student
{
public:
    TeachingAssistant(
        string n,
        string a,
        int e,
        string d,
        int s,
        char g
    )
        : Person(n, a),
          Staff(n, a, e, d),
          Student(n, a, s, g)
    {
    }

    void display()
    {
        cout << "Name         : " << name << endl;
        cout << "Address      : " << address << endl;
        cout << "Employee ID  : " << employeeId << endl;
        cout << "Department   : " << department << endl;
        cout << "Student ID   : " << studentId << endl;
        cout << "Grade        : " << grade << endl;
    }
};

int main()
{
    TeachingAssistant ta(
        "Aman",
        "Delhi",
        501,
        "Computer Science",
        2201,
        'A'
    );

    ta.display();

    return 0;
}
