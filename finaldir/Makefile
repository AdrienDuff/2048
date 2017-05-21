
CC = g++ -o3

LIBS = -L/usr/lib /usr/lib/x86_64-linux-gnu /usr/lib/libqthreads.so.0 -lguile -ldl -lreadline -ltermcap -lm

INCLUDES = -I/usr/include/g++-2 -I/usr/include/gtkmm-2.4 -I/usr/lib/sigc++/include -I/usr/include/glibmm-2.4 -I/usr/include/gtk-2.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I/usr/include/glib -I/usr/lib/x86_64-linux-gnu/glib-2.0/include `pkg-config --cflags --libs gtkmm-2.4`

CFLAGS = -g -Wall -Wno-return-type $(INCLUDES) -DSWIG_GLOBAL

neat2: networks.o genetics.o experiments.o neatmain.o neatswig_wrap.o
	$(CC) $(CFLAGS) $(LIBS) networks.o genetics.o experiments.o neatswig_wrap.o neatmain.o -o neat `pkg-config --cflags --libs gtkmm-2.4`

neat: networks.o genetics.o experiments.o neatmain.o neatswig_wrap.o
	$(CC) $(CFLAGS) $(LIBS) networks.o genetics.o experiments.o neatswig_wrap.o neatmain.o -o neat `pkg-config --cflags --libs gtkmm-2.4

networks.o: networks.cpp networks.h
	$(CC) $(CFLAGS) -c networks.cpp -o networks.o  

genetics.o: genetics.cpp networks.h genetics.h
	$(CC) $(CFLAGS) -c genetics.cpp -o genetics.o

visual.o: networks.h
	$(CC) $(CFLAGS) -c visual.cpp -o visual.o

experiments.o: experiments.cpp experiments.h networks.h
	$(CC) $(CFLAGS) -c experiments.cpp -o experiments.o

neatswig_wrap.o: neatswig.i neatswig_wrap.cpp networks.h
	$(CC) $(CFLAGS) -c neatswig_wrap.cpp -o neatswig_wrap.o

#neatswig_wrap.cpp: neatswig.i
#	swig -guile -c++ neatswig.i
#	cp neatswig_wrap.c neatswig_wrap.cpp

neatmain.o: neatmain.cpp neatmain.h neat.h networks.h
	$(CC) $(CFLAGS) -c neatmain.cpp -o neatmain.o





#`gtkmm-2.4-config --cflags --libs` 
















