#ifndef PRODUCAOCIENTIFICA_H
#define PRODUCAOCIENTIFICA_H
#include <string>

using namespace std;

namespace dominio
{
    class ProducaoCientifica 
    {
        string titulo;
        bool qualificada;
       
        public:
            ProducaoCientifica(string titulo, bool qualificada);
            string getTitulo();
            bool isQualificada();
    };
}

#endif /* PRODUCAOCIENTIFICA_H */

