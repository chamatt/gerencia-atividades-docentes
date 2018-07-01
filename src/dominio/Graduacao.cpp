#include "Graduacao.h"
#include "Atividade.h"


namespace dominio
{

    Graduacao::Graduacao(int CHSemanal) {
        this->CHSemanal = CHSemanal;
    }
    
    Curso* Graduacao::getCurso(){
        return curso;
    }
    

}
