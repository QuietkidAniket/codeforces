#include <bits/stdc++.h>
using namespace std;

string encrypt(string m, string key){
    int mod = key.size();
    for(int i = key.size(), j = 0; i < m.size(); i++, j++)
        key += key[j % mod];

    string ans = "";
    for(int i = 0; i < m.size(); i++)
        ans += (m[i]-'A' + key[i]-'A') % 26 + 'A';

    return ans;
}

string decrypt(string c, string key){
    int mod = key.size();
    for(int i = key.size(), j = 0; i < c.size(); i++, j++)
        key += key[j % mod];

    string ans = "";
    for(int i = 0; i < c.size(); i++)
        ans += (c[i]-key[i]+26) % 26 + 'A';

    return ans;
}

int main(){
    int choice;
    string text, key;

    cout << "1. Encrypt\n2. Decrypt\nEnter choice: ";
    cin >> choice;

    cout << "Enter text (CAPITAL LETTERS): ";
    cin >> text;
    cout << "Enter key (CAPITAL LETTERS): ";
    cin >> key;

    if(choice == 1)
        cout << "Encrypted text: " << encrypt(text, key);
    else if(choice == 2)
        cout << "Decrypted text: " << decrypt(text, key);
    else
        cout << "Invalid choice";

    return 0;
}
