/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comparador.cpp
 * Author: mathe
 * 
 * Created on 30 de Junho de 2018, 19:47
 */

#include "Comparador.h"
#include "../dominio/Docente.h"
#include "../professor/StringUtils.h"
#include "../professor/DateUtils.h"
#include "../professor/NumberUtils.h"
#include "../professor/Tokenizer.h"

namespace utilitarios {
    
    Comparador::Comparador() {
        
    }

    Comparador::Comparador(const Comparador& orig) {
    }

    Comparador::~Comparador() {
    }

    int Comparador::timeCompare(string date1, string date2){
        time_t d1 =  parseDate(date1, DATE_FORMAT_PT_BR_SHORT);
        time_t d2 =  parseDate(date2, DATE_FORMAT_PT_BR_SHORT);
        return d1 - d2;
    }
    
    int Comparador::PAD(Docente d1, Docente d2){
        return stringCompare(d1.getNome(), d2.getNome());
    }   

    int Comparador::PPG(Discente d1, Discente d2) {
        if (stringCompare(d1.getPosGraduacao().getNomeDoPrograma(), d2.getPosGraduacao().getNomeDoPrograma()) == 0) {
                if (timeCompare(d1.getPosGraduacao().getDataDeIngresso(), d2.getPosGraduacao().getDataDeIngresso()) == 0) {
                        return stringCompare(d1.getNome(), d2.getNome());
                }

                if (timeCompare(d1.getPosGraduacao().getDataDeIngresso(), (d2.getPosGraduacao().getDataDeIngresso()) < 0)
                        return -1;
                else
                        return 1;
        }

        return stringCompare(d1.getPosGraduacao().getNomeDoPrograma(), d2.getPosGraduacao().getNomeDoPrograma());
    }
    int Comparador::Alocacao(DidaticoAula d1, DidaticoAula d2) {
        if (stringCompare(d1.getDocente().getNome(), d2.getDocente().getNome()) == 0)
                return stringCompare(d1.getCodigo(), d2.getCodigo());

        return stringCompare(d1.getDocente().getNome(), d2.getDocente().getNome());
    }
}

