#include "Curso.hpp"
#include "Pessoa.hpp"
#include "Disciplina.hpp"

#include<list>
#include <iostream>

Curso::Curso(std::string nomeCurso, int anoCriacaoCurso, Pessoa& coordenadorCurso)
    :nomeCurso{nomeCurso}, anoCriacaoCurso{anoCriacaoCurso}, coordenadorCurso{coordenadorCurso}
{

}  
        
std::string Curso::getNomeCurso()
{
    return this->nomeCurso;
}


Pessoa& Curso::getCoordenadorCurso()
{
    return this->coordenadorCurso;
}


void Curso::adicionarDisciplina(Disciplina* disciplina)
{
    try
    {
        this->disciplinas.push_back(disciplina);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << '\n' << std::endl;
    }
}


bool Curso::removerDisciplina(Disciplina* disciplina)
{
    try
    {
        std::list<Disciplina*>::iterator it{this->disciplinas.begin()};

        while (it != this->disciplinas.end())
        {
            if((*it) == disciplina)
            {
                delete *it;
                it = this->disciplinas.erase(it);
                std::cout << "\nDisciplina removida com sucesso!" << std::endl;
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


bool Curso::removerDisciplina(std::string nome)
{
    try
    {
        std::list<Disciplina*>::iterator it{this->disciplinas.begin()};

        while (it != this->disciplinas.end())
        {
            if ((*it)->getNome() == nome)
            {
                delete *it;
                it = this->disciplinas.erase(it);
                std::cout << "\nDisciplina removida com sucesso!" << std::endl;
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


std::list<Disciplina*> Curso::getListaDisciplina(){
    return this->disciplinas;
}


void Curso::printListaDisciplina()
{
    try
    {
        std::list<Disciplina*>::iterator it{this->disciplinas.begin()};
        std::cout << "\nImprimindo disciplinas:" << std::endl;
        while(it != this->disciplinas.end())
        {
            std::cout << "\tDisciplina: " << (*it)->getNome() << std::endl;    
            std::cout << "\tAlunos: " << std::endl;
            (*it)->printVetorAlunos();
            it++;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << '\n' << std::endl;
       
    }
}
