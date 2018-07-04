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
#include <fstream>

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
        
	map<int, Docente*> LeituraCSV::leDocentes() {
        //throws (FileNotFoundException, IOException, CodigoDocenteRepetidoException) {

            ifstream stream(arquivos.getDocentes());
            
            if (stream.is_open()) {
                map<int, Docente*> docentes;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    int codigo;
                    try {
                        codigo = stoi(propriedades[0]);
                    } catch(exception e){
                        throw ParseException();
                    }
                    string nome = propriedades[1];
                    string departamento = propriedades[2];

                    Docente* docente = new Docente(codigo, nome, departamento);
                    checaCodigoDocenteRepetido(docentes, docente);
                    docentes[codigo] = docente;
                }
                stream.close();
                return docentes;
            }
            else {  
                throw IOException();
            }
	}
        
        
        
        
        
        
        
        

        
        
	map<long, Discente> LeituraCSV::leDiscentes(){
        //throws FileNotFoundException, IOException, MatriculaDiscenteRepetidaException {
            ifstream stream(arquivos.getDiscentes());
            
            if (stream.is_open()) {
                map<int, Discente*> discentes;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    long matricula;
                    int codigoCurso;
                    try {
                        matricula = (long) stoi(propriedades[0]);
                        codigoCurso = stoi(propriedades[2]);
                    } catch(exception e){
                        throw ParseException();
                    }
                    string nome = propriedades[1];

                    Discente* discente = new Discente(matricula, nome, codigoCurso);
                    checaMatriculaDiscenteRepetida(discentes, discente);
                    discentes[matricula] = discente;
                }
                stream.close();
                return discentes;
            }
            else {  
                throw IOException();
            }

	}

        
        
	map<int, ProducaoCientifica> LeituraCSV::leProducoesCientificas(map<int, Docente> docentes){
//			throws FileNotFoundException, IOException, CodigoDocenteEmPublicacaoInvalidoException {
		
            
            ifstream stream(arquivos.getProducaoCientifica());
            if (stream.is_open()) {
                map<int, ProducaoCientifica*> producoesCientificas;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    
                    int codigoDocente;
                    try {
                        codigoDocente = stoi(propriedades[0]);
                    } catch(exception e){
                        throw ParseException();
                    }
                    
                    string tituloDaPublicacao = propriedades[1];
                    bool qualificada = (propriedades.size() > 2 && propriedades[2] == "X") ? true : false;
                    
                    ProducaoCientifica* producaoCientifica = new ProducaoCientifica(codigoDocente, tituloDaPublicacao,
						qualificada);
                    checaDocenteEmProducaoCientifica(docentes, producaoCientifica);
                    producoesCientificas[codigoDocente] = producaoCientifica;
                }
                stream.close();
                return producoesCientificas;
            }
            else {  
                throw IOException();
            }

	}

        
        
	map<int, Curso> LeituraCSV::leCursos(){
//			throws FileNotFoundException, IOException, CodigoCursoRepetidoException, NivelCursoInconsistenteException {
		
            
            
            ifstream stream(arquivos.getCursos());
            
            if (stream.is_open()) {
                map<int, Curso*> cursos;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    
                    int codigo;
                    try {
                        codigo = stoi(propriedades[0]);
                    } catch(exception e){
                        throw ParseException();
                    }
                    string nome = propriedades[1];
                    bool graduacao = (propriedades.size() > 2 && propriedades[2].equals("X")) ? true : false;
                    bool posGraduacao = (propriedades.size() > 3 && propriedades[3].equals("X")) ? true : false;
                    
                    Curso* curso = new Curso(codigo, nome, graduacao);
                    checaCodigoCursoRepetido(cursos, curso);
                    checaCurso(curso, posGraduacao);
                    cursos[codigo] = curso;
                    
                    
                    // Conexao com docentes
                    
                    
                    
                }
                stream.close();
                return cursos;
            }
            else {  
                throw IOException();
            }

	}

        
	map<DidaticoAula> LeituraCSV::leDidaticoAulas(map<int, Docente*> &docentes, map<int, Curso*> &cursos){
		
            
            
            ifstream stream(arquivos.getDidaticoAulas());
            
            if (stream.is_open()) {
                map<string, DidaticoAula*> didaticoAulas;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    
                    int codigoDocente;
                    int cargaSemanal;
                    int cargaSemestral;
                    int codigoCurso;
                    try {
                        codigoDocente = stoi(propriedades[2]);
                        cargaSemanal = stoi(propriedades[3]);
                        cargaSemestral = stoi(propriedades[4]);
                        codigoCurso = stoi(propriedades[5]);
                    } catch(exception e){
                        throw ParseException();
                    }
                    string codigo = propriedades[0];
                    string nome = propriedades[1];
                    
                    
                    // Instancia uma aula e adiciona no mapa de aulas
                    DidaticoAula* didaticoAula = new DidaticoAula(codigo, nome, docentes[codigoDocente], cargaSemanal, cargaSemestral,
                                    cursos[codigoCurso]);
                    checaCodigoDisciplinaRepetido(didaticoAulas, didaticoAula);
                    checaDocenteInvalidoEmDisciplina(didaticoAula, docentes);
                    checaCursoEmDisciplina(cursos, didaticoAula);
                    didaticoAulas[codigo] = didaticoAula;
                            
                            
                    //Conexao com docente
                    docentes[codigoDocente]->addListaDidaticoAula(didaticoAula);
                    
                    // Conexao com curso (adicionar na lista de docentes do curso)
                    cursos[codigoCurso]->addListaDocentes(docentes[codigoDocente]);
                            
                }
                stream.close();
                return didaticoAulas;
            }
            else {  
                throw IOException();
            }
            
	}

        
        
	map<Graduacao> LeituraCSV::leGraduacoes(map<int, Docente*>& docentes, map<long, Discente*>& discentes, map<int, Curso*> &cursos) {
		
            ifstream stream(arquivos.getOrientacaoGraducao());
            
            if (stream.is_open()) {
                map<int, Graduacao*> graduacoes;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    
                    int codigoDocente;
                    int matriculaDiscente;
                    int codigoCurso;
                    int cargaSemanal;
                    
                    try {
                        codigoDocente = stoi(propriedades[0]);
                        matriculaDiscente = stoi(propriedades[1]);
                        codigoCurso = stoi(propriedades[2]);
                        cargaSemanal = stoi(propriedades[3]);
                    } catch(exception e){
                        throw ParseException();
                    }

                    
                    // Instancia a graduacao com suas propriedades e adiciona ao mapa de graduacoes
                    Graduacao* graduacao = new Graduacao(docentes[codigoDocente], discentes[matriculaDiscente], cursos[codigoCurso], cargaSemanal);
                    checaDocenteEmOrientacao(docentes, discentes, graduacao);
                    checaCursoEmOrientacao(cursos, discentes, graduacao);
                    graduacoes[matriculaDiscente] = graduacao;
                    
                    // Conexao com Docente
                    docentes[codigoDocente]->addListaGraduacao(graduacao);
                    
                    // Conexao com Discente
                    discentes[matriculaDiscente]->setGraduacao(graduacao);
                    
                    // Conexao com Curso - Nao necessário, o curso sabe sua graduacao na hora da leitura
                    
                }
                stream.close();
                return graduacoes;
            }
            else {  
                throw IOException();
            }
            
          

	}

        
        
	map<PosGraduacao> LeituraCSV::lePosGraduacoes(map<int, Docente*>& docentes, map<long, Discente*>& discentes){
		
            
            ifstream stream(arquivos.getOrientacaoPos());
            
            if (stream.is_open()) {
                map<int, PosGraduacao*> posGraduacoes;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    
                    int codigoDocente;
                    int matriculaDiscente;
                    int cargaSemanal;
                    
                    try {
                        codigoDocente = stoi(propriedades[0]);
                        matriculaDiscente = stoi(propriedades[1]);
                        cargaSemanal = stoi(propriedades[4]);
                    } catch(exception e){
                        throw ParseException();
                    }
                    string date = propriedades[2];
                    string programa = propriedades[3];
                    
                    
                    //Instanciamento da posGraduacao nova e logo em seguida é adicionada no mapa
                    PosGraduacao* posGraduacao = new PosGraduacao(docentes[codigoDocente], discentes[matriculaDiscente], date, programa,
                                    cargaSemanal);
                    checaDocenteEmOrientacao(docentes, discentes, posGraduacao);
                    checaData(discentes, posGraduacao);
                    posGraduacoes[matriculaDiscente] = posGraduacao;
                    
                    
                    //Conexoes com docente
                    docentes[codigoDocente]->addListaPosGraduacao(posGraduacao);
                    
                    //Conexao com discente
                    discentes[matriculaDiscente]->setPosGraduacao(posGraduacao);
                    
                }
                stream.close();
                return posGraduacoes;
            }
            else {  
                throw IOException();
            }
	}
}

