#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double initBalance) {
        accountNumber = accNum;
        balance = initBalance;
        interestRate = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Средства успешно внесены." << endl;
        }
        else {
            cout << "Ошибка: Неверная сумма для внесения." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Средства успешно сняты." << endl;
            }
            else {
                cout << "Ошибка: Недостаточно средств на счете." << endl;
            }
        }
        else {
            cout << "Ошибка: Неверная сумма для снятия." << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    double getInterest() {
        return balance * interestRate * (1 / 12);
    }

    void setInterestRate(double rate) {
        if (rate >= 0) {
            interestRate = rate;
            cout << "Процентная ставка успешно обновлена." << endl;
        }
        else {
            cout << "Ошибка: Неверная процентная ставка." << endl;
        }
    }

    int getAccountNumber() {
        return accountNumber;
    }

    friend bool transfer(BankAccount& sender, BankAccount& receiver, double amount);
};

bool transfer(BankAccount& sender, BankAccount& receiver, double amount) {
    if (amount > 0) {
        if (sender.balance >= amount) {
            sender.balance -= amount;
            receiver.balance += amount;
            cout << "Перевод успешно выполнен." << endl;
            return true;
        }
        else {
            cout << "Ошибка: Недостаточно средств для перевода." << endl;
        }
    }
    else {
        cout << "Ошибка: Неверная сумма для перевода." << endl;
    }
    return false;
}


int main() {
    setlocale(LC_ALL, "Russian");

    BankAccount a(12345, 1000.0);
    BankAccount b(54321, 500.0);

    cout << "Баланс первого аккаунта: " << a.getBalance() << endl;
    cout << "Баланс второго аккаунта: " << b.getBalance() << endl;

    transfer(a, b, 505.8);

    cout << "Баланс первого аккаунта после перевода: " << a.getBalance() << endl;
    cout << "Баланс второго аккаунта после перевода: " << b.getBalance() << endl;

    return 0;
}
