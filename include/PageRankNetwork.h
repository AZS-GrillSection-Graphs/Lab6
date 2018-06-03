#ifndef GRAPHS6_PAGERANKNETWORK_H
#define GRAPHS6_PAGERANKNETWORK_H

#include "DiGraph.h"


class PageRankNetwork
{
public:
    PageRankNetwork(DiGraph * graph, const double d);
    virtual void CalculatePageRank(const unsigned numberOfIterations) = 0;

protected:
    int iRand(const int min, const int max);
    void PrintProbability() const;
    void PrintVertexesHierarchy() const;

    DiGraph * m_graph;
    std::vector<double> m_probability;
    const double m_d;
};

#endif //GRAPHS6_PAGERANKNETWORK_H
