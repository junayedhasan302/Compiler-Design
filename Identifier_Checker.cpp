// JUNAYED HASAN
#include <bits/stdc++.h>
using namespace std;
string isValidIdentifier(string s) {
    string keywords[] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while", "class",
        "public", "private", "protected", "this", "new",
        "delete", "try", "catch", "throw", "bool", "true",
        "false", "using", "namespace", "virtual", "friend",
        "inline", "operator", "template", "typename"
    };

    if (s.empty()) {
        return "Invalid Identifier";
    }

    for (int i = 0; i < 56; i++) {
        if (s == keywords[i]) {
            return "Invalid Identifier";
        }
    }

    if (!((s[0] >= 'A' && s[0] <= 'Z') ||
          (s[0] >= 'a' && s[0] <= 'z') ||
          s[0] == '_')) {
        return "Invalid Identifier";
    }

    for (int i = 1; i < s.size(); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= '0' && s[i] <= '9') ||
              s[i] == '_')) {
            return "Invalid Identifier";
        }
    }

    return "Valid Identifier";
}

int main() {

    // cout << isValidIdentifier("abc") << endl;
    // cout << isValidIdentifier("_abc") << endl;
    // cout << isValidIdentifier("abc123") << endl;
    // cout << isValidIdentifier("123abc") << endl;
    // cout << isValidIdentifier("abc@123") << endl;
    // cout << isValidIdentifier("int") << endl;
    // cout << isValidIdentifier("hello_world") << endl;
    // cout << isValidIdentifier("A12") << endl;
    
    string s;
    cout<<"\nEnter a identifier name: ";
    getline(cin, s);
    cout<<endl;
    cout<<isValidIdentifier(s);
    main();
    return 0;
}


/*
========================================

Example 1:

INPUT:
Enter a identifier name: hello_world

OUTPUT:
Valid Identifier


----------------------------------------

Example 2:

INPUT:
Enter a identifier name: 123abc

OUTPUT:
Invalid Identifier


----------------------------------------

Example 3:

INPUT:
Enter a identifier name: int

OUTPUT:
Invalid Identifier


----------------------------------------

Example 4:

INPUT:
Enter a identifier name: abc@123

OUTPUT:
Invalid Identifier


----------------------------------------

Example 5:

INPUT:
Enter a identifier name: _abc

OUTPUT:
Valid Identifier

========================================
*/