# todo: posar object files a out/ i source files a src/

CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Aerolinia.o Passatger.o Vol.o Reserva.o
	$(LINK.cc) -o $@ $^

program.o: program.cpp Aerolinia.hpp Passatger.hpp Vol.hpp

Aerolinia.o: Aerolinia.cpp Aerolinia.hpp Passatger.hpp Vol.hpp

Passatger.o: Passatger.cpp Passatger.hpp

Vol.o: Vol.cpp Vol.hpp

Reserva.o: Reserva.cpp Reserva.hpp Passatger.hpp Vol.hpp

.PHONY: clean
clean:
	rm -vf *

.PHONY: test
test:
	./program.exe < samples/sample1.inp
	./program.exe < samples/sample2.inp
	./program.exe < samples/sample3.inp
	./program.exe < samples/sample4.inp

test1:
	./program.exe < samples/sample1.inp | diff - samples/sample1.cor
test2:
	./program.exe < samples/sample2.inp | diff - samples/sample2.cor

#	Descomenteu les següents línies si voleu comprovar tots
#	els jocs de proves.
test4:
#	./program.exe < samples/sample1.inp | diff - samples/sample1.cor
#	./program.exe < samples/sample2.inp | diff - samples/sample2.cor
#	./program.exe < samples/sample3.inp | diff - samples/sample3.cor
#	./program.exe < samples/sample4.inp | diff - samples/sample4.cor
