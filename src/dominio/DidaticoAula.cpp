#include "DidaticoAula.h"
#include "Atividade.h"


namespace dominio
{

    DidaticoAula::DidaticoAula(string codigo, string nome, int CHSemanal, int CHSemestral) 
    {
        this->codigo = codigo;
        this->nome = nome;
        this->CHSemanal = CHSemanal;
        this->CHSemestral = CHSemestral;
    }
    int DidaticoAula::getCHSemestral() {
        return CHSemestral;
    }

    string DidaticoAula::getCodigo() {
        return codigo;
    }

    Docente* DidaticoAula::getDocente() {
        return Docente;
    }

    string DidaticoAula::getNome() {
        return nome;
    }

    Curso* DidaticoAula::getCurso(){
        return curso;
    }
    





   
}



