/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Freire Meira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 10/10/2026
Objetivo    : Organizar a saida dos vagoes da estacao.
Dificuldade : Entender como usar o pop e push nesse caso.
Uso de IA   : Saber o que tinah que fazer na funcao main e comentar o codigo.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. ESTRUTURA DO NÓ (A "caixa" da lista)
// ==========================================
// Usamos 'typedef' para não precisarmos escrever 'struct no' toda vez, 
// podendo chamar apenas de 'no'.
typedef struct no {
    int valor;              // O número do vagão do trem
    struct no* proximo;     // O ponteiro que liga ao vagão de baixo na pilha
} no;


// ==========================================
// 2. FUNÇÕES DA PILHA (LIFO - Last In, First Out)
// ==========================================

// PUSH: Insere um novo vagão no TOPO da pilha (início da lista)
// Usamos '**' (ponteiro para ponteiro) porque precisamos alterar quem é a 'cabeca' original lá no main.
void push(no** cabeca, int novovalor) {
    // 1. Pede espaço na memória para o novo vagão
    no* nonovo = (no*)malloc(sizeof(no));
    
    // 2. Coloca o número do trem dentro dele
    nonovo->valor = novovalor;
    
    // 3. O novo vagão aponta para o antigo topo da pilha
    nonovo->proximo = (*cabeca);
    
    // 4. A coroa de "topo da pilha" agora passa para este novo vagão
    (*cabeca) = nonovo;
}

// POP: Remove o vagão do TOPO da pilha e devolve o número dele
int pop(no** cabeca) {
    // Se a pilha estiver vazia, não há o que remover
    if (*cabeca == NULL) {
        return -1;
    }
    
    // 1. Seguramos o vagão do topo em uma variável temporária para não perdê-lo
    no* temp = (*cabeca);
    int removido = temp->valor; // Guardamos o número do vagão para devolver no final
    
    // 2. O topo da pilha desce para o vagão de baixo
    *cabeca = (*cabeca)->proximo;

    // 3. Destruímos o vagão antigo (libera a memória para não dar vazamento)
    free(temp);
    
    return removido; // Devolve o trem que saiu da estação
}

// TOPO: Apenas "espia" qual é o trem que está no topo, sem removê-lo
int topo(no** cabeca) {
    if (*cabeca == NULL) {
        return -1;
    }
    return (*cabeca)->valor; // Retorna o valor do primeiro nó
}

// VAZIA: Verifica se a pilha está vazia
// Retorna 1 (Verdadeiro) se estiver vazia, ou 0 (Falso) se tiver algum nó.
int vazia(no** cabeca) {
    return (*cabeca) == NULL;
}


// ==========================================
// 3. O SIMULADOR DA ESTAÇÃO (Lógica do Jogo)
// ==========================================
int main() {
    int vagoes;

    // O Beecrowd roda vários cenários. Ele para quando o número de vagões for 0.
    while (scanf("%d", &vagoes) && vagoes != 0) {
        
        while (1) { // Laço infinito para ler as várias ordens alvo dentro do mesmo cenário
            
            int alvo[1005]; // Vetor para guardar a ordem que queremos que os trens saiam
            
            scanf("%d", &alvo[0]);
            
            // Se o primeiro trem da ordem for 0, acabou este bloco de testes.
            if (alvo[0] == 0) {
                printf("\n"); // O Beecrowd exige uma linha em branco separando os blocos
                break;        // Quebra o while(1) e volta para o while de cima (ler novo 'N')
            }
            
            // Lê o resto da ordem desejada e guarda no vetor
            for (int i = 1; i < vagoes; i++) {
                scanf("%d", &alvo[i]);
            }

            // --- INÍCIO DA SIMULAÇÃO ---
            
            no* estacao = NULL;     // A nossa pilha começa vazia
            int vagao_chegando = 1; // Os trens sempre chegam na ordem: 1, 2, 3...
            int indice_alvo = 0;    // Ponteiro para sabermos qual trem queremos que saia agora

            // O simulador roda enquanto ainda tiver trem pra chegar OU enquanto 
            // o trem certo estiver na porta pronto para sair.
            while (vagao_chegando <= vagoes || (!vazia(&estacao) && topo(&estacao) == alvo[indice_alvo])) {
                
                // CONDIÇÃO 1: O trem que eu quero que saia (alvo) está no topo da estação?
                if (!vazia(&estacao) && topo(&estacao) == alvo[indice_alvo]) {
                    pop(&estacao);  // Tira o trem da estação (ele foi para a saída!)
                    indice_alvo++;  // Avançamos para olhar qual é o próximo trem da lista desejada
                }
                // CONDIÇÃO 2: Se não é o trem certo, ainda tem trem lá fora para empurrar pra dentro?
                else if (vagao_chegando <= vagoes) {
                    push(&estacao, vagao_chegando); // Joga o trem novo dentro da estação
                    vagao_chegando++;               // O próximo trem a chegar será o número seguinte
                }
                // CONDIÇÃO 3: Não é o trem certo e acabaram os trens de fora.
                else {
                    break; // Engarrafou tudo! É impossível montar a ordem pedida.
                }
            }

            // --- FIM DA SIMULAÇÃO ---

            // Se a estação terminou vazia, significa que todos os trens saíram com sucesso
            if (vazia(&estacao)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            
            // FAXINA DE MEMÓRIA:
            // Se o resultado foi "No", sobraram trens presos na estação.
            // Precisamos esvaziar a pilha inteira, senão o próximo teste vai 
            // começar com a estação já cheia, arruinando o resultado!
            while (!vazia(&estacao)) {
                pop(&estacao);
            }
        }
    }
    return 0;
}
