#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "json.hpp"
#include "ASI.h"
using json = nlohmann::json;
int main()
{
    sf::RenderWindow window(sf::VideoMode(400,400), "ASI Test");
    window.setFramerateLimit(30);
    ASI asi;



    // setup networking here
    sf::UdpSocket socket;
    socket.setBlocking(false);
    char buffer[1024];
    memset(buffer,'\0',1024);
    sf::Packet packet;
    std::size_t received = 0;
    sf::IpAddress sender;
    unsigned short port;
    json j;

    std::cout << "Starting up" << std::endl;
    if (socket.bind(12800) != sf::Socket::Done)
        {
            std::cout << "couldnt bind socket" << std::endl;
        }
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (socket.receive(buffer, sizeof(buffer), received, sender, port)==sf::Socket::Done)
        {
            std::cout << "I got Data" <<std::endl;
            try {
            std::cout << "trying to parse" <<std::endl;

            j = json::parse(buffer);
            std::cout << std::setw(4) << j << std::endl;
            }
            catch(...)
            {
                std::cout << "problem parsing " << std::endl << buffer << std::endl;
            }
            memset(buffer,'\0',received);
        }
        asi.update();
        window.clear();
        asi.draw(window);
        window.display();
    }

    return 0;
}
