CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

sortir.exe: sortir.o laberint.o direccio.o casella.o coord.o
	$(CXX) -o sortir.exe sortir.o

sortir.o: sortir.cpp laberint.hpp casella.hpp direccio.hpp coord.hpp

laberint.o: laberint.cpp laberint.hpp casella.hpp

direccio.o: direccio.cpp direccio.hpp coord.hpp

casella.o: casella.cpp casella.hpp direccio.hpp

coord.o: coord.cpp coord.hpp

clean:
	rm -f *.exe *.o