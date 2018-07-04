#include "Graduacao.h"
#include "Atividade.h"


namespace dominio
{

    Graduacao::Graduacao(Docente* docente, Discente* discente, Curso* curso, int CHSemanal){
        this->docente = docente;
        this->discente = discente;
        this->curso = curso;
        this->CHSemanal = CHSemanal;
        
    }
    
    Curso* Graduacao::getCurso(){
        return curso;
    }
    
    void Graduacao::setCurso(Curso* curso){
        this->curso = curso;
    }
    int Graduacao::getCHSemanal(){
        return CHSemanal;
    }

}
