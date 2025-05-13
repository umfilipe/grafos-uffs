/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nome:      Eduardo Pazzini Zancanaro // Filipe Medeiros de Almeida
 * Matricula: 2221101031                // 2221101029
 */
#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include <iostream>
class Grafo {
public:
    Grafo(int num_vertices);

    void addAresta(Aresta e);

    bool eh_bipartido_1();
    bool eh_bipartido_2();
private:
    int num_vertices_;
    int num_arestas_;
    bool dfs(int v, std::vector<int>& cor);
    std::vector<std::vector<int>> matriz_adj_;
    bool eh_bipartido_1(int vertice, std::vector<bool>& removido, std::vector<bool>& set1, std::vector<bool>& set2);
};

#endif /* GRAFO_H */
