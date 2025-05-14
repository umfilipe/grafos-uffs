/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nome:      Eduardo Pazzini Zancanaro // Filipe Medeiros de Almeida
 * Matricula: 2221101031                // 2221101029
 */

#include "Grafo.h"

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

bool Grafo::eh_bipartido_1(std::vector<bool>& removido, std::vector<bool>& set1, std::vector<bool>& set2) {
    int contadorRemovidos = 0;
    for (bool flag : removido) {
        if (flag) {
            contadorRemovidos++;
        }
    }
    if (contadorRemovidos == num_vertices_) {
        return true;
    }

    int indice = -1;
    for (int i = 0; i < num_vertices_; i++) {
        if (!removido[i]) {
            indice = i;
            break;
        }
    }

    removido[indice] = true;

    if (eh_bipartido_1(removido, set1, set2)) {
        bool podeConjunto1 = true;
        for (int i = 0; i < num_vertices_; i++) {
            if (matriz_adj_[indice][i] && set1[i]) {
                podeConjunto1 = false;
                break;
            }
        }

        if (podeConjunto1) {
            set1[indice] = true;
            return true;
        }

        bool podeConjunto2 = true;
        for (int i = 0; i < num_vertices_; i++) {
            if (matriz_adj_[indice][i] && set2[i]) {
                podeConjunto2 = false;
                break;
            }
        }

        if (podeConjunto2) {
            set2[indice] = true;
            return true;
        }
    }

    removido[indice] = false;
    return false;
}

bool Grafo::eh_bipartido_1() {
    std::vector<bool> removido(num_vertices_, false);
    std::vector<bool> conjunto1(num_vertices_, false);
    std::vector<bool> conjunto2(num_vertices_, false);

    return eh_bipartido_1(removido, conjunto1, conjunto2);
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
    vector<int> cor(num_vertices_, -1);
    for (int i = 0; i < num_vertices_; ++i) {
        if (cor[i] == -1) {
            cor[i] = 0;
            if (!dfs(i, cor)) return false;
        }
    }
    return true;
}
