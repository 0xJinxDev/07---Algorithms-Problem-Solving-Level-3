// Write a program to trim right / left / all
#include <iostream>
#include <string>

using namespace std;

void ReadString(string& line, const string& Message) {
    cout << Message << endl;
    getline(cin, line);
}

void TrimLeft(string& line) {
    size_t i = 0;

    while (i < line.length() && line[i] == ' ') {
        i++;
    }

    line = line.substr(i);
}

void TrimRight(string& line) {
    if (line.empty())
        return;

    int i = line.length() - 1;

    while (i >= 0 && line[i] == ' ') {
        i--;
    }

    line = line.substr(0, i + 1);
}

void TrimAll(string& line) {
    TrimLeft(line);
    TrimRight(line);
}

int main() {
    string line;
    ReadString(line, "Enter your line:");

    cout << "\nAfter Trim Left:\n";
    TrimLeft(line);
    cout << line << endl;

    cout << "\nAfter Trim Right:\n";
    TrimRight(line);
    cout << line << endl;

    cout << "\nAfter Trim All:\n";
    TrimAll(line);
    cout << line << endl;

    return 0;
}
