#include "LeituraCSV.h"
#include <iostream>
#include <cstdio>
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

	void LeituraCSV::checaCodigoDocenteRepetido(map<int, Docente*> &docentes, int codigoDoDocente){
                if(docentes.count(codigoDoDocente) > 0){
                    throw CodigoDocenteRepetidoException(codigoDoDocente);
                }
	}

	void LeituraCSV::checaMatriculaDiscenteRepetida(map<long, Discente*> &discentes, long matricula){
            if(discentes.count(matricula) > 0){
                throw MatriculaDiscenteRepetidaException(matricula);
            }
	}

	void LeituraCSV::checaCodigoCursoRepetido(map<int, Curso*> &cursos, int codigoDoCurso) {
		if(cursos.count(codigoDoCurso) > 0){
                    throw CodigoCursoRepetidoException(codigoDoCurso);
                }
	}

	void LeituraCSV::checaCodigoDisciplinaRepetido(map<string, DidaticoAula*> &disciplinas, string codigoDaDisciplina){
                if(disciplinas.count(codigoDaDisciplina) > 0){
                    throw CodigoDisciplinaRepetidoException(codigoDaDisciplina);
                }
	}

	void LeituraCSV::checaDocenteInvalidoEmDisciplina(map<int, Docente*> &docentes, int codigoDoDocente, string nomeDaDisciplina){
            
            if(docentes.count(codigoDoDocente) > 0) return;
            
            throw CodigoDocenteEmDisciplinaInvalidoException(nomeDaDisciplina, codigoDoDocente);
		
	}

	void LeituraCSV::checaDocenteEmOrientacao(map<int, Docente*> &docentes, map<long, Discente*> &discentes, int codigoDoDocente, int matriculaDoDiscente){
		
                if(docentes.count(codigoDoDocente) > 0) return;

		string nome = discentes[matriculaDoDiscente]->getNome();;

		throw CodigoDocenteEmOrientacaoInvalidoException(nome, matriculaDoDiscente);
	}

	void LeituraCSV::checaDocenteEmProducaoCientifica(map<int, Docente*> &docentes, int codigoDoDocente, string tituloDaProducao){
                if(docentes.count(codigoDoDocente) > 0) return;

		throw CodigoDocenteEmPublicacaoInvalidoException(tituloDaProducao, codigoDoDocente);
	}

	void LeituraCSV::checaCursoEmOrientacao(map<int, Curso*> &cursos, map<long, Discente*> &discentes, int codigoDoCurso, long matriculaDoDiscente){
            if(cursos.count(codigoDoCurso) > 0) return;

            string nome = discentes[matriculaDoDiscente]->getNome();

            throw CodigoCursoEmOrientacaoInvalidoException(nome, codigoDoCurso);
	}

	void LeituraCSV::checaCursoEmDisciplina(map<int, Curso*> &cursos, int codigoDoCurso, string nomeDaDisciplina){
            if(cursos.count(codigoDoCurso) > 0) return;
            
            throw CodigoCursoEmDisciplinaInvalidoException(nomeDaDisciplina, codigoDoCurso);
	}

	void LeituraCSV::checaCurso(Curso* curso, bool pg) {
		if (curso->isGraduacao() == pg)
			throw NivelCursoInconsistenteException(curso->getNome(), curso->getCodigo());
	}

	void LeituraCSV::checaData(map<long, Discente*> discentes, string dataDeIngresso, long matriculaDoDiscente){
            time_t now = time(0);
            string dataAtual =  formatDate(now, DATE_FORMAT_PT_BR_SHORT);
            string nome = "";
            Discente* a;
            if (Comparador::timeCompare(dataAtual, dataDeIngresso) < 0) {
                a = (discentes[matriculaDoDiscente]);
                nome = a->getNome();
                throw DataIngressoFuturaException(nome, dataDeIngresso);
            }
	}
    

    // Faz a leitura da planilha de docentes
    // Cria um mapa no qual a chave é o codigo do docente e o valor é um ponteiro para Docente.
	map<int, Docente*> LeituraCSV::leDocentes() {

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
                    
                    //cout << codigo << " " << nome << " " << departamento << endl;

                    checaCodigoDocenteRepetido(docentes, codigo);
                    
                    Docente* docente = new Docente(codigo, nome, departamento);
                    
                    docentes[codigo] = docente;
                }
                stream.close();
                return docentes;
            }
            else {  
                throw IOException();
            }
	}
        
    // Faz a leitura da planilha de discentes
    // Cria um mapa no qual a chave é o codigo do docente e o valor é um ponteiro para Docente.
	map<long, Discente*> LeituraCSV::leDiscentes(){
            ifstream stream(arquivos.getDiscentes());
            
            if (stream.is_open()) {
                map<long, Discente*> discentes;
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
                    //cout << matricula << " " << nome << " " << codigoCurso << endl;
                    
                    codigoCurso++;
                    checaMatriculaDiscenteRepetida(discentes, matricula);
                    
                    Discente* discente = new Discente(matricula, nome);
                    discente->setPosGraduacao(NULL);
                    discentes[matricula] = discente;
                }
                stream.close();
                
                return discentes;
            }
            else {  
                throw IOException();
            }

	}

        
    // Faz a leitura da planilha de producoes cientificas
    // Relaciona com docente, adicionando as producoes a lista de producoes de cada docente
    // Cria um mapa no qual a chave é o codigo do docente e o valor é um ponteiro para ProducaoCientifica
	map<int, ProducaoCientifica*> LeituraCSV::leProducoesCientificas(map<int, Docente*>& docentes){
		
            
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
                    
                    //cout << codigoDocente << " " << tituloDaPublicacao << " " << qualificada << endl;
                    
                    checaDocenteEmProducaoCientifica(docentes, codigoDocente, tituloDaPublicacao);
                    
                    
                    //Instanciamento da producao científica, conexao com docente, e adicionar no mapa
                    ProducaoCientifica* producaoCientifica = new ProducaoCientifica(docentes[codigoDocente], tituloDaPublicacao,
						qualificada);
                    producoesCientificas[codigoDocente] = producaoCientifica;
                    
                    
                    // Conexao do docente com producao
                    docentes[codigoDocente]->addListaProducao(producaoCientifica);
                    
                    
                    
                }
                stream.close();
                return producoesCientificas;
            }
            else {  
                throw IOException();
            }

	}

        
    // Faz a leitura da planilha de cursos
    // Cria um mapa no qual a chave é o codigo do curso e o valor é um ponteiro para Curso
	map<int, Curso*> LeituraCSV::leCursos(){
		
            
            
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
                    bool graduacao = (propriedades.size() > 2 && propriedades[2] == "X") ? true : false;
                    //bool posGraduacao = (propriedades.size() > 3 && propriedades[3] == "X") ? true : false;
                    
                    //cout << codigo << " " << nome << " " << graduacao << endl;
                    
                    checaCodigoCursoRepetido(cursos, codigo);
                    
                    Curso* curso = new Curso(codigo, nome, graduacao);
                    cursos[codigo] = curso;
                    
                    
                    
                    
                }
                stream.close();
                return cursos;
            }
            else {  
                throw IOException();
            }

	}

    // Faz a leitura da planilha de aulas
    // Relaciona com docente, adicionando as aula a lista de aula de cada docente 
    // e adiciona cada docente a lista docentes do curso em que eles lecionam
    // Cria um mapa no qual a chave é o codigo da Aula e o valor é um ponteiro para DidaticoAula
	map<string,DidaticoAula*> LeituraCSV::leDidaticoAulas(map<int, Docente*> &docentes, map<int, Curso*> &cursos){
		
            
            
            ifstream stream(arquivos.getDidaticoAulas());
            
            if (stream.is_open()) {
                map<string, DidaticoAula*> didaticoAulas;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    if(propriedades[0].size() == 0) break;
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
                    
                   // cout << codigo << " " << nome << " " << codigoDocente << " ";
                   // cout << cargaSemanal << " " << cargaSemestral << " " << codigoCurso << endl;
                    
                    //Checa as Excecoes 
                    checaCodigoDisciplinaRepetido(didaticoAulas, codigo);
                    checaDocenteInvalidoEmDisciplina(docentes, codigoDocente, nome);
                    checaCursoEmDisciplina(cursos, codigoCurso, nome);
                    
                    // Instancia uma aula e adiciona no mapa de aulas
                    DidaticoAula* didaticoAula = new DidaticoAula(codigo, nome, docentes[codigoDocente], cargaSemanal, cargaSemestral, cursos[codigoCurso]);
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

        
    // Faz a leitura da planilha de graduacoes
    // Relaciona com docente, adicionando as graduacoes a lista de graduacoes de cada docente e 
    // Linkando o discente com a graduacao
    // Cria um mapa no qual a chave é o codigo do docente e o valor é um ponteiro para Graduacao
	map<long, Graduacao*> LeituraCSV::leGraduacoes(map<int, Docente*>& docentes, map<long, Discente*>& discentes, map<int, Curso*> &cursos) {
		
            ifstream stream(arquivos.getOrientacaoGraducao());
            
            if (stream.is_open()) {
                map<long, Graduacao*> graduacoes;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    if(propriedades[0].size() == 0) break;
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

                   // cout << codigoDocente << " " << matriculaDiscente << " ";
                    //cout << codigoCurso << " " << cargaSemanal << endl;
                    checaDocenteEmOrientacao(docentes, discentes, codigoDocente, matriculaDiscente);
                    checaCursoEmOrientacao(cursos, discentes, codigoCurso, matriculaDiscente);
                    
                    
                    // Instancia a graduacao com suas propriedades e adiciona ao mapa de graduacoes
                    Graduacao* graduacao = new Graduacao(docentes[codigoDocente], discentes[matriculaDiscente], cursos[codigoCurso], cargaSemanal);
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

        
    // Faz a leitura da planilha de pos-graduacoes
    // Relaciona com docente, adicionando as graduacoes a lista de pos-graduacoes de cada docente e 
    // Linkando o discente com a pos-graduacao
    // Cria um mapa no qual a chave é o codigo do docente e o valor é um ponteiro para PosGraduacao    
	map<long, PosGraduacao*> LeituraCSV::lePosGraduacoes(map<int, Docente*>& docentes, map<long, Discente*>& discentes){
		
            
            ifstream stream(arquivos.getOrientacaoPos());
            
            if (stream.is_open()) {
                map<long, PosGraduacao*> posGraduacoes;
                string descartavel;
                getline(stream, descartavel);
                while (stream.good())
                {
                    vector<string> propriedades = leLinha(stream);
                    
                    int codigoDocente;
                    long matriculaDiscente;
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
                    
                   // cout << codigoDocente << " " << matriculaDiscente << " ";
                   // cout << date << " " << programa << " " << cargaSemanal << endl;
                    //Checa as excecoes
                    checaDocenteEmOrientacao(docentes, discentes, codigoDocente, matriculaDiscente);
                    checaData(discentes, date, matriculaDiscente);
                    
                    //Instanciamento da posGraduacao nova e logo em seguida é adicionada no mapa
                    PosGraduacao* posGraduacao = new PosGraduacao(docentes[codigoDocente], discentes[matriculaDiscente], date, programa,
                                    cargaSemanal);
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

