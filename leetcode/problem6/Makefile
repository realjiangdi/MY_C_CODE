CC = gcc
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings

CFLAGS  = -g -Wall

TARGET = zigzag_conversion

all:$(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS)  -o $(TARGET) $(TARGET).c
	
clean:
	$(RM) $(TARGET)
