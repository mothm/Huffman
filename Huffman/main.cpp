#include <iostream>
#include <fstream>
#include <string>

int* count(std::ifstream& input)
{
    input.seekg(0, ios::end);
    long endByte = input.tellg();
    input.seekg(0, ios::beg);
    char *buffer = new char[endByte];
    input.read(buffer, endByte);
    int *counts = new int[256];
    for (int i = 0; i < 256; i++)
        counts[i] = 0;
    for (int i = 0; i < endByte; i++)
    {
        char symbol = buffer[i];
        counts[symbol]++;
    }
    counts[256] = 1;
    return counts&;
}

void compress()
{
    using namespace std;
    cout << "WELCOME TO THE .TXT FILE COMPRESSION SYSTEM" << endl;
    string name;
    ifstream *p_in = 0;
    while (1)
    {
        cout << "Please enter the file name you would like to compress: ";
        cin >> name;
        ifstream in(name);
        if (!in)
        {
            cout << "INVALID FILE NAME" << endl;
            continue;
        }
        p_in = in;
        break;
    }
    int *fileCount = count(*p_in);
}

int main()
{
    while (1)
    {
        using namespace std;
        cout << "Choose whether you would like to:" << endl;
        cout << "\t-Compress a File (1)" << endl;
        cout << "\t-Expand a Compressed File (2)" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            compress();
            break;
        }
        else if (choice == 2)
        {
            expand();
            break;
        }
        else
            cout << "INVALID OPTION." << endl;
    }
    return 0;
}
