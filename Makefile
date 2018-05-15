compile:
	clear
	g++ -o chess `pkg-config --cflags --libs gtkmm-3.0` *.cpp
	./chess

debug:
	clear
	g++ -o chess `pkg-config --cflags --libs gtkmm-3.0` *.cpp -g
	gdb chess