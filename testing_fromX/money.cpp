#include <iostream>
#include <cmath>
#include <cstdlib>
#include "money.hpp"

using namespace std;


void Money::input(){
    char dollarSign;
    cin >> dollarSign; //hopefully
        if (dollarSign != '$') {
            cout << "No dollar sign in Money input.\n";
            exit(1);
        }
        double amountAsDouble;
        cin >> amountAsDouble;
        dollars = dollarsPart(amountAsDouble);
        cents = centsPart(amountAsDouble);
}

void Money::output() const {
    int absDollars = abs(dollars);
    int absCents = abs(cents);
    if (dollars < 0 || cents < 0)
        cout << "$-";
    else
        cout << '$';
    cout << absDollars;
    if (absCents >= 10)
        cout << '.' << absCents;
    else
        cout << '.' << '0' << absCents;
}

int Money::dollarsPart(double amount) const {
    return static_cast<int>(amount);
}

int Money::centsPart(double amount) const {
    double doubleCents = amount * 100;
    int intCents = (round(fabs(doubleCents))) % 100;
    if (amount < 0)
        intCents = -intCents;
    
    return intCents;
}

int Money::round(double number) const {
    return static_cast<int>(floor(number + 0.5));
}

const Money operator +(const Money& amount1, const Money& amount2) {
    int allCents1 = amount1.getCents() + amount1.getDollars()*100;
    int allCents2 = amount2.getCents() + amount2.getDollars()*100;
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents);
    int finalDollars = absAllCents/100;
    int finalCents = absAllCents % 100;
    
    if (sumAllCents < 0){
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    
    return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2) {
    int allCents1 = amount1.getCents() + amount1.getDollars()*100;
    int allCents2 = amount2.getCents() + amount2.getDollars()*100;
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents);
    int finalDollars = absAllCents/100;
    int finalCents = absAllCents % 100;
    
    if (diffAllCents < 0){
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    
    return Money(finalDollars, finalCents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return ((amount1.getDollars() == amount2.getDollars()) && (amount1.getCents() == amount2.getCents()));
}
const Money operator -(const Money& amount) {
    return Money(-amount.getDollars(), -amount.getCents());
}
