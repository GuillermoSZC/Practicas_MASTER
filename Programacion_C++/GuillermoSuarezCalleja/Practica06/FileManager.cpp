#include"FileManager.h"
#include<string>

void* FileManager::mOpenFile(const char* _cName, const char* _cMode)
{
	FILE* file;
	fopen_s(&file, _cName, _cMode);

	return file;
}

unsigned int FileManager::mReadFile(void* _vFile)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	unsigned int uiNumChars(0);
	unsigned int uiNum(0);
	char* cBuffer;

	fseek(file, 0, SEEK_END);
	uiNum = ftell(file) + 1;
	rewind(file);

	cBuffer = new char[uiNum];

	uiNumChars = fread(cBuffer, 1, uiNum - 1, file);
	*(cBuffer + uiNumChars) = '\0';

	//std::cout << "Buffer read: " << _cAux << std::endl;
	delete[] cBuffer;
	cBuffer = nullptr;
	mCloseFile(_vFile);

	return uiNumChars;
}

const char* FileManager::mWriteFile(void* _vFile, const char* _cBuffer, unsigned int _uiSize)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	fwrite(_cBuffer, 1, _uiSize, file);
	mCloseFile(_vFile);

	return _cBuffer;
}

unsigned int FileManager::mNumOfStrings(void* _vFile, char* _cadena)
{
	// En esta Funcion solo va a contar con la palabra exacta pasada por parametro, es decir
	// si en el fichero hay alguna palabra con algun caracter al lado no la cuenta, ejemplo: 
	// param:(Hello) - file: (aHello - Helloa - hello - palabraHello) no contaria 
	// Si param es Hello y en fichero encuentra un Hello exacto si lo cuenta
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	char* cBuffer;
	unsigned int uiNumChars(0);
	unsigned int uiNum(0);
	unsigned int uiSuma_(0);
	unsigned int uiAux(0);
	unsigned int uiSizeCad = strlen(_cadena);
	bool val = true;

	fseek(file, 0, SEEK_END);
	uiNum = ftell(file) + 1;
	rewind(file);

	cBuffer = new char[uiNum];

	uiNumChars = fread(cBuffer, 1, uiNum, file);
	*(cBuffer + uiNumChars) = '\0';

	for (int i = 0; *(cBuffer + i) != '\0'; ++i)
	{
		if (*(cBuffer + i) != ' ' && *(cBuffer + i) != '\n')
		{
			if (*(cBuffer + i) == *(_cadena + uiAux))
			{
				++uiAux;
				if (uiAux == uiSizeCad)
				{
					if (
						(*(cBuffer + i + 1) == ' ' || *(cBuffer + i + 1) == ','
							|| *(cBuffer + i + 1) == '.' || *(cBuffer + i + 1) == '\n'
							|| *(cBuffer + i + 1) == '\0')
						&&
						(*(cBuffer + i - uiSizeCad) == ' '
							|| *(cBuffer + i - uiSizeCad) == ',' || *(cBuffer + i - uiSizeCad) == '.'
							|| *(cBuffer + i - uiSizeCad) == '\n'))
					{
						++uiSuma_;
						uiAux = 0;
						// 							std::cout << "principio 1: " << *(buffer + i - iSizeCad) << std::endl;
						// 							std::cout << "posicion: " << i << std::endl;
					}
					else
					{
						uiAux = 0;
					}
				}
			}
		}
	}

	for (unsigned int i = 0; i < uiSizeCad; ++i)
	{
		if (*(cBuffer + i) != *(_cadena + i))
		{
			val = false;
		}
	}
	// std::cout << "FINAL: '" << *(buffer + iSizeCad) << "'" << std::endl;
	if (*(cBuffer + uiSizeCad) != ' ' && *(cBuffer + uiSizeCad) != ','
		&& *(cBuffer + uiSizeCad) != '.')
	{
		val = false;
	}

	if (val)
	{
		++uiSuma_;
	}

	delete[] cBuffer;
	cBuffer = nullptr;
	mCloseFile(_vFile);

	return uiSuma_;
}

unsigned int FileManager::mSumaNumeros(void* _vFile)
{
	// En esta funcion solo va a sumar los numeros que esten separados por una coma
	// Si hay numeros sueltos no los sumará
	FILE* file(reinterpret_cast<FILE*>(_vFile));
	unsigned int uiSum_(0);
	unsigned int uiNum(0);
	unsigned int uiNumChars(0);
	unsigned int uiValComma(1);
	char* cBuffer;
	std::string sCad;
	bool bSemaph = false;

	fseek(file, 0, SEEK_END);
	uiNum = ftell(file) + 1;
	rewind(file);

	cBuffer = new char[uiNum];

	uiNumChars = fread(cBuffer, 1, uiNum, file);
	*(cBuffer + uiNumChars) = '\0';

	for (unsigned int i = 0; i < uiNumChars + 1; ++i)
	{
		if ((*(cBuffer + i) >= 48 && *(cBuffer + i) <= 57)) // 48 en ASCII es 0 y 57 en ASCII es 9
		{
			bSemaph = true;
			sCad += *(cBuffer + i); // Concateno cada numero leido
			uiValComma++;
			// std::cout << sCad << std::endl;
		}
		else
		{
			if (bSemaph)
			{
				if (*(cBuffer + i - uiValComma) == ',' || *(cBuffer + i) == ',')
				{
					//std::cout << "else: '" << *(cBuffer + i) << "'" << std::endl;
					uiSum_ += stoi(sCad); // sCad se castea a un int se va sumando con cada numero que vaya teniendo anteriormente uiNum
					sCad = "";
					uiValComma = 1;
					bSemaph = false;
				}
				else
				{
					sCad = "";
				}
			}
		}
	}

	delete[] cBuffer;
	cBuffer = nullptr;
	mCloseFile(_vFile);

	return uiSum_;
}

void FileManager::mCloseFile(void* _vFile)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));
	// std::cout << "File closed." << std::endl;

	fclose(file);
}