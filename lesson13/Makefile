APPNAME=main
OUTPUT_FILE_NAME=output.txt

SRCS+=main.c
SRCS+=temp_functions.c
SRCS+=structs.c
CFLAGS+= -g -O0

all:
	@echo compiling $(SRCS)
	@gcc $(SRCS) -o $(APPNAME) -O2
	@echo use \'./$(APPNAME) -h\' for additional info.
clean:
	@echo ''
	rm -f $(APPNAME) $(OUTPUT_FILE_NAME)
debug:
	@echo compiling $(SRCS)
	@gcc -o $(APPNAME) $(SRCS) -DDEBUG $(CFLAGS) 
	@echo use \'./$(APPNAME) -h\' for additional info.