#ifndef POSGRADUACAO_H
#define POSGRADUACAO_H

#include <string>


using namespace std;

namespace dominio
{
    class PosGraduacao: public Orientacao {

        string nomeDoPrograma;
        string dataDeIngresso;

        public:
            PosGraduacao(int CHSemanal,string dataDeIngresso,string nomeDoPrograma);
            string getNomeDoPrograma();
            string getDataDeIngresso();
    };
}

#endif /* POSGRADUACAO_H */

