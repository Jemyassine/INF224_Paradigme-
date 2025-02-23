# Jemni Yassine Abdallah

# My Project

This project is a multimedia management system implemented in C++. It includes functionalities for managing various types of multimedia files such as photos, videos, and films. The project also includes a server-client architecture for remote access and manipulation of the multimedia database.

## Project Structure

### CPP/ 
- ccsocket.cpp ccsocket.h 
- client.cpp 
- Film.cpp Film.h 
- Group.cpp Group.h 
- main.cpp 
- Makefile
-   Media/ IMG_0005.JPEG IMG_0306.JPEG IMG_0310.JPEG ... 
- Multimedia.cpp Multimedia.h 
- MultimediaManager.cpp MultimediaManager.h 
- MultimediaManagerTest.h 
- Photo.cpp Photo.h 
- server.cpp 
- ServerTools.h 
- tcpserver.cpp tcpserver.h 
- TestPolymorphisme.h 
- Video.cpp Video.h 
### Doxygen/ 
- docbook/ ... 
- html/ ... 
- latex/ 
- man/ 
- rtf/ 
- xml/ 

### README.md 

### swing/ 
 - src/ Main.java
 - src/swing/Window.java
 - src/swing/Client.java



## Components

### Multimedia Management

- **Multimedia**: Base class for all multimedia types.
- **Photo**: Class for managing photo files.
- **Video**: Class for managing video files.
- **Film**: Class for managing film files.
- **Group**: Class for managing groups of multimedia files.
- **MultimediaManager**: Class for managing the multimedia database.

### Server-Client Architecture

- **TCPServer**: Class for handling server-side TCP connections.
- **Client**: Class for handling client-side operations.
- **ServerTools**: Utility functions for server operations.

## Build and Run

### Prerequisites

- C++ compiler
- Make

### Build

Navigate to the `CPP` directory and run:

```sh
make
```


### Multimedia Management

- **Multimedia**: Base class for all multimedia types.
- **Photo**: Class for managing photo files.
- **Video**: Class for managing video files.
- **Film**: Class for managing film files.
- **Group**: Class for managing groups of multimedia files.
- **MultimediaManager**: Class for managing the multimedia database.

### Server-Client Architecture

- **TCPServer**: Class for handling server-side TCP connections.
- **Client**: Class for handling client-side operations.
- **ServerTools**: Utility functions for server operations.

## Build and Run

### Prerequisites

- C++ compiler
- Make

### Build

Navigate to the `CPP` directory and run:

```sh
make
```

### Run

```sh
make run
```