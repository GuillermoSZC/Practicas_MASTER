#pragma once

void* mOpenFile(const char*, const char*);
unsigned int mReadFile(void*);
const char* mWriteFile(void*, const char*, unsigned int);
unsigned int mNumOfStrings(void*, char*);
unsigned int mSumaNumeros(void*);
void mCloseFile(void*);