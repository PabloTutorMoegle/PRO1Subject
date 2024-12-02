CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o laberint.o direccio.o casella.o coord.o
	$(CXX) -o program.exe program.o

program.o: program.cpp laberint.hpp casella.hpp direccio.hpp coord.hpp

laberint.o: laberint.cpp laberint.hpp casella.hpp

direccio.o: direccio.cpp direccio.hpp coord.hpp

casella.o: casella.cpp casella.hpp direccio.hpp

coord.o: coord.cpp coord.hpp

clean:
	rm -f *.exe *.o

# g++ -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -o program.exe proves_casella.cpp casella.cpp direccio.cpp coord.cpp
# g++ -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -o program.exe proves_laberint.cpp laberint.cpp direccio.cpp coord.cpp casella.cpp
