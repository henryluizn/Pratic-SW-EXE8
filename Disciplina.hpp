#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP

#include <string>
#include <list>

#include "Pessoa.hpp"

class Disciplina{
	public:
	//construtor da classe
		Disciplina(std::string nome, Pessoa& professor);
		
		std::string getNome();
		void setNome(std::string nome);
		
		int getCargaHoraria();
		void setCargaHoraria(unsigned int cargaHoraria);

		Pessoa& getProfessor();
		void setProfessor(Pessoa& professor);
		
	// -------- novas implementacoes ------------
		std::string getNomeProfessor();
		bool adicionarAluno(Pessoa* aluno);
		bool removerAluno(Pessoa* aluno);
		bool removerAluno(long long cpf);
		int getQtdAlunos();
		std::list<Pessoa*> getAlunos();
		void printVetorAlunos();

	// ------------------------------------------	
	private:
		std::string nome;
		unsigned short int cargaHoraria;
	// -------- novas implementacoes ------------
		std::list<Pessoa*> alunos;
		
		Pessoa professor;
		int qtd_alunos;
	// ------------------------------------------	
};
#endif
