// JUNAYED HASAN
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("6.Input.txt");
    ofstream output("6.Output.txt");

    if (!file.is_open()) {
        cout << "Input file not found!" << endl;
        return 1;
    }

    string line, result;
    bool insideComment = false;

    while (getline(file, line)) {
        result = "";

        for (int i = 0; i < line.length(); i++) {

            if (insideComment) {
                if (line[i] == '*' && line[i + 1] == '/') {
                    insideComment = false;
                    i++;
                }
            }
            else if (line[i] == '/' && line[i + 1] == '/') {
                break;
            }
            else if (line[i] == '/' && line[i + 1] == '*') {
                insideComment = true;
                i++;
            }
            else {
                result += line[i];
            }
        }

        if (result.find_first_not_of(" \t") != string::npos) {
            output << result << endl;
        }
    }

    file.close();
    output.close();

    cout << "Comments removed successfully!" << endl;

    return 0;
}
