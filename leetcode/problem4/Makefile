CC = gcc
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings

CFLAGS  = -g -Wall

TARGET = median_of_two_sorted_arrays

all:$(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS)  -o $(TARGET) $(TARGET).c
	
clean:
	$(RM) $(TARGET)
