#ifndef GRAPHS6_STOCHASTICPAGERANKNETWORK_H
#define GRAPHS6_STOCHASTICPAGERANKNETWORK_H

#include "DiGraph.h"
#include "PageRankNetwork.h"


class StochasticPageRankNetwork final : public PageRankNetwork
{
public:
    StochasticPageRankNetwork(DiGraph * graph, const double d);
    void CalculatePageRank(const unsigned numberOfIterations) override;

private:

};

#endif //GRAPHS6_STOCHASTICPAGERANKNETWORK_H
