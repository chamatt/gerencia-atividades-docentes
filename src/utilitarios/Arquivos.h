#include <string>

using namespace std;

#ifndef ARQUIVOS_H
#define ARQUIVOS_H

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
    
    string GetCursos() const;

    string GetDidaticoAulas() const;

    string GetDiscentes() const;

    string GetDocentes() const;

    string GetOrientacaoGraducao() const;

    string GetOrientacaoPos() const;

    string GetProducaoCientifica() const;

    bool IsReadOnly() const;

    bool IsWriteOnly() const;

    
    virtual ~Arquivos();
private:

};

#endif /* ARQUIVOS_H */

