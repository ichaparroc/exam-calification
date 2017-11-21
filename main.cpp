#include<iostream>
#define N_PREG 60

using namespace std;

int main(void)
{
  int n_instancias,n_cursos,preg_curso[60],n_postulantes,nota_total,buenas_curso,puntero;
  char clave[N_PREG+1];
  char respuesta[N_PREG+1];
  cout<<" PROGRAMA DE CALIFICACION DE EXAMENES POR CURSO "<<endl;
  cout<<"================================================"<<endl<<endl;
  cout<<"Ingrese la cantidad de cursos: ";cin>>n_cursos;
  int suma=0;
  for(int i=0;i<n_cursos;i++)
  {
    cout<<"Cantidad de preguntas del curso "<<i<<" :";cin>>preg_curso[i];
  	suma+=preg_curso[i];
  }
  if(N_PREG!=suma)
  {
  	cout<<"Error no coinciden cantidad de preguntas";
  	return 0;
  }
  cout<<"Ingrese la clave de respuestas: ";cin>>clave;
  cout<<"Ingrese el nro de postulantes: ";cin>>n_postulantes;
  for(int i=0;i<n_postulantes;i++)
  {
    cout<<"Ingrese Respuesta"<<i<<": ";
    for(int i=0;i<N_PREG;i++)
    	cin>>respuesta[i];
    nota_total=0;
    puntero=0;
    for(int j=0;j<n_cursos;j++)
    {
      buenas_curso=0;
      for(int k=puntero;k<puntero+preg_curso[j];k++)
      {
        if(respuesta[k]==clave[k] || clave[k]=='*')
        {
          nota_total+=10;
          buenas_curso++;
        }
        else
        {
          if(respuesta[k]=='_')
            nota_total++;
		}
        //cuando la clave dice *
      }
      cout<<";"<<(float)buenas_curso/preg_curso[j];
      puntero+=preg_curso[j];
    }
    cout<<";"<<nota_total<<endl;
  }
}
