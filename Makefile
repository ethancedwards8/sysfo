sysfo: sysfo.c
	$(CC) sysfo.c -o sysfo

clean:
	rm sysfo

install: sysfo
	mkdir -p /usr/bin/
	cp sysfo /usr/bin/sysfo

uninstall: 
	rm -f /usr/bin/sysfo
