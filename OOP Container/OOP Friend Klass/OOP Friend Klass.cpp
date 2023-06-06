#include <iostream>
#include <cmath>
#include <string>
#include "container.cpp"

class ChiefCrook
{
    friend class Member;
public:
    int bill = 10000;
    friend class Decorator_Chief;
    int serial_number;
    int profit() {
        return bill;
    }
    void Get(int money) {
        bill = bill+money;
        std::cout << bill;
    }
private:
};

class Member : public ChiefCrook {
public:
    void transfer(Member& x) {
        x.Get(bill / 10);
        bill = (bill / 10) * 9;
    }
    void transfer(ChiefCrook& x) {
        x.Get(bill / 10);
        bill = (bill / 10) * 9;
    }
};

void swap(list<Member> y, list<Member> x) {
    list<Member> z = y;
    y = x;
    x = z;
}

int main() 
{
    ChiefCrook Mafioznik;
    list<Member> the_list;
    list<Member>::iterator list_iter;
    for (int i=0; i < 5;i++) {
        Member Member_;
        the_list.add(Member_);
    }
    list_iter = the_list.begin();
    //std::cout << (*list_iter).profit();
    for (int i = 0; i < 4; i++) {
        Member x = *list_iter;
        ++list_iter;
        Member y = *list_iter;
        x.transfer(y);
        *list_iter = y;
    }
    Member x = *list_iter;
    x.transfer(Mafioznik);
    std::cout << Mafioznik.profit();
    return 0;
}