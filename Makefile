compress_str: compress_str.c
	cc -g $< -o $@

clean:
	rm -f compress_str
