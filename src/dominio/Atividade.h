#ifndef ATIVIDADE_H
#define ATIVIDADE_H



namespace dominio
{
    class Docente;
    class Atividade
    {
    protected:
       int CHSemanal;
       Docente* docente;
        
    public:
        int getCHSemanal();
        virtual Docente* getDocente() = 0;
        virtual void setDocente(Docente& docente) = 0;
    };
    
}

#endif /* ATIVIDADE_H */

