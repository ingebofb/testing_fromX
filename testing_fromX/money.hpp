#ifndef money_hpp
#define money_hpp

#include <stdio.h>


class Money {
  
private:
    int dollars;
    int cents;
    
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
    
public:
    Money() : dollars(0), cents(0) {};
    Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount)) {};
    Money(int dollars, int cents) : dollars(dollars), cents(cents) {};
    Money(int dollars) : dollars(dollars), cents(0) {};
    
    double getAmount() const {return dollars + cents*0.01;}
    int getDollars() const {return dollars;}
    int getCents() const {return cents;}
    
    void input();
    void output() const;
};

const Money operator +(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount1, const Money& amount2);
bool operator ==(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount);


#endif /* money_hpp */
