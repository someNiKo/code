GCC     = gcc
CFLAGS  = -g -Wall -Wshadow $(INCS)
OBJ     = lib/exceptio.o lib/genlib.o lib/graphics.o lib/linkedlist.o lib/random.o lib/simpio.o lib/strlib.o main.o lib/draw_kun.o
COBJ    = lib\exceptio.o lib\genlib.o lib\graphics.o lib\linkedlist.o lib\random.o lib\simpio.o lib\strlib.o main.o lib\draw_kun.o
LINKOBJ = lib/exceptio.o lib/genlib.o lib/graphics.o lib/linkedlist.o lib/random.o lib/simpio.o lib/strlib.o main.o lib/draw_kun.o
LIBS    = -L"G:/mingw64/lib" -L"G:/mingw64/x86_64-w64-mingw32/lib" -static-libgcc -mwindows
INCS    = -I"G:/mingw64/include" -I"G:/mingw64/x86_64-w64-mingw32/include" -I"G:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include" \
 -I"E:/code/include"
DEL     = del 
BIN     = game.exe
TEXTS   = Makefile~ .Makefile.un~ main.c~ .main.c.un~ lib\exceptio.c~ lib\.exceptio.c.un~ lib\genlib.c~ lib\.genlib.c.un~ \
lib\graphics.c~ lib\.graphics.c.un~ lib\linkedlist.c~ lib\.linkedlist.c.un~ lib\random.c~ lib\.random.c.un~ \
lib\simpio.c~ lib\.simpio.c.un~ lib\strlib.c~ lib\.strlib.c.un~ lib\draw_kun.c~ lib\.draw_kun.c.un~



$(BIN): $(OBJ)
	$(GCC) $(LINKOBJ) -o $(BIN) $(LIBS) -g 

main.o: main.c
	$(GCC) -c main.c -o main.o $(CFLAGS)

lib/exceptio.o: lib/exceptio.c
	$(GCC) -c lib/exceptio.c -o lib/exceptio.o $(CFLAGS)

lib/genlib.o: lib/genlib.c
	$(GCC) -c lib/genlib.c -o lib/genlib.o $(CFLAGS)

lib/graphics.o: lib/graphics.c
	$(GCC) -c lib/graphics.c -o lib/graphics.o $(CFLAGS)

lib/linkedlist.o: lib/linkedlist.c
	$(GCC) -c lib/linkedlist.c -o lib/linkedlist.o $(CFLAGS)

lib/random.o: lib/random.c
	$(GCC) -c lib/random.c -o lib/random.o $(CFLAGS)


lib/simpio.o: lib/simpio.c
	$(GCC) -c lib/simpio.c -o lib/simpio.o $(CFLAGS)


lib/strlib.o: lib/strlib.c
	$(GCC) -c lib/strlib.c -o lib/strlib.o $(CFLAGS)

lib/draw_kun.o: lib/draw_kun.c
	$(GCC) -c lib/draw_kun.c -o lib/draw_kun.o $(CFLAGS)

clean: 
	${DEL} $(COBJ) $(BIN) $(TEXTS) 

fclean:
	${DEL} $(TEXTS)

run:
	./$(BIN)
