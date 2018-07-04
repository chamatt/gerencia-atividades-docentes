#include "../professor/StringUtils.h"
#include "../professor/DateUtils.h"
#include "../professor/NumberUtils.h"
#include "../professor/Tokenizer.h"
#include "../dominio/Discente.h"
#include "../dominio/Docente.h"
#include "../dominio/DidaticoAula.h"

using namespace dominio;
using namespace cpp_util;


#ifndef COMPARADOR_H
#define COMPARADOR_H
namespace utilitarios{
    namespace Comparador {
        
            int timeCompare(string date1, string date2);
            bool PAD(Docente* d1, Docente* d2);
            bool PPG(Discente* d1, Discente* d2);
            bool Alocacao(DidaticoAula* d1, DidaticoAula* d2);
            bool RHA(vector<string> s1, vector<string> d2);
    }
}
#endif /* COMPARADOR_H */

