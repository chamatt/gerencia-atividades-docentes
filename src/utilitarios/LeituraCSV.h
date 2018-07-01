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
#include "src/dominio/Orientacao.h"


using namespace std;
using namespace excecoes;
using namespace dominio;
using namespace utilitarios;
using namespace cpp_util;

class LeituraCSV {
private:
        Arquivos arquivos;
	vector<string> leLinha(ifstream sc);

	void checaCodigoDocenteRepetido(map<int, Docente*> &docentes, Docente* docente);
	void checaMatriculaDiscenteRepetida(map<long, Discente*> &discentes, Discente* discente);
	void checaCodigoCursoRepetido(map<int, Curso*> &cursos, Curso* curso);
	void checaCodigoDisciplinaRepetido(map<string, DidaticoAula*> &disciplinas, DidaticoAula* disciplina);
	void checaDocenteInvalidoEmDisciplina(map<Docente*> &docentes, DidaticoAula* disc);
        void checaDocenteEmOrientacao(map<int, Docente*> &docentes, map<long, Discente*> &discentes, Orientacao* orientacao);
	void checaDocenteEmProducaoCientifica(map<int, Docente*> &docentes, ProducaoCientifica* prod);
        void checaCursoEmOrientacao(map<int, Curso*> &cursos, map<long, Discente*> &discentes, Graduacao* grad);
	void checaCursoEmDisciplina(map<Curso*> &cursos, DidaticoAula* disc);
	void checaCurso(Curso curso, bool pg);
	void checaData(map<Discente> discentes, PosGraduacao pg);

public:
        LeituraCSV(Arquivos arquivos);
        
        LeituraCSV(const LeituraCSV& orig);
        
        virtual ~LeituraCSV();
    
	map<Docente> leDocentes();

	map<Discente> leDiscentes();

	map<ProducaoCientifica> leProducoesCientificas(map<Docente> docentes);

	map<Curso> leCursos();

	map<DidaticoAula> leDidaticoAulas(map<Docente> docentes, map<Curso> cursos);

	map<Graduacao> leGraduacoes(map<Docente> docentes, map<Discente> discentes, map<Curso> cursos);

	map<PosGraduacao> lePosGraduacoes(map<Docente> docentes, map<Discente> discentes);

};

#endif /* LEITURACSV_H */

