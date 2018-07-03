#ifndef ORIENTACAO_H
#define ORIENTACAO_H
#include "Discente.h"
#include "Atividade.h"

namespace dominio
{
    class Orientacao: public Atividade {
        
        Discente* discente;
     
    public:
        Discente* getDiscente();

    };
}

#endif /* ORIENTACAO_H */

