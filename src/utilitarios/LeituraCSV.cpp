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
#include "../professor/NumberUtils.h"
#include "../professor/StringUtils.h"
#include "../dominio/Orientacao.h"

using namespace std;
using namespace excecoes;
using namespace dominio;
using namespace cpp_util;
using namespace utilitarios;



namespace utilitarios {
    
    
    
        LeituraCSV::LeituraCSV(Arquivos& arquivos) {
            this->arquivos = arquivos;
        }
        
	vector<string> LeituraCSV::leLinha(ifstream& sc) {
		string linha;
                getline(sc, linha);
                
		Tokenizer tok(linha, ';');
                
                vector<string> propriedades = tok.remaining();
                
		for(int i = 0; i < (int) propriedades.size(); i++) {
                    propriedades[i] = trim(propriedades[i]);
		}
		
		return propriedades;
	}

	void LeituraCSV::checaCodigoDocenteRepetido(map<int, Docente*> &docentes, Docente* docente){
                if(docentes.count(docente->getCodigo()) > 0){
                    throw CodigoDocenteRepetidoException(docente->getCodigo());
                }
	}

	void LeituraCSV::checaMatriculaDiscenteRepetida(map<long, Discente*> &discentes, Discente* discente){
            if(discentes.count(discente->getMatricula()) > 0){
                throw MatriculaDiscenteRepetidaException(discente->getMatricula());
            }
	}

	void LeituraCSV::checaCodigoCursoRepetido(map<int, Curso*> &cursos, Curso* curso) {
		if(cursos.count(curso->getCodigo()) > 0){
                    throw CodigoCursoRepetidoException(curso->getCodigo());
                }
	}

	void LeituraCSV::checaCodigoDisciplinaRepetido(map<string, DidaticoAula*> &disciplinas, DidaticoAula* disciplina){
                if(disciplinas.count(disciplina->getCodigo()) > 0){
                    throw CodigoDisciplinaRepetidoException(disciplina->getCodigo());
                }
	}

	void LeituraCSV::checaDocenteInvalidoEmDisciplina(map<int, Docente*> &docentes, DidaticoAula* disc){
            
            if(docentes.count(disc->getDocente()->getCodigo() > 0)) return;
            
            throw CodigoDocenteEmDisciplinaInvalidoException(disc->getNome(), disc->getDocente()->getCodigo());
		
	}

	void LeituraCSV::checaDocenteEmOrientacao(map<int, Docente*> &docentes, map<long, Discente*> &discentes, Orientacao* orientacao){
		
                if(docentes.count(orientacao->getDocente()->getCodigo()) > 0) return;

		string nome = discentes[orientacao->getDiscente()->getMatricula()]->getNome();;

		throw CodigoDocenteEmOrientacaoInvalidoException(nome, orientacao->getDocente()->getCodigo());
	}

	void LeituraCSV::checaDocenteEmProducaoCientifica(map<int, Docente*> &docentes, ProducaoCientifica* prod){
                if(docentes.count(prod->getDocente()->getCodigo()) > 0) return;

		throw CodigoDocenteEmPublicacaoInvalidoException(prod->getTitulo(), prod->getDocente()->getCodigo());
	}

	void LeituraCSV::checaCursoEmOrientacao(map<int, Curso*> &cursos, map<long, Discente*> &discentes, Graduacao* grad){
            if(cursos.count(grad->getCurso()->getCodigo()) > 0) return;

            string nome = discentes[grad->getDiscente()->getMatricula()]->getNome();

            throw CodigoCursoEmOrientacaoInvalidoException(nome, grad->getCurso()->getCodigo());
	}

	void LeituraCSV::checaCursoEmDisciplina(map<int, Curso*> &cursos, DidaticoAula* disc){
            if(cursos.count(disc->getCurso()->getCodigo()) > 0) return;
            
            throw CodigoCursoEmDisciplinaInvalidoException(disc->getNome(), disc->getCurso()->getCodigo());
	}

	void LeituraCSV::checaCurso(Curso* curso, bool pg) {
		if (curso->isGraduacao() == pg)
			throw NivelCursoInconsistenteException(curso->getNome(), curso->getCodigo());
	}

	void LeituraCSV::checaData(map<long, Discente*> discentes, PosGraduacao* pg){
            time_t now = time(0);
            string dataAtual =  formatDate(now, DATE_FORMAT_PT_BR_SHORT);
            string nome = "";
            Discente* a;
            if (Comparador::timeCompare(dataAtual, pg->getDataDeIngresso()) < 0) {
                a = (discentes[pg->getDiscente()->getMatricula()]);
                nome = a->getNome();
                throw DataIngressoFuturaException(nome, pg->getDataDeIngresso());
            }
	}
        /*
	map<Docente> leDocentes() throws FileNotFoundException, IOException, CodigoDocenteRepetidoException {

		try (Scanner scanner = new Scanner(new FileReader(arquivos.getDocentes()));) {
			scanner.nextLine();
			map<Docente> docentes = new Arraymap<Docente>();
			while (scanner.hasNextLine()) {

				vector<string> propriedades = leLinha(scanner);

				int codigo = Integer.parseInt(propriedades[0]);
				string nome = propriedades[1];
				string departamento = propriedades[2];

				Docente docente = new Docente(codigo, nome, departamento);
				checaCodigoDocenteRepetido(docentes, docente);
				docentes.add(docente);

			}
			return docentes;
		}

	}

	map<Discente> leDiscentes() throws FileNotFoundException, IOException, MatriculaDiscenteRepetidaException {
		try (Scanner scanner = new Scanner(new FileReader(arquivos.getDiscentes()))) {
			scanner.nextLine();
			map<Discente> discentes = new Arraymap<Discente>();
			while (scanner.hasNextLine()) {
				vector<string> propriedades = leLinha(scanner);

				long matricula = Integer.parseInt(propriedades[0]);
				string nome = propriedades[1];
				int codigoCurso = Integer.parseInt(propriedades[2]);

				Discente discente = new Discente(matricula, nome, codigoCurso);
				checaMatriculaDiscenteRepetida(discentes, discente);
				discentes.add(discente);
			}
			return discentes;
		}

	}

	map<ProducaoCientifica> leProducoesCientificas(map<Docente> docentes)
			throws FileNotFoundException, IOException, CodigoDocenteEmPublicacaoInvalidoException {
		try (Scanner scanner = new Scanner(new FileReader(arquivos.getProducaoCientifica()));) {
			scanner.nextLine();
			map<ProducaoCientifica> producoesCientificas = new Arraymap<ProducaoCientifica>();
			while (scanner.hasNextLine()) {
				vector<string> propriedades = leLinha(scanner);

				int codigoDocente = Integer.parseInt(propriedades[0]);
				string tituloDaPublicacao = propriedades[1];
				bool qualificada = (propriedades.length > 2 && propriedades[2].equals("X")) ? true : false;

				ProducaoCientifica producaoCientifica = new ProducaoCientifica(codigoDocente, tituloDaPublicacao,
						qualificada);
				checaDocenteEmProducaoCientifica(docentes, producaoCientifica);
				producoesCientificas.add(producaoCientifica);
			}
			return producoesCientificas;
		}

	}

	map<Curso> leCursos()
			throws FileNotFoundException, IOException, CodigoCursoRepetidoException, NivelCursoInconsistenteException {
		try (Scanner scanner = new Scanner(new FileReader(arquivos.getCursos()));) {
			scanner.nextLine();

			map<Curso> cursos = new Arraymap<Curso>();
			while (scanner.hasNextLine()) {
				vector<string> propriedades = leLinha(scanner);
				int codigo = Integer.parseInt(propriedades[0]);
				string nome = propriedades[1];
				bool graduacao = (propriedades.length > 2 && propriedades[2].equals("X")) ? true : false;
				bool posGraduacao = (propriedades.length > 3 && propriedades[3].equals("X")) ? true : false;

				Curso curso = new Curso(codigo, nome, graduacao);
				checaCodigoCursoRepetido(cursos, curso);
				checaCurso(curso, posGraduacao);
				cursos.add(curso);
			}
			return cursos;
		}

	}

	map<DidaticoAula> leDidaticoAulas(map<Docente> docentes, map<Curso> cursos){
		try (Scanner scanner = new Scanner(new FileReader(arquivos.getDidaticoAulas()));) {
			scanner.nextLine();
			map<DidaticoAula> didaticoAulas = new Arraymap<DidaticoAula>();
			while (scanner.hasNextLine()) {
				vector<string> propriedades = leLinha(scanner);

				string codigo = propriedades[0];
				string nome = propriedades[1];
				int codigoDocente = Integer.parseInt(propriedades[2]);
				int cargaSemanal = Integer.parseInt(propriedades[3]);
				int cargaSemestral = Integer.parseInt(propriedades[4]);
				int codigoCurso = Integer.parseInt(propriedades[5]);

				DidaticoAula didaticoAula = new DidaticoAula(codigo, nome, codigoDocente, cargaSemanal, cargaSemestral,
						codigoCurso);
				checaCodigoDisciplinaRepetido(didaticoAulas, didaticoAula);
				checaDocenteInvalidoEmDisciplina(didaticoAula, docentes);
				checaCursoEmDisciplina(cursos, didaticoAula);
				didaticoAulas.add(didaticoAula);
			}
			return didaticoAulas;
		}

	}

	map<Graduacao> leGraduacoes(map<Docente> docentes, map<Discente> discentes, map<Curso> cursos) {
		try (Scanner scanner = new Scanner(new FileReader(arquivos.getOrientacaoGraducao()));) {
			scanner.nextLine();
			map<Graduacao> graduacoes = new Arraymap<Graduacao>();
			while (scanner.hasNextLine()) {
				vector<string> propriedades = leLinha(scanner);

				int codigoDocente = Integer.parseInt(propriedades[0]);
				int matriculaDiscente = Integer.parseInt(propriedades[1]);
				int codigoCurso = Integer.parseInt(propriedades[2]);
				int cargaSemanal = Integer.parseInt(propriedades[3]);

				Graduacao graduacao = new Graduacao(codigoDocente, matriculaDiscente, codigoCurso, cargaSemanal);
				checaDocenteEmOrientacao(docentes, discentes, graduacao);
				checaCursoEmOrientacao(cursos, discentes, graduacao);
				graduacoes.add(graduacao);
			}
			return graduacoes;
		}

	}

	map<PosGraduacao> lePosGraduacoes(map<Docente> docentes, map<Discente> discentes){
		try (Scanner scanner = new Scanner(new FileReader(arquivos.getOrientacaoPos()));) {
			scanner.nextLine();
			map<PosGraduacao> posGraduacoes = new Arraymap<PosGraduacao>();
			while (scanner.hasNextLine()) {
				vector<string> propriedades = leLinha(scanner);

				int codigoDocente = Integer.parseInt(propriedades[0]);
				int matriculaDiscente = Integer.parseInt(propriedades[1]);
				string sDate = propriedades[2];
				Date date = new SimpleDateFormat("dd/MM/yyyy").parse(sDate);
				string programa = propriedades[3];
				int cargaSemanal = Integer.parseInt(propriedades[4]);

				PosGraduacao posGraduacao = new PosGraduacao(codigoDocente, matriculaDiscente, date, programa,
						cargaSemanal);
				checaDocenteEmOrientacao(docentes, discentes, posGraduacao);
				checaData(discentes, posGraduacao);
				posGraduacoes.add(posGraduacao);
			}
			return posGraduacoes;
		}

	}*/
}

