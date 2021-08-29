CC = gcc

sysfo: sysfo.c
	$(CC) sysfo.c -o sysfo

clean:
	rm sysfo

install: sysfo.c
	mkdir -p /usr/bin/
	clang sysfo.c -o /usr/bin/sysfo

uninstall: 
	rm -f /usr/bin/sysfo
