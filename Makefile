HEADERS = tictactoe.h
SOURCES = client.cpp server.cpp tictactoe.cpp
OBJECTS = server.o client.o tictactoe.o



build_server: $(OBJECTS)
	g++ -o server -g $(OBJECTS)

build_client: $(OBJECTS)
	g++ -o client -g $(OBJECTS)

build: $(OBJECTS)
	g++ -c $(SOURCES)

clean:
	rm -i *.o client server
