#include <iostream>
#include"graph.h"


// удаление вершины
void Graph::delVertex(int vnumber) {
    // Ваш код должен быть здесь 
    for (int i = 0; i < vertexCount; ++i)
    {
        if (vertexes[i] == vnumber)
        {
            vertexes[i] = -1;
            for(int j = 0; j < vertexCount;++j )
            {
                matrix[j][i] = 0;
                matrix[i][j] = 0;
            }
            for (; i < vertexCount; ++i)
            {
                vertexes[i] = vertexes[i + 1];
            }
            
            vertexCount--;
        }
    }
}
// удаление ребра
void Graph::delEdge(int v1, int v2) {
    // Ваш код должен быть здесь    
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}


int main()
{
   /* Graph g;
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 3);
    g.addEdge(1, 2, 11);
    g.addEdge(2, 3, 9);


    for (int i = 0; i < SIZE; ++i)
    {
            std::cout << g.vertexes[i]<<std::endl;
        
    }

    g.delEdge(0, 2);
    g.delEdge(1, 2);
    g.delEdge(2, 3);
    g.delVertex(2);


    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << g.vertexes[i] << std::endl;

    }*/
   Graph g;
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);
    g.addVertex(8);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(4, 3, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(4, 7, 1);
    g.addEdge(3, 6, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(3, 8, 1);
    g.addEdge(5, 8, 1);
    g.addEdge(8, 6, 1);
    g.addEdge(7, 6, 1);

   // g.depth(0);
   // g.width(0);

    
   /* g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 3);
    g.addEdge(1, 2, 11);
    g.addEdge(2, 3, 9);*/

    std::cout << g.findPathCount(0, 6) << std::endl;
    Graph gr;
    gr.addVertex(0);
    gr.addVertex(1);
    gr.addVertex(2);
    gr.addVertex(3);
    gr.addVertex(4);
    gr.addVertex(5);

    gr.addEdge(0, 2, 1);
    gr.addEdge(0, 4, 1);
    gr.addEdge(0, 5, 1);
    gr.addEdge(1, 4, 1);
    gr.addEdge(1, 5, 1);
    gr.addEdge(2, 3, 1);
    gr.addEdge(2, 4, 1);
    gr.addEdge(4, 5, 1);

    std::cout << gr.findPathCount(0, 1) << std::endl;
    return 0;
}