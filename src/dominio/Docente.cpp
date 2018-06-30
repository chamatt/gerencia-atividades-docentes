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



     

    
}
