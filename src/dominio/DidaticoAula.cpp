#include "DidaticoAula.h"
#include "Atividade.h"


namespace dominio
{

    DidaticoAula::DidaticoAula(string codigo, string nome, Docente* docente, int CHSemanal, int CHSemestral, Curso* curso)
    {
        this->codigo = codigo;
        this->nome = nome;
        this->CHSemanal = CHSemanal;
        this->CHSemestral = CHSemestral;
        this->docente = docente;
        this->curso = curso;
    }
    int DidaticoAula::getCHSemestral() {
        return CHSemestral;
    }

    string DidaticoAula::getCodigo() {
        return codigo;
    }

    string DidaticoAula::getNome() {
        return nome;
    }

    Curso* DidaticoAula::getCurso(){
        return curso;
    }
    





   
}



