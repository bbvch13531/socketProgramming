CXX = g++

all: server client

server: server.cpp
	$(CXX) -o $@ $<

client: client.cpp
	$(CXX) -o $@ $<

clean:
	rm -f server
	rm -f client