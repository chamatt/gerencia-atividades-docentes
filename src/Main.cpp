#include <cstdlib>
#include <map>
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

using namespace std;
using namespace utilitarios;
using namespace dominio;


/*
 * 
 */
int main(int argc, char** argv) {
    
            Arquivos* arquivos = new Arquivos(argc, argv);

//            LeituraCSV leitor;
            map<int, Docente*> docentes; // Codigo do docente
            map<long, Discente*> discentes; // Matricula do discente
            map<int, ProducaoCientifica*> producoesCientificas; // codigo do docente
            map<int, Curso*> cursos; // Codigo do curso
            map<string, DidaticoAula*> didaticoAulas; // Codigo da aula
            map<long, Graduacao*> graduacoes; // matricula do discente
            map<long, PosGraduacao*> posGraduacoes; // matricula do discente
//
//
//            leitor = new LeituraCSV(arquivos);
//            docentes = leitor.leDocentes();
//            discentes = leitor.leDiscentes();
//            producoesCientificas = leitor.leProducoesCientificas(docentes);
//            cursos = leitor.leCursos();
//            didaticoAulas = leitor.leDidaticoAulas(docentes, cursos);
//            graduacoes = leitor.leGraduacoes(docentes, discentes, cursos);
//            posGraduacoes = leitor.lePosGraduacoes(docentes, discentes);
//
//            Relacionamentos relacionamentos = new Relacionamentos();
//
//            relacionamentos.ConectaInformacoesDocente(docentes, producoesCientificas, graduacoes, posGraduacoes,
//                            didaticoAulas);
//            relacionamentos.ConectaInformacoesDiscente(discentes, posGraduacoes);
//            relacionamentos.ConectaInformacoesCurso(cursos, didaticoAulas);
//
//            EscritaCSV escritor = new EscritaCSV();
//            escritor.escrevePAD(docentes);
//            escritor.escreveAlocacao(didaticoAulas);
//            escritor.escreveDiscentesProGrad(discentes);
//            escritor.escreveRHA(cursos);
//        }
//        } catch (IOException e) {
//                cout << "Erro de I/O";
//        } catch (java.text.ParseException p) {
//                Scout << "Erro de formatação";
//        } catch (CodigoDocenteRepetidoException cd) {
//        } catch (MatriculaDiscenteRepetidaException md) {
//        } catch (CodigoCursoRepetidoException cr) {
//        } catch (CodigoDisciplinaRepetidoException cdr) {
//        } catch (CodigoDocenteEmDisciplinaInvalidoException cdi) {
//        } catch (CodigoDocenteEmOrientacaoInvalidoException oi) {
//        } catch (CodigoDocenteEmPublicacaoInvalidoException pi) {
//        } catch (CodigoCursoEmOrientacaoInvalidoException ci) {
//        } catch (CodigoCursoEmDisciplinaInvalidoException di) {
//        } catch (NivelCursoInconsistenteException ni) {
//        } catch (DataIngressoFuturaException df) {
//        }
    
    
    
    
    return 0;
}

