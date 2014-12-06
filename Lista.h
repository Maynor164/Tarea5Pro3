#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;

//Trabajo en grupo realizado con
//Kevin Lanza
//Iveth Sabillon
//Merary Fernandez
template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
//Tomando referencia de http://blog.alguien.at/2010/12/lista-enlazada-simple-en-cc.html
//Linea de codigo 77
{
//Creamos un ciclo para evaluar si el nuestra variable de inicio esta vacia si lo esta muestra true de lo contrario false
     if(inicio == NULL)
        {
            return true;
        }
     return false;
}

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
//Regresamos el primer valor de nuestro nodo
    return inicio->valor;
    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
{
//Creamos un nodo que empiece en inicio
   Nodo<Tipo>*temp = inicio;
//Usamos el ciclo para recorrer la lista
    while(temp->sig!=NULL)
    {
        temp= temp->sig;
    }
//Regresamos el valor que almacenamos en nuestra variable temporal
    return temp->valor;

}
    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
 {
//Creamos un nodo que empiece en inicio
    Nodo<Tipo>*temp = inicio;
//Creamos una variable de valor pequeño para evaluarla con la de nuestra lista
    int mayor = -9999;
//Creamos el ciclo en el cual comparamos si el nuestro valor temporal(de la lista) es mayor al nuestra variable
//si lo es almacena el valor en la variable mayor y evalua los otros valores temporales y retorna el valor mayor
    while(temp!=NULL)
        {
            if(mayor<temp->valor)
            {
                mayor = temp->valor;
            }
            temp=temp->sig;
        }
        return mayor;
 }
};
#endif // LISTA_H
