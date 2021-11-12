#pragma once

void* mOpenFile(const char*, const char*);
unsigned int mReadFile(void*, char*, char*&);
const char* mWriteFile(void*, const char*, unsigned int);
unsigned int mNumOfStrings(void*, char*, char*&);
void mCloseFile(void*);