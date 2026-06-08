#include <iostream>

using namespace std;

struct No {
    int senha;
    No* proximo;
};

struct FilaPonteiro {
    No* inicio = nullptr;
    No* fim = nullptr;
    int total = 0;
};

bool vazia(FilaPonteiro &f) {
    return f.total == 0;
}

void enfileirar(FilaPonteiro &f, int valor) {
    No* novo = new No();
    novo->senha = valor;
    novo->proximo = nullptr;
    
    if (vazia(f)) {
        f.inicio = novo;
    } else {
        f.fim->proximo = novo;
    }
    f.fim = novo;
    f.total++;
}

int desenfileirar(FilaPonteiro &f) {
    if (!vazia(f)) {
        No* aux = f.inicio;
        int valor = aux->senha;
        f.inicio = f.inicio->proximo;
        
        if (f.inicio == nullptr) {
            f.fim = nullptr;
        }
        
        delete aux;
        f.total--;
        return valor;
    }
    return -1;
}

void limparFila(FilaPonteiro &f) {
    while (!vazia(f)) {
        desenfileirar(f);
    }
}

int main() {
    FilaPonteiro senhasGeradas;
    FilaPonteiro senhasAtendidas;
    
    int proximaSenha = 1;
    int op;

    do {
        cout << "\nAguando atendimento: " << senhasGeradas.total << " senha(s)" << endl;
        cout << "===== SISTEMA ATENDIMENTO (PONTEIRO) =====" << endl;
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
                limparFila(senhasAtendidas);
            }
        } 
        else {
            cout << "Opcao invalida!" << endl;
        }

    } while (op != 0);

    return 0;
}
