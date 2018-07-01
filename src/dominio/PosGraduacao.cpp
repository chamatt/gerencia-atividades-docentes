#include "PosGraduacao.h"
#include "Atividade.h"

namespace dominio
{

    PosGraduacao::PosGraduacao(int CHSemanal, string dataDeIngresso, string nomeDoPrograma) {
        this->dataDeIngresso=dataDeIngresso;
        this->nomeDoPrograma=nomeDoPrograma;
        this->CHSemanal=CHSemanal;
    }

    string PosGraduacao::getDataDeIngresso() {
        return dataDeIngresso;
    }

    string PosGraduacao::getNomeDoPrograma() {
        return nomeDoPrograma;
    }


   
}
