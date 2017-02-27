#ifndef DCSINTERFACE_H
#define DCSINTERFACE_H
#include <SFML/Network.hpp>
#include "json.hpp"


class DCSInterface
{
    public:
        DCSInterface();
        virtual ~DCSInterface();

    protected:

    private:
        sf::UdpSocket socket; // the socket that will be used for receiving udp
        char buffer[1024];
        unsigned short port; // port to bind to

};

#endif // DCSINTERFACE_H
