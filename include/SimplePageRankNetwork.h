#ifndef GRAPHS6_SIMPLEPAGERANKNETWORK_H
#define GRAPHS6_SIMPLEPAGERANKNETWORK_H

#include "DiGraph.h"


class SimplePageRankNetwork
{
public:
    SimplePageRankNetwork(DiGraph * graph, const double d);
    void CalculatePageRank(const unsigned numberOfIterations);

private:
    int iRand(const int min, const int max);
    int &GetRandomNeighbour(int index) const;
    int Teleport() const;
    void PrintProbability() const;


    DiGraph *& m_graph;
    std::vector<double> m_numOfVisits;
    const double m_probability;
};

#endif //GRAPHS6_SIMPLEPAGERANKNETWORK_H
