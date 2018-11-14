HEADERS = tictactoe.h
SERVER_SRC = server.cpp tictactoe.cpp
SERVER_OBJ = server.o tictactoe.o
CLIENT_SRC = client.cpp tictactoe.cpp
CLIENT_OBJ = client.o tictactoe.o


server: $(SERVER_OBJ)
	g++ $(SERVER_OBJ) -o server

client: $(CLIENT_OBJ)
	g++ $(CLIENT_OBJ) -o client

build_s: $(SERVER_SRC)
	g++ -g -c $(SERVER_SRC)

build_c: $(CLIENT_SRC)
	g++ -g -c $(CLIENT_SRC)

all: $(SERVER_SRC) $(CLIENT_SRC)
	g++ -g -c $(SERVER_SRC) $(CLIENT_SRC)

clean:
	rm -i *.o client server
