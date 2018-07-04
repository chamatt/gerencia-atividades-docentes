#ifndef DOCENTE_H
#define DOCENTE_H
#include <string>

#include "DidaticoAula.h"
#include "Graduacao.h"
#include "PosGraduacao.h"
#include "Curso.h"
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
             vector<DidaticoAula*> disciplinas;
             vector<Graduacao*> graduacoes;
             vector<PosGraduacao*> posGraduacoes;
             vector<ProducaoCientifica*> producoes;
             
             
        public:
            Docente(int codigo, string nome, string departamento);
            string getNome();
            string getDepartamento();
            int getCodigo();
            int getTotalHorasSemanaisAula();
            int getTotalAulasSemestraisAula();
            int getTotalAulasSemanaisOrientacao();
            int getNumProducoesQualificadas();
            int getNumProducoesNaoQualificadas();
            
            
            void addListaProducao(ProducaoCientifica* prod);

            void addListaGraduacao(Graduacao* grad);

            void addListaPosGraduacao(PosGraduacao* pg);

            void addListaDidaticoAula(DidaticoAula* disc);

            vector<DidaticoAula*> getDisciplinas();

            vector<Graduacao*> getGraduacoes();

            vector<PosGraduacao*> getPosGraduacoes();

            vector<ProducaoCientifica*> getProducoes();

            
        
    };
}

#endif /* DOCENTE_H */

