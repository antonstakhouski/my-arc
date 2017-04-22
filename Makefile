CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c btree.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=huff
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# %.o: %.c
#         $(CC) -c &^

.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o $(TARGET)


