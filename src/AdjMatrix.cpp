#include "AdjMatrix.h"

void AdjMatrix::ConvertFromAdjList(std::vector<std::vector<int>> adjList)
{
    int matrixSize = adjList.size();
    m_adjMatrix = std::vector<std::vector<int>>(matrixSize, std::vector<int>(matrixSize, 0));

    for(int i = 0; i < adjList.size(); ++i)
    {
        for(int j = 0; j < adjList[i].size(); ++j)
        {
            m_adjMatrix[i][adjList[i][j]] = 1;
        }
    }
}

int AdjMatrix::GetDegreeOfVertex(const int index) const
{
    int degree = 0;

    for(int i = 0; i < m_adjMatrix.size(); i++)
        if(m_adjMatrix[index][i] == 1)
            degree++;

    for(int i = 0; i < m_adjMatrix.size(); i++)
        if(m_adjMatrix[i][index] == 1)
            degree++;

    return degree;
}

int AdjMatrix::GetOutdegreeOfVertex(const int index) const
{
    int degree = 0;

    for(int i = 0; i < m_adjMatrix.size(); i++)
        if(m_adjMatrix[index][i] == 1)
            degree++;

    return degree;
}

std::vector<int> & AdjMatrix::operator[](const int index)
{
    return m_adjMatrix[index];
}

std::vector<int> AdjMatrix::operator[](const int index) const
{
    return m_adjMatrix[index];
}