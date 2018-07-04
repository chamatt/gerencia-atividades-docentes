#include "Discente.h"
#include "Curso.h"

namespace dominio
{
    Discente :: Discente(long matricula, string nome)
    {
        this->matricula = matricula;
	this->nome = nome;
    }
    
    long Discente::getMatricula() 
    {
        return matricula;
    }
    
    string Discente::getNome() 
    {
        return nome;
    }
    
    Curso* Discente::getCurso() {
        return curso;
    }


    PosGraduacao* Discente::getPosGraduacao(){
        return posGraduacao;
    }
    
    void Discente::setPosGraduacao(PosGraduacao* posGraduacao){
        this->posGraduacao = posGraduacao;
    }
    
    Graduacao* Discente::getGraduacao(){
        return graduacao;
    }
    void Discente::setGraduacao(Graduacao* graduacao){
        this->graduacao = graduacao;
    }
    
    
}

