#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
	T* arr; // Puntero al inicio de array
	int max; // Tamaño actual del array ( alterable);
	int n; // Elementos de la lista
	static const int MINSIZE; //Tamaño mínimo de array
	void resize(int new_size)
	{

	  
	  T* narr = new T[new_size];
		int i = 0;
		if( max < new_size ) i = 0;
		else if (max > new_size) i = 1;

		switch(i)
		{
			case 0: 
			        
				for( int j = 0; j < max; j++)
				{
					narr[j] = arr[j];
				};
				while(max < new_size)
				{
					narr[max] = NULL;
					max++;
				};
				break;

			case 1:
			    
				for(int d = 0; d< new_size; d++)
				{
					narr[d] = arr[d];
				};
				break;

		};

			delete[] arr;
			arr = narr; //Actualización de puntero;
			max = new_size;
		};




    public:
       
	
	ListArray()//Creación e inicialización
	{
	arr = new T[MINSIZE];//Crea  array
	T*arr = arr[MINSIZE];
	max = MINSIZE; //Tamaño es minsize;
	n = 0; //Numero de elementos?
	};

	~ListArray()
	{
		delete[] arr;//Destructor
	};

	T operator[](int pos)
	{
	  if(pos < 0 || pos > size()-1) throw std::out_of_range;
		else return arr[pos]; //Devuelve el numero en pos
	};

	friend std::ostream&operator<<(std::ostream &out, const ListArray<T> &list)
	{
		//Imprimir instancia de listarray


	  std::cout<<"Elementos : "<<n<<std::endl;
	  std::cout<<"Tamanyo : "<<size()<<std::endl;
	  std::cout<<"Valores por elemento : ";
	  
	    for (int i = 0; i< size(-1); i++)
	    {
	      std::cout<<"["<<arr[i]<<"]";
	    };
	    std::cout<<std::endl;
	};

        
  void insert (int pos, T e) override
  {
    
    if(pos < 0 || pos > size()-1)
      throw std::out_of_range(" Posicion fuera de rango");
    else{
      for( int c = 0; c < size(); c++)
	{
	  if(n == pos  ) //Está vacío
	    {
	      arr[pos] = e;
	    }
	  //-----------------------------------------------------------------------------------
	}else if ( n < pos)//Hay hueco aún
	   {
	     arr[n] = e;
	   }
      //----------------------------------------------------------------------------------------
      else if( n== pos+1  && (pos > 0 || pos < size()-1) //Esa posición esta ocupada
	{
	  resize (size() +1);
	  
	  for(int i = size(); i > pos; i--)//Subimos a las nuevas posiciones los elementos por encima de pos;
      {
	arr[i] = arr[i-1];
      }
	    arr[pos] = e
	  
	}
	//-------------------------------------------------------------------------------------- 
	  
	}
	else if( n!= 0 && pos == 0) // Si hay elementos pero quiere que sea la pos 0;
	  {
	    preppend ( e);
	  }
      //------------------------------------------------------------------------------------------------
	else if(n+1 == pos  && pos = size()-1)//El numero de elementos es el maximo posible y es al final
	  {
	    append (e);
	  }
    }
    n++;
  };

  
  void append(T e)override
  {
    
    //Puede llamar a resize;
    void resize(size()+1);
    n++;
    arr[max-1] = e;
    
  };
  
  void prepend(T e)override
  {
    
    void resize(size()+1);
    for(int i = size()-1; i >-1; i--)
      {
	if(i > 0)
	  {
	arr[i] = arr[i-1];
      }
	else
	  {
	    arr[i] = e;
	}
      }
    n++
  };
  
  T remove(int pos)override
  {
    
    if(pos <0 || pos> size()-1) throw std::out_of_range("Fuera de rango");
    else
      {
	int b = arr[pos];
	resize( size()-1);
	return b;
      }n--;
  };
  
  T get(int pos)override
  {
     if(pos <0 || pos> size()-1) throw std::out_of_range("Fuera de rango");
     else
       {
	 return arr[pos];
       }
  };
  
  int search(T e)override
  {
    for()int i = 0; i< size(); i++)
    {
      if(arr[i] == e) return i;// recorre el array y si esa posicion coincide pues devuelve.
      else if(i == size())
	{
	  std::cout<<"No se encuentra el valor en el array"<<std::endl;
	  return -1;
	}
    }
  };
  
  bool empty()override
  {
    if(n = 0)
      {
	std::cout<<"Array vacio"<<std::endl;
	return true;
      }
    else
      {
	std::cout<<"Array con elementos"<<std::endl;
	return false;
      }
  };
  
  int size()override
  {
    return n;
  };

};
