#ifndef ORIENTACAO_H
#define ORIENTACAO_H
#include "Discente.h"
#include "Atividade.h"

namespace dominio
{
    class Orientacao: public Atividade {
        
    protected:
        Discente* discente;
     
    public:
        Discente* getDiscente();
        void setDiscente(Discente* discente);

    };
}

#endif /* ORIENTACAO_H */

