#ifndef DIDATICOAULA_H
#define DIDATICOAULA_H
#include "Docente.h"
#include <string>

using namespace std;

namespace dominio
{
    class DidaticoAula : public Atividade
    {
        string codigo;
        string nome;
        int CHSemestral;
        dominio::Docente docente;
        
        public: 
            DidaticoAula(string codigo, string nome, int CHSemanal, int CHSemestral);
            string getCodigo();
            string getNome();
            int getCHSemestral();
            dominio::Docente getDocente();
            void setDocente(Docente docente);
    };  
}

#endif /* DIDATICOAULA_H */

