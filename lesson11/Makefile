APPNAME=mycp
SRCS+=main.c
SRCS+=utils.c

all:
	gcc $(SRCS) -o $(APPNAME) -Wshadow
clean:
	rm -f $(APPNAME) test
install:
	cp $(APPNAME) /usr/bin
uninstall:
	rm -f /usr/bin/$(APPNAME)