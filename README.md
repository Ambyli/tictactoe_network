# tictactoe_network
A simple tictactoe program that can be played over the internet.

ToCompile:
    
    make client
  
    make server
  
    make clean
  

ToRun:

    ./server <port_number>
  
    ./client <host_addr> <port_number>
  

How To Play:

    Client initially has first move.
  
    Board input is from 0-9.
  
    |0|1|2|
  
    |3|4|5|
  
    |6|7|8|
  
    To quit the game just send the kill command (ctrl+c) for either client or server.
  

Info:

  Currently the program is set up so that both client and server contain the board
  and all that is sent between the two programs is the cordinates where the game pieces
  go. It is however set up so that a alternate implementation can be made where the 
  sends the board to the client. This would put all the trust on the server and make
  the client have no permissions to manipulate the game without going through the
  server first.
  Currently if a user disconnects, the host will trust the client is still there 
  and if a new client connects then it WONT receive the games moves.
