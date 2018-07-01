#include "Atividade.h"


namespace dominio
{

    Docente* Atividade::getDocente(){
        return docente;
    }
    
    
    int Atividade::getCHSemanal() 
    {
        return CHSemanal;
    }
    
    void Atividade::setDocente(Docente* docente) {
        this->docente = docente;
    }
    

}
