#ifndef PAGERANK_ADJMATRIX_H
#define PAGERANK_ADJMATRIX_H

#include <vector>


class AdjMatrix
{
public:
    AdjMatrix() {};
    ~AdjMatrix() {};

    void ConvertFromAdjList(std::vector<std::vector<int>> adjList);
    int GetDegreeOfVertex(const int index) const;
    int GetOutdegreeOfVertex(const int index) const;

    std::vector<int> & operator[](const int index);
    std::vector<int> operator[](const int index) const;

private:
    std::vector<std::vector<int>> m_adjMatrix;
};


#endif //PAGERANK_ADJMATRIX_H
