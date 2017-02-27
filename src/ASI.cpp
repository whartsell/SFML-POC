#include "ASI.h"

ASI::ASI()
{
    //ctor
    loadTextures();
    backgroundSprite.setTexture(background);
    needleSprite.setTexture(needle);
    needleSprite.setOrigin(sf::Vector2f(200,200));
    needleSprite.setPosition(sf::Vector2f(200,200));
    capSprite.setTexture(cap);
    rotation = 0;
    keys = {48,//asi dial
            49,//asi window
            };
}

ASI::~ASI()
{
    //dtor
}

void ASI::update()
{
    rotation ++;
    needleSprite.setRotation(rotation);
}

void ASI::draw(sf::RenderWindow& windowRef)
{
    windowRef.draw(backgroundSprite);
    windowRef.draw(needleSprite);
    windowRef.draw(capSprite);
}

void ASI::loadTextures()
{
    needle.loadFromFile("resources/WhiteNeedleAnemo.png", sf::IntRect(0,0,400,400));
    needle.setSmooth(true);
    cap.loadFromFile("resources/CapNeedleAnemo.png", sf::IntRect(0,0,400,400));
    background.loadFromFile("resources/Anemometer.png", sf::IntRect(0,0,400,400));
}
