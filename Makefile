TARGET := hello \
  1_Reverse_Words_in_a_String \
  2_Evaluate_Reverse_Polish_Notation \
  3_Max_Points_on_a_Line
CC := gcc
GPP := g++

all: $(TARGET)

hello: main.c
	$(CC) $< -o $@
	
1_Reverse_Words_in_a_String: 1_Reverse_Words_in_a_String.cpp
	$(GPP) $< -o $@

2_Evaluate_Reverse_Polish_Notation: 2_Evaluate_Reverse_Polish_Notation.cpp
	$(GPP) -std=gnu++0x $< -o $@

3_Max_Points_on_a_Line: 3_Max_Points_on_a_Line.cpp
	$(GPP) -std=gnu++0x $< -o $@

clean:
	rm -f $(TARGET)
