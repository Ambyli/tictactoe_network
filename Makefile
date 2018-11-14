HEADERS = tictactoe.h
OBJECTS = server.o client.o tictactoe.o

server: $(OBJECTS)
	g++ server.cpp tictactoe.cpp -o server

client: $(OBJECTS)
	g++ client.cpp tictactoe.cpp -o client

clean:
	rm -i *.o client server
