/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nome:      Eduardo Pazzini Zancanaro // Filipe Medeiros de Almeida
 * Matricula: 2221101031                // 2221101029
 */
#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    int a, b = 0;
    cin >> a >> b;
    Grafo grafo(a);

    for (int i = 0; i < b; i++) {
        int v1, v2;
        char t;
        cin >> v1 >> v2 >> t;

        if (t == 'A')
        {
            grafo.addAresta(Aresta(v1, v2));
        }
    }

    cout << (grafo.eh_bipartido_1() ? "SIM" : "NAO") << endl;
    cout << (grafo.eh_bipartido_2() ? "SIM" : "NAO") << endl;

    return 0;
}
