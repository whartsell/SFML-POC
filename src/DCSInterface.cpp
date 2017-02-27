#include "DCSInterface.h"
#include<iostream>


DCSInterface::DCSInterface()
{
    //ctor
    port = 12800;
    socket.setBlocking(false);
    if (socket.bind(12800) != sf::Socket::Done)
        {
            std::cout << "couldnt bind socket" << std::endl;
        }
}

DCSInterface::~DCSInterface()
{
    //dtor
}
