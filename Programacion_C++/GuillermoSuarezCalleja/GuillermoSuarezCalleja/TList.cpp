#include "TList.h"
#include <iostream>

using namespace Tool;

TList::TList(const TList& other)
{
	TList::Node* node = other.m_Head;
	while (node != nullptr)
	{
		Push(node->m_Value);
		node = node->m_NextPtr;
	}
}

int TList::Size() {
	return printf("\nList size: %d\n", m_ListSize);
}

int TList::Push(const char* psz)
{
	TList::Node* newNode = new TList::Node(psz);

	newNode->m_id = m_ListSize;
	newNode->m_NextPtr = nullptr;
	newNode->m_Prev = m_Tail;

	if (!m_Head)
	{
		m_Head = newNode;
	}

	else
	{
		m_Tail->m_NextPtr = newNode;
	}

	m_Tail = newNode;
	m_Iterator = m_Head;

	m_ListSize++;

	return 0;
}

const char* TList::First() {

	if (m_Head != NULL)
	{
		return m_Head->m_Value;
	}
	else
	{
		return "Not found";
	}
}

const char* TList::Next()
{
	TList::Node* temp = nullptr;

	if (m_Iterator->m_NextPtr != NULL)
	{
		m_Iterator = m_Iterator->m_NextPtr;
		temp = m_Iterator;
		return temp->m_Value;
	}

	else
	{
		m_Iterator = m_Head;
		temp = m_Iterator;
		return temp->m_Value;
	}
}

const char* TList::Pop()
{
	TList::Node* p_Temp = nullptr;
	TList::Node* p_Temp02 = nullptr;

	if (m_Head != nullptr)
	{
		p_Temp02 = m_Head;
		p_Temp = m_Head->m_NextPtr;

		m_Head = p_Temp;
		m_ListSize--;

		for (unsigned int i = 0; i < m_ListSize; i++)
		{
			p_Temp->m_id = i;
			p_Temp = p_Temp->m_NextPtr;
		}

		return p_Temp02->m_Value;
	}
	else
	{
		return "Not found";
	}


}

void TList::Reset()
{
	delete m_Head;
	m_Head = nullptr;

	m_ListSize = 0;

	printf("\nLista eliminada");
}

void TList::ShowList()
{
	//Copiamos la lista para mostrarla y asi no modificar nada.
	TList m_Size;
	m_Size.m_Head = m_Head;

	printf("List: \n");

	while (m_Size.m_Head != NULL)
	{
		printf("Element %d -> %s\n", m_Size.m_Head->m_id, m_Size.m_Head->m_Value);
		m_Size.m_Head = m_Size.m_Head->m_NextPtr;
	}
}