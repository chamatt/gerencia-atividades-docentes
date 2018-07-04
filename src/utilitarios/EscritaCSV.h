#ifndef ESCRITACSV_H
#define ESCRITACSV_H
#include <fstream>
#include "Arquivos.h"
#include <map>
#include "../dominio/Docente.h"
#include <algorithm>
#include "Comparador.h"

using namespace std;
using namespace dominio;
using namespace utilitarios;
using namespace Comparador;

namespace utilitarios
{
    class EscritaCSV 
    {
        public:
            void escrevePAD(map< int, Docente*> &docentes);
            
    };
}

#endif /* ESCRITACSV_H */

