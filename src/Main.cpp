#include <cstdlib>
#include "utilitarios/Arquivos.h"
#include "dominio/Docente.h"
#include "dominio/Discente.h"


using namespace std;
using Arquivos = utilitarios::arquivos;
using Docentes = dominio::Docentes;
using Discentes = dominio::Discentes;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
            Arquivos arquivos = new Arquivos(args);

//            LeituraCSV leitor;
//            map<int, Docente> docentes;
//            List<Discente> discentes;
//            List<ProducaoCientifica> producoesCientificas;
//            List<Curso> cursos;
//            List<DidaticoAula> didaticoAulas;
//            List<Graduacao> graduacoes;
//            List<PosGraduacao> posGraduacoes;
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
    }
    
    
    
    return 0;
}
