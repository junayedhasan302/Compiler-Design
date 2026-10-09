// JUNAYED HASAN
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "Cannot open input.txt" << endl;
        return 1;
    }

    // Check whether the file is empty
    if (file.peek() == EOF) {
        cout << "Error: input.txt is empty." << endl;
        return 1;
    }

    string line;
    int singleLine = 0;
    int multiLine = 0;
    bool insideMulti = false;

    while (getline(file, line)) {
        int i = 0;

        while (i < line.length()) {
            // Skip content inside an existing multi-line comment
            if (insideMulti) {
                if (i + 1 < line.length() &&
                    line[i] == '*' && line[i + 1] == '/') {
                    insideMulti = false;
                    i += 2;
                } else {
                    i++;
                }
            }
            // Detect single-line comments
            else if (i + 1 < line.length() &&
                     line[i] == '/' && line[i + 1] == '/') {
                singleLine++;
                break;
            }
            // Detect multi-line comment openings
            else if (i + 1 < line.length() &&
                line[i] == '/' && line[i + 1] == '*') {
                multiLine++;
                insideMulti = true;
                i += 2;
            }
            else {
                i++;
            }
        }
    }

    file.close();

    cout << "Single-line comments: " << singleLine << endl;
    cout << "Multi-line comment openings: " << multiLine << endl;

    return 0;
}