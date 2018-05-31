#ifndef GRAPHS6_SIMPLEPAGERANKNETWORK_H
#define GRAPHS6_SIMPLEPAGERANKNETWORK_H

#include "DiGraph.h"
#include "PageRankNetwork.h"


class SimplePageRankNetwork final : public PageRankNetwork
{
public:
    SimplePageRankNetwork(DiGraph * graph, const double d);
    void CalculatePageRank(const unsigned numberOfIterations) override;

private:
    int GetRandomNeighbour(int index) const;
    int Teleport() const;
};

#endif //GRAPHS6_SIMPLEPAGERANKNETWORK_H
