#include <iostream>

class CBase
{
  int num;
public:
  CBase() 
  { 
    num = 0; 
    function1(); // para el apartado d)
  }
  virtual ~CBase() 
  {
    printf("Objeto clase base borrado.\n"); 
  }
  virtual void function1() 
  { 
    printf("Funcion virtual de la clase Base.\n"); 
  }
  virtual void function2() {}
};

class CHija : public CBase
{
public:
  CHija() 
  {
    function1(); // para el apartado d)
  }
  ~CHija() override
  {
    printf("Objeto clase Hija borrado.\n");
  }

  void function1() override 
  { 
    printf("Funcion virtual desde la clase hija.\n"); 
  }
};

class CNoVirtual
{
  int num;
public:
  CNoVirtual() { num = 0; }
  ~CNoVirtual()
  {
    printf("Objeto de la clase 'CNoVirtual' borrado.\n");
  }
  void function() 
  {
    printf("Funcion NO virtual de la clase 'CNoVirtual'\n"); 
  }
};

int main()
{
  CBase* objBase = new CBase();
  CHija* objHija = new CHija();
	CNoVirtual* objNoVirtual = new CNoVirtual();

// Si se hace un cast a int** del objeto de la clase base podemos acceder a su direccion de memoria.
  
  int** pVTable = reinterpret_cast<int**>(objBase);
  printf("Direccion de memoria de la VTable: 0x%08X\n", reinterpret_cast<int>(*pVTable));
  // a) ¿Cuánto espacio ocupa la tabla de funciones virtuales?
  /*
    La vtable ocupa 4 bytes por cada metodo virtual, es decir
    si tiene 2 metodos virtuales ocuparia 8 bytes.
  */

  // b) ¿Dónde está situada la tabla de funciones virtuales?
  /*
    Se encuentra en una zona de memoria estática en el ejecutable.
  */

	// c) ¿Cuánto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales ?
  /*
    Ocupa 4 bytes más de diferencia.
  */
  std::cout << "\nObjeto clase virtual: " << sizeof(*objBase) << " bytes.\n";
  std::cout << "Objeto clase NO virtual: " << sizeof(*objNoVirtual) << " bytes.\n";
  
  // d) ¿Qué pasa si llamo a un método virtual desde el constructor?
  /*
    Que deja de ser virtual, la llamada nunca irá a una clase derivada 
    con el constructor que se está ejecutando en ese momento.
  */

	/* 
		e) Comparar la llamada a una función virtual con la llamada a una función no
		virtual.¿Cuántos pasos adicionales tienen que realizarse para llamar a una
		función cuando esta es virtual ?
  */
  /*
    Se realiza un paso más desde la llamada de un método virtual, 
    ya que tiene que buscar el método a través de la vtable
  */

	printf("\n\n");
  objBase->function1();
  objHija->function1();
  objNoVirtual->function();

	printf("\n\n");
	delete objNoVirtual;
	objNoVirtual = nullptr;
	delete objHija;
	objHija = nullptr;
  delete objBase;
  objBase = nullptr;
  
  return 0;
}