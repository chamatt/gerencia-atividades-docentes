#include <string>

using namespace std;

#ifndef ARQUIVOS_H
#define ARQUIVOS_H

namespace utilitarios {
    class Arquivos {

        string docentes;
        string discentes;
        string producaoCientifica;
        string cursos;
        string didaticoAulas;
        string orientacaoGraducao;
        string orientacaoPos;
        bool writeOnly = false;
        bool readOnly = false;

    public:

        Arquivos(int argc, char* argv[]);
        Arquivos(const Arquivos& orig);

        string getCursos() const;

        string getDidaticoAulas() const;

        string getDiscentes() const;

        string getDocentes() const;

        string getOrientacaoGraducao() const;

        string getOrientacaoPos() const;

        string getProducaoCientifica() const;

        bool isReadOnly() const;

        bool isWriteOnly() const;


        virtual ~Arquivos();
    private:

    };
}

#endif /* ARQUIVOS_H */

