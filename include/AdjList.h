#ifndef GRAPHS4_ADJLIST_H
#define GRAPHS4_ADJLIST_H

#include <vector>
#include "IncMatrix.h"


class AdjList
{
public:
    AdjList() = default;
    ~AdjList() = default;

    explicit AdjList(const std::vector<std::vector<int>> adjList);
    static AdjList ConstructAdjListFromAdjMatrix(std::vector<std::vector<int>> adjMatrix);
    IncMatrix ConvertToIncMatrix() const;

    void Print() const;

    std::vector<std::vector<int>> GetAdjList() const;
    unsigned Size() const;
    std::vector<int> & operator[](const int index);
    std::vector<int> operator[](const int index) const;

private:
    std::vector<std::vector<int>>m_adjList;
};

#endif //GRAPHS4_ADJLIST_H
