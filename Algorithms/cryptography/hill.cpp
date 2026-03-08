#include <iostream>
#include <vector>
using namespace std;

int modInverse(int a){
    a = (a%26+26)%26;
    for(int i=1;i<26;i++)
        if((a*i)%26==1)
            return i;
    return -1;
}

vector<vector<int>> inverseKey(vector<vector<int>> &k){
    int det = (k[0][0]*k[1][1] - k[0][1]*k[1][0]) % 26;
    int invDet = modInverse(det);

    vector<vector<int>> inv(2, vector<int>(2));
    inv[0][0] =  k[1][1]*invDet % 26;
    inv[0][1] = -k[0][1]*invDet % 26;
    inv[1][0] = -k[1][0]*invDet % 26;
    inv[1][1] =  k[0][0]*invDet % 26;

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            inv[i][j] = (inv[i][j]+26)%26;

    return inv;
}

string encrypt(string msg, vector<vector<int>> &key){
    if(msg.size()%2) msg+='x';
    string res="";

    for(int i=0;i<msg.size();i+=2){
        for(int r=0;r<2;r++){
            int sum = key[r][0]*(msg[i]-'a') +
                      key[r][1]*(msg[i+1]-'a');
            res += char(sum%26+'a');
        }
    }
    return res;
}

string decrypt(string c, vector<vector<int>> &key){
    auto inv = inverseKey(key);
    string res="";

    for(int i=0;i<c.size();i+=2){
        for(int r=0;r<2;r++){
            int sum = inv[r][0]*(c[i]-'a') +
                      inv[r][1]*(c[i+1]-'a');
            res += char(sum%26+'a');
        }
    }
    return res;
}

int main(){
    int choice;
    vector<vector<int>> key(2, vector<int>(2));

    cout << "Enter 2x2 key matrix:\n";
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin >> key[i][j];

    cout << "1. Encrypt\n2. Decrypt\nEnter choice: ";
    cin >> choice;

    string text;
    cout << "Enter text (lowercase): ";
    cin >> text;

    if(choice == 1)
        cout << "Encrypted text: " << encrypt(text, key);
    else if(choice == 2)
        cout << "Decrypted text: " << decrypt(text, key);
    else
        cout << "Invalid choice";

    return 0;
}