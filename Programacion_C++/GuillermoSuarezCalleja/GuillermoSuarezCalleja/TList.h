#pragma once

namespace Tool
{
	class TList
	{
	private:

		struct Node
		{
			unsigned int m_id;
			const char* m_Value;
			Node* m_NextPtr;
			Node* m_Prev;

			Node(const char* value) : m_Value(value), m_NextPtr(nullptr), m_Prev(nullptr), m_id(0) {}
		};

		TList::Node* m_Head = nullptr;
		TList::Node* m_Tail = nullptr;
		TList::Node* m_Iterator = nullptr;
		unsigned int m_ListSize = 0;

	public:

		/*Constructors*/
		TList(const TList& other);
		TList() = default;
		/*Methods*/

		int Size();
		int Push(const char* psz);
		const char* First();
		const char* Next();
		const char* Pop();
		void Reset();
		void ShowList();

		static TList GetReverseList(TList lstSrc)
		{
			TList m_Temp = lstSrc;
			TList m_Next, m_Prev;

			while (m_Temp.m_Head != nullptr)
			{
				m_Prev.m_Head = m_Temp.m_Head->m_NextPtr;
				m_Temp.m_Head->m_NextPtr = m_Next.m_Head;

				m_Next.m_Head = m_Temp.m_Head;
				m_Temp.m_Head = m_Prev.m_Head;
			}

			lstSrc.m_Head = m_Next.m_Head;

			//Ajustamos el id de cada elemento.
			unsigned int i = 0;
			while (m_Next.m_Head)
			{
				m_Next.m_Head->m_id = i;
				m_Next.m_Head = m_Next.m_Head->m_NextPtr;
				i++;
			}

			return lstSrc;
		}
	};

}