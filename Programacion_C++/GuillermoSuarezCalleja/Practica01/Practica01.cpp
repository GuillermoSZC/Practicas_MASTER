#include<iostream>

#define MASK_1_BYTE 0x000000FF
#define MASK_2_BYTE 0x00FF0000
#define MASK_3_BYTE 0xFF00FFFF
#define MASK_4_BYTE 0x0000000F
#define MASK_5_BYTE 0x00000001
#define MASK_6_BYTE 0xFFFFFFF14 // PREGUNTAR [14?]

// Prototipos de Funciones
int GetBalas(unsigned int);
void SumarBalas(unsigned int*, int);
int GetCompa(unsigned int);
bool balasInf(unsigned int);
void activarBalasInf(unsigned int*, bool);

int main()
{
  int iCantidadBalas = 0, iVal = 0;
  unsigned int uiNum(2908121815); // HEX - AD566AD6 
  unsigned int* piNum = reinterpret_cast<unsigned int*>(&uiNum);

  printf("%s\n","Cuantas balas quieres anadir?");
  scanf_s("%d", &iCantidadBalas);

  printf("Numero de balas: %d\n", GetBalas(uiNum));
  SumarBalas(piNum, iCantidadBalas);
  printf("Numero de companeros: %d\n", GetCompa(uiNum));

  if (balasInf(uiNum))
  {
    printf("%s\n", "El modo balas infinitas esta activado.");
  }
  else
  {
    printf("%s\n", "El modo balas infinitas esta desactivado.");
  }

  printf("%s\n", "Quieres activar o desactivar el modo balas infinitas? 1 Y - 0 N");
  scanf_s("%d", &iVal);
  if (iVal) 
  {
    activarBalasInf(piNum, balasInf(uiNum)); // Metodo para activar o desactivar modo balas inf
  }
} // MAIN

int GetBalas(unsigned int _uData) 
{
  int iNumBalas(_uData >> 16);
  iNumBalas = _uData >> 16; // Se mueven a la derecha los bits para conseguir: 0xXXXX054D
  iNumBalas &= MASK_1_BYTE; // AND para borrar los bits que no interesan

  return iNumBalas;
}

void SumarBalas(unsigned int* _uData, int _uCant)
{
  unsigned int iValue(*_uData);
  iValue &= MASK_2_BYTE;
  iValue >>= 16;
  iValue += _uCant;
  // printf("%d\n", iValue);
  iValue <<= 16;
  *_uData &= MASK_3_BYTE;
  *_uData |= iValue;
  printf("%d", _uCant);
  printf("%s\n", " balas anadidas.");
  printf("%d", GetBalas(*_uData));
  printf("%s\n", " balas totales.");
}

int GetCompa(unsigned int _uData)
{
  unsigned int aux(_uData>>12);
  aux &= MASK_4_BYTE;
  return aux;
}

bool balasInf(unsigned int _uData) 
{
  int aux(_uData);
  aux &= MASK_5_BYTE;
  // printf("%d\n", aux);
  return (aux == 1) ? true : false;
}

void activarBalasInf(unsigned int* _uData, bool _bVal) 
{
  int aux(*_uData);
  if (_bVal)
  {
    aux &= MASK_6_BYTE;
    *_uData &= aux;
    printf("%s\n", "Modo balas infinitas desactivado.");
  }
  else
  {
    aux &= MASK_5_BYTE;
    *_uData |= aux;
    printf("%s\n", "Modo balas infinitas activado.");
  }
}