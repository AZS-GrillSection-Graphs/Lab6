#include "AdjMatrix.h"
#include "IterationPageRankNetwork.h"

IterationPageRankNetwork::IterationPageRankNetwork(DiGraph *graph, const double d) : PageRankNetwork(graph, d)
{

}

void IterationPageRankNetwork::CalculatePageRank(const unsigned numberOfIterations)
{
    InitialiseProbability();

    int graphSize = m_graph->SizeOfGraph();
    std::vector<std::vector<double>> P(graphSize, std::vector<double>(graphSize, 0.0));

    InitialiseStochasticMatrix(P);

    for(int i = 0; i < numberOfIterations; i++)
        VectorMatrixMultiplication(P);

    std::cout << "Iterations of vector probabilities PageRank Method:" << std::endl;

    PrintVertexesHierarchy();
}

void IterationPageRankNetwork::VectorMatrixMultiplication(const std::vector<std::vector<double>> &P)
{
    int size = m_graph->SizeOfGraph();
    std::vector<double> resultOfMultipication(size, 0.0);

    for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                resultOfMultipication[i] += this->m_probability[j] * P[j][i];

    this->m_probability = resultOfMultipication;
}

void IterationPageRankNetwork::InitialiseStochasticMatrix(std::vector<std::vector<double>> &P)
{
    int numberOfVertices = m_graph->SizeOfGraph();

    AdjMatrix adjMatrix;
    adjMatrix.ConvertFromAdjList(m_graph->GetAdjList().GetAdjList());

    std::vector<int> outdegreesOfGraph(numberOfVertices, 0);
    for(int i = 0; i < numberOfVertices; i++)
        outdegreesOfGraph[i] = adjMatrix.GetOutdegreeOfVertex(i);

    for(int i = 0; i < numberOfVertices; i++)
        for(int j = 0; j < numberOfVertices; j++)
            if(outdegreesOfGraph[i] == 0)
                P[i][j] = 1.0 / numberOfVertices;
            else
                P[i][j] = (1 - m_d) * adjMatrix[i][j] / outdegreesOfGraph[i] + m_d / numberOfVertices;

}

void IterationPageRankNetwork::InitialiseProbability()
{
    int numberOfVertices = this->m_graph->SizeOfGraph();

    for(auto & item: this->m_probability)
        item = 1.0 / numberOfVertices;
}
