CC=gcc
TARGET=huff
all: $(TARGET)
# $(TARGET): main.o
#         $(CC) -o $(TARGET) main.o
%: %.o
	$(CC) -o $@ &^
%.o: %.c
	$(CC) -c &^
clean:
	rm -rf *.o $(TARGET)


