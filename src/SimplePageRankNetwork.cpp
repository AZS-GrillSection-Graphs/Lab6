#include <cstdlib>
#include <iostream>
#include "SimplePageRankNetwork.h"


SimplePageRankNetwork::SimplePageRankNetwork(DiGraph * graph, const double d) : PageRankNetwork(graph, d)
{

}

void SimplePageRankNetwork::CalculatePageRank(const unsigned numberOfIterations)
{
    int index = 0;

    for(unsigned i = 0; i < numberOfIterations; ++i)
    {
        m_probability[index] += 1;

        int nextMove = iRand(1, 100);

        if(m_graph->HasNeighbours(index) && nextMove > static_cast<int>(m_d * 100))
        {
            index = GetRandomNeighbour(index);
        }
        else
        {
            index = Teleport();
        }
    }

    for(auto & item: m_probability)
    {
        item /= numberOfIterations;
    }

    std::cout << "Simple PageRank method:" << std::endl;

    PrintVertexesHierarchy();
}

int SimplePageRankNetwork::Teleport() const
{
    return rand() % m_graph->SizeOfGraph();
}

int SimplePageRankNetwork::GetRandomNeighbour(int index) const
{
    return m_graph->GetAdjList()[index][rand() % m_graph->GetAdjList()[index].size()];
}
