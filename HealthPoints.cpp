
#include "HealthPoints.h"
HealthPoints::HealthPoints(int maxHP) :m_currentHP(maxHP),m_MaxHP(maxHP) {
    if(maxHP<=0)
        throw InvalidArgument();
}

int HealthPoints::getCurrentHP() {
    return m_currentHP;
}

int HealthPoints::getMaxHP() {
    return m_MaxHP;
}

HealthPoints& HealthPoints::operator+=(const int number){
    if (m_currentHP + number <= this->m_MaxHP){
        this->m_currentHP += number;
    }
    else{
        this->m_currentHP = m_MaxHP;
    }
    return *this;
}

HealthPoints operator+(HealthPoints& healthPoints1, const int number){
    HealthPoints result = healthPoints1;
    return result+=number;
}

HealthPoints operator+(const int number, HealthPoints& healthPoints1){
    HealthPoints result = healthPoints1;
    return result+=number;
}


HealthPoints& HealthPoints::operator-=(const int number){
    if(this->m_currentHP - number >= 0){
        this->m_currentHP -= number;
    }
    else{
        this->m_currentHP = 0;
    }
    return *this;
}

HealthPoints operator-(HealthPoints& healthPoints1, const int number){
    HealthPoints temp = healthPoints1;
    return temp-= number;
}

HealthPoints operator-(const int number, HealthPoints& healthPoints1){
    HealthPoints temp = healthPoints1;
    return temp-= number;
}


bool operator==(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2 ){
    if (healthPoints1.m_currentHP == healthPoints2.m_currentHP){
        return true;
    }
    else{
        return false;
    }
}

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2){
    if (healthPoints1 == healthPoints2){
        return false;
    }
    else {
        return true;
    }
}


bool operator<(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2){
    if (healthPoints1.m_currentHP < healthPoints2.m_currentHP){
        return true;
    }
    else {
        return false;
    }
}

bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2){
    if ((healthPoints1 == healthPoints2) || (healthPoints1 < healthPoints2) ){
        return true;
    }
    else{
        return false;
    }
}

bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2){
    if ((healthPoints1 < healthPoints2) || (healthPoints1 == healthPoints2)){
        return false;
    }
    else{
        return true;
    }
}

bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2){
    if ((healthPoints1 > healthPoints2) || (healthPoints1 == healthPoints2)){
        return true;
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, HealthPoints toPrint){
    os << toPrint.getCurrentHP()<< '(' <<toPrint.getMaxHP()<< ')';
    return os;
}


/**
int main (){
    try {
        HealthPoints healthpoints1;
        HealthPoints healthpoints2(150);
        cout << healthpoints1 << endl;
        cout << healthpoints2 << endl;
    } catch (HealthPoints::InvalidArgument& e){
        cout << "I caught the problem!" << endl;
    }

}**/