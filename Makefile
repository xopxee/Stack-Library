CC = gcc
LDFLAGS = -Wall -Wextra -Werror
TARGET = main
HEADERS = stack.h
SOURCES = main.c stack.c
DEPENDENCIES = $(HEADERS) $(SOURCES) 

all: $(TARGET)

$(TARGET): $(DEPENDENCIES)
	$(CC) $(LDFLAGS) $(SOURCES) -o $(TARGET)
	
run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(TARGET)