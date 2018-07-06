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
        Docente* getDocente();
        void setDocente(Docente* docente);
    };
    
}

#endif /* ATIVIDADE_H */

