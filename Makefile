CXX = g++

all: server client

server: server.cpp
	$(CXX) -I../ -o $@ $<

client: client.cpp
	$(CXX) -I../ -o $@ $<

clean:
	rm -f server
	rm -f client