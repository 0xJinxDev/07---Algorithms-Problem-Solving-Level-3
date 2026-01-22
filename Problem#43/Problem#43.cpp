//Write a program to replace words in a string with/out match case

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void ReadString(string& line, const string& Message) {
    cout << Message << endl;
    getline(cin, line);
}

void AppendWord(string& line, const string& word, const string& Delim) {
    if (!line.empty())
        line += Delim;
    line += word;
}

bool MatchedWords(const string& original, const string& word) {

    if (original.length() != word.length())
        return false;

    for (size_t i = 0; i < original.length(); i++) {
        if (tolower(original[i]) != tolower(word[i]))
            return false;
    }
    return true;
}

void ReplaceWordsInString(string& line,const string& Original,const string& New,const string& Delim,bool MatchCase) {

    string word, temp = line;
    line.clear();

    for (short i = 0; i < temp.length();) {

        if (temp.substr(i, Delim.length()) != Delim) {
            word += temp[i];
            i++;
        }
        else {
            if (!word.empty()) {

                string FinalWord =
                    (MatchCase && word == Original) || (!MatchCase && MatchedWords(Original, word)) ? New : word;

                AppendWord(line, FinalWord, Delim);
                word.clear();
            }
            i += Delim.length();
        }
    }

    if (!word.empty()) {

        string FinalWord =
            (MatchCase && word == Original) || (!MatchCase && MatchedWords(Original, word)) ? New : word;

        AppendWord(line, FinalWord, Delim);
    }
}

int main() {

    string line, Original, New;

    ReadString(line, "Please enter your line:");
    ReadString(Original, "Please enter the word you want to replace:");
    ReadString(New, "Please enter the new word:");

    ReplaceWordsInString(line, Original, New, " ", false);
    cout << "Your line without match case:\n" << line << endl;

    return 0;
}
