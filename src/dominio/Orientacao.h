#ifndef ORIENTACAO_H
#define ORIENTACAO_H
#include "Discente.h"

namespace dominio
{
    class Orientacao: public Atividade {
        
        Discente* discente;
     
    public:
        virtual Discente* getDiscente() = 0;

    };
}

#endif /* ORIENTACAO_H */

