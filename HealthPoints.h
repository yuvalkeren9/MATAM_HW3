
#ifndef HW3_HEALTHPOINTS_H
#define HW3_HEALTHPOINTS_H

#include <iostream>

using std::cout;
using std::endl;




/** --------------- HealthPoints class ---------------*/
/**
 * this class represents the health points that a certain player holds at any given moment in the game.
 *the health points of a player is any natural number between 0
 * and the maxHP that the player was initialized with */

class HealthPoints {
public:
    /**
     * Constructor of the HealthPoints class type.
     * @param maxHP - the maxHP that the player was initialized.
     * @return a new instance of HealthPoints.
     */

    HealthPoints(int maxHP= defaultMaxHP);

    /**
     * Operator += of the HealthPoints type
     *
     * Using the operator+ of int and m_currentHp, and saving it to m_currentHP.
     * Does not allow going over the m_maxHP.
     *
     * @param number - the number to add to m_healthpoints.
     * @return HealthPoints& reference.
     */
    HealthPoints& operator+=(const int number);

    /**
    * Operator -= of the HealthPoints type
    *
    * Using the operator- of int and m_currentHp, and saving it to m_currentHP.
    * Does not allow going under 0.
    *
    * @param number - the number to decrease to m_healthpoints.
    * @return HealthPoints& reference.
    */
    HealthPoints& operator-=(const int number);

    /**
     * operator== of HealthPoints type
     *
     * comparing the m_currentHP of both instances
     *
     * @param healthPoints1 - healthPoints instance
     * @param healthPoints2 - healthPoints instance
     * @return true/false according to logical bool
     */
    friend bool operator==(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2);

    /**
    * operator< of HealthPoints type
    *
   * comparing the m_currentHP of both instances
   *
   * @param healthPoints1 - healthPoints instance
   * @param healthPoints2 - healthPoints instance
   * @return true/false according to logical bool
   */
    friend bool operator<(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2);
    /**
     * getter for the MaxHP member
     *
     * @return m_MaxHP
     */
    friend std::ostream& operator<<(std::ostream& os, HealthPoints toPrint);

   /**
    * class type for returning InvalidArgument exception
    */
    class InvalidArgument{};
private:
    /** defining a default value for MaxHP */
    static const int defaultMaxHP = 100;

    /**members of the class */
    int m_currentHP;
    int m_MaxHP;
};


/** overloading the +/- operators. There are 2 instances so that the operator will be usable from both sides.*/

HealthPoints operator+(HealthPoints& healthPoints1, const int number);
HealthPoints operator+(const int number, HealthPoints& healthPoints1);
HealthPoints operator-(HealthPoints& healthPoints1, const int number);
//HealthPoints operator-(const int number, HealthPoints& healthPoints1);


/** overloading the diffrent bool operators for comparing HealthPoints type */

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

/** a printing function for the HealthPoints type.
 * Prints the type in the following way: m_currentHP(m_MaxHP)*/

std::ostream& operator<<(std::ostream& os, HealthPoints toPrint);
#endif //HW3_HEALTHPOINTS_H