#include "PageRankNetwork.h"


PageRankNetwork::PageRankNetwork(DiGraph *graph, const double d) : m_graph(graph), m_probability(d)
{
    m_numOfVisits = std::vector<double>(m_graph->SizeOfGraph(), 0.0);
}

int PageRankNetwork::iRand(const int min, const int max)
{
    return rand() % max + min;
}

void PageRankNetwork::PrintProbability() const
{
    std::cout << "Probability Vector:" << std::endl;

    for(int i = 0; i < m_graph->SizeOfGraph(); ++i)
    {
        std::cout << i + 1 << ": " << m_numOfVisits[i] << std::endl;
    }

    std::cout << std::endl;
}

void PageRankNetwork::PrintVertexesHierarchy() const
{
    std::cout << "Vertexes Hierarchy:" << std::endl;
}
