#include <iostream>
#include "DiGraph.h"
#include "SimplePageRankNetwork.h"
#include "StochasticPageRankNetwork.h"
#include "IterationPageRankNetwork.h"


void ShowMenuOptions()
{
    std::cout << std::endl;
    std::cout << "1 :   Load Graph from file" << std::endl;
    std::cout << "2 :   Draw a random Graph" << std::endl;
    std::cout << "0 :   Exit" << std::endl;
    std::cout << std::endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    DiGraph * graph = nullptr;

    std::cout << "Welcome in PageRank simulation. Please choose an action: " << std::endl;
    ShowMenuOptions();

    unsigned option;
    std::cin >> option;
    std::cin.clear();

    while(option != 0)
    {
        switch(option)
        {
            case 0:
                break;

            case 1:
                graph = new DiGraph("AdjacencyList.txt");
                graph->Print();
                graph->Draw();
                break;

            case 2:
                graph = new DiGraph(5, 0.2);
                graph->Print();
                graph->Draw();
                break;

            default:
                std::cout << "Not known action.";
                break;
        }

        IterationPageRankNetwork iter(graph, 0.15);

        if(graph != nullptr)
        {
            PageRankNetwork * pageRankA = new SimplePageRankNetwork(graph, 0.15);
            pageRankA->CalculatePageRank(10000);

            IterationPageRankNetwork * pageRankB = new IterationPageRankNetwork(graph, 0.15);
            pageRankB->CalculatePageRank(10000);

            delete pageRankA;
            delete pageRankB;
            delete graph;
            graph = nullptr;
        }

        ShowMenuOptions();
        std::cin >> option;
        std::cin.clear();
    }


    return 0;
}