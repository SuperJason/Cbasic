TARGET := hello
SRC := main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $< -o $@

clean:
	rm $(TARGET)
									
