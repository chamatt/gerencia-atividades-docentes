#include "PosGraduacao.h"
#include "Atividade.h"

namespace dominio
{

    PosGraduacao::PosGraduacao(Docente* docente, Discente* discente, string dataDeIngresso, string nomeDoPrograma, int CHSemanal) {
        this->dataDeIngresso=dataDeIngresso;
        this->nomeDoPrograma=nomeDoPrograma;
        this->CHSemanal=CHSemanal;
        this->docente = docente;
        this->discente = discente;
    }

    string PosGraduacao::getDataDeIngresso() {
        return dataDeIngresso;
    }

    string PosGraduacao::getNomeDoPrograma() {
        return nomeDoPrograma;
    }
    
    
    

   
}
