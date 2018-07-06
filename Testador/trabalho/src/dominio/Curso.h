#ifndef CURSO_H
#define CURSO_H
#include <string>
#include <vector>

using namespace std;

namespace dominio
{
    class Docente;
    
    class Curso 
    {
        string nome;
        int codigo;
        bool graduacao;
        vector <Docente*> docentes;
        
        public:
            Curso(int codigo, string nome, bool graduacao);
            int getCodigo();
            string getNome();
            bool isGraduacao();
            vector <Docente*> getListaDocentes();
            void addListaDocentes(Docente* docente);
    };
}

#endif /* CURSO_H */

