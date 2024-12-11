CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

SRCS = sortir.cpp laberint.cpp direccio.cpp casella.cpp coord.cpp

TARGET = sortir.exe

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

distclean:
	rm -f *.exe *.o

# Para probar el programa con el fichero de entrada "laberint.txt" ejecutar 
# el siguiente comando: ./sortir.exe < proves/laberint.0.txt 100 i
# proves/laberint.0.txt = fichero de entrada con el laberinto
# 100 = cantidad de bateria inicial
# i = iterativo (para ejecutar el algoritmo de forma iterativa)
# en lugar de una "i" se puede poner una "r" para ejecutar el algoritmo de forma recursiva