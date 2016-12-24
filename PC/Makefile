TARGET = service
CC := gcc
OBJECTS = main.o module.o socket.o
ifeq ($(compile), debug)
	CFLAGS := -O2 -g -std=c99
else
	CFLAGS := -O2 -std=c99
endif
LDFLAGS = -lm

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)
	make clean

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -fr $(OBJECTS)
