#ifndef DISCENTE_H
#define DISCENTE_H
#include <string>
#include "Curso.h"

using namespace std;

namespace dominio
{
  class PosGraduacao;
  class Graduacao;
  
  class Discente   
    {  
        string nome;  
        long matricula;  
        Curso* curso;
        PosGraduacao* posGraduacao;
        Graduacao* graduacao;
          
        public:  
            Discente(long matricula, string nome);  
            long getMatricula();  
            string getNome();  
            Curso* getCurso();  
            PosGraduacao* getPosGraduacao();
            Graduacao* getGraduacao();
            void setPosGraduacao(PosGraduacao* posGraduacao);
            void setGraduacao(Graduacao* graduacao);
            
            
	/*void addListaProducao(ProducaoCientifica prod);

	void addListaGraduacao(Graduacao grad);

	void addListaPosGraduacao(PosGraduacao pg);

	void addListaDidaticoAula(DidaticoAula disc);*/


    };  
 
}

#endif /* DISCENTE_H */

