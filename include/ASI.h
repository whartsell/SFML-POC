#ifndef ASI_H
#define ASI_H
#include <SFML/Graphics.hpp>


class ASI
{
    public:
        ASI();
        virtual ~ASI();
        void update();
        void draw(sf::RenderWindow& windowRef);

    protected:

    private:
        sf::Texture background,needle,cap;
        sf::Sprite backgroundSprite,needleSprite,capSprite;
        void loadTextures();
        int rotation;
};

#endif // ASI_H
