compress_str: compress_str.c
	cc $< -o $@

clean:
	rm -f compress_str
