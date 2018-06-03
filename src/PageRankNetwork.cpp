#include <algorithm>
#include "PageRankNetwork.h"


PageRankNetwork::PageRankNetwork(DiGraph *graph, const double d) : m_graph(graph), m_d(d)
{
    m_probability = std::vector<double>(m_graph->SizeOfGraph(), 0.0);
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
        std::cout << i + 1 << ": " << m_probability[i] << std::endl;
    }

    std::cout << std::endl;
}

void PageRankNetwork::PrintVertexesHierarchy() const
{
    std::vector<std::pair<int, double>> hierarchy;

    for(int i = 0; i < m_probability.size(); ++i)
    {
        hierarchy.emplace_back(std::pair<int, double>(i + 1, m_probability[i]));
    }

    std::sort(hierarchy.begin(), hierarchy.end(),
              [](const std::pair<int, double> val1, const std::pair<int, double> val2)
              {return val1.second > val2.second;});

    std::cout << "Vertexes Hierarchy:" << std::endl;

    for(int i = 0; i < hierarchy.size(); ++i)
    {
        std::cout << "Vertex nr: " << hierarchy[i].first << " PageRank: " << hierarchy[i].second << std::endl;
    }
}
