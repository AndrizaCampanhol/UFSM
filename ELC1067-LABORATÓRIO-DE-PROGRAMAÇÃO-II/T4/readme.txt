# ---------------------------------------------------------------------------- #
#                          Funcionalidades Construídas                         #
# ---------------------------------------------------------------------------- #

-> Foram construídas todas as funcionalidades solicitadas no trabalho.

# ---------------------------------------------------------------------------- #
#                          Organização do Programa                             #
# ---------------------------------------------------------------------------- #

-> Foram especificadas as structs de No (para fila guardando ticket, para pilha id e o proximo no para ambos), assim como para fila e pilha que recebem ponteiros(no de inicio e fim para fila e o primeiro no para a pilha).

-> Ao iniciar o programa, criamos as tres filas(normal, alta e unica) e a pilha vazias, e alocamos um espaço de memória para armazenar os dados que serão recebidos posteriormente.

-> Após, chamamos a função menu, que irá controlar toda a interação com o usuário. Para ela, passamos como parâmetros unica, normal, alta e bandejas.

-> A seguir, a função menu (localizada na menu.c) imprime um "Menu Inicial", onde são apresentadas as opções de ações para o usuário, e de acordo com o input chama cada um das funções, passando por parâmetro os dados necessários.

-> Por fim, quando a opção "0" for escolhida para sair, as filas e a pilha serão liberadas e o programa chega ao fim.

# ---------------------------------------------------------------------------- #
-> Caso necessário, abaixo estão as funcionalidades das funções implementadas.
# ---------------------------------------------------------------------------- #




# ---------------------------------------------------------------------------- #
#                                  menu.c                                      #
# ---------------------------------------------------------------------------- #

-> O controle geral ocorre na menu.c, onde o usuário informa a opção em que deseja seguir ou se deseja finalizar a operação.

-> As funções do menu são utilizadas para receber os dados necessários para as funções da fila.c e pilha.c chamadas nelas e assim executar a operação selecionada.

# ---------------------------------------------------------------------------- #
#                                  fila.c                                      #
# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
#                          Função fila_cria                                    #
# ---------------------------------------------------------------------------- #

-> Objetivo: criar uma fila (normal, alta ou unica).

-> Nessa função, primeiramente cria-se uma fila e aloca-se memoria para ela.
-> Em seguida, os nos de ini e fim sao setados para nulo.
-> Por fim, é retornada a fila.

# ---------------------------------------------------------------------------- #
#                          Função fila_vazia                                   #
# ---------------------------------------------------------------------------- #

-> Objetivo: verificar se a fila esta vazia, recebendo a fila por parametro.

-> Retorna "1" se a fila estiver vazia e "0" caso não.

# ---------------------------------------------------------------------------- #
#                          Função fila_insere                                  #
# ---------------------------------------------------------------------------- #

-> Objetivo: inserir um no no final de uma fila, recebendo a fila e o ticket por parametro.

-> Nessa função, cria-se um no e aloca-se memoria para ele, o no recebe o valor do ticket e o prox é setado para nulo.
-> Em seguida, se for o primeiro adicionado, é inserido no inicio, caso nao, é inserido na prox posicao depois do fim.
-> Por fim, o fim da fila é atualizado para o novo no adicionado.

# ---------------------------------------------------------------------------- #
#                          Função fila_retira                                  #
# ---------------------------------------------------------------------------- #

-> Objetivo: retirar o primeiro no de uma fila, recebendo a fila por parametro.

-> Nessa função, primeiramente utiliza-se fila_vazia, caso nao estiver vazia, um no é criado para receber as informacoes do primeiro no.
-> Em seguida, e o ini da fila recebe o prox elemento, caso for nulo, atualiza o fim da fila para nulo tambem. 
-> Por fim, o no é liberado e uma mensagem de sucesso é escrita.

# ---------------------------------------------------------------------------- #
#                          Função fila_libera                                  #
# ---------------------------------------------------------------------------- #

-> Objetivo: liberar toda a fila, recebendo a fila por parametro.

-> Libera cada um dos elementos por meio de um while e por fim libera a fila.

# ---------------------------------------------------------------------------- #
#                          Função tamanho_fila                                 #
# ---------------------------------------------------------------------------- #

-> Objetivo: calcular o tamanho de uma fila e retorna-lo, recebendo a fila por parametro.

-> Se a fila nao estiver vazia, conta a quantidade de elementos por meio de um while e por fim retorna a quantidade.

# ---------------------------------------------------------------------------- #
#                          Função move_fila_unica                              #
# ---------------------------------------------------------------------------- #

-> Objetivo: movo um no de uma fila(normal ou alta) para a unica, recebendo a fila unica e a outra por parametro.

-> Nessa função, o primeiro no da outra fila é retirado da mesma, atualizando-se os ponteiros necessarios.
-> Por fim, esse no é inserido na fila unica, atualizando-se os ponteiros necessarios.

# ---------------------------------------------------------------------------- #
#                          Função adicionar_fila                               #
# ---------------------------------------------------------------------------- #

-> Objetivo: chamar a funcao que insere um no e passar o numero do ticket para a mesma, recebendo fila por parametro.

-> Nessa função, é perguntado o numero do ticket e a funcao fila_insere é chamada.
-> Por fim, uma mensagem de sucesso é escrita caso o aluno for adicionado a fila.

# ---------------------------------------------------------------------------- #
#                          Função retirar_fila_unica                           #
# ---------------------------------------------------------------------------- #

-> Objetivo: chamar a funcao que libera o primeiro no para a fila unica, recebendo a fila unica por parametro.

-> Chama a funcao fila_retira passando a fila unica.

# ---------------------------------------------------------------------------- #
#                          Função fusao_fila_unica                             #
# ---------------------------------------------------------------------------- #

-> Objetivo: preencher a fila unica com as outras filas, respeitando a prioridade, recebendo a fila normal , alta e unica por parametro.

-> Nessa função, a funcao tamanho_fila é utilizada para verificar quantas posicoes serao preenchidas na fila unica.
-> Em seguida, são feitos testes para verificar se a fila unica esta cheia ou se as outras duas estao vazias simultaneamente.
-> Por fim, sao preenchidas as posicoes disponiveis na fila unica, com prioridade a fila alta e uma mensagem de sucesso é escrita.

# ---------------------------------------------------------------------------- #
#                          Função liberar_fila                                 #
# ---------------------------------------------------------------------------- #

-> Objetivo: chamar a funcao que libera a fila para fila recebida, recebendo fila por parametro.

-> Chama a funcao fila_libera passando a fila recebida.

# ---------------------------------------------------------------------------- #
#                          Função imprime_fila                                 #
# ---------------------------------------------------------------------------- #

-> Objetivo: imprimir a fila recebida, recebendo fila por parametro.

-> Nessa função, primeiramente utiliza-se fila_vazia, caso nao estiver vazia, utiliza-se tamanho_fila para percorrer a fila.
-> Por fim, um for imprime cada um dos elementos da fila.

# ---------------------------------------------------------------------------- #
#                                  pilha.c                                     #
# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
#                          Função pilha_cria                                   #
# ---------------------------------------------------------------------------- #

-> Objetivo: criar uma pilha.

-> Nessa função, primeiramente cria-se uma pilha e aloca-se memoria para ela.
-> Em seguida, o prim no é setados para nulo.
-> Por fim, é retornada a pilha.

# ---------------------------------------------------------------------------- #
#                          Função pilha_vazia                                  #
# ---------------------------------------------------------------------------- #

-> Objetivo: verificar se a pilha esta vazia, recebendo a pilha por parametro.

-> Retorna "1" se a pilha estiver vazia e "0" caso não.

# ---------------------------------------------------------------------------- #
#                          Função pilha_push                                   #
# ---------------------------------------------------------------------------- #

-> Objetivo: adicionar uma bandeja na pilha, recebendo a pilha e o id por parametro.

-> Nessa função, cria-se um no e aloca-se memoria para ele.
-> Em seguida, o no recebe o id e o prox como o o primeiro da pilha, e o primeiro recebe o novo no.
-> Por fim, uma mensagem de sucesso é escrita.

# ---------------------------------------------------------------------------- #
#                          Função pilha_pop                                    #
# ---------------------------------------------------------------------------- #

-> Objetivo: retirar uma bandeja da pilha, recebendo a pilha por parametro.

-> Nessa função, primeiramente utiliza-se pilha_vazia, caso nao estiver vazia, um no é criado para receber as informacoes do primeiro no.
-> Em seguida, o no recebe o primeiro no da pilha, o primeiro recebe o prox dele e o no é liberado.
-> Por fim, uma mensagem de sucesso é escrita.

# ---------------------------------------------------------------------------- #
#                          Função pilha_libera                                 #
# ---------------------------------------------------------------------------- #

-> Objetivo: liberar toda a pilha, recebendo a pilha por parametro.

-> Libera cada um dos elementos por meio de um while e por fim libera a pilha.

# ---------------------------------------------------------------------------- #
#                          Função imprime_pilha                                #
# ---------------------------------------------------------------------------- #

-> Objetivo: imprimir a pilha recebida, recebendo pilha por parametro.

-> Nessa função, primeiramente utiliza-se pilha_vazia para verificar se ha elementos na pilha.
-> Por fim, um while imprime cada um dos elementos da fila.
