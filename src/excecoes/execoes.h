#ifndef EXCECOES_H
#define EXCECOES_H

#include <exception>
#include <string>
#include <cstring>
using namespace std;

namespace excecoes {
    class IOException : public exception
    {
    private:
        string msg;

    public:
        IOException(string message = "Erro de I/O") : msg(message)
        {

        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class ParseException : public exception
    {
    private:
        string msg;

    public:
        ParseException(string message = "Erro de formatação") : msg(message)
        {
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class ClassNotFoundException : public exception
    {
    private:
        string msg;

    public:
        ClassNotFoundException(string message = "") : msg(message)
        {
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class CodigoDocenteRepetidoException : public exception
    {
    private:
        string msg;

    public:
        CodigoDocenteRepetidoException(int codigo)
        {
            msg("Código repetido para docente: " + codigo + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class MatriculaDiscenteRepetidaException : public exception
    {
    private:
        string msg;

    public:
        MatriculaDiscenteRepetidaException(int codigo)
        {
         msg("Código repetido para discente: " + codigo + ".");   
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class CodigoCursoRepetidoException : public exception
    {
    private:
        string msg;

    public:
        CodigoCursoRepetidoException(int codigo)
        {
            msg("Código repetido para curso: " + codigo + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class CodigoDisciplinaRepetidoException : public exception
    {
    private:
        string msg;

    public:
        CodigoDisciplinaRepetidoException(string codigo)
        {
            msg("Código repetido para disciplina: " + codigo + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class CodigoDocenteEmDisciplinaInvalidoException : public exception
    {
    private:
        string msg;

    public:
        CodigoDocenteEmDisciplinaInvalidoException(string nome, int codigo)
        {
            msg("Código de docente inválido na disciplina \"" + nome + "\": " + codigo + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class CodigoDocenteEmOrientacaoInvalidoException : public exception
    {
    private:
        string msg;

    public:
        CodigoDocenteEmOrientacaoInvalidoException(string nome, int codigo)
        {
            msg("Código de docente inválido na orientação do aluno \"" + nome + "\": " + codigo + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class CodigoDocenteEmPublicacaoInvalidoException : public exception
    {
    private:
        string msg;

    public:
        CodigoDocenteEmPublicacaoInvalidoException(string nome, int codigo)
        {
            msg("Código de docente inválido na publicação \"" + nome + "\": " + codigo + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class CodigoCursoEmOrientacaoInvalidoException : public exception
    {
    private:
        string msg;

    public:
        CodigoCursoEmOrientacaoInvalidoException(string nome, int codigo)
        {
            msg("Código de curso inválido na orientação do aluno \"" + nome + "\": " + codigo + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class CodigoCursoEmDisciplinaInvalidoException : public exception
    {
    private:
        string msg;

    public:
        CodigoCursoEmDisciplinaInvalidoException(string nome, int codigo) 
        {
            msg("Código de curso inválido na disciplina \"" + nome + "\": " + codigo + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class NivelCursoInconsistenteException : public exception
    {
    private:
        string msg;

    public:
        NivelCursoInconsistenteException(string nome, int codigo) 
        {
            msg("Inconsistência ao definir o nível do curso: " + codigo + " - " + nome + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };

    class DataIngressoFuturaException : public exception
    {
    private:
        string msg;

    public:
        DataIngressoFuturaException(string nome, string data)
        {
            msg("Data de ingresso do aluno \"" + nome + "\" está no futuro: "
				+ data + ".");
        }

        const char * what() const throw()
        {
            return msg.c_str();
        }
    };
}
#endif