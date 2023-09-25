CC = clang++
Files = src/*.cc -o
Output = build/Program

LIBS = -L/usr/local/lib -I/usr/local/include
LDFLAGS= -lX11

OPT1 = -O3 -std=c++20 -stdlib=libc++ -target x86_64-pc-freebsd13.2 -H 
OPT2 = -flto -fvectorize -fstack-protector-strong -fslp-vectorize -v

main:
	mkdir -p build
	$(CC) $(Files) $(Output) $(LIBS) $(LDFLAGS) $(OPT1) $(OPT2)