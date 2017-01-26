#ifndef ROCKET_H
#define ROCKET_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "upgrade.h"


class rocket : public sf::Drawable
{
    public:
        rocket();
        rocket(std::vector<upgrade*> upgradeList);
        void setLocation(sf::Vector2f loc);

        float boost;
        float aerodynamic;
        int coolness;

        //Calculate Rocket Stats from Upgrade List
        void updateStats();

        int m_totalCoins;

        sf::Vector2f m_position;
        float m_currentVelocity;

    protected:

    private:
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;


        sf::Texture m_texture_rocket;
        std::vector<upgrade*> myUpgradeList;

        //Upgrades
        upgrade* rocketbody;
        upgrade* rocketgoggles;
        upgrade* rocketwings;
        upgrade* rocketbooster;
        upgrade* rockettail;

};

#endif // ROCKET_H
