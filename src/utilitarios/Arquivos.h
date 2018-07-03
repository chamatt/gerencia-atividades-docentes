#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <string>
#include <cstring>

using namespace std;


namespace utilitarios {
    class Arquivos {

        string docentes;
        string discentes;
        string producaoCientifica;
        string cursos;
        string didaticoAulas;
        string orientacaoGraducao;
        string orientacaoPos;
       
    public:

        Arquivos(int argc, char* argv[]);
       // Arquivos(const Arquivos& orig);

        string getCursos();

        string getDidaticoAulas();

        string getDiscentes();

        string getDocentes();

        string getOrientacaoGraducao();

        string getOrientacaoPos();

        string getProducaoCientifica();
        
        ~Arquivos();
    private:

    };
}

#endif /* ARQUIVOS_H */

