#include "EscritaCSV.h"
#include "../excecoes/execoes.h"
#include <iostream>
using namespace excecoes;

namespace utilitarios
{

    EscritaCSV::EscritaCSV() {

    }

    void EscritaCSV::escrevePAD(map<int, Docente*> &docentes) 
    {
        ofstream out ("1-pad.csv");
        if(out.is_open())
        {
            out << "Docente;Departamento;Horas Semanais Aula;Horas Semestrais Aula;Horas Semanais Orientação;Produções Qualificadas;Produções Não Qualificadas" << endl;

            map<int, Docente*> :: iterator it;
            vector <Docente*> vet;

            for(it = docentes.begin();it != docentes.end();it++)
            {
                it->second->calcularTotalHoras();
                it->second->calcularProducoesQualificadas();
                vet.push_back(it->second);
            }

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
            out.close();
        }
        else {
            throw IOException();
        }
        
        
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
                    out.close();
                }
                else {
                    throw IOException();
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
                    out.close();
                 }
                 else {
                    throw IOException();
                }
                  
            }


    
    void EscritaCSV::escreveRHA(map<int, Curso*>& cursos)  {
		
                ofstream out ("2-rha.csv");
                if(out.is_open())
                {
                    out << "Departamento;Docente;Cód. Curso;Curso;Horas Semestrais Aula" << endl;
                    vector< vector<string> > itensRelatorio;
					vector<string> temp;
                    for(auto &curso : cursos){
                        vector<Docente*> listaDocentes = curso.second->getListaDocentes();
                        for(auto &docente : listaDocentes){
                            string nomeDoDepartamento = "";
                            string nomeDoDocente = "";
                            int totalHoras = 0;
                            string codigoDoCurso = to_string(curso.second->getCodigo());
                            string nomeDoCurso = curso.second->getNome();
                            for(auto &aula : docente->getDisciplinas()){
                                if(aula->getCurso()->getCodigo() == curso.second->getCodigo()){
                                    totalHoras += aula->getCHSemestral();
                                    nomeDoDepartamento = aula->getDocente()->getDepartamento();
                                    nomeDoDocente = aula->getDocente()->getNome();
                                    
                                    temp.clear();
                                    temp.push_back(nomeDoDepartamento);
                                    temp.push_back(nomeDoDocente);
                                    temp.push_back(codigoDoCurso);
                                    temp.push_back(nomeDoCurso);
                                    temp.push_back(to_string(totalHoras));
									
                                    itensRelatorio.push_back(temp);
                                }
                            }
                            
                        }
                    }
                    sort(itensRelatorio.begin(), itensRelatorio.end(),RHA);
                    
                    int tam = (int)itensRelatorio.size();
            
                    for(int i=0;i<tam;i++)
                    {
                        out << itensRelatorio[i][0] << ";";
                        out << itensRelatorio[i][1] << ";";
                        out << itensRelatorio[i][2] << ";";
                        out << itensRelatorio[i][3] << ";";
                        out << itensRelatorio[i][4] << endl;
                    }
                    out.close();
                    
                    
                }
                else {
                    throw IOException();
                }
                
		
	}
    
    

    
    
}
