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
        m_numOfVisits[index] += 1;

        int nextMove = iRand(1, 100);

        if(m_graph->HasNeighbours(index) && nextMove > static_cast<int>(m_probability * 100))
        {
            index = GetRandomNeighbour(index);
        }
        else
        {
            index = Teleport();
        }
    }

    for(auto & item: m_numOfVisits)
    {
        item /= numberOfIterations;
    }

    PrintProbability();
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
