#ifndef CURSO_H
#define CURSO_H
#include <string>
#include <vector>
#include "Docente.h"

using namespace std;

namespace dominio
{
    class Curso 
    {
        string nome;
        int codigo;
        bool graduacao;
        vector <Docente> docentes;
        
        public:
            Curso(int codigo, string nome, bool graduacao);
            int getCodigo();
            string getNome();
            bool isGraduacao();
            vector <Docente> getListaDocentes();
            
            /*public void addListaDocentes(Docente docente) {
		if (!docentes.contains(docente))
			docentes.add(docente);
	}
            */
    };
}

#endif /* CURSO_H */

