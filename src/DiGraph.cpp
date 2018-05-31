#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

#include "GraphException.h"
#include "DiGraph.h"


DiGraph::DiGraph(const int numberOfVertices, const double probability)
{
    DiGraph::ValidateRandomGraph(numberOfVertices, probability);

    std::cout << "Random DiGraph G(" << numberOfVertices << ", " << probability << ")" << std::endl << std::endl;

    std::vector<std::vector<int>> adjMatrix;
    DiGraph::FillRandomAdjacencyMatrix(adjMatrix, numberOfVertices, probability);

    m_adjList = new AdjList(AdjList::ConstructAdjListFromAdjMatrix(adjMatrix));
}

DiGraph::DiGraph(const char *fileName)
{
    std::ifstream inputFile;

    if (!inputFile.is_open())
    {
        inputFile.open(fileName, std::ios::in);

        if(!inputFile)
        {
            std::cerr << "Failed to open " << fileName << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    std::string representationName;
    std::getline(inputFile, representationName);

    try
    {
        if(representationName != "AL")
            throw(GraphException("Please use adjacency list as graph representation."));
    }
    catch(GraphException & exception)
    {
        std::cout << exception.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    ReadAdjacencyMatrixFromFileStream(inputFile);

    inputFile.close();
}

DiGraph::~DiGraph()
{
    delete m_adjList;
}

void DiGraph::ReadAdjacencyMatrixFromFileStream(std::ifstream & inputFile)
{
    std::vector<std::vector <int>>rows;
    std::string line;

    while(std::getline(inputFile, line))
    {
        std::istringstream streamLine(line);
        std::vector<int> col;

        while(!streamLine.eof())
        {
            int value;
            streamLine >> value;

            if(streamLine.fail())
                break;

            col.push_back(value);
        }

        rows.push_back(col);
    }

    m_adjList = new AdjList(rows);
}

void DiGraph::ValidateRandomGraph(const int numberOfVertices, const double probability)
{
    try
    {
        if(numberOfVertices < 0)
            throw(GraphException("Graph cannot has negative amount of vertices."));
        if(probability < 0 || probability > 1)
            throw(GraphException("Invalid value of probability."));
    }
    catch(GraphException & er)
    {
        std::cerr << er.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

int DiGraph::iRand(const int min, const int max)
{
    return rand() % max + min;
}

void DiGraph::FillRandomAdjacencyMatrix(std::vector<std::vector<int>> &adjMatrix,
                                        const int numberOfVertices, const double probability)
{
    srand(static_cast<unsigned int>(time(0)));

    for(int i = 0; i < numberOfVertices; ++i)
    {
        std::vector<int>row;

        for(int j = 0; j < numberOfVertices; ++j)
        {
            row.emplace_back(0);
        }

        adjMatrix.emplace_back(row);
    }

    for(int i = 0; i < numberOfVertices; ++i)
    {
        for(int j = 0; j < numberOfVertices; ++j)
        {
            int random = DiGraph::iRand(1, 100);
            int prob = static_cast<int>(probability * 100);

            if(i != j && prob >= random)
            {
                adjMatrix[i][j] = 1;
            }
        }
    }
}

void DiGraph::Print() const
{
    m_adjList->Print();
}

void DiGraph::Draw() const
{
    IncMatrix incMatrix = m_adjList->ConvertToIncMatrix();
    incMatrix.PrintToFile();

    std::string command = "python3 DiGraphVisualization.py IncidenceMatrix.txt";
    system(command.c_str());
}
