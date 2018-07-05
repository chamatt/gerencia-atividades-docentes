#include <cstdlib>
#include <map>
#include <iostream>
#include "utilitarios/Arquivos.h"
#include "dominio/Docente.h"
#include "dominio/Discente.h"
#include "dominio/Atividade.h"
#include "dominio/Curso.h"
#include "dominio/DidaticoAula.h"
#include "dominio/Graduacao.h"
#include "dominio/Orientacao.h"
#include "dominio/PosGraduacao.h"
#include "dominio/ProducaoCientifica.h"
#include "utilitarios/EscritaCSV.h"
#include "utilitarios/LeituraCSV.h"
#include "excecoes/execoes.h"

using namespace std;
using namespace utilitarios;
using namespace dominio;
using namespace excecoes;


/*
 * 
 */
int main(int argc, char** argv) {
        
        try{
            Arquivos arquivos(argc, argv);
            map<int, Docente*> docentes; // Codigo do docente -> Docente
            map<long, Discente*> discentes; // Matricula do discente -> Discente
            map<int, ProducaoCientifica*> producoesCientificas; // Codigo do docente -> Prod. Cientifica
            map<int, Curso*> cursos; // Codigo do curso -> Curso
            map<string, DidaticoAula*> didaticoAulas; // Codigo da aula -> Aula
            map<long, Graduacao*> graduacoes; // Matricula do Discente -> Graduacao
            map<long, PosGraduacao*> posGraduacoes; // Matricula do Discente -> PosGraduacao

                
            // Realização de todas as leituras e atribui ao mapa
            LeituraCSV* leitor = new LeituraCSV(arquivos);
            docentes = leitor->leDocentes();
            discentes = leitor->leDiscentes();
            producoesCientificas = leitor->leProducoesCientificas(docentes);
            cursos = leitor->leCursos();
            didaticoAulas = leitor->leDidaticoAulas(docentes, cursos);
            graduacoes = leitor->leGraduacoes(docentes, discentes, cursos);
            posGraduacoes = leitor->lePosGraduacoes(docentes, discentes);
          
            // Faz as escritas dos arquivos CSV
           EscritaCSV* escritor = new EscritaCSV();
           escritor->escrevePAD(docentes);
           escritor->escreveAlocacao(didaticoAulas);
           escritor->escreveDiscentesProGrad(discentes);
           escritor->escreveRHA(cursos);
        } catch (IOException e) {
            cout << e.what();
        } catch (ParseException p) {
            cout << p.what();
        } catch (CodigoDocenteRepetidoException cd) {
            cout << cd.what();
        } catch (MatriculaDiscenteRepetidaException md) {
            cout << md.what();
        } catch (CodigoCursoRepetidoException cr) {
            cout << cr.what();
        } catch (CodigoDisciplinaRepetidoException cdr) {
            cout << cdr.what();
        } catch (CodigoDocenteEmDisciplinaInvalidoException cdi) {
            cout << cdi.what();
        } catch (CodigoDocenteEmOrientacaoInvalidoException oi) {
            cout << oi.what();
        } catch (CodigoDocenteEmPublicacaoInvalidoException pi) {
            cout << pi.what();
        } catch (CodigoCursoEmOrientacaoInvalidoException ci) {
            cout << ci.what();
        } catch (CodigoCursoEmDisciplinaInvalidoException di) {
            cout << di.what();
        } catch (NivelCursoInconsistenteException ni) {
            cout << ni.what();
        } catch (DataIngressoFuturaException df) {
            cout << df.what();
        }
    
    
    
    
    return 0;
}

