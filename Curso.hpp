#ifndef CURSO_HPP
#define CURSO_HPP

#include<list>

#include "Pessoa.hpp"
#include "Disciplina.hpp"

class Curso
{
    public:
        Curso(std::string nomeCurso, int anoCriacaoCurso, Pessoa& coordenadorCurso);
        std::string getNomeCurso();
        Pessoa& getCoordenadorCurso();

        void adicionarDisciplina(Disciplina* disciplina);
        bool removerDisciplina(Disciplina* disciplina);
        bool removerDisciplina(std::string nome);
        std::list<Disciplina*> getListaDisciplina();
        void printListaDisciplina();


    private:
        std::string nomeCurso;
        int anoCriacaoCurso;
        Pessoa coordenadorCurso;
        std::list<Disciplina*> disciplinas;

};

#endif
