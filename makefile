parametrosCompilacao=-Wall #-Wshadow
nomePrograma=exe8

all: $(nomePrograma)

$(nomePrograma): main.o Pessoa.o Curso.o Disciplina.o 
	g++ -o $(nomePrograma) main.o Pessoa.o Curso.o Disciplina.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Pessoa.o: Pessoa.hpp Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

Curso.o: Curso.hpp Curso.cpp
	g++ -c Curso.cpp $(parametrosCompilacao)

Disciplina.o: Disciplina.hpp Disciplina.cpp
	g++ -c Disciplina.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
