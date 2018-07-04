#include "EscritaCSV.h"

namespace utilitario
{

    void EscritaCSV::escrevePAD(map<int, Docente*> &docentes) 
    {
        ofstream out ("1-pad.csv");
        out.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        if(out.is_open())
        {
            out << "Docente;Departamento;Horas Semanais Aula;Horas Semestrais Aula;Horas Semanais Orientação;Produções Qualificadas;Produções Não Qualificadas" << endl;

            map<int, Docente*> :: iterator it;
            vector <Docente*> vet;

            for(it = docentes.begin();it != docentes.end();it++)
                vet.push_back(it->second);

            sort(vet.begin(),vet.end(),PAD);

            int tam = (int)vet.size();
            
            for(int i=0;i<tam;i++)
            {
                out << vet[i]->getNome() << ";";
                out << vet[i]->getDepartamento() << ";";
                out << vet[i]->getTotalHorasSemanaisAula()<< ";";
                out << vet[i]->getTotalAulasSemestraisAula() << ";";
                out << vet[i]->getTotalAulasSemanaisOrientacao() << ";";
                out << vet[i]->getNumProducoesQualificadas() << ";";
                out << vet[i]->getNumProducoesNaoQualificadas() << endl;
            }
        }
        
        out.close();
    } 
        void EscritaCSV::escreveAlocacao(map<string, DidaticoAula*>& disc) 
        {
                ofstream out ("3-alocacao.csv");
                out.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                
                if(out.is_open())
                {
                    out << "Docente;Código;Nome;Carga Horária Semestral" << endl;
                    
                    vector <DidaticoAula*> vet;
                    map <string,DidaticoAula*> :: iterator it;
                    
                    for(it = disc.begin();it != disc.end();it++)
                            vet.push_back(it->second);
                    
                    sort(vet.begin(),vet.end(),Alocacao);
                    
                    int tam = (int)vet.size();
            
                    for(int i=0;i<tam;i++)
                    {
                        out << vet[i]->getDocente()->getNome() << ";";
                        out << vet[i]->getCodigo() << ";";
                        out << vet[i]->getNome() << ";";
                        out << vet[i]->getCHSemestral() << endl;
                    }
                }
        }
            void EscritaCSV::escreveDiscentesProGrad(map<long, Discente*> &discentes) 
            {
                 ofstream out ("4-ppg.csv");
                 out.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                
                 if(out.is_open())
                 {
                     out << "Nome do Programa;Data de Ingresso;Matrícula;Nome" << endl;
                     
                     map<long,Discente*> :: iterator it;
                     vector <Discente*> discentePPG;
                     
                     for(it = discentes.begin();it != discentes.end();it++)
                            if(it->second->getPosGraduacao() != NULL) discentePPG.push_back(it->second);
                     
                     
                     sort(discentePPG.begin(),discentePPG.end(),PPG);
                     
                      int tam = (int)discentePPG.size();
            
                    for(int i=0;i<tam;i++)
                    {
                        out << discentePPG[i]->getPosGraduacao()->getNomeDoPrograma() << ";";
                        out << discentePPG[i]->getPosGraduacao()->getDataDeIngresso() << ";";
                        out << discentePPG[i]->getMatricula() << ";";
                        out << discentePPG[i]->getNome() << endl;
                    }
                 }
            }


    
    
    
    

    
    
}