#include "Arraylist.h"
#define AL_INCREMENT 10

int al_add(ArrayList* pList,void* pElement)
{
    int returnAux=-1, flag=0;
    void** aux;

    if(this!=NULL && pElement!=NULL)
    {
        if(this->size==this->reservedSize) //Si quiero cargar mas datos de los que elegi por defecto voy a hacer realloc
        {
            aux= (void**) realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT));
            if(aux!=NULL)
            {
                this->pElements = aux;
                this->reservedSize = this->reservedSize + AL_INCREMENT;
            }
            else
            {
                flag=1;
            }
        } //Esta funcion es resize up, despues la llamo, tambien la necesito para al_push, etc...

        //Con el size podemos saber en que posicion vamos a cargar la estructura
        if(flag==0) //Si pudo agregar el elemento entonces hago lo siguiente:
        {
            this->pElements=pElement[this->size] = pElement;
            this->size++; //Para que cuando tenga que cargar otro elemento no me lo pise
            returnAux=0;
        }

    }

    return returnAux;
}
