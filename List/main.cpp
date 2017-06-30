#include <bits/stdc++.h>

using namespace std;

template <class T>
class SequentialList
{
public:
    SequentialList(void)
    {
        m_BufLength = m_InitLength;
        m_pBuf = new T[m_BufLength];
        m_Count = 0;
    }

    void Add(T item)
    {
        if(m_Count < m_BufLength)
        {
            m_pBuf[m_Count] = item;
            m_Count++;
        }
        else
        {
            T * temp = new T[m_BufLength + m_Increment];
            for(int i = 0; i < m_Count; i++)
            {
                temp[i] = m_pBuf[i];
            }
            temp[m_Count] = item;
            m_Count++;
            m_BufLength += m_Increment;
            delete[] m_pBuf;
            m_pBuf = temp;
        }
    }

    ~SequentialList(void)
    {
        if(m_pBuf != NULL)
        {
            delete[] m_pBuf;
        }
        m_Count = 0;
        m_BufLength = 0;
    }

    void GetMax(void)
    {
        for(int i = 0; i < m_Count; i++)
        {
            for(int j = i + 1; j < m_Count;j++)
            {
                if(m_pBuf[i] > m_pBuf[j])
                {
                    T temp = m_pBuf[i];
                    m_pBuf[i] = m_pBuf[j];
                    m_pBuf[j] = temp;
                }
            }
        }
    }

protected:
    static const int m_InitLength = 1000;
    static const int m_Increment = sizeof Student;
    int m_BufLength;
    int m_Count;
    T * m_pBuf;
};

class Student
{
protected:
    int num, height;
public:
    Student():num(0), height(0){};
};

int main()
{

}
