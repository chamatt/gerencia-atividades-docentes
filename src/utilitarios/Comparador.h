/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comparador.h
 * Author: mathe
 *
 * Created on 30 de Junho de 2018, 19:47
 */

#include "../dominio/Docente.h"
#include "../professor/StringUtils.h"
#include "../professor/DateUtils.h"
#include "../professor/NumberUtils.h"
#include "../professor/Tokenizer.h"



#ifndef COMPARADOR_H
#define COMPARADOR_H
namespace utilitarios{
    class Comparador {
        public:
            Comparador();
            Comparador(const Comparador& orig);
            
            int timeCompare(string date1, string date2);
            int PAD(Docente d1, Docente d2);
            int PPG(Discente d1, Discente d2);
            int Alocacao(DidaticoAula d1, DidaticoAula d2);
            
            virtual ~Comparador();
        private:

    };
}
#endif /* COMPARADOR_H */

