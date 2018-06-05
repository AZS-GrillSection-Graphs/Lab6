#ifndef PAGERANK_ITERATIONPAGERANKNETWORK_H
#define PAGERANK_ITERATIONPAGERANKNETWORK_H

#include "DiGraph.h"
#include "PageRankNetwork.h"


class IterationPageRankNetwork : public PageRankNetwork
{
public:
    IterationPageRankNetwork(DiGraph * graph, const double d);
    void CalculatePageRank(const unsigned numberOfIterations) override;

private:
    void InitialiseProbability();
    void InitialiseStochasticMatrix(std::vector<std::vector<double>> &P);
    void VectorMatrixMultiplication(const std::vector<std::vector<double>> &P);
};


#endif //PAGERANK_ITERATIONPAGERANKNETWORK_H
