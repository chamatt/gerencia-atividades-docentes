#ifndef DIDATICOAULA_H
#define DIDATICOAULA_H
#include "Atividade.h"
#include "Curso.h"
#include <string>

using namespace std;

namespace dominio
{
    class DidaticoAula : public Atividade
    {
        string codigo;
        string nome;
        Curso* curso;
        int CHSemestral;
        
        public: 
            DidaticoAula(string codigo, string nome, int CHSemanal, int CHSemestral);
            string getCodigo();
            string getNome();
            int getCHSemestral();
            Curso* getCurso();
            
    };  
}

#endif /* DIDATICOAULA_H */

