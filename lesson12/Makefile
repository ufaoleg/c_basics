APPNAME=main
OUTPUT_FILE_NAME=output.txt

SRCS+=main.c
SRCS+=utils.c
SRCS+=structs.c

all:
	gcc $(SRCS) -o $(APPNAME)
clean:
	rm -f $(APPNAME) $(OUTPUT_FILE_NAME)
debug:
	gcc -o $(APPNAME) $(SRCS) -DDEBUG