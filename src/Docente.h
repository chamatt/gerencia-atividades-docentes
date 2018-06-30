#ifndef DOCENTE_H
#define DOCENTE_H
#include <string>

using namespace std;

namespace dominio
{
    
    class Docente
    {
        
        private:
             string nome;
             int codigo;
             string departamento;
             int totalHorasSemanaisAula = 0;
             int totalHorasSemestraisAula = 0;
             int totalHorasSemanaisOrientacao = 0;
             int numProdQualificadas = 0;
             int numProdNaoQualificadas = 0;

        public:
            Docente(int codigo, string nome, string departamento);
            
        
    };
}

#endif /* DOCENTE_H */

