#include <cstdlib>
#include <iostream>
#include "SimplePageRankNetwork.h"


SimplePageRankNetwork::SimplePageRankNetwork(DiGraph * graph, const double d) : m_graph(graph), m_probability(d)
{
    m_numOfVisits = std::vector<double>(m_graph->SizeOfGraph(), 0.0);
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
}

int SimplePageRankNetwork::Teleport() const
{
    return rand() % m_graph->SizeOfGraph();
}

int & SimplePageRankNetwork::GetRandomNeighbour(int index) const
{
    return m_graph->GetAdjList()[index][rand() % m_graph->GetAdjList()[index].size()];
}

int SimplePageRankNetwork::iRand(const int min, const int max)
{
    return rand() % max + min;
}

void SimplePageRankNetwork::PrintProbability() const
{
    std::cout << "Probability Vector:" << std::endl;

    for(int i = 0; i < m_graph->SizeOfGraph(); ++i)
    {
        std::cout << i + 1 << ": " << m_numOfVisits[i] << std::endl;
    }
}

