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

    int accountChoice;
    cout << "Выберите аккаунт (1 - аккаунт А, 2 - аккаунт B): ";
    cin >> accountChoice;

    if (accountChoice == 1) {
        cout << "Баланс аккаунта A: " << a.getBalance() << endl;
        double amount;
        cout << "Введите сумму для перевода: ";
        cin >> amount;
        if (transfer(a, b, amount)) {
            cout << "Баланс аккаунта A после перевода: " << a.getBalance() << endl;
            cout << "Баланс аккаунта B после перевода: " << b.getBalance() << endl;
        }
    }
    else if (accountChoice == 2) {
        cout << "Баланс аккаунта B: " << b.getBalance() << endl;
        double amount;
        cout << "Введите сумму для перевода: ";
        cin >> amount;
        if (transfer(b, a, amount)) {
            cout << "Баланс аккаунта A после перевода: " << a.getBalance() << endl;
            cout << "Баланс аккаунта B после перевода: " << b.getBalance() << endl;
        }
    }
    else {
        cout << "Ошибка: Неверный выбор аккаунта." << endl;
    }

    return 0;
}
