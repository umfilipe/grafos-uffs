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
#include <exception>
#include <string>
#include <iostream>

using namespace std;

void print_exception(const exception &e, int level = 0) {
    cerr << "exception: " << string(level, ' ') << e.what() << "\n";
    try {
        rethrow_if_nested(e);
    } catch(const std::exception& nested_exception) {
        print_exception(nested_exception, (level + 2));
    }
}

int main() {
    try {
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
    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}
