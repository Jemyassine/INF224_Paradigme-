#ifndef SERVERTOOLS_H
#define SERVERTOOLS_H 

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "tcpserver.h"
#include "MultimediaManager.h"

class ServerTools {
public:
    // Splits the input string 'name' into words and stores them in the array 'parameters'.
    // Returns the number of words extracted.
    // If a double space ("  ") is found, returns 1 immediately.
    static int getWords(std::string parameters[], const std::string& name)
    {
        if (name.find("  ") != std::string::npos) // check for double spaces
            return 1;

        std::string word; // temporary storage for each word
        std::stringstream iss(name); // use stringstream to parse words
        int i = 0; // word counter
        while (iss >> word) // while there are words in the stream
            parameters[i++] = word; // store each word and increment counter
        return i;
    }

    // Processes a protocol request string and interacts with the MultimediaManager.
    // Returns a response string that is sent back to the client.
    static std::string protocolDealer(const std::string& request, MultimediaManager & manager)
{
    const std::string codeEndLine = "ç;1";
    std::ostringstream oss; 

    if (request == "lGrp") {  
        manager.listALLGroups(oss);
    }
    else if (request == "lMlt") {
        manager.listAllMultimedias(oss);
    }
    else {
        // Assume the request has a command and an argument.
        if (request.length() < 5)
            return "Invalid request format" + codeEndLine;
                
        std::string command = request.substr(0, 4);
        int stringSize = request.length() - 5; // 4 chars for command and 1 for space
        std::string name = request.substr(5, stringSize);

        if (command.substr(0, 3) == "add") {
            int width = 0;
            if (command == "addV")
                width = 3;
            else if (command == "addP")
                width = 4;
            else
                return "Unknown add command" + codeEndLine;

            std::string parameters[10];  // fixed size array
            int count = getWords(parameters, name);
            if (count < width)
                return "Make sure the form is complete before trying again." + codeEndLine;

            try {
                if (width == 3)
                    manager.createVideo(parameters[0], parameters[1], std::stoi(parameters[2]));
                else
                    manager.createPhoto(parameters[0], parameters[1], std::stoi(parameters[2]), std::stoi(parameters[3]));
            }
            catch (const std::invalid_argument &e) {
                return "Bad input: invalid argument" + codeEndLine;
            }
            catch (const std::out_of_range &e) {
                return "Integer overflow: out of range" + codeEndLine;
            }
            return "adding " + parameters[0] + codeEndLine;
        }
        else {
            if (stringSize > 0) {
                if (command == "play") {
                    manager.playMultimedia(name);
                    return "playing " + name + codeEndLine;
                }
                else if (command == "find") {
                    std::ostringstream ossFind;
                    manager.displayMultimedia(name, ossFind);
                    return ossFind.str() + codeEndLine;
                }
                else if (command == "remv") {
                    manager.removeMultimedia(name);
                    return "removing " + name + codeEndLine;
                }
                else {
                    return "command not found" + codeEndLine;
                }
            }
            else {
                return "Please, provide a name!" + codeEndLine;
            }
        }
    }

    // Get the complete response from the stream.
    std::string response = oss.str();
    // Replace newline and carriage return characters with a space (or any character that does not interfere)
    std::replace(response.begin(), response.end(), '\n', ' ');
    std::replace(response.begin(), response.end(), '\r', ' ');
    // Append your custom end-of-message code.
    return response + codeEndLine;
}

};

#endif
