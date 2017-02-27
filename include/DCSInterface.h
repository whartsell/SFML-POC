#ifndef DCSINTERFACE_H
#define DCSINTERFACE_H
#include <SFML/Network.hpp>
#include "json.hpp"

#define UDP_RECV_BUFFER_SIZE 1024

class DCSInterface
{
    public:
        DCSInterface();
        virtual ~DCSInterface();
        void poll();


    protected:

    private:
        sf::UdpSocket socket; // the socket that will be used for receiving udp
        char buffer[UDP_RECV_BUFFER_SIZE];
        unsigned short port; // port to bind to
        std::size_t received;
        sf::IpAddress sender;
        void onMessageReceived();
        void subscribe();

};

#endif // DCSINTERFACE_H
