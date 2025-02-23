##########################################
#
#  Exemple de Makefile compatible Windows/Linux
#
##########################################
.PHONY: clean clean-all run run-server run-client

# Nom du programme
SERVER = server
CLIENT = client
CLISERV = cliserv

# Fichiers sources
CLIENT_SOURCES = client.cpp ccsocket.cpp
SERVER_SOURCES = Multimedia.cpp Photo.cpp Video.cpp Film.cpp Group.cpp MultimediaManager.cpp server.cpp tcpserver.cpp ccsocket.cpp
CLISERV_SOURCES = $(SERVER_SOURCES) $(CLIENT_SOURCES) Makefile

# Fichiers objets
CLIENT_OBJETS = $(CLIENT_SOURCES:%.cpp=%.o)
SERVER_OBJETS = $(SERVER_SOURCES:%.cpp=%.o)

# Compilateur C++
CXX = g++

# Options du compilateur
CXXFLAGS = -std=c++11 -Wall -g

# Options de l'éditeur de liens
LDFLAGS =

# Commande pour supprimer des fichiers (adaptée pour Windows/Linux)
ifeq ($(OS),Windows_NT)
LDLIBS = -lws2_32
RM = del /Q
NULL = NUL
else
RM = rm -f
NULL = /dev/null
LDLIBS = -lpthread
endif

##########################################
# Règles de compilation et exécution

all: $(SERVER)

run: $(SERVER)
	./$(SERVER)

run-client: $(CLIENT)
	./$(CLIENT)

$(SERVER): depend-$(SERVER) $(SERVER_OBJETS)
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $(SERVER_OBJETS) $(LDLIBS)

$(CLIENT): depend-$(CLIENT) $(CLIENT_OBJETS)
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $(CLIENT_OBJETS) $(LDLIBS)

clean:
	-@$(RM) *.o depend-$(CLIENT) depend-$(SERVER) core 1>$(NULL) 2>&1

clean-all: clean
	-@$(RM) $(CLIENT) $(SERVER) 1>$(NULL) 2>&1

tar:
	tar cvf $(CLISERV).tar.gz $(CLISERV_SOURCES)

# Gestion des dépendances
depend-$(CLIENT):
	$(CXX) $(CXXFLAGS) -MM $(CLIENT_SOURCES) > depend-$(CLIENT)

depend-$(SERVER):
	$(CXX) $(CXXFLAGS) -MM $(SERVER_SOURCES) > depend-$(SERVER)

###########################################
# Règles implicites

.SUFFIXES: .cpp .cxx .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

#############################################
# Inclusion du fichier des dépendances

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),clean-all)
	-include depend-$(CLIENT)
	-include depend-$(SERVER)
endif
endif
