#include "Curso.h"


namespace dominio
{
    Curso::Curso(int codigo, string nome, bool graduacao) 
    {
           this->nome = nome;
	   this->codigo = codigo;
	   this->graduacao = graduacao;
    }
    
    int Curso::getCodigo() 
    {
        return codigo;
    }
    
    string Curso::getNome() 
    {
        return nome;
    }
    
    bool Curso::isGraduacao() 
    {
        return graduacao;
    }
    vector<Docente*> Curso::getListaDocentes() 
    {
        return docentes;
    }
    void Curso::addListaDocentes(Docente* docente) {
        if(docentes.find() == docentes.end())
            docentes.push_back(docente);
    }




}
