#include "Discente.h"

namespace dominio
{
    Discente :: Discente(long matricula, string nome, int codigoDoCurso)
    {
        this->matricula = matricula;
	this->nome = nome;
	this->codigoDoCurso = codigoDoCurso;
    }
    
    long Discente::getMatricula() 
    {
        return matricula;
    }
    
    string Discente::getNome() 
    {
        return nome;
    }


    
    
    
}

