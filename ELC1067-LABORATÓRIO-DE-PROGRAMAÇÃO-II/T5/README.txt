# ---------------------------------------------------------------------------- #
#                          Funcionalidades Construídas                         #
# ---------------------------------------------------------------------------- #

-> Foram construídas todas as funcionalidades solicitadas no trabalho.

# ---------------------------------------------------------------------------- #
#                          Organização do Programa                             #
# ---------------------------------------------------------------------------- #

-> Foram especificadas as structs para fila de Aluno, guardando matricula, ano, um ponteiro para nome e para o proximo aluno. Assim como listaAlunos, que recebe um ponteiro para o aluno de inicio da fila.
-> Foram especificadas as structs para arvore de Curso, guardando codigo, um poteiro para nome, centro, alunos e para o pai, filho a esquerda e a direita. Assim como Arvore, que recebe um ponteiro para a raiz da arvore.

-> Ao iniciar o programa, criamos uma lista de alunos e uma arvore vazias, e alocamos um espaço de memória para armazenar os dados que serão recebidos posteriormente.

-> Após, chamamos a função menu, que irá controlar toda a interação com o usuário. Para ela, passamos como parâmetro a arvore criada.

-> A seguir, a função menu (localizada na menu.c) imprime um "Menu Inicial", onde são apresentadas as opções de ações para o usuário, e de acordo com o input chama cada um das funções, passando por parâmetro os dados necessários.

-> Por fim, quando a opção "0" for escolhida para sair, o programa chega ao fim.

# ---------------------------------------------------------------------------- #
-> Caso necessário, abaixo estão as funcionalidades das funções implementadas.
# ---------------------------------------------------------------------------- #




# ---------------------------------------------------------------------------- #
#                                  menu.c                                      #
# ---------------------------------------------------------------------------- #

-> O controle geral ocorre na menu.c, onde o usuário informa a opção em que deseja seguir ou se deseja finalizar a operação.

-> As funções do menu são utilizadas para receber os dados necessários para as funções da lista.c e arvore.c chamadas nelas e assim executar a operação selecionada.

# ---------------------------------------------------------------------------- #
#                          Funções Auxiliares                                  #
# ---------------------------------------------------------------------------- #

-> lista.c: localizaAlunoAnterior.

-> Objetivo: auxiliar as funcoes de inserção e remoção, localizando e retornando o aluno anterior.

# ---------------------------------------------------------------------------- #
#                          Funções Criar                                       #
# ---------------------------------------------------------------------------- #

-> lista.c: criaListaAlunos e criaAluno.
-> arvore.c: arv_cria e arv_cria_no.

-> Objetivo: alocar memória, setar o dados respectivos as variáveis de cada elemento, setar o próximo elemente como nulo e retornar o elemento.

# ---------------------------------------------------------------------------- #
#                          Funções Buscar                                      #
# ---------------------------------------------------------------------------- #

-> lista.c: buscaAluno.
-> arvore.c: buscarCurso e buscaFilho.

-> Objetivo: percorrer a lista ou arvore para encontrar e retornar o elemento solicitado. 

# ---------------------------------------------------------------------------- #
#                          Funções Inserir                                     #
# ---------------------------------------------------------------------------- #

-> lista.c: insereAluno.
-> arvore.c: arv_insere, arv_insere_no e arv_insere_no2.

-> Objetivo: inserir um aluno na lista ou um no na arvore.

# ---------------------------------------------------------------------------- #
#                          Funções Remover                                     #
# ---------------------------------------------------------------------------- #

-> lista.c: removeAluno e liberaLista.
-> arvore.c: arv_remove_no, arv_remove_no2 e arv_remove_no3

-> Objetivo: remover ou liberar aluno, lista ou no da arvore.

# ---------------------------------------------------------------------------- #
#                          Funções Imprimir                                    #
# ---------------------------------------------------------------------------- #

-> lista.c: imprimeAlunos.
-> arvore.c: imprimeCursos.

-> Objetivo: percorrer e imprimir alunos ou cursos.

# ---------------------------------------------------------------------------- #
#                          Funções Interacao                                   #
# ---------------------------------------------------------------------------- #

-> arvore.c: adicionarCurso, removerCurso, adicionarAluno, removerAluno, imprimirCursos, imprimirAlunos e imprimeRelatorioCursos.

-> Objetivo: chamar as respectivas funções solicitadas e passar os parametros necessários.
