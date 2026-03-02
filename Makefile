CC = gcc
LDFLAGS = 
TARGET = main
HEADERS = stack.h
SOURCES = main.c stack.c
DEPENDENCIES = $(HEADERS) $(SOURCES) 

all: $(TARGET)

$(TARGET): $(DEPENDENCIES)
	$(CC) $(SOURCES) -o $(TARGET)
	
run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(TARGET)