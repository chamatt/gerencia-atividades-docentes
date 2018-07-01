#ifndef DISCENTE_H
#define DISCENTE_H
#include <string>

using namespace std;

namespace dominio
{
  class Discente   
    {  
        string nome;  
        long matricula;  
        int codigoDoCurso;  
          
        public:  
            Discente(long matricula, string nome, int codigoDoCurso);  
            long getMatricula();  
            string getNome();  
    };  
 
}

#endif /* DISCENTE_H */

