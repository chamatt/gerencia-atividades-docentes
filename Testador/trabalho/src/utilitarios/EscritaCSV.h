#ifndef ESCRITACSV_H
#define ESCRITACSV_H
#include <fstream>
#include "Arquivos.h"
#include <map>
#include "../dominio/Docente.h"
#include <algorithm>
#include "Comparador.h"
#include <string>
#include "../dominio/DidaticoAula.h"
#include "../dominio/Discente.h"
#include <vector>

using namespace std;
using namespace dominio;
using namespace utilitarios;
using namespace Comparador;

namespace utilitarios
{
    class EscritaCSV 
    {
        public:
            EscritaCSV();
            void escrevePAD(map< int, Docente*> &docentes);
            void escreveAlocacao(map <string,DidaticoAula*> &disc);
            void escreveDiscentesProGrad(map <long,Discente*> &discentes);
            void escreveRHA(map<int, Curso*>& cursos);
    };
}

#endif /* ESCRITACSV_H */

