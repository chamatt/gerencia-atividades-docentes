#ifndef GRADUACAO_H
#define GRADUACAO_H
#include "Curso.h"
#include "Orientacao.h"

namespace dominio
{
    class Graduacao: public Orientacao {
        Curso* curso;
    
    public:
        Graduacao(int CHSemanal);
        Curso* getCurso();
    };
    
}

#endif /* GRADUACAO_H */

