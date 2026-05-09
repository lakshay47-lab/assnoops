//q1
#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
    string title;
    string author;
    string ISBN;
};

class Library
{
    Book books[10];
    int total = 0;

public:
    bool addNewBook(string &title, string &author, string &ISBN)
    {
        if (total >= 10)
        {
            return false;
        }

        books[total].title = title;
        books[total].author = author;
        books[total].ISBN = ISBN;

        total++;

        return true;
    }

    bool removeBooks(string &ISBN);

    void displayDetails()
    {
        cout << "Library\n";

        for (int i = 0; i < total; i++)
        {
            cout << "Title  : " << books[i].title << endl;
            cout << "Author : " << books[i].author << endl;
            cout << "ISBN   : " << books[i].ISBN << endl;
            cout << endl;
        }
    }
};

bool Library::removeBooks(string &ISBN)
{
    for (int i = 0; i < total; i++)
    {
        if (books[i].ISBN == ISBN)
        {
            for (int j = i; j < total - 1; j++)
            {
                books[j] = books[j + 1];
            }

            total--;
            return true;
        }
    }

    return false;
}

int main()
{
    Library lib;

    string t1 = "C++";
    string a1 = "balaguruswamy";
    string i1 = "101";

    string t2 = "Physics";
    string a2 = "HC Verma";
    string i2 = "102";

    string t3 = "Maths";
    string a3 = "RD Sharma";
    string i3 = "103";

    string t4 = "Chemistry";
    string a4 = "OP Tandon";
    string i4 = "104";

    string t5 = "English";
    string a5 = "ruskin bond";
    string i5 = "105";

    lib.addNewBook(t1, a1, i1);
    lib.addNewBook(t2, a2, i2);
    lib.addNewBook(t3, a3, i3);
    lib.addNewBook(t4, a4, i4);
    lib.addNewBook(t5, a5, i5);

    string removeId = "103";

    lib.removeBooks(removeId);

    lib.displayDetails();

    return 0;
}


//q2
#include <iostream>
#include <string>

using namespace std;

class Book
{
    string title;
    string author;
    string ISBN;

public:
    Book()
    {
        this->title = "NA";
        this->author = "NA";
        this->ISBN = "000";
    }

    Book(string title, string author, string ISBN)
    {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
    }

    Book(const Book &b)
    {
        this->title = b.title;
        this->author = b.author;
        this->ISBN = b.ISBN;
    }

    bool removeBooks(const string &ISBN)
    {
        if (this->ISBN == ISBN)
        {
            this->title = "";
            this->author = "";
            this->ISBN = "";

            return true;
        }

        return false;
    }

    void displayDetails()
    {
        if (title != "")
        {
            cout << "Title  : " << title << endl;
            cout << "Author : " << author << endl;
            cout << "ISBN   : " << ISBN << endl;
            cout << endl;
        }
    }
};

int main()
{
    Book books1[3] =
    {
        Book("C++", " balaguruswamy", "111"),
        Book("Physics", "HC Verma", "112"),
        Book("Maths", "RD Sharma", "113")
    };

    Book *books2 = new Book[2]
    {
        Book("Chemistry", "OP Tandon", "114"),
        Book("English", "ruskin bond", "115")
    };

    books1[1].removeBooks("112");

    cout << "\nInitializer List Objects\n\n";

    for (int i = 0; i < 3; i++)
    {
        books1[i].displayDetails();
    }

    cout << "\nDynamic Initialization Objects\n\n";

    for (int i = 0; i < 2; i++)
    {
        books2[i].displayDetails();
    }

    delete[] books2;

    return 0;
}



//q3
#include <iostream>
#include <string>

using namespace std;

class Account
{
    const long accountNumber;
    long transactionId;
    string transactionType;
    double balance;

    static long nextId;

public:
    Account(const long acc, const double bal)
        : accountNumber(acc)
    {
        balance = bal;
        transactionId = 0;
        transactionType = "None";
    }

    long depositAmount(const long to, const long from, const double amount)
    {
        if (accountNumber == to)
        {
            balance += amount;
            transactionType = "Credited";
            transactionId = ++nextId;
        }

        return transactionId;
    }

    long creditAmount(const long to, const long from, const double amount)
    {
        if (accountNumber == from)
        {
            balance -= amount;
            transactionType = "Debited";
            transactionId = ++nextId;
        }

        return transactionId;
    }

    void displayDetails() const
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance        : " << balance << endl;
        cout << "Transaction ID : " << transactionId << endl;
        cout << "Transaction    : " << transactionType << endl;
        cout << endl;
    }
};

long Account::nextId = 1000;

int main()
{
    Account a1(1001, 5000);
    Account a2(1002, 7000);
    Account a3(1003, 9000);
    Account a4(1004, 4000);
    Account a5(1005, 8000);

    a1.creditAmount(1002, 1001, 1000);
    a2.depositAmount(1002, 1001, 1000);

    a3.creditAmount(1004, 1003, 1500);
    a4.depositAmount(1004, 1003, 1500);

    a1.displayDetails();
    a2.displayDetails();
    a3.displayDetails();
    a4.displayDetails();
    a5.displayDetails();

    return 0;
}



//q4
#include <iostream>

using namespace std;

class Second;

class First
{
    int value1;

public:
    First(int x)
    {
        value1 = x;
    }

    friend int total(First, Second);
};

class Second
{
    int value2;

public:
    Second(int y)
    {
        value2 = y;
    }

    friend int total(First, Second);
};

int total(First a, Second b)
{
    return a.value1 + b.value2;
}

int main()
{
    First f(40);
    Second s(60);

    cout << "Sum = " << total(f, s) << endl;

    return 0;
}







//q5
#include <iostream>

using namespace std;

class Complex
{
    int real;
    int imaginary;

public:
    Complex(int r, int i)
    {
        real = r;
        imaginary = i;
    }

    Complex(const Complex &c)
    {
        real = c.real;
        imaginary = c.imaginary;
    }

    void display()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }

    friend void sum(Complex, Complex);
};

void sum(Complex c1, Complex c2)
{
    int r = c1.real + c2.real;
    int i = c1.imaginary + c2.imaginary;

    cout << "Sum = " << r << " + " << i << "i" << endl;
}

int main()
{
    Complex c1(4, 5);
    Complex c2(2, 3);

    Complex c3(c1);

    cout << "Complex 1 : ";
    c1.display();

    cout << "Complex 2 : ";
    c2.display();

    cout << "Copied Complex : ";
    c3.display();

    sum(c1, c2);

    return 0;
}
