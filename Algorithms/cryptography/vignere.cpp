#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> table(){
    vector<vector<char>> t(26, vector<char>(26));
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            t[i][j] = 'A' + (i+j)%26;
    return t;
}

string encrypt(string msg, string key){
    auto t = table();
    int mod = key.size();
    for(int i=key.size(), j=0;i<msg.size();i++,j++)
        key += key[j%mod];

    string enc="";
    for(int i=0;i<msg.size();i++)
        enc += t[msg[i]-'A'][key[i]-'A'];

    return enc;
}

string decrypt(string c, string key){
    auto t = table();
    int mod = key.size();
    for(int i=key.size(), j=0;i<c.size();i++,j++)
        key += key[j%mod];

    string dec="";
    for(int i=0;i<c.size();i++){
        for(int j=0;j<26;j++){
            if(t[j][key[i]-'A'] == c[i]){
                dec += char('A'+j);
                break;
            }
        }
    }
    return dec;
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
