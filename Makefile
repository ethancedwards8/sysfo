
sysfo: sysfo.c
	gcc sysfo.c -o sysfo

clean:
	rm sysfo

install: sysfo.c
	mkdir -p /usr/bin/
	gcc sysfo.c -o /usr/bin/sysfo

uninstall: 
	rm -f /usr/bin/sysfo
