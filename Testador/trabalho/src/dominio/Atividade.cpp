#include "Atividade.h"


namespace dominio
{
    int Atividade::getCHSemanal() 
    {
        return CHSemanal;
    }
    
    Docente* Atividade::getDocente(){
        return docente;
    }
    void Atividade::setDocente(Docente* docente){
        this->docente = docente;
    }
}
