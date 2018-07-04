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
            vector<string> leLinha(ifstream& sc);

            void checaCodigoDocenteRepetido(map<int, Docente*> &docentes, int codigoDoDocente);
            void checaMatriculaDiscenteRepetida(map<long, Discente*> &discentes, long matricula);
            void checaCodigoCursoRepetido(map<int, Curso*> &cursos, int codigoDoCurso);
            void checaCodigoDisciplinaRepetido(map<string, DidaticoAula*> &disciplinas, string codigoDaDisciplina);
            void checaDocenteInvalidoEmDisciplina(map<int, Docente*> &docentes, int codigoDoDocente, string nomeDaDisciplina);
            void checaDocenteEmOrientacao(map<int, Docente*> &docentes, map<long, Discente*> &discentes, int codigoDoDocente, int matriculaDoDiscente);
            void checaDocenteEmProducaoCientifica(map<int, Docente*> &docentes, int codigoDoDocente, string tituloDaProducao);
            void checaCursoEmOrientacao(map<int, Curso*> &cursos, map<long, Discente*> &discentes, int codigoDoCurso, long matriculaDoDiscente);
            void checaCursoEmDisciplina(map<int, Curso*> &cursos, int codigoDoCurso, string nomeDaDisciplina);
            void checaCurso(Curso* curso, bool pg);
            void checaData(map<long, Discente*> discentes, string dataDeIngresso, long matriculaDoDiscente);

    public:
            LeituraCSV(Arquivos& arquivos);

            virtual ~LeituraCSV();

            map<int, Docente*> leDocentes();

            map<long, Discente*> leDiscentes();

            map<long, ProducaoCientifica*> leProducoesCientificas(map<int, Docente*> &docentes);

            map<int, Curso*> leCursos();

            map<string, DidaticoAula*> leDidaticoAulas(map<int, Docente*>& docentes, map<int, Curso*>& cursos);

            map<long, Graduacao*> leGraduacoes(map<int, Docente*>& docentes, map<long, Discente*>& discentes, map<int, Curso*> &cursos);

            map<long, PosGraduacao*> lePosGraduacoes(map<int, Docente*>& docentes, map<long, Discente*>& discentes);

    };

}
#endif /* LEITURACSV_H */

