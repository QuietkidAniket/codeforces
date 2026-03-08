#include <bits/stdc++.h>
using namespace std;

int P10[] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
int P8[] = {6, 3, 7, 4, 8, 5, 10, 9};
int IP[] = {2, 6, 3, 1, 4, 8, 5, 7};
int IP_INV[] = {4, 1, 3, 5, 7, 2, 8, 6};
int EP[] = {4, 1, 2, 3, 2, 3, 4, 1};
int P4[] = {2, 4, 3, 1};
int S0[4][4] = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
int S1[4][4] = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};
vector<int> permute(vector<int> bits, int *p, int n)
{
  vector<int> out(n);
  for (int i = 0; i < n; i++)
    out[i] = bits[p[i] - 1];
  return out;
}
vector<int> leftShift(vector<int> bits, int shifts)
{
  rotate(bits.begin(), bits.begin() + shifts, bits.end());
  return bits;
}
vector<int> XOR(vector<int> a, vector<int> b)
{
  vector<int> r(a.size());
  for (int i = 0; i < a.size(); i++)
    r[i] = a[i] ^ b[i];
  return r;
}
int binToDec(int b1, int b2) { return b1 * 2 + b2; }
vector<int> decToBin(int n) { return {n / 2, n % 2}; }
vector<int> fk(vector<int> bits, vector<int> key)
{
  vector<int> left(bits.begin(), bits.begin() + 4);
  vector<int> right(bits.begin() + 4, bits.end());
  vector<int> ep = permute(right, EP, 8);
  vector<int> xored = XOR(ep, key);
  int row0 = binToDec(xored[0], xored[3]);
  int col0 = binToDec(xored[1], xored[2]);
  int row1 = binToDec(xored[4], xored[7]);
  int col1 = binToDec(xored[5], xored[6]);
  vector<int> sboxOut;
  vector<int> s0 = decToBin(S0[row0][col0]);
  vector<int> s1 = decToBin(S1[row1][col1]);
  sboxOut.insert(sboxOut.end(), s0.begin(), s0.end());
  sboxOut.insert(sboxOut.end(), s1.begin(), s1.end());
  vector<int> p4 = permute(sboxOut, P4, 4);
  vector<int> leftNew = XOR(left, p4);
  vector<int> out;
  out.insert(out.end(), leftNew.begin(), leftNew.end());
  out.insert(out.end(), right.begin(), right.end());
  return out;
}
void generateKeys(vector<int> key, vector<int> &K1, vector<int> &K2)
{
  vector<int> p10 = permute(key, P10, 10);
  vector<int> left(p10.begin(), p10.begin() + 5);
  vector<int> right(p10.begin() + 5, p10.end());
  left = leftShift(left, 1);
  right = leftShift(right, 1);
  vector<int> combined;
  combined.insert(combined.end(), left.begin(), left.end());
  combined.insert(combined.end(), right.begin(), right.end());
  K1 = permute(combined, P8, 8);
  left = leftShift(left, 2);
  right = leftShift(right, 2);
  combined.clear();
  combined.insert(combined.end(), left.begin(), left.end());
  combined.insert(combined.end(), right.begin(), right.end());
  K2 = permute(combined, P8, 8);
  cout << "K1: ";
  for (auto i : K1)
    cout << i;
  cout << endl;
  cout << "K2: ";
  for (auto i : K2)
    cout << i;
  cout << endl;
}
vector<int> encrypt(vector<int> pt, vector<int> K1, vector<int> K2)
{
  vector<int> ip = permute(pt, IP, 8);
  vector<int> r1 = fk(ip, K1);
  vector<int> sw;
  sw.insert(sw.end(), r1.begin() + 4, r1.end());
  sw.insert(sw.end(), r1.begin(), r1.begin() + 4);
  vector<int> r2 = fk(sw, K2);
  return permute(r2, IP_INV, 8);
}
vector<int> decrypt(vector<int> ct, vector<int> K1, vector<int> K2)
{
  vector<int> ip = permute(ct, IP, 8);
  vector<int> r1 = fk(ip, K2);
  vector<int> sw;
  sw.insert(sw.end(), r1.begin() + 4, r1.end());
  sw.insert(sw.end(), r1.begin(), r1.begin() + 4);
  vector<int> r2 = fk(sw, K1);
  return permute(r2, IP_INV, 8);
}
int main()
{
  string keyStr, ptStr;
  cout << "Enter 10-bit key: ";
  cin >> keyStr;
  cout << "Enter 8-bit plaintext: ";
  cin >> ptStr;
  vector<int> key, pt;
  for (char c : keyStr)
    key.push_back(c - '0');
  for (char c : ptStr)
    pt.push_back(c - '0');
  vector<int> K1, K2;
  generateKeys(key, K1, K2);
  vector<int> ct = encrypt(pt, K1, K2);
  vector<int> dec = decrypt(ct, K1, K2);
  cout << "Ciphertext: ";
  for (int b : ct)
    cout << b;
  cout << "\nDecrypted: ";
  for (int b : dec)
    cout << b;
  cout << endl;
  return 0;
}
