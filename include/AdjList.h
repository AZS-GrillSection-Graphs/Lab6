#ifndef GRAPHS4_ADJLIST_H
#define GRAPHS4_ADJLIST_H

#include <vector>
#include <iostream>
#include "IncMatrix.h"


class AdjList
{
public:
    AdjList() {}
    ~AdjList() {}

    explicit AdjList(const std::vector<std::vector<int>> adjList);
    static AdjList ConstructAdjListFromAdjMatrix(std::vector<std::vector<int>> adjMatrix);
    IncMatrix ConvertToIncMatrix() const;

    void Print() const;

    std::vector<std::vector<int>> GetAdjList() const;
    int GetDegreeOfVertex(const int index) const;
    unsigned Size() const;
    std::vector<int> & operator[](const int index);
    std::vector<int> operator[](const int index) const;

private:
    std::vector<std::vector<int>> m_adjList;
};

#endif //GRAPHS4_ADJLIST_H
