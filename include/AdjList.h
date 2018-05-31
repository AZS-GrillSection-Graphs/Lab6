#ifndef GRAPHS4_ADJLIST_H
#define GRAPHS4_ADJLIST_H

#include <vector>
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
    unsigned Size() const;
    std::vector<int> & operator[](const int index);
    std::vector<int> operator[](const int index) const;

private:
    std::vector<std::vector<int>> m_adjList = std::vector<std::vector<int>>(1, std::vector<int>(1, 0));
};

#endif //GRAPHS4_ADJLIST_H
