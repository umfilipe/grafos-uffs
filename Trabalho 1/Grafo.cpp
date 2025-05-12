/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nome:      Eduardo Pazzini Zancanaro // Filipe Medeiros de Almeida
 * Matricula: 2221101031                // 2221101029
 */
#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

void Grafo::addAresta(Aresta e) {
    matriz_adj_[e.v1][e.v2] = 1;
    matriz_adj_[e.v2][e.v1] = 1;

    num_arestas_++;
}

bool Grafo::eh_bipartido_1(vector<int>& removed, vector<int>& set1, vector<int>& set2) {
    int vertice = -1;
    for (int i = 0; i < num_vertices_; i++) {
        if (!removed[i]) {
            vertice = i;
            break;
        }
    }
    if (vertice == -1) return true;

    bool CanBeSet1 = true;
    for (int i = 0; i < num_vertices_; i++)
    {
        if (matriz_adj_[vertice][i] && set1[i]) {
            CanBeSet1 = false;
            break;
        }
    }

    if(CanBeSet1) {
        set1[vertice] = true;
        removed[vertice] = true;
        return eh_bipartido_1(removed, set1, set2);
    } else {
        bool CanBeSet2 = true;
        for (int i = 0; i < num_vertices_; i++)
        {
            if (matriz_adj_[vertice][i] && set1[i]) {
                CanBeSet2 = false;
                break;
            }
        }
        if (CanBeSet2)
        {
            set2[vertice] = true; // adiciona o vertice ao conjunto 2
            removed[vertice] = true; // remove o vertice do grafo
            return eh_bipartido_1(removed, set1, set2); // chama a funcao recursivamente
        }
    }
    return false;
}

bool Grafo::eh_bipartido_1() {
    std::vector<int> removed(num_vertices_, false);
    std::vector<int> set1(num_vertices_, false);
    std::vector<int> set2(num_vertices_, false);

    return eh_bipartido_1(removed, set1, set2);
}

bool Grafo::dfs(int v, std::vector<int>& cor) {
    for (int u = 0; u < num_vertices_; ++u) {
        if (matriz_adj_[v][u]) {
            if (cor[u] == -1) {
                cor[u] = 1 - cor[v];
                if (!dfs(u, cor)) return false;
            } else if (cor[u] == cor[v]) {
                return false;
            }
        }
    }
    return true;
}

bool Grafo::eh_bipartido_2() {
    std::vector<int> cor(num_vertices_, -1);

    for (int i = 0; i < num_vertices_; ++i) {
        if (cor[i] == -1) {
            cor[i] = 0;
            if (!dfs(i, cor)) return false;
        }
    }

    return true;
}
