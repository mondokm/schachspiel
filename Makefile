compile:
	mkdir -p bin
	g++ -o bin/chess `pkg-config --cflags --libs gtkmm-3.0` src/*.cpp
	./bin/chess

debug:
	mkdir -p bin
	g++ -o bin/chess `pkg-config --cflags --libs gtkmm-3.0` src/*.cpp -g
	gdb bin/chess