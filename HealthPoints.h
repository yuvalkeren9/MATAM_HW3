//
// Created by eladm on 21/05/2022.
//

#ifndef HW3_HEALTHPOINTS_H
#define HW3_HEALTHPOINTS_H

#include <iostream>

using std::cout;
using std::endl;

class HealthPoints {
public:
    explicit HealthPoints(int maxHP= defaultMaxHP);

    HealthPoints& operator+=(const int number);
    HealthPoints& operator-=(const int number);
    friend bool operator==(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2);
    friend bool operator<(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2);
    int getMaxHP();
    int getCurrentHP();
    class InvalidArgument{};
private:
    static const int defaultMaxHP = 100;
    int m_currentHP;
    int m_MaxHP;
};

HealthPoints operator+(HealthPoints& healthPoints1, const int number);
HealthPoints operator+(const int number, HealthPoints& healthPoints1);
HealthPoints operator-(HealthPoints& healthPoints1, const int number);
HealthPoints operator-(const int number, HealthPoints& healthPoints1);
bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
std::ostream& operator<<(std::ostream& os, HealthPoints toPrint);
#endif //HW3_HEALTHPOINTS_H