#include "Disciplina.hpp"
#include "Pessoa.hpp"
#include <iostream>


// construtor modificado
Disciplina::Disciplina(std::string nome, Pessoa& professor)
	:nome{nome}, professor{professor}, qtd_alunos{0}{
}


std::string Disciplina::getNome(){
	return this->nome;
}


void Disciplina::setNome(std::string nome){
	this->nome = nome;
}


int Disciplina::getCargaHoraria(){
	return this->cargaHoraria;
}


void Disciplina::setCargaHoraria(unsigned int cargaHoraria){
	this->cargaHoraria = cargaHoraria;
}


Pessoa& Disciplina::getProfessor()
{
	return this->professor;
}


void Disciplina::setProfessor(Pessoa& professor)
{
	this->professor = professor;
}

// -------- novas implementacoes ------------	

std::string Disciplina::getNomeProfessor()
{
	return this->getProfessor().getNome();
}
	

int Disciplina::getQtdAlunos()
{
	return this-> qtd_alunos;
}


bool Disciplina::adicionarAluno(Pessoa* aluno)
{
	try
	{
		this->alunos.push_back(aluno);
		this->qtd_alunos+=1;

		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}


std::list<Pessoa*> Disciplina::getAlunos()
{
	return this->alunos;
}


void Disciplina::printVetorAlunos(){
	try{
		std::list<Pessoa*>::iterator it{this->alunos.begin()};
		for ( ; it != this->alunos.end(); it++)
		{
			std::cout << "\t\t- Aluno: " << (*it)->getNome() << std::endl;
		}
	}catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}


bool Disciplina::removerAluno(Pessoa* aluno)
{
	try
	{
		std::list<Pessoa*>::iterator it{this->alunos.begin()};

		while(it != this->alunos.end())
		{
			if (((*it)->getNome() == aluno->getNome()) && ((*it)->getCpf() == aluno->getCpf()))
			{
				delete *it;
				it = alunos.erase(it);
				std::cout << "\nAluno removido com sucesso" << std::endl;
				this->qtd_alunos-=1;
				return true;
			}else{
				it++;
			}
		}
		return false;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n' << std::endl;
		return false;
	}
}



bool Disciplina::removerAluno(long long cpf)
{
	try
	{
		std::list<Pessoa*>::iterator it{this->alunos.begin()};

		while (it != this->alunos.end())
		{
			if ((*it)->getCpf() == cpf)
			{
				delete *it;
				this->alunos.erase(it);
				std::cout << "\nAluno removido com sucesso" << std::endl;
				this->qtd_alunos-=1;
				return true;
			}else{
				it++;
			}
		}
		return false;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n' << std::endl;
		return false;
	}
}



// ------------------------------------------	
