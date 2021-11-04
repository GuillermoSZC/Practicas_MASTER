// practica4.cpp
//
#include <stdio.h>
#include <consola.h>

struct TEntity;
typedef void (*funcEntity)(TEntity *);


// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity *m_funcs;
	TEntity(funcEntity *funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};


void DrawA(TEntity* _pEntity) {
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("A");
}

void DrawB(TEntity* _pEntity) {
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("B");
}

void MoveRight(TEntity* _pEntity) {
	_pEntity->m_ix++;
}

void MoveRightDown(TEntity* _pEntity) {
	_pEntity->m_ix++;
	_pEntity->m_iy--;
}

/*void MoveLeft(TEntity* _pEntity) {
	_pEntity->m_ix--;
}*/

/*void MoveLeftDown(TEntity* _pEntity) {
	_pEntity->m_ix--;
	_pEntity->m_iy--;
}*/

/*void MoveLeftUp(TEntity* _pEntity) {
	_pEntity->m_ix--;
	_pEntity->m_iy++;
}*/

/*void MoveRightUp(TEntity* _pEntity) {
	_pEntity->m_ix++;
	_pEntity->m_iy++;
}*/

/*void MoveDown(TEntity* _pEntity) {
	_pEntity->m_iy--;
}*/

/*void MoveUp(TEntity* _pEntity) {
	_pEntity->m_iy++;
}*/

void checkLimits(TEntity* _pEntity) {
	if (_pEntity->m_ix > 30) {
		_pEntity->m_ix = 0;
	}
	else if (_pEntity->m_ix < 0) {
		_pEntity->m_ix = 29;
	}
	if (_pEntity->m_iy > 30) {
		_pEntity->m_iy = 0;
	}
	else if (_pEntity->m_iy > 0) {
		_pEntity->m_iy = 29;
	}
} 

// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main(int argc, char* argv[])
{
	funcEntity oFunc01[2] =
	{ &DrawA, MoveRight };

	funcEntity* pFunc02 = new funcEntity[2];
	pFunc01[0] = &DrawB;
	pFunc01[1] = &MoveRightDown;


	TEntity aEntities[] =
	{
		TEntity (oFunc01, 0, 0);
		TEntity (oFunc02, 4, 4);
	}

	unsigned int const uNumEntities = sizeof(aEntities) / sizeof(TEntity);

	while (true) {
		for (TEntity& rEntity : aEntities) {
			// Move
			(*rEntity.m_funcs + 1)(&rEntity);
			checkLimits(&rEntity);
			// Draw
			(*rEntity.m_funcs)(&rEntity);
		}
		hidecursor();
		Sleep(500);
		clear();
	}

	
	
}

