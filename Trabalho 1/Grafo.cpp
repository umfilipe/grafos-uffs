/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nome:      Eduardo Pazzini Zancanaro // Filipe Medeiros de Almeida
 * Matricula: 2221101031                // 2221101029
 */

#include "Grafo.h"
#include <algorithm>

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

// Implementação recursiva
bool Grafo::eh_bipartido_1(int vertice, vector<int>& removed, vector<int>& conjunto) {
    if (removed.size() == num_vertices_) return true;

    // Encontrar o próximo vértice não removido
    int menorIndice = -1;
    for (int i = 0; i < num_vertices_; i++) {
        if (find(removed.begin(), removed.end(), i) == removed.end()) {
            menorIndice = i;
            break;
        }
    }

    removed.push_back(menorIndice);

    if (eh_bipartido_1(vertice + 1, removed, conjunto)) {
        // Tenta adicionar ao conjunto 1
        bool podeConjunto1 = true;
        for (int i = 0; i < num_vertices_; i++) {
            if (matriz_adj_[menorIndice][i] && conjunto[i] == 1) {
                podeConjunto1 = false;
                break;
            }
        }

        if (podeConjunto1) {
            conjunto[menorIndice] = 1;
            return true;
        }

        // Tenta adicionar ao conjunto 2
        bool podeConjunto2 = true;
        for (int i = 0; i < num_vertices_; i++) {
            if (matriz_adj_[menorIndice][i] && conjunto[i] == 2) {
                podeConjunto2 = false;
                break;
            }
        }

        if (podeConjunto2) {
            conjunto[menorIndice] = 2;
            return true;
        }
    }

    removed.pop_back();
    return false;
}

bool Grafo::eh_bipartido_1() {
    vector<int> removidos;
    vector<int> conjunto(num_vertices_, 0);  // 0: não atribuído, 1 ou 2

    return eh_bipartido_1(0, removidos, conjunto);
}

// DFS (já estava correto)
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
    vector<int> cor(num_vertices_, -1);
    for (int i = 0; i < num_vertices_; ++i) {
        if (cor[i] == -1) {
            cor[i] = 0;
            if (!dfs(i, cor)) return false;
        }
    }
    return true;
}
