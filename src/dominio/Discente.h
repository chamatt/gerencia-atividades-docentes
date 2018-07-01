#ifndef DISCENTE_H
#define DISCENTE_H
#include <string>
#include "Curso.h"

using namespace std;

namespace dominio
{
  class PosGraduacao;
  
  class Discente   
    {  
        string nome;  
        long matricula;  
        Curso* curso;
        PosGraduacao* posGraduacao;
          
        public:  
            Discente(long matricula, string nome, int codigoDoCurso);  
            long getMatricula();  
            string getNome();  
            Curso* getCurso();  
            
	void addListaProducao(ProducaoCientifica prod);

	void addListaGraduacao(Graduacao grad);

	void addListaPosGraduacao(PosGraduacao pg);

	void addListaDidaticoAula(DidaticoAula disc);


    };  
 
}

#endif /* DISCENTE_H */

