#include "Comparador.h"


namespace utilitarios {
    
        int Comparador::timeCompare(string date1, string date2){
            time_t d1 =  parseDate(date1, DATE_FORMAT_PT_BR_SHORT);
            time_t d2 =  parseDate(date2, DATE_FORMAT_PT_BR_SHORT);
            return d1 - d2;
        }

        bool Comparador::PAD(Docente* d1, Docente* d2)
        {
            int value = stringCompare(d1->getNome(), d2->getNome());
            return value < 0;
        }   

        bool Comparador::PPG(Discente* d1, Discente* d2) {
            
            int value = stringCompare(d1->getPosGraduacao()->getNomeDoPrograma(), d2->getPosGraduacao()->getNomeDoPrograma());
            
            if (value == 0) 
            {
                int value2 = timeCompare(d1->getPosGraduacao()->getDataDeIngresso(), d2->getPosGraduacao()->getDataDeIngresso());
                
                 if (value2 == 0) 
                 {
                           int value3 = stringCompare(d1->getNome(), d2->getNome());
                           return value3 < 0;
                 }

                return value2 < 0;
            }

            return value < 0;
        }
        bool Comparador::Alocacao(DidaticoAula* d1, DidaticoAula* d2) {
            
            int value = stringCompare(d1->getDocente()->getNome(), d2->getDocente()->getNome());
            
            if (value == 0)
            {
                int value2 = stringCompare(d1->getCodigo(), d2->getCodigo());
                return value2 < 0;
            }
         
            return value < 0;
        }

        bool RHA(vector<string> s1, vector<string> s2){
            int value = stringCompare(s1[0],s2[0]);

            if(value == 0)
            {
                int value2 = stringCompare(s1[1],s2[1]);

                if(value2 == 0)
                {
                    int value3 = stringCompare(s1[3],s2[3]);
                    return value3 < 0;
                }

                return value2 < 0;
            }

            return value < 0;
        }
}

