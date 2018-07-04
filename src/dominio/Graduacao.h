#ifndef GRADUACAO_H
#define GRADUACAO_H
#include "Curso.h"
#include "Orientacao.h"

namespace dominio
{
    class Graduacao: public Orientacao {
        Curso* curso;
        int CHSemanal;
    
    public:
        Graduacao(Docente* docente, Discente* discente, Curso* curso, int CHSemanal);
        Curso* getCurso();
        void setCurso(Curso* curso);
        int getCHSemanal();
    };
    
}

#endif /* GRADUACAO_H */

