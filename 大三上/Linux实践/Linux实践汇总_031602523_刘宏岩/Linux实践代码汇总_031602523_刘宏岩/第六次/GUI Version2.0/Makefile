sever: sever.cpp 
	g++ -o sever sever.cpp -std=c++11 `pkg-config gtk+-2.0 --cflags --libs`
	g++ -o client client.cpp -std=c++11 `pkg-config gtk+-2.0 --cflags --libs`

clean: 
	rm -f *.o sever
	rm -f *.o client
	
