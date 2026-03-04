SOURCES=main.c Assembler.c Coder.c Parser.c Map.c utils.c
EXECUTABLE=assembler

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	gcc -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f $(EXECUTABLE) *.o *.hack
