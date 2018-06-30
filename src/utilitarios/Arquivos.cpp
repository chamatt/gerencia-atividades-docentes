/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * string:   Arquivos.cpp
 * Author: mathe
 * 
 * Created on 30 de Junho de 2018, 19:07
 */
#include <string>
#include "Arquivos.h"
using namespace std;


namespace utilitarios {
    Arquivos::Arquivos(const Arquivos& orig) {
    }

    Arquivos::~Arquivos() {
    }
    
    Arquivos::Arquivos(int argc, char* argv[]) {
            for (int i = 0; i < argv.length; i++) {
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
                    if (!strcmp(argv[i], "--read-only")) {
                            readOnly = true;
                    }
                    if (!strcmp(argv[i], "--write-only")) {
                            writeOnly = true;
                    }
            }

    }




    string Arquivos::GetDocentes() {
            return docentes;
    }

    string Arquivos::GetDiscentes() {
            return discentes;
    }

    string Arquivos::GetProducaoCientifica() {
            return producaoCientifica;
    }

    string Arquivos::GetCursos() {
            return cursos;
    }

    string Arquivos::GetDidaticoAulas() {
            return didaticoAulas;
    }

    string Arquivos::GetOrientacaoGraducao() {
            return orientacaoGraducao;
    }

    string Arquivos::GetOrientacaoPos() {
            return orientacaoPos;
    }

    bool Arquivos::IsWriteOnly() {
            return writeOnly;
    }

    bool Arquivos::IsReadOnly() {
            return readOnly;
    }


}

