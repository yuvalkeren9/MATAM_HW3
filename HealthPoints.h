//
// Created by eladm on 21/05/2022.
//

#ifndef HW3_HEALTHPOINTS_H
#define HW3_HEALTHPOINTS_H


class HealthPoints {
public:
explicit HealthPoints(int maxHP=100);


    class InvalidArgument{};

private:
    int m_currentHP;
    int m_MaxHP;
};


#endif //HW3_HEALTHPOINTS_H
