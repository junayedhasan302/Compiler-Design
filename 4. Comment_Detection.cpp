// JUNAYED HASAN
#include <bits/stdc++.h>
using namespace std;
int main(){

    string line;
    bool singleLine = false, multiLine = false;
    getline(cin, line); // Take one line of input
    for (int i = 0; i + 1 < line.size(); i++){
        if (line[i] == '/' && line[i + 1] == '/'){
            singleLine = true;
            break;
        }

        if (line[i] == '/' && line[i + 1] == '*'){
            multiLine = true;
            break;
        }
    }

    if (singleLine) cout <<"Single-line comment"<<endl;
    else if (multiLine)cout <<"Multi-line comment"<<endl;
    else cout <<"No comment"<<endl;

    return 0;
}