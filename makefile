CC = g++
Files = src/*.cc -o
Output = build/Program

PKGCONF = `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`

OPT1 = -O3 -std=c++20
OPT2 = -fstack-protector-strong

main:
	mkdir -p build
	$(CC) $(Files) $(Output) $(PKGCONF) $(OPT1) $(OPT2)