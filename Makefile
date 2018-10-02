CXX = g++

all: server client

server: server.cpp myheader.h
	$(CXX) -I../ -o $@ $<

client: client.cpp myheader.h
	$(CXX) -I../ -o $@ $<

clean:
	rm -f server
	rm -f client
