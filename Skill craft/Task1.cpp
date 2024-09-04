#include <iostream>
#include <string>
using namespace std;

string caesarCipher(string text, int shift, bool decrypt = false) {
    string result = "";
    if (decrypt) {
        shift = -shift;
    }
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isupper(ch)) {
            result += char(int(ch + shift - 65) % 26 + 65);
        }
        else if (islower(ch)) {
            result += char(int(ch + shift - 97) % 26 + 97);
        }
        else {
            result += ch;
        }
    }

    return result;
}

int main() {
    string text;
    int shift;
    string mode;

    cout << "Caesar Cipher Program" << endl;
    cout << "Do you want to 'encrypt' or 'decrypt' the message? ";
    cin >> mode;
    cin.ignore(); 

    cout << "Enter the message: ";
    getline(cin, text);

    cout << "Enter the shift value (e.g., 3): ";
    cin >> shift;

    bool decrypt = (mode == "decrypt");

    string result = caesarCipher(text, shift, decrypt);
    cout << "Result: " << result << endl;

    return 0;
}
