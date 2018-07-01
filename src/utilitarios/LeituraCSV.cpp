#include "LeituraCSV.h"
#include "../utilitarios/Arquivos.h"
#include "../utilitarios/Comparador.h"
#include "../excecoes/execoes.h"
#include "../dominio/Curso.h"
#include "../dominio/Discente.h"
#include "../dominio/Docente.h"
#include "../dominio/ProducaoCientifica.h"
#include "../professor/DateUtils.h"
#include "../professor/NumPunctPTBR.h"
//import gerencia.atividades.dominio.DidaticoAula;
//import gerencia.atividades.dominio.Graduacao;
//import gerencia.atividades.dominio.Orientacao;
//import gerencia.atividades.dominio.PosGraduacao;
//import gerencia.atividades.dominio.ProducaoCientifica;

using namespace std;
using namespace excecoes;
using namespace dominio;
using namespace utilitarios;
using namespace cpp_util;



class LeituraCSV {
	
private:
        Arquivos arquivos;
	vector<string> leLinha(Scanner sc) {
		string all = sc.nextLine();
		vector<string> propriedades = all.split(";");
		
		for(int i = 0; i < propriedades.length; i++) {
			propriedades[i] = propriedades[i].trim();
		}
		
		return propriedades;
	}

	void checaCodigoDocenteRepetido(map<Docente> docentes, Docente docente){
                if(docentes.count(docente.getCodigo) > 0){
                    throw new CodigoDocenteRepetidoException(docente.getCodigo());
                }
	}

	void checaMatriculaDiscenteRepetida(map<int, Discente> discentes, Discente discente){
            if(discentes.count(discente.getMatricula()) > 0){
                throw new MatriculaDiscenteRepetidaException(discente.getMatricula());
            }
	}

	void checaCodigoCursoRepetido(map<Curso> cursos, Curso curso) {
		if(cursos.count(curso.getCodigo()) > 0){
                    throw new CodigoCursoRepetidoException(curso.getCodigo());
                }
	}

	void checaCodigoDisciplinaRepetido(map<DidaticoAula> disciplinas, DidaticoAula disciplina){
                if(disciplinas.count(disciplina.getCodigo()) > 0){
                    throw new CodigoDisciplinaRepetidoException(disciplina.getCodigo());
                }
	}

	void checaDocenteInvalidoEmDisciplina(DidaticoAula disc, map<Docente> lista){
            
            for (Docente docente : lista) {
			if (docente.getCodigo() == disc.getCodigoDocente())
				return;
		}
            
		throw new CodigoDocenteEmDisciplinaInvalidoException(disc.getNome(), disc.getCodigoDocente());
	}

	void checaDocenteEmOrientacao(map<Docente> docentes, map<Discente> discentes, Orientacao orientacao){
		for (Docente docente : docentes) {
			if (docente.getCodigo() == orientacao.getCodigoDocente())
				return;
		}

		string nome = null;

		for (Discente discente : discentes) {
			if (discente.getMatricula() == orientacao.getMatriculaDoDiscente()) {
				nome = discente.getNome();
				break;
			}
		}

		throw new CodigoDocenteEmOrientacaoInvalidoException(nome, orientacao.getCodigoDocente());
	}

	void checaDocenteEmProducaoCientifica(map<Docente> docentes, ProducaoCientifica prod){
		for (Docente docente : docentes) {
			if (docente.getCodigo() == prod.getCodigoDoDocente())
				return;
		}

		throw new CodigoDocenteEmPublicacaoInvalidoException(prod.getTitulo(), prod.getCodigoDoDocente());
	}

	void checaCursoEmOrientacao(map<Curso> cursos, map<Discente> discentes, Graduacao grad){
		for (Curso curso : cursos) {
			if (curso.getCodigo() == grad.getCodigoDoCurso())
				return;
		}

		string nome = null;

		for (Discente discente : discentes) {
			if (discente.getMatricula() == grad.getMatriculaDoDiscente()) {
				nome = discente.getNome();
				break;
			}
		}

		throw new CodigoCursoEmOrientacaoInvalidoException(nome, grad.getCodigoDoCurso());
	}

	void checaCursoEmDisciplina(map<Curso> cursos, DidaticoAula disc){
		for (Curso curso : cursos) {
			if (curso.getCodigo() == disc.getCodigoDoCurso())
				return;
		}

		throw new CodigoCursoEmDisciplinaInvalidoException(disc.getNome(), disc.getCodigoDoCurso());
	}

	void checaCurso(Curso curso, bool pg) {
		if (curso.getGraduacao() == pg)
			throw new NivelCursoInconsistenteException(curso.getNome(), curso.getCodigo());
	}

	void checaData(map<Discente> discentes, PosGraduacao pg){
		time_t now = time(0);
                
                string dataAtual =  formatDate(now, DATE_FORMAT_PT_BR_SHORT);
		
                string nome = "";

		if (timeCompare(dataAtual, pg.getDataDeIngresso()) < 0) {
                    
                    nome = discentes[pg.getDataDeIngresso].getNome();
                    throw new DataIngressoFuturaException(nome, pg.getDataDeIngresso());
		}
	}

public:
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

	map<DidaticoAula> leDidaticoAulas(map<Docente> docentes, map<Curso> cursos)
			throws FileNotFoundException, IOException, CodigoDisciplinaRepetidoException,
			CodigoDocenteEmDisciplinaInvalidoException, CodigoCursoEmDisciplinaInvalidoException {
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

	map<Graduacao> leGraduacoes(map<Docente> docentes, map<Discente> discentes, map<Curso> cursos)
			throws FileNotFoundException, IOException, CodigoDocenteEmOrientacaoInvalidoException,
			CodigoCursoEmOrientacaoInvalidoException {
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

	map<PosGraduacao> lePosGraduacoes(map<Docente> docentes, map<Discente> discentes)
			throws FileNotFoundException, IOException, ParseException, CodigoDocenteEmOrientacaoInvalidoException,
			DataIngressoFuturaException {
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

	}
}

