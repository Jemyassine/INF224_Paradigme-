// server.cpp
// TP C++
// Eric Lecolinet - Telecom ParisTech - 2016.

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "MultimediaManager.h"
#include "ServerTools.h"

const int PORT = 3331;

int main(int argc, char* argv[])
{
    // Create a global MultimediaManager instance.
    MultimediaManager manager;
#ifdef _WIN32

    // Optionally, pre-populate the multimedia database.
    manager.createPhoto("Photo1", ".\\Media\\IMG_0005.JPEG", 48.858844, 2.294351);
    manager.createPhoto("Photo2", ".\\Media\\IMG_0306.JPEG", 40.748817, -73.985428);
    manager.createPhoto("Photo3", ".\\Media\\IMG_0310.JPEG", 40.748817, -73.985428);
    manager.createPhoto("Photo4", ".\\Media\\IMG_0756.JPEG", 40.748817, -73.985428);
    manager.createVideo("Video1", ".\\Media\\Samara.mp4", 120);
    // You can add more objects as needed.
#elif __linux__
    manager.createPhoto("Photo1", "./Media/IMG_0005.JPEG", 48.858844, 2.294351);
    manager.createPhoto("Photo2", "./Media/IMG_0306.JPEG", 40.748817, -73.985428);
    manager.createPhoto("Photo3", "./Media/IMG_0310.JPEG", 40.748817, -73.985428);
    manager.createPhoto("Photo4", "./Media/IMG_0756.JPEG", 40.748817, -73.985428);
    manager.createVideo("Video1", "./Media/Samara.mp4", 120);
    // You can add more objects as needed.
#endif



    // Create the TCPServer with a lambda callback to process each client request.
    auto* server = new TCPServer([&](std::string const& request, std::string& response) -> bool {
        std::cout << "Request received: " << request << std::endl;

        // Process the request using ServerTools, which handles the protocol.
        // The response is built once and then sent back to the client.
        response = ServerTools::protocolDealer(request, manager);
        
        // Return true to keep the connection open.
        return true;
    });

    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
