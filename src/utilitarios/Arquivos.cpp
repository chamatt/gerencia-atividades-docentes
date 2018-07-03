#include "Arquivos.h"

using namespace std;

namespace utilitarios {
    
   /* Arquivos::Arquivos(const Arquivos& orig) {
    }*/

    Arquivos::~Arquivos() {
    }
    
    Arquivos::Arquivos(int argc, char* argv[]) {
            for (int i = 0; i < argc; i++) {
                    if (!strcmp(argv[i], "-d")) {
                            docentes = string(argv[i + 1]);
                    }
                    if (!strcmp(argv[i], "-a")) {
                            discentes = string(argv[i + 1]);
                    }
                    if (!strcmp(argv[i], "-p")) {
                            producaoCientifica = string(argv[i + 1]);
                    }
                    if (!strcmp(argv[i], "-c")) {
                            cursos = string(argv[i + 1]);
                    }
                    if (!strcmp(argv[i], "-r")) {
                            didaticoAulas = string(argv[i + 1]);
                    }
                    if (!strcmp(argv[i], "-og")) {
                            orientacaoGraducao = string(argv[i + 1]);
                    }
                    if (!strcmp(argv[i], "-op")) {
                            orientacaoPos = string(argv[i + 1]);
                    }
            }

    }




    string Arquivos::getDocentes() {
            return docentes;
    }

    string Arquivos::getDiscentes() {
            return discentes;
    }

    string Arquivos::getProducaoCientifica() {
            return producaoCientifica;
    }

    string Arquivos::getCursos() {
            return cursos;
    }

    string Arquivos::getDidaticoAulas() {
            return didaticoAulas;
    }

    string Arquivos::getOrientacaoGraducao() {
            return orientacaoGraducao;
    }

    string Arquivos::getOrientacaoPos() {
            return orientacaoPos;
    }
}

