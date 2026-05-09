//q1
#include <iostream>
using namespace std;

class Rectangle {
private:
    int length, breadth;

public:

    Rectangle() {
        length = 0;
        breadth = 0;
    }

    
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    
    Rectangle(int x) {
        length = x;
        breadth = x;
    }

    int area() {
        return length * breadth;
    }
};

int main() {
    Rectangle r1;     
    Rectangle r2(5);     
    Rectangle r3(4, 6);  

    cout << "Area r1 = " << r1.area() << endl;
    cout << "Area r2 = " << r2.area() << endl;
    cout << "Area r3 = " << r3.area() << endl;

    return 0;
}


//q2
#include <iostream>
using namespace std;

class Rectangle {
private:
    int length, breadth;

public:
    
    Rectangle(int l = 0, int b = 0) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }

    
    ~Rectangle() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Rectangle r[3] = {
        Rectangle(),       
        Rectangle(5),       
        Rectangle(4, 6)     
    };

    for (int i = 0; i < 3; i++) {
        cout << "Area of Rectangle " << i + 1 << " = "
             << r[i].area() << endl;
    }

    return 0;
}


//q3
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Constructor called" << endl;
    }

    // Destructor
    ~Demo() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Demo d1;
    return 0;
}


//q4
#include <iostream>
using namespace std;

class Rectangle {
    int length, breadth;

public:
    Rectangle(int l = 0, int b = 0) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }

    ~Rectangle() {
        cout << "Rectangle object destroyed" << endl;
    }
};

int main() {

    
    int *iptr = new int;
    *iptr = 10;
    cout << "Integer value = " << *iptr << endl;
    delete iptr;

 
    float *fptr = new float;
    *fptr = 5.5;
    cout << "Float value = " << *fptr << endl;
    delete fptr;

  
    int *iarr = new int[5];
    cout << "Integer array elements: ";
    for (int i = 0; i < 5; i++) {
        iarr[i] = i + 1;
        cout << iarr[i] << " ";
    }
    cout << endl;
    delete[] iarr;


    float *farr = new float[3];
    cout << "Float array elements: ";
    for (int i = 0; i < 3; i++) {
        farr[i] = (i + 1) * 1.1;
        cout << farr[i] << " ";
    }
    cout << endl;
    delete[] farr;


    Rectangle *r1 = new Rectangle(4, 5);
    cout << "Area of rectangle = " << r1->area() << endl;
    delete r1;

   
    Rectangle *rarr = new Rectangle[2] {
        Rectangle(2, 3),
        Rectangle(6, 4)
    };

    for (int i = 0; i < 2; i++) {
        cout << "Area of rectangle " << i + 1
             << " = " << rarr[i].area() << endl;
    }

    delete[] rarr;

    return 0;
}
