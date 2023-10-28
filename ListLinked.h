#include <ostream>
#include <iostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T>
{

    private:

  Node<T> *first;
  int n;
        
    public:


  ListLinked()
 {
   first = nullptr;
   n = 1;
 }

~ListLinked()
  {
    Node<T> *aux = nullptr; //Creamos un puntero auxiliar que apunta a null;
    while(aux != nullptr)//Mientras este no apunte a null, es decir, mientras haya nodos:
      {
	aux = first->next; //Equivalente a aux = aux->next
        delete[] first; //Borra first
	first = aux; //Ahora first es aux y apuntan al mismo lado, por eso al repetir bucle ahora aux apunta al siguiente
      }
    n = 0; //No hay elementos ahora
  }

 T operator[](int pos)
 {
   if(pos<0 || pos>n-1)
   {
     throw std::out_of_range("Fuera de rango");
   }
   else
     {
       Node<T> *aux = first; //Creamos el auxiliar que apunta al primer elemento
       for(int i = 0; i<pos; i++)
	 {
	   aux = aux->next; //Avanzo aux al siguiente nodo y cuando acaba el bucle, aux apunta al nodo de la pos que toca.
	 }
       return aux->data;
        
     }   
 }


  
 friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list)
 {
   Node<T> *aux = list->first;
   while(aux !=nullptr)
     {
       std::cout<<"Elemento : "<< list->n<<"Posicion : "<<(list->n-1)<< "Valor almacenado : " << aux->data << std::endl;
       aux = aux->next;
     }
   return out;
 }

  //---------------------------------------- MÉTODOS DE LIST.H -----------------------------------------------------------\\




  
  void insert (int pos, T e) override
  {
    
    if(pos < 0 || pos > n-1)
      throw std::out_of_range(" Posicion fuera de rango");
    
    else{
      
      if(pos == 0)//Posicion es al inicio, osea 0, entonces preppend
	{
	  first = new Node(e, first);
	 n++;
	}
      if(pos == n-1)//posicion es al final, append
	{
      	Node<T> *aux = first;
	while( aux != nullptr)
	  {
	    aux = aux->next; //Cuando salga del bucle entonces está en el final
	  }
	aux->next = new Node(e);//El siguiente de aux será un nuevo nodo al final de la secuencia
	n++;
	}
      else//Cualquier otra dentro del rango
	{
	Node<T> *aux = first; //Creamos el auxiliar que apunta al primer elemento e irá hasta pos
	Node<T> *ant = first; //Creamos otro auxiliar que irá a la posición pos--
       for(int i = 0; i<pos; i++)
	 {
	   aux = aux->next; //Avanzo aux al siguiente nodo y cuando acaba el bucle, aux apunta al nodo de la posicion.
	 }

       for(int i = 0; i<pos-1; i++)
	 {
	   ant = ant->next; // Avanzo sig al siguiente nodo y cuando acaba el bucle, sig apunta al nodo de la posicion anterior a la que toca.
	 }

       ant->next = new Node(e,aux); //Nodo que ocupa la posicion pos y apunta al que la ocupaba (aux);

 
	}
      
      n++; }
   
  }

  
  void append(T e)override
  {
    if(n == 0)throw std::exception("No existe una lista aún");
    
    if(n == 1)//Lista iniciada pero sin nada
      {
	first = new Node(e);
      }
    else
      {
	Node<T> *aux = first;
	while( aux != nullptr)
	  {
	    aux = aux->next; //Cuando salga del bucle entonces está en el final
	  }
	aux->next = new Node(e);//El siguiente de aux será un nuevo nodo al final de la secuencia
	n++;//Incremento de numero de elementos

      }
   
   
  }
  
  void prepend(T e)override
  {
     if(n == 0)throw std::exception("No existe una lista aún");
     if(n == 1)//Lista iniciada pero sin nada
      {
	first = new Node(e);
      }
     else
       {
	 first = new Node(e, first);
	 n++;
       }
   
    
    }

  
  T remove(int pos)override
  {
    
    if(pos <0 || pos> n-1) throw std::out_of_range("Fuera de rango");
    else
      {
	Node<T> *aux = first; //Creamos el auxiliar que apunta al primer elemento e irá hasta pos--
	Node<T> *ant = first; //Creamos otro auxiliar que irá a la posición pos++
       for(int i = 0; i<pos; i++)
	 {
	   aux = aux->next; //Avanzo aux al siguiente nodo y cuando acaba el bucle, aux apunta al nodo de la posicion.
	 }

       for(int i = 0; i<pos-1; i++)
	 {
	   ant = ant->next; // Avanzo sig al siguiente nodo y cuando acaba el bucle, sig apunta al nodo de la posicion antterior a la que toca.
	 }
      
       ant->next = aux->next; // Que el anterior apunte al siguiente del que queremos quitar.
	int resultado = aux->data;
       delete[] aux;
       
      
    n--;
    return resultado;
      }
  }

  
  
  T get(int pos)override
  {
     if(pos <0 || pos> n-1) throw std::out_of_range("Fuera de rango");
     else
       {
	  Node<T> *aux = first; //Creamos el auxiliar que apunta al primer elemento
       for(int i = 0; i<pos; i++)
	 {
	   aux = aux->next; //Avanzo aux al siguiente nodo y cuando acaba el bucle, aux apunta al nodo de la pos que toca.
	 }
       return aux->data;
       }
  }
  
  int search(T e)override
  {
    Node<T> *aux = first;
    int pos = 0; //Inicializamos un puntero que vamos a mover y una variable de posición
   while(aux !=nullptr)
     {
       if(aux->data == e) return pos;//Si el valor coincide, devuelve la posición
       pos++;
       aux = aux->next;//Si no, incrementa la posición y el puntero.
     }
   return -1;
  }
  
  bool empty()override
  {
    if(n == 0) return true;
    else return false;
  }
  
  int size()override
  {
    return n;
  }





};









  
       
