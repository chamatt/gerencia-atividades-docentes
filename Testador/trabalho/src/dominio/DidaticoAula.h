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
            
            DidaticoAula(string codigo, string nome, Docente* docente, int CHSemanal, int CHSemestral,
                                    Curso* curso);
            string getCodigo();
            string getNome();
            int getCHSemestral();
            Curso* getCurso();
            
    };  
}

#endif /* DIDATICOAULA_H */

