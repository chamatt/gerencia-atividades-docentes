#include "Orientacao.h"
#include "Discente.h"

namespace dominio {
    Discente* Orientacao::getDiscente(){
        return discente;
    }
    void Orientacao::setDiscente(Discente* discente){
        this->discente = discente;
    }
   
}


