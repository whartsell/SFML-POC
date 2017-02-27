#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "json.hpp"
#include "ASI.h"
#include "DCSInterface.h"
using json = nlohmann::json;
int main()
{
    sf::RenderWindow window(sf::VideoMode(400,400), "ASI Test");
    window.setFramerateLimit(30);
    ASI asi;
    DCSInterface interface;

    std::cout << "Starting up" << std::endl;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        interface.poll();
        asi.update();

        window.clear();
        asi.draw(window);
        window.display();
    }

    return 0;
}
