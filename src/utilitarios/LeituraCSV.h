#ifndef LEITURACSV_H
#define LEITURACSV_H


#include "LeituraCSV.h"
#include "../utilitarios/Arquivos.h"
#include "../utilitarios/Comparador.h"
#include "../excecoes/execoes.h"
#include "../dominio/Docente.h"
#include "../dominio/Discente.h"
#include "../dominio/Atividade.h"
#include "../dominio/Curso.h"
#include "../dominio/DidaticoAula.h"
#include "../dominio/Graduacao.h"
#include "../dominio/Orientacao.h"
#include "../dominio/PosGraduacao.h"
#include "../dominio/ProducaoCientifica.h"
#include "../professor/DateUtils.h"
#include "../professor/NumPunctPTBR.h"
#include "../dominio/Orientacao.h"
#include <map>


using namespace std;
using namespace excecoes;
using namespace dominio;
using namespace utilitarios;
using namespace cpp_util;


namespace utilitarios {
    class LeituraCSV {
    private:
            Arquivos arquivos;
            vector<string> leLinha(ifstream sc);

            void checaCodigoDocenteRepetido(map<int, Docente*> &docentes, Docente* docente);
            void checaMatriculaDiscenteRepetida(map<long, Discente*> &discentes, Discente* discente);
            void checaCodigoCursoRepetido(map<int, Curso*> &cursos, Curso* curso);
            void checaCodigoDisciplinaRepetido(map<string, DidaticoAula*> &disciplinas, DidaticoAula* disciplina);
            void checaDocenteInvalidoEmDisciplina(map<int, Docente*> &docentes, DidaticoAula* disc);
            void checaDocenteEmOrientacao(map<int, Docente*> &docentes, map<long, Discente*> &discentes, Orientacao* orientacao);
            void checaDocenteEmProducaoCientifica(map<int, Docente*> &docentes, ProducaoCientifica* prod);
            void checaCursoEmOrientacao(map<int, Curso*> &cursos, map<long, Discente*> &discentes, Graduacao* grad);
            void checaCursoEmDisciplina(map<int, Curso*> &cursos, DidaticoAula* disc);
            void checaCurso(Curso* curso, bool pg);
            void checaData(map<long, Discente*> discentes, PosGraduacao* pg);

    public:
            LeituraCSV(Arquivos& arquivos);

            virtual ~LeituraCSV();

            map<int, Docente> leDocentes();

            map<long, Discente> leDiscentes();

            map<int, ProducaoCientifica> leProducoesCientificas(map<int, Docente> docentes);

            map<int, Curso> leCursos();

            map<string, DidaticoAula> leDidaticoAulas(map<int, Docente> docentes, map<int, Curso> cursos);

            map<int, Graduacao> leGraduacoes(map<int, Docente> docentes, map<long, Discente> discentes, map<int, Curso> cursos);

            map<int, PosGraduacao> lePosGraduacoes(map<int, Docente> docentes, map<int, Discente> discentes);

    };

}
#endif /* LEITURACSV_H */

