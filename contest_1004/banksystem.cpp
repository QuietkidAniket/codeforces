#include <iostream>
 #include <thread>
 #include <mutex>
 using namespace std;
 class BankAccount {
 private:
  double balance;
  mutex mtx;
 public:
  BankAccount(double initial_balance) : balance(initial_balance) {}
  void deposit(double amount) {
 lock_guard<mutex> lock(mtx);
 balance += amount;
 cout << "Husband deposited: " << amount << ", New Balance: " << balance << endl;
  }
  void withdraw(double amount) {
 lock_guard<mutex> lock(mtx);
 if (amount <= balance) {
    balance -= amount;
    cout << "Wife withdrew: " << amount << ", New Balance: " << balance << endl;
 } else {
    cout << "Insufficient funds for withdrawal of " << amount << endl;
 }
  }
  double get_balance() const {
 return balance;
  }
 };
 void husband_deposit(BankAccount &account, double amount) {
  account.deposit(amount);
 }
 void wife_withdraw(BankAccount &account, double amount) {
  account.withdraw(amount);
 }
 int main() {
  double initial_balance, withdraw_amount, deposit_amount;
  cout << "Enter initial account balance: ";
  cin >> initial_balance;
  BankAccount account(initial_balance);
  cout << "Enter amount to withdraw (wife's action): ";
  cin >> withdraw_amount;
  cout << "Enter amount to deposit (husband's action): ";
  cin >> deposit_amount;
  thread husband_thread(husband_deposit, ref(account), deposit_amount);
  thread wife_thread(wife_withdraw, ref(account), withdraw_amount);
  husband_thread.join();
  wife_thread.join();
  cout << "Final Balance: " << account.get_balance() << endl;
 return 0;
 }