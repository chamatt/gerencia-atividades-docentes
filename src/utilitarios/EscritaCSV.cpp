#include "EscritaCSV.h"

namespace utilitario
{

    void EscritaCSV::escrevePAD(map<int, Docente*> &docentes) 
    {
        ofstream out ("1-pad.csv");
        out.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        
        out << "Docente;Departamento;Horas Semanais Aula;Horas Semestrais Aula;Horas Semanais Orientação;Produções Qualificadas;Produções Não Qualificadas" << endl;
       
        map<int, Docente*> :: iterator it;
        vector <Docente*> vet;
        
        for(it = docentes.begin();it != docentes.end();it++)
            vet.push_back(it->second);
        
        sort(vet.begin(),vet.end(),PAD);
        
        for(int i=0;i<vet.size();i++)
        {
            out << vet[i]->getNome() << ";";
            out << vet[i]->getDepartamento() << ";";
            out << vet[i]->getTotalHorasSemanaisAula()<< ";";
            out << vet[i]->getTotalAulasSemestraisAula() << ";";
            out << vet[i]->getTotalAulasSemanaisOrientacao() << ";";
            out << vet[i]->getNumProducoesQualificadas() << ";";
            out << vet[i]->getNumProducoesNaoQualificadas() << endl;
        }
        
        out.close();
    }

    
    
}