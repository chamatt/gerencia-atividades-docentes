#ifndef PRODUCAOCIENTIFICA_H
#define PRODUCAOCIENTIFICA_H
#include <string>

using namespace std;

namespace dominio
{
    class Docente;
    
    class ProducaoCientifica 
    {
        string titulo;
        bool qualificada;
        Docente* docente;
       
        public:
            ProducaoCientifica(string titulo, bool qualificada);
            string getTitulo();
            bool isQualificada();
            Docente* getDocente();
    };
}

#endif /* PRODUCAOCIENTIFICA_H */

