#ifndef DOCENTE_H
#define DOCENTE_H
#include <string>

#include "DidaticoAula.h"
#include "Graduacao.h"
#include "PosGraduacao.h"
#include "ProducaoCientifica.h"

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
            string getNome();
            string getDepartamento();
            int getCodigo();
            int getTotalHorasSemanaisAula();
            getTotalAulasSemestraisAula();
            getTotalAulasSemanaisOrientacao();
            getNumProducoesQualificadas();
            getNumProducoesNaoQualificadas();
            
            
            
            
        
    };
}

#endif /* DOCENTE_H */

