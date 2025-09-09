CFLAGS = -g -I/usr/local/include/freetype2 -I../../shared/stb -I/opt/homebrew/include
CFLAGS += -DGL_SILENCE_DEPRECATION
CFLAGS += -Wall -Werror -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable
LFLAGS = -L/usr/local/lib/ -lfreetype

build: out/libfont_loader.dylib out/font_loader.h

out/libfont_loader.dylib: src/fl.c
	clang -dynamiclib $(CFLAGS) -o out/libfont_loader.dylib src/fl.c $(LFLAGS)

out/font_loader.h: src/fl.h
	cp src/fl.h out/font_loader.h
