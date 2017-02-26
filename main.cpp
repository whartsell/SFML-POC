#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "json.hpp"
using json = nlohmann::json;
int main()
{
    sf::RenderWindow window(sf::VideoMode(400,400), "ASI Test");
    sf::Texture background,needle,cap;

    window.setFramerateLimit(30);
    needle.loadFromFile("resources/WhiteNeedleAnemo.png", sf::IntRect(0,0,400,400));
    needle.setSmooth(true);
    cap.loadFromFile("resources/CapNeedleAnemo.png", sf::IntRect(0,0,400,400));
    if (!background.loadFromFile("resources/Anemometer.png", sf::IntRect(0,0,400,400)))
    {
        std::cout << "You Bombed";
    }
    sf::Sprite backgroundSprite,needleSprite,capSprite;
    backgroundSprite.setTexture(background);
    needleSprite.setTexture(needle);
    needleSprite.setOrigin(sf::Vector2f(200,200));
    needleSprite.setPosition(sf::Vector2f(200,200));
    capSprite.setTexture(cap);

    int rotation = 0;

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
    //if (socket.bind(12800,sf::IpAddress("192.168.1.11")) != sf::Socket::Done)
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
        //std::cout << "im trying" <<std::endl;

        if (socket.receive(buffer, sizeof(buffer), received, sender, port)==sf::Socket::Done)
        //if (socket.receive(packet,sender,port)==sf::Socket::Done)
        {
            std::cout << "I got Data" <<std::endl;
            //std::cout << packet <<std:endl;
            //std::cout << sender.toString() << " said: " << buffer << std::endl;
            try {
            std::cout << "trying to parse" <<std::endl;
            //char data[received];
            //std::memcpy(data,buffer,received);
            j = json::parse(buffer);
            std::cout << std::setw(4) << j << std::endl;
            //delete[] data;
            }
            catch(...)
            {
                std::cout << "problem parsing " << std::endl << buffer << std::endl;
            }
            memset(buffer,'\0',received);
        }

        rotation ++;
        needleSprite.setRotation(rotation);
        window.clear();
        window.draw(backgroundSprite);
        window.draw(needleSprite);
        window.draw(capSprite);
        window.display();
    }

    return 0;
}
