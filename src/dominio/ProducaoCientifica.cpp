#include "ProducaoCientifica.h"
#include <string>

using namespace std;

namespace dominio
{
    
    ProducaoCientifica::ProducaoCientifica(Docente* docente,string titulo, bool qualificada) 
    {
        this->docente = docente;
        this->titulo = titulo;
        this->qualificada = qualificada;
    }
    string ProducaoCientifica::getTitulo() 
    {
        return titulo;
    }

    bool ProducaoCientifica::isQualificada() 
    {
        return qualificada;
    }

    Docente* ProducaoCientifica::getDocente(){
        return docente;
    }


}


