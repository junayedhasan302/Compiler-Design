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
    if (s.empty()) {return "Invalid Identifier";}
    for (int i = 0; i < 56; i++) {
        if (s == keywords[i]) {
            return "Invalid Identifier";
        }}
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
            return "Invalid Identifier";}}
    return "Valid Identifier";
}
int main() {
    string s;
    cout<<"\n---3rd LAB: Identifier_Checker---";
    cout<<"\nEnter a identifier name: ";
    getline(cin, s);
    cout<<isValidIdentifier(s);
    main();
    return 0;
}
