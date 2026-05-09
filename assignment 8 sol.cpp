//q1(FUNCTION TEMPLATE)
#include <iostream>

using namespace std;

template <class T>
void swapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 10;
    int y = 20;

    swapValues(x, y);

    cout << x << " " << y << endl;

    float p = 2.5;
    float q = 7.8;

    swapValues(p, q);

    cout << p << " " << q << endl;

    return 0;
}



//q2
#include <iostream>

using namespace std;

template <class T>
T findMinimum(T arr[], int n)
{
    T mini = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < mini)
        {
            mini = arr[i];
        }
    }

    return mini;
}

int main()
{
    int arr[] = {7, 2, 9, 1, 5};

    cout << "Min = "
         << findMinimum(arr, 5)
         << endl;

    return 0;
}


//q3
#include <iostream>

using namespace std;

template <class T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <class T>
void display(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = {9, 4, 7, 1, 3};

    bubbleSort(arr, 5);

    display(arr, 5);

    return 0;
}


//q4
#include <iostream>

using namespace std;

template <class T>
int linearSearch(T arr[], int n, T key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {11, 22, 33, 44, 55};

    int pos = linearSearch(arr, 5, 33);

    if (pos != -1)
    {
        cout << "element Found at Index "
             << pos << endl;
    }
    else
    {
        cout << " Not Found\n";
    }

    return 0;
}


//q5
#include <iostream>

using namespace std;

template <class T>
void process(T a)
{
    cout << "Single Parameter : "
         << a << endl;
}

template <class T>
void process(T a, T b)
{
    cout << "Same Type Parameters : "
         << a << " "
         << b << endl;
}

template <class T, class U>
void process(T a, U b)
{
    cout << "Different Type Parameters : "
         << a << " "
         << b << endl;
}

int main()
{
    process(10);

    process(5, 8);

    process(7, 4.5);

    return 0;
}


//CLASS TEMPLATE
//q1
#include <iostream>

using namespace std;

template <class T>
class Stack
{
    T arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(T value)
    {
        if (top == 99)
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Removed : "
             << arr[top--]
             << endl;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    s.display();

    return 0;
}


//q2
#include <iostream>

using namespace std;

template <class T>
class Queue
{
    T arr[100];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(T value)
    {
        if (rear == 99)
        {
            cout << "queue is Full\n";
            return;
        }

        arr[++rear] = value;
    }

    void dequeue()
    {
        if (front > rear)
        {
            cout << "queue is Empty\n";
            return;
        }

        cout << "removed : "
             << arr[front++]
             << endl;
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue<int> q;

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}


//q3
#include <iostream>

using namespace std;

template <class T1, class T2>
class Pair
{
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b)
    {
        first = a;
        second = b;
    }

    void display()
    {
        cout << "First  : "
             << first << endl;

        cout << "Second : "
             << second << endl;
    }
};

int main()
{
    Pair<int, string> p(101, "Lakshay");

    p.display();

    return 0;
}


//q4
#include <iostream>

using namespace std;

template <class T>
class Arithmetic
{
    T a;
    T b;

public:
    Arithmetic(T x, T y)
    {
        a = x;
        b = y;
    }

    void operations()
    {
        cout << "Addition       : "
             << a + b << endl;

        cout << "Subtraction    : "
             << a - b << endl;

        cout << "Multiplication : "
             << a * b << endl;

        cout << "Division       : "
             << a / b << endl;
    }
};

int main()
{
    Arithmetic<float> obj(20, 5);

    obj.operations();

    return 0;
}


//q5
#include <iostream>

using namespace std;

template <class T>
class Array
{
    T arr[100];
    int size;

public:
    void input(int n)
    {
        size = n;

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Array<int> a;

    a.input(5);

    a.display();

    return 0;
}
