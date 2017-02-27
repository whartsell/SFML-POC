#include "DCSInterface.h"
#include<iostream>

using json = nlohmann::json;

DCSInterface::DCSInterface()
{
    //ctor
    port = 12800;
     memset(buffer,'\0',UDP_RECV_BUFFER_SIZE);
    socket.setBlocking(false);
    received = 0;
    if (socket.bind(12800) != sf::Socket::Done)
        {
            std::cout << "couldnt bind socket" << std::endl;
        }
}

void DCSInterface::poll()
{
    if (socket.receive(buffer, sizeof(buffer), received, sender, port)==sf::Socket::Done)
        {
            std::cout << "I got Data" <<std::endl;
            try {
            std::cout << "trying to parse" <<std::endl;

            json j = json::parse(buffer);
            std::cout << std::setw(4) << j << std::endl;
            }
            catch(...)
            {
                std::cout << "problem parsing " << std::endl << buffer << std::endl;
            }
            memset(buffer,'\0',received);
        }
}

DCSInterface::~DCSInterface()
{
    //dtor
}
