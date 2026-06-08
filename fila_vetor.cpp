#include <iostream>

using namespace std;

const int MAX = 100;

struct FilaVetor {
    int dados[MAX];
    int inicio = 0;
    int fim = 0;
    int total = 0;
};

bool vazia(FilaVetor &f) {
    return f.total == 0;
}

bool cheia(FilaVetor &f) {
    return f.total == MAX;
}

void enfileirar(FilaVetor &f, int valor) {
    if (!cheia(f)) {
        f.dados[f.fim] = valor;
        f.fim = (f.fim + 1) % MAX;
        f.total++;
    }
}

int desenfileirar(FilaVetor &f) {
    if (!vazia(f)) {
        int valor = f.dados[f.inicio];
        f.inicio = (f.inicio + 1) % MAX;
        f.total--;
        return valor;
    }
    return -1;
}

int main() {
    FilaVetor senhasGeradas;
    FilaVetor senhasAtendidas;
    
    int proximaSenha = 1;
    int op;

    do {
        cout << "\nAguando atendimento: " << senhasGeradas.total << " senha(s)" << endl;
        cout << "===== SISTEMA ATENDIMENTO (VETOR) =====" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Realizar atendimento" << endl;
        cout << "Opcao: ";
        cin >> op;

        if (op == 1) {
            enfileirar(senhasGeradas, proximaSenha);
            cout << "Senha gerada: " << proximaSenha << endl;
            proximaSenha++;
        } 
        else if (op == 2) {
            if (vazia(senhasGeradas)) {
                cout << "Nao ha senhas na fila para atender!" << endl;
            } else {
                int senhaAtendida = desenfileirar(senhasGeradas);
                cout << "Atendendo a senha: " << senhaAtendida << endl;
                enfileirar(senhasAtendidas, senhaAtendida);
            }
        } 
        else if (op == 0) {
            if (!vazia(senhasGeradas)) {
                cout << "Nao eh possivel sair. Ainda existem senhas aguardando!" << endl;
                op = -1; 
            } else {
                cout << "\nEncerrando sistema..." << endl;
                cout << "Total de senhas atendidas: " << senhasAtendidas.total << endl;
            }
        } 
        else {
            cout << "Opcao invalida!" << endl;
        }

    } while (op != 0);

    return 0;
}
