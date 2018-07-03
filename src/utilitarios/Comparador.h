#include "../professor/StringUtils.h"
#include "../professor/DateUtils.h"
#include "../professor/NumberUtils.h"
#include "../professor/Tokenizer.h"
#include "../dominio/Discente.h"
#include "../dominio/Docente.h"
#include "../dominio/DidaticoAula.h"


#ifndef COMPARADOR_H
#define COMPARADOR_H
namespace utilitarios{
    
    class Comparador {
        public:
            Comparador();
            Comparador(const Comparador& orig);
            int timeCompare(string date1, string date2);
            int PAD(Docente d1, Docente d2);
            int PPG(Discente d1, Discente d2);
            int Alocacao(DidaticoAula d1, DidaticoAula d2);
            
            virtual ~Comparador();

    };
}
#endif /* COMPARADOR_H */

