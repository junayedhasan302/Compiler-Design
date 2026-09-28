// JUNAYED HASAN
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    int i = 0;
    while (i < s.length()){
        while (i < s.length() && (s[i] == ' ' || s[i] == '@' || s[i] == ',' || s[i] == ';' || s[i] == '$' || s[i] == ':')){
            i++;
        }
        if (i >= s.length())
            break;
        cout << "<";
        while (i < s.length() && s[i] != ' ' && s[i] != '@' && s[i] != ',' && s[i] != ';' && s[i] != '$' && s[i] != ':'){
            cout << s[i];
            i++;
        }
        cout << ">" << endl;
    }
    return 0;
}



/*

=========================================
INPUT:
Enter a string: int a = b + c;

<int>
<a>
<=>
<b>
<+>
<c>


-----------------------------------------
INPUT:
Enter a string: hello@world,programming;

OUTPUT:
<hello>
<world>
<programming>


-----------------------------------------
INPUT:
Enter a string: int sum = a + b;

OUTPUT:
<int>
<sum>
<=>
<a>
<+>
<b>
=========================================
*/