CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: example.out
	./example.out

example.out: obj/Dr3D_gnuplot_api.o obj/example.o
	g++ -o example.out objexample.o obj/Dr3D_gnuplot_api.o -lpthread

obj/example.o: src/example.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/example.o src/example.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

clear:
	rm example.out example.o Dr3D_gnuplot_api.o
