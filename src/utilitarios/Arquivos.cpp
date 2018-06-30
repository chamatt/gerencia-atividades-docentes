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

Arquivos::Arquivos() {
    
}

Arquivos::Arquivos(const Arquivos& orig) {
}

Arquivos::~Arquivos() {
}


string docentes;
string discentes;
string producaoCientifica;
string cursos;
string didaticoAulas;
string orientacaoGraducao;
string orientacaoPos;
bool writeOnly = false;
bool readOnly = false;

Arquivos(int argc, char* argv[]) {
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

string getDocentes() {
        return docentes;
}

string getDiscentes() {
        return discentes;
}

string getProducaoCientifica() {
        return producaoCientifica;
}

string getCursos() {
        return cursos;
}

string getDidaticoAulas() {
        return didaticoAulas;
}

string getOrientacaoGraducao() {
        return orientacaoGraducao;
}

string getOrientacaoPos() {
        return orientacaoPos;
}

bool isWriteOnly() {
        return writeOnly;
}

bool isReadOnly() {
        return readOnly;
}
