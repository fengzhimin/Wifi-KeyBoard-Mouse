TARGET = service
CC := gcc
OBJECTS = main.o module.o socket.o
ifeq ($(compile), debug)
	CFLAGS := -O2 -Wall -g
else
	CFLAGS := -O2 -Wall
endif
LDFLAGS = -lm

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)
	make clean

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -fr $(OBJECTS)
