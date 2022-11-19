all:
	g++ -std=c++17 -g -Wall ./src/*.cpp ./src/libs/window/*.cpp ./src/libs/rectangle/*.cpp ./src/libs/mouse/*.cpp \
	./src/libs/keyboard/*.cpp ./src/libs/image/*.cpp ./src/libs/font/*.cpp \
	./bin/*.dll -I vendor/include -L vendor/lib -lmingw32 \
	-lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -llua54 -o bin/lgf

	./bin/lgf.exe

build:
	g++ -std=c++17 -g -Wall ./src/*.cpp ./src/libs/window/*.cpp ./src/libs/rectangle/*.cpp ./src/libs/mouse/*.cpp \
	./src/libs/keyboard/*.cpp ./src/libs/image/*.cpp ./src/libs/font/*.cpp \
	./bin/*.dll -I vendor/include -L vendor/lib -lmingw32 \
	-lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -llua54 -o bin/lgf

run:
	./bin/lgf.exe