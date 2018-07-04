#include "Docente.h"

namespace dominio
{
    Docente::Docente(int codigo, string nome, string departamento) 
    {
        this->codigo = codigo;
        this->nome = nome;
        this->departamento = departamento;
    }
    
    int Docente::getCodigo()
    {
        return codigo;
    }
    
    string Docente::getNome()
    {
        return nome;
    }
    
     string Docente::getDepartamento() 
     {
         return departamento;
     }
     
     int Docente::getNumProducoesNaoQualificadas()
     {
         return numProdNaoQualificadas;
     }
     
     int Docente::getNumProducoesQualificadas()
     {
         return numProdQualificadas;
     }
     
     int Docente::getTotalAulasSemanaisOrientacao() 
     {
         return totalHorasSemanaisOrientacao;
     }
     
    
     int Docente::getTotalAulasSemestraisAula() 
     {
         return totalHorasSemestraisAula;
     }
     
    int Docente::getTotalHorasSemanaisAula() 
    {
        return totalHorasSemanaisAula;
    }

    
        void Docente::addListaProducao(ProducaoCientifica* prod) {
		producoes.push_back(prod);
	}

	void Docente::addListaGraduacao(Graduacao* grad) {
		graduacoes.push_back(grad);
	}

	void Docente::addListaPosGraduacao(PosGraduacao* pg) {
		posGraduacoes.push_back(pg);
	}

	void Docente::addListaDidaticoAula(DidaticoAula* disc) {
		disciplinas.push_back(disc);
	}

	vector<DidaticoAula*> Docente::getDisciplinas() {
		return disciplinas;
	}

	vector<Graduacao*> Docente::getGraduacoes() {
		return graduacoes;
	}

	vector<PosGraduacao*> Docente::getPosGraduacoes() {
		return posGraduacoes;
	}

	vector<ProducaoCientifica*> Docente::getProducoes() {
		return producoes;
	}


     

    
}
