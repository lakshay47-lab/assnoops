//q1
include <iostream>
using namespace std;

struct Student
{
    string name;
    int rollNo;
    string degree;
    string hostel;
    float currentCGPA;

    void addDetails()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Degree: ";
        cin >> degree;
        cout << "Enter Hostel: ";
        cin >> hostel;
        cout << "Enter CGPA: ";
        cin >> currentCGPA;
    }

    void updateDetails()
    {
        cout << "Update Degree: ";
        cin >> degree;
    }

    void updateCGPA()
    {
        cout << "Enter New CGPA: ";
        cin >> currentCGPA;
    }

    void updateHostel()
    {
        cout << "Enter New Hostel: ";
        cin >> hostel;
    }

    void displayDetails()
    {
        cout << "Student Details:";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Degree: " << degree << endl;
        cout << "Hostel: " << hostel << endl;
        cout << "CGPA: " << currentCGPA << endl;
    }
};

int main()
{
    Student s;
    s.addDetails();
    s.updateCGPA();
    s.displayDetails();
    return 0;
}

//q2
#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    float cgpa;

    void privateDisplay()
    {
        cout << "Private Display Accessed";
    }

public:
    string degree;
    string hostel;

    void addDetails()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void updateCGPA(float newCGPA)
    {
        cgpa = newCGPA;
        privateDisplay();   
    }

    void displayDetails()
    {
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollNo;
        cout << "\nCGPA: " << cgpa;
        cout << "\nDegree: " << degree;
        cout << "\nHostel: " << hostel << endl;
    }
};

int main()
{
    Student s;
    s.addDetails();
    s.degree = "BTech";
    s.hostel = "H1";
    s.updateCGPA(8.5);
    s.displayDetails();
    return 0;
}
//public is accessible outside class,private isnt
//public used for interface,private for data hiding
//public is not default in class but private is


//q3
#include <iostream>
using namespace std;

class Demo
{
private:
    void privateFunction()
    {
        cout << " called";
    }

public:
    void publicFunction()
    {
        privateFunction();  
    }
};

int main()
{
    Demo d;
    d.publicFunction();
    return 0;
} 


//q4
#include <iostream>
using namespace std;

class Rectangle
{
    int width, height;

public:
    void getdata()
    {
        cout << "Enter width and height: ";
        cin >> width >> height;
    }

    void calculatearea()
    {
        cout << "Area = " << width * height << endl;
    }
};

int main()
{
    Rectangle r;
    r.getdata();
    r.calculatearea();
    return 0;
}


//q5
#include <iostream>
using namespace std;

class Complex
{
    float real, imag;

public:
    void setComplex(float r, float i)
    {
        real = r;
        imag = i;
    }

    void displayComplex()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    Complex add(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

int main()
{
    Complex c1, c2, c3;
    c1.setComplex(2.5, 3.5);
    c2.setComplex(1.5, 4.5);

    c3 = c1.add(c2);

    cout << "Sum = ";
    c3.displayComplex();
    return 0;
}

//q6
#include <iostream>


int value = 100;

class Demo
{
private:
    int value;              
    static int count;       

public:
    
    Demo(int value)
    {
        this->value = value;
        count++;
    }

    
    void show();


    static void displayCount();
};


int Demo::count = 0;


void Demo::show()
{
    std::cout << "Local value : " << value << std::endl;

    
    std::cout << "Global value      : " << ::value << std::endl;

    
    std::cout << "Object count      : " << Demo::count << std::endl;
}


void Demo::displayCount()
{
    std::cout << "Total objects created : "
              << Demo::count << std::endl;
}

int main()
{
    
    std::cout << " Scope Resolution Operator ::";

    Demo d1(10);
    Demo d2(20);

    d1.show();

    std::cout << "\n";

    d2.show();

    std::cout << "\n";

    Demo::displayCount();

    return 0;
}


//q7
#include <iostream>
using namespace std;

namespace First
{
    int x = 10;
    void show()
    {
        cout << "First namespace x = " << x << endl;
    }
}

namespace Second
{
    int x = 20;
    void show()
    {
        cout << "Second namespace x = " << x << endl;
    }
}

int main()
{
    First::show();
    Second::show();
    return 0;
}
