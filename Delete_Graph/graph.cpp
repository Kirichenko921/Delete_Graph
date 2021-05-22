#include "graph.h"
#include <iostream>

#define VERYBIGINT 1000000000
Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
/* Для проверки, существует ли ребро, нужно посмотреть значение элемента матрицы смежности с индексами номеров вершин (если есть ребро, он отличен от 0).*/
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
/*Для проверки, существует ли вершина, нужно проверить, есть ли ее номер в массиве vertexes.*/
bool Graph::vertexExists(int vnumber)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == vnumber)
            return true;
    return false;
}

void Graph::depth(int start)
{
    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false; // инициализируем как непосещенные
    depthInner(start, visited); // запуск алгоритма 

    std::cout << std::endl;
}

void Graph::depthInner(int current, bool visited[])
{
    std::cout << "v" << current << " -> "; // вывод текущей
    visited[current] = true; // помечаем как посещенную
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(current, i) && !visited[i])
            depthInner(i, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину
    }
}

void Graph::width(int start)
{
    int queue_to_visit[SIZE]; // очередь вершин для обхода
    int queueCount = 0;

    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    queue_to_visit[queueCount++] = start; // кладем в очередь начальную вершину
    while (queueCount > 0)
    {
        // взятие из очереди вершины
        int current = queue_to_visit[0];
        queueCount--;
        for (int i = 0; i < queueCount; i++)
        {
            queue_to_visit[i] = queue_to_visit[i + 1];
        }
        visited[current] = true;
        std::cout << "v" << current << " -> ";
        // поиск смежных вершин и добавление их в очередь
        for (int i = 0; i < SIZE; i++)
        {
            bool alreadyAdded = false;
            for (int j = 0; j < queueCount; j++)
                if (queue_to_visit[j] == i)
                {
                    alreadyAdded = true;
                    break;
                }
            if (!alreadyAdded && edgeExists(current, i) && !visited[i])
                queue_to_visit[queueCount++] = i;
        }
    }
    std::cout << std::endl;
}
int Graph::findPathCount(int from, int to)
{
   
   int numberPaths = 0;  // количество возможных путей
   bool visited[SIZE]; // список посещенных вершин
   for (int i = 0; i < SIZE; i++)
       visited[i] = false;
   int arrCountPaths[SIZE];
   for (int i = 0; i < SIZE; i++)
       arrCountPaths[i] = 0;
     findPathCountInner(visited,to,numberPaths,from,arrCountPaths); // запуск алгоритма 
  
             return numberPaths;
 
}

void Graph::findPathCountInner(bool visited[], int to, int& numberPaths, int current,int arrCountPaths[])
{
   if (current == to) // если попали в конечную точку увеличиваем количество путей 
    {
       for (int v = 0; v < SIZE; ++v)
       {
           if (!arrCountPaths[v])
               visited[v] = false;
       }
        ++numberPaths;
               return;
    }
    int queue_to_visit[SIZE]; // очередь вершин для обхода из текущей вершины
    int countEdge = 0;  // количество вершин для обхода
    for (int i = 0, j=0; i < SIZE; i++) // поиск вершин для следующего шага 
     {
        if (edgeExists(current, i)&& !visited[i]) // если существует ребро и оно ведёт не в предыдущую и не вначальную вершину 
        {
            queue_to_visit[j] = i;                           // добавляем в очередь 
            ++j;
             ++countEdge;                                     // и увеличиваем счётчик
        }
    }
    if (countEdge > 0)
    {
        visited[current] = true;
    }
    arrCountPaths[current] = countEdge;
    for (int i = 0; i < countEdge; i++) // переходи в следующую вершину если такая есть
    {
        findPathCountInner(visited, to, numberPaths, queue_to_visit[i], arrCountPaths);
        --arrCountPaths[current];
        if (!arrCountPaths[current])
            visited[current] = false;
    }
  
}

int Graph::findMinWayDFS(int from, int to)
{
    int minDistance = VERYBIGINT;  // количество возможных путей
    int currentPath = 0; //текущая длина пути
    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
    int arrCountPaths[SIZE];
    for (int i = 0; i < SIZE; i++)
        arrCountPaths[i] = 0;

    findMinWayDFSInner(visited, to, minDistance, currentPath, from, arrCountPaths); // запуск алгоритма 

    return minDistance;
}

void Graph::findMinWayDFSInner(bool visited[], int to, int& minDistance,int currentPath,int current, int arrCountPaths[])
{
    if (current == to) // если попали в конечную точку увеличиваем количество путей 
    {
        for (int v = 0; v < SIZE; ++v)
        {
            if (!arrCountPaths[v])
                visited[v] = false;
        }
        if (currentPath < minDistance)
        {
            minDistance = currentPath;
        }
        return;
    }
    int queue_to_visit[SIZE]; // очередь вершин для обхода из текущей вершины
    int countEdge = 0;  // количество вершин для обхода
    int arrEdgeWeights[SIZE];//массив веса смежных рёбер для вершины
    for (int i = 0, j = 0; i < SIZE; i++) // поиск вершин для следующего шага 
    {
        if (edgeExists(current, i) && !visited[i]) // если существует ребро и оно ведёт не посещённую вершину
        {
            queue_to_visit[j] = i;                           // добавляем в очередь 
            arrEdgeWeights[j] = matrix[current][i];          // заносим вес ребра для этой пары вершин
            ++j;
            ++countEdge;                                     // и увеличиваем счётчик
        }
    }
    if (countEdge > 0)
    {
        visited[current] = true;
    }
    arrCountPaths[current] = countEdge;
    for (int i = 0; i < countEdge; i++) // переходим в следующую вершину если такая есть
    {
        
        findMinWayDFSInner(visited, to, minDistance, currentPath + arrEdgeWeights[i] , queue_to_visit[i], arrCountPaths);
        --arrCountPaths[current];
        if (!arrCountPaths[current])
            visited[current] = false;
    }

}