TARGET := hello 1_reverse_words_in_a_string
CC := gcc
GPP := g++

all: $(TARGET)

hello: main.c
	$(CC) $< -o $@
	
1_reverse_words_in_a_string: 1_reverse_words_in_a_string.cpp
	$(GPP) $< -o $@

clean:
	rm -f $(TARGET)
									
