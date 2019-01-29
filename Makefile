all:
	@echo "project not complete"

capture: screen/capture.c
	gcc -Wall -o capture screen/capture.c -lX11

dumper: dumper/dumper.cpp
	g++ -std=c++17 -o dumper dumper/dumper.cpp

executer: command/executer.cpp
	g++ -std=c++17 -o command command/executer.cpp

help:
	@echo "capture			screen capture agent"
	@echo "dumper			file dumper agent"
	@echo "executer			command execution agent"

clean:
	rm -f capture
