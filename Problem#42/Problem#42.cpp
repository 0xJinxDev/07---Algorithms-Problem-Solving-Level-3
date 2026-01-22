//Write a program to replace words in a string

#include <iostream>
#include <string>

using namespace std;

void ReadString(string& line, const string& Message) {
    cout << Message << endl;
    getline(cin, line);
}

void AppendWord(string& line,const string& word,const string& Original,const string& New,const string& Delim) {

    if (!line.empty()) {
        line += Delim;
    }

    if (word == Original)
        line += New;
    else
        line += word;
}

void ReplaceWordsInString(string& line,const string& Original,const string& New,const string& Delim) {

    string word, temp = line;
    line.clear();

    for (short i = 0; i < temp.length();) {

        if (temp.substr(i, Delim.length()) != Delim) {
            word += temp[i];
            i++;
        }
        else {
            if (!word.empty()) {
                AppendWord(line, word, Original, New, Delim);
                word.clear();
            }
            i += Delim.length();
        }
    }

    if (!word.empty()) {
        AppendWord(line, word, Original, New, Delim);
    }
}

int main() {

    string line, Original, New;

    ReadString(line, "Please enter your line:");
    ReadString(Original, "Please enter the word you want to replace:");
    ReadString(New, "Please enter the new word:");

    ReplaceWordsInString(line, Original, New, " ");
    cout << line << endl;

    return 0;
}
