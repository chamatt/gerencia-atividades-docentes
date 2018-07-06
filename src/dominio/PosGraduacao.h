#ifndef POSGRADUACAO_H
#define POSGRADUACAO_H

#include <string>
#include "Orientacao.h"


using namespace std;

namespace dominio
{
    class PosGraduacao: public Orientacao {

        string nomeDoPrograma;
        string dataDeIngresso;

        public:
            PosGraduacao(Docente* docente, Discente* Discente,
                    string dataDeIngresso,string nomeDoPrograma, int CHSemanal);
            string getNomeDoPrograma();
            string getDataDeIngresso();
            
    };
}

#endif /* POSGRADUACAO_H */

