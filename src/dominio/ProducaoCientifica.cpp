#include "ProducaoCientifica.h"
#include <string>

using namespace std;

namespace dominio
{
    
    ProducaoCientifica::ProducaoCientifica(string titulo, bool qualificada) 
    {
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


