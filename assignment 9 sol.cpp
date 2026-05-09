//q1
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream file("NUM.TXT");

    for (int i = 1; i <= 200; i++)
    {
        file << i << " ";
    }

    file.close();

    cout << "data is written\n";

    return 0;
}


//q2
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void countAlphabets()
{
    ifstream file("NOTES.TXT");

    char ch;
    int count = 0;

    while (file.get(ch))
    {
        if (isalpha(ch))
        {
            count++;
        }
    }

    cout << " Alphabets = "
         << count << endl;

    file.close();
}

int main()
{
    countAlphabets();

    return 0;
}



//q3
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream source("source.txt");
    ofstream destination("destination.txt");

    char ch;

    while (source.get(ch))
    {
        destination.put(ch);
    }

    source.close();
    destination.close();

    cout << "file is copied";

    return 0;
}



//q4
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    char str[100];

    cout << "Enter String : ";
    cin.getline(str, 100);

    cout << "Length = "
         << strlen(str)
         << endl;

    ofstream outFile("text.txt");

    outFile << str;

    outFile.close();

    ifstream inFile("text.txt");

    char ch;

    cout << "Stored Characters : ";

    while (inFile.get(ch))
    {
        cout << ch;
    }

    inFile.close();

    return 0;
}


//q5(a)
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream file("A-Z.txt");

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        file << ch;
    }

    file.close();

    ifstream inFile("A-Z.txt");

    inFile.seekg(9);

    char ch;

    inFile.get(ch);

    cout << "10th Character = "
         << ch << endl;

    inFile.close();

    return 0;
}


//q5(b)
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file("A-Z.txt", ios::in | ios::out);

    file.seekp(4);

    file.put('X');

    file.close();

    cout << "fifth  character is  Replaced";

    return 0;
}


//q5(c)
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("A-Z.txt");

    file.seekg(0, ios::end);

    cout << "File Size = "
         << file.tellg()
         << " bytes\n";

    file.close();

    return 0;
}

//q5(d)
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("A-Z.txt");

    file.seekg(-1, ios::end);

    char ch;

    file.get(ch);

    cout << "Last Character = "
         << ch << endl;

    file.close();

    return 0;
}




//q5(e)
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outFile("data.txt");

    outFile << "This is line 1\n";
    outFile << "This is line 2\n";
    outFile << "This is line 3\n";

    outFile.close();

    ifstream inFile("data.txt");

    inFile.seekg(10);

    cout << "Current Position = "
         << inFile.tellg()
         << endl;

    char ch;

    cout << "Remaining Content :\n";

    while (inFile.get(ch))
    {
        cout << ch;
    }

    inFile.close();

    return 0;
}





//q6
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file("sample.txt", ios::out | ios::in | ios::trunc);

    string text = "Hello World";

    for (int i = 0; i < text.length(); i++)
    {
        file.put(text[i]);

        cout << "Position after writing "
             << text[i]
             << " = "
             << file.tellp()
             << endl;
    }

    file.seekp(6);

    file << "C++";

    file.close();

    cout << "the word is successfully replaced\n";

    return 0;
}
