#include <iostream>
#include <fstream>

using namespace std;

struct llamadas
{
  int horas, minutos, segundos, duracion;
  int cant, codigo;
  llamadas *next;
};

llamadas *AgregarNodo (llamadas * f);
void BorrarLista (llamadas * f);
void MostrarLista (llamadas * f);
llamadas *LeerArchivo (int &error, int &lineas);
void CantTiemp (llamadas * f, int lineas, int &cant1, int &cant2, int &cant3,
		float &tiemp1, float &tiemp2, float &tiemp3);
void Monto (llamadas * f, int lineas, float &m1, float &m2, float &m3,
	    float tiemp1, float tiemp2, float tiemp3);


int
main (void)
{

  int error = 0, i = 0, cantidad = 0;
  llamadas *datos = NULL;
  int cantidad1, cantidad2, cantidad3;
  float tiempo1, tiempo2, tiempo3;
  float monto1, monto2, monto3;

  datos = LeerArchivo (error, cantidad);
  if (error)
    {
      cerr << "Problemas con el archivo" << endl;
    }
  else
    {
      cout << "Se leyeron: " << cantidad << " lineas." << endl;
      CantTiemp (datos, cantidad, cantidad1, cantidad2, cantidad3, tiempo1,
		 tiempo2, tiempo3);

      cout << "Cantidad de llamadas '1': " << cantidad1 << "\tduracion: " <<
	tiempo1;
      cout << "\tCantidad de llamadas '2': " << cantidad2 << "\tduracion: " <<
	tiempo2;
      cout << "\tCantidad de llamadas '3': " << cantidad3 << "\tduracion: " <<
	tiempo3 << endl;

      Monto (datos, cantidad, monto1, monto2, monto3, tiempo1, tiempo2,
	     tiempo3);

      cout << "Monto total del tipo '1':$ " << monto1;
      cout << "\tMonto total del tipo '2':$ " << monto2;
      cout << "\tMonto total del tipo '3':$ " << monto3 << endl;



      return error;

    }
}

llamadas *
AgregarNodo (llamadas * f)
{
  llamadas *ult = NULL, *aux = NULL;

  aux = new llamadas;
  if (aux != NULL)
    {
      aux->next = NULL;
      if (f != NULL)
	{
	  while (f != NULL)
	    {
	      ult = f;
	      f = f->next;
	    }
	  ult->next = aux;
	}
    }


  return aux;
}

void
BorrarLista (llamadas * f)
{
  llamadas *aux = NULL;

  while (f != NULL)
    {
      aux = f;
      f = f->next;
      delete aux;
    }
}

void
MostrarLista (llamadas * f)
{
  while (f != NULL)
    {
      cout << f->horas << " " << f->minutos << " " << f->segundos << " " <<
	" " << f->duracion << " " << f->codigo << endl;
      f = f->next;
    }
}

llamadas *
LeerArchivo (int &error, int &lineas)
{
  int i = 0, tmp = 0;
  char nombre[30];
  ifstream entrada;
  llamadas *pri = NULL, *aux = NULL;

  cout << "Ingrese el nombre del archivo: " << endl;
  cin >> nombre;

  entrada.open (nombre);
  if (entrada.fail ())
    {
      error = 1;
    }
  else
    {
      while ((!entrada.eof ()) && (!error))
	{
	  aux = AgregarNodo (pri);
	  if (aux == NULL)
	    {
	      error = 2;
	    }
	  else
	    {
	      if (pri == NULL)
		{
		  pri = aux;
		}
	      lineas++;
	      aux->horas = tmp;
	      entrada >> aux->minutos >> aux->segundos >> aux->
		duracion >> aux->codigo >> tmp;
	    }
	}
      entrada.close ();
    }

  return pri;
}


void
CantTiemp (llamadas * f, int lineas, int &cant1, int &cant2, int &cant3,
	   float &tiemp1, float &tiemp2, float &tiemp3)
{
  int i = 0, total = 50 * lineas;
  for (i = 1; i < total; i++)
    {
      if (f->codigo == 1)
	{
	  cant1++;
	  tiemp1 += f->duracion;
	}
      if (f->codigo == 2)
	{
	  cant2++;
	  tiemp2 += f->duracion;
	}
      else
	{
	  cant3++;
	  tiemp3 += f->duracion;
	}
    }
}

void
Monto (llamadas * f, int lineas, float &m1, float &m2, float &m3,
       float tiemp1, float tiemp2, float tiemp3)
{

  int i = 0, total = 50 * lineas;
  for (i = 1; i < total; i++)
    {
      m1 = 0.1 * tiemp1;
      m2 = 0.025 * tiemp2;
      m3 = 0.045 * tiemp3;
    }
}
