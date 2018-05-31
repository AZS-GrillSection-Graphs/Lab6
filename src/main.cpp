#include <iostream>
#include "DiGraph.h"


void ShowMenuOptions()
{
    std::cout << "1 :   Load Graph from file" << std::endl;
    std::cout << "2 :   Draw a random Graph" << std::endl;
    std::cout << "0 :   Exit" << std::endl;
}

int main()
{
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
                graph = new DiGraph(5, 0.5);
                graph->Print();
                graph->Draw();
                break;

            default:
                std::cout << "Not known action.";
                break;
        }

        delete graph;

        ShowMenuOptions();
        std::cin >> option;
        std::cin.clear();
    }


    return 0;
}