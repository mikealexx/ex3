#include <iostream>
#include "HealthPoints.h"

HealthPoints::HealthPoints():
    m_maxHP(DEFAULT_MAX_HP),
    m_hp(DEFAULT_MAX_HP)
{}

HealthPoints::HealthPoints(const int maxHP):
    m_maxHP(maxHP),
    m_hp(m_maxHP)
{
    if(maxHP<=0) {
        throw HealthPoints::InvalidArgument();
    }
}

HealthPoints& HealthPoints::operator+=(const int hpToAdd)
{
    if(this->m_hp+hpToAdd > this->m_maxHP) {
        this->m_hp = this->m_maxHP;
    }
    else if(this->m_hp+hpToAdd < 0) {
        this->m_hp = 0;
    }
    else {
        this->m_hp += hpToAdd;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(const int hpToSubtract)
{
    if(this->m_hp-hpToSubtract > this->m_maxHP) {
        this->m_hp = this->m_maxHP;
    }
    else if(this->m_hp-hpToSubtract < 0) {
        this->m_hp = 0;
    }
    else {
        this->m_hp -= hpToSubtract;
    }
    return *this;
}

HealthPoints operator+(const HealthPoints& hp, const int hpToAdd)
{
    HealthPoints result = hp;
    result += hpToAdd;
    return result;
}

HealthPoints operator+(const int hpToAdd, const HealthPoints& hp)
{
    HealthPoints result = hp + hpToAdd;
    return result;
}

HealthPoints operator-(const HealthPoints& hp, const int hpToSubtract)
{
    HealthPoints result = hp;
    result -= hpToSubtract;
    return result;
}

HealthPoints operator-(const int hpToSubtract, const HealthPoints& hp)
{
    HealthPoints result = hp - hpToSubtract;
    return result;
}

bool operator==(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return hp1.m_hp == hp2.m_hp;
}

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return !(hp1 == hp2);
}

bool operator<(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return hp1.m_hp < hp2.m_hp;
}

bool operator>(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return hp1.m_hp > hp2.m_hp;
}

bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return !(hp1 > hp2);
}

bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return !(hp1 < hp2);
}

ostream& operator<<(ostream& os, const HealthPoints& hp)
{
    os << hp.m_hp << "(" << hp.m_maxHP << ")";
    return os;
}