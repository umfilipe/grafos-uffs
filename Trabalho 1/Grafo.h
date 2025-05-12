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
    /** Constroi um grafo simples que possui o numero de vertices recebido por
     *  parametro e que nao possui arestas */
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);
    void addAresta(Aresta e);

    bool eh_bipartido_1();
    bool eh_bipartido_2();
private:
    int num_vertices_;
    int num_arestas_;
    bool dfs(int v, std::vector<int>& cor);
    void print_vector(const std::vector<int>& v, const std::string& nome);
    std::vector<std::vector<int>> matriz_adj_;
    bool eh_bipartido_1(std::vector<int>& removed, std::vector<int>& set1, std::vector<int>& set2);
    void valida_vertice(int v);
    void valida_aresta(Aresta e);
};

#endif /* GRAFO_H */
