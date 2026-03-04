SOURCES=main.c VMtranslator.c Coder.c Parser.c utils.c
EXECUTABLE=VMtranslator

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	gcc -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f $(EXECUTABLE) *.o *.asm
