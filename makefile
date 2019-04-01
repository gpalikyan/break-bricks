main.exe : main.cpp game.cpp items.cpp break_bricks.cpp
	g++ -g -O0  -std=c++11 `pkg-config --cflags gtkmm-3.0` -o main.exe main.cpp game.cpp items.cpp break_bricks.cpp `pkg-config --libs gtkmm-3.0` 