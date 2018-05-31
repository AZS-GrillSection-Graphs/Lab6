#ifndef GRAPHS4_DIGRAPH_H
#define GRAPHS4_DIGRAPH_H

#include <fstream>
#include "AdjList.h"


class DiGraph
{
public:
    DiGraph(const int numberOfVertices, const double probability);
    DiGraph(const char * fileName);
    ~DiGraph();

    void Print() const;
    void Draw() const;

    unsigned SizeOfGraph() const;
    AdjList GetAdjList() const;
    bool HasNeighbours(const int vertex) const;

private:
    static void ValidateRandomGraph(const int numberOfVertices, const double probability);
    static int iRand(const int min, const int max);
    void FillRandomAdjacencyMatrix(std::vector<std::vector<int>> &adjMatrix,
                                          const int numberOfVertices, const double probability);

    void ReadAdjacencyMatrixFromFileStream(std::ifstream &inputFile);


    AdjList * m_adjList;
};

#endif //GRAPHS4_DIGRAPH_H
