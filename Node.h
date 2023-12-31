#include <ostream>
#include <iostream>
template <typename T> 
class Node {
  
	public:
  T data;
  Node<T>* next;

  Node( T data, Node<T>* next =nullptr)//Constructor de Node
    {
      this->data = data;
      if(next != nullptr) this->next = next;
      else this->next = nullptr;
    }

  friend std::ostream&operator<<(std::ostream & out, const Node<T> &node)
  {
    //Impresión de la instancia del nodo
    std::cout<<"Nodo con valor : "<<node.data<<std::endl; //No sé si es node->data, node.data o data
	return out;					    
  }
  

};
