# ---------------------------------------------------------------------------- #
#                          Funcionalidades Construídas                         #
# ---------------------------------------------------------------------------- #

-> Foram construídas todas as funcionalidades solicitadas no trabalho

# ---------------------------------------------------------------------------- #
#                          Organização do Programa                             #
# ---------------------------------------------------------------------------- #

-> Foram especificadas as structs de Aluno, Professor, Projeto e Vinculo, assim como suas listas que recebem ponteiros: listaAluno, listaProfessor, listaProjeto e listaVinculo.

-> Ao iniciar o pragrama, criamos uma lista vazia para cada uma das listas citadas acima e alocamos um espaço de memória para armazenar os dados que serão recebidos posteriormente.

-> Após, chamamos a função menu, que irá controlar toda a interação com o usuário. Para ela, passamos como parâmetros alunos, professores, projetos e vinculos.

-> Por fim, a função menu (localizada na menu.c) imprime um "Menu Inicial", onde são apresentadas as opções de ações para o usuário, e de acordo com o input chama cada um das funções, passando por parâmetro os dados necessários.

# ---------------------------------------------------------------------------- #
-> Caso necessário, abaixo estão as funcionalidades das funções implementadas.
# ---------------------------------------------------------------------------- #




# ---------------------------------------------------------------------------- #
#                                  menu.c                                      #
# ---------------------------------------------------------------------------- #

-> O controle geral ocorre na menu.c, onde o usuário informa a opção em que deseja seguir ou se deseja finalizar a operação.

-> As funções do menu são utilizadas para receber os dados necessários para as funções da lista.c chamadas nelas e assim executar a operação selecionada.

# ---------------------------------------------------------------------------- #
#                          Função cadastrarAluno                               #
# ---------------------------------------------------------------------------- #

-> Objetivo: receber os dados para cadastrar um aluno na lista, utilizando insereAluno.

-> Nessa função, recebe-se a lista de alunos por parâmetro e aloca-se memória para nome e telefone, e um int para a matrícula.

-> Em seguida, os dados são informados pelo usuário por input e associados as respectivas variáveis.

-> Por fim, é chamada a função insereAluno e uma mensagem de sucesso é escrita, caso o cadastro tenha ocorrido de forma correta.

# ---------------------------------------------------------------------------- #
#                          Função cadastrarProfessor                           #
# ---------------------------------------------------------------------------- #

-> Objetivo: receber os dados para cadastrar um professor na lista, utilizando insereProfessor.

-> Nessa função, recebe-se a lista de professores por parâmetro e aloca-se memória para nome e departamento, e um int para o código.

-> Em seguida, os dados são informados pelo usuário por input e associados as respectivas variáveis.

-> Por fim, é chamada a função insereProfessor e uma mensagem de sucesso é escrita, caso o cadastro tenha ocorrido de forma correta.

# ---------------------------------------------------------------------------- #
#                          Função cadastrarProjeto                             #
# ---------------------------------------------------------------------------- #

-> Objetivo: receber os dados para cadastrar um projeto na lista, utilizando insereProjeto.

-> Nessa função, recebe-se a lista de projetos e de professores por parâmetro e aloca-se memória para descrição e tipo, um int para o cod e para o cod do professor, e um float para o orçamento anual e para o orçamento atual.

-> Em seguida, os dados são informados pelo usuário por input e associados as respectivas variáveis.

-> A função buscaProfessor é utilizada para identificar se o professor informado é válido, caso não , descrição e tipo são liberados, o projeto não é cadastrado e uma mensagem de professor não cadastrado é exibida.

-> Por fim, caso o professor for válido, a função insereProjeto é chamada e uma mensagem de sucesso é escrita, caso o cadastro tenha ocorrido de forma correta.

# ---------------------------------------------------------------------------- #
#                          Função cadastrarVinculo                             #
# ---------------------------------------------------------------------------- #

-> Objetivo: receber os dados para cadastrar um vinculo na lista, utilizando insereVinculo.

-> Nessa função, recebe-se a lista de vinculos, alunos e projetos por parâmetro e cria-se um int para o código do projeto e matricula do aluno, e um float para o valor da bolsa e para o orçamento atual.

-> Em seguida, os dados são informados pelo usuário por input e associados as respectivas variáveis.

-> As funçãos buscaProjeto e buscaAluno são utilizada para identificar se ambos informados são válidos, caso não, uma mensagem de não cadastrado é exibida para o que não foi identificado.

-> A função buscaOrcamentoAtualProjeto é utilizada para verificar se há orçamento para a criação do vínculo, caso não, uma mensagem de orçamento insuficiente é exibida.

-> Por fim, caso as buscas forem válidas, a função insereVinculo é chamada e uma mensagem de sucesso é escrita, caso o cadastro tenha ocorrido de forma correta.

# ---------------------------------------------------------------------------- #
#                          Função removerVinculo                               #
# ---------------------------------------------------------------------------- #

-> Objetivo: receber os dados para remover um vinculo na lista, utilizando excluiVinculo.

-> Nessa função, recebe-se a lista de vinculos, projetos e alunos por parâmetro e cria-se um int para a matrícula do aluno, código do projeto e quantidade de meses.

-> Em seguida, os dados são informados pelo usuário por input e associados as respectivas variáveis.

-> Por fim, é chamada a função excluiVinculo.


# ---------------------------------------------------------------------------- #
-> A funcionalidade das funções da lista.c citadas serão explicadas abaixo.
# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
#                                 lista.c                                      #
# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
#                          Funções criaLista                                   #
# ---------------------------------------------------------------------------- #

-> criaListaAlunos, criaListaProfessores, criaListaProjetos e criaListaVinculos.

->  Objetivo: alocar memória, setar o inicio como nulo e retornar a lista.

# ---------------------------------------------------------------------------- #
#                          Funções cria                                        #
# ---------------------------------------------------------------------------- #

-> criaAluno, criaProfessor, criaProjeto e criaVinculo.

->  Objetivo: alocar memória, setar o dados respectivos as variáveis de cada elemento, setar o próximo elemente como nulo e retornar o elemento.

# ---------------------------------------------------------------------------- #
#                          Funções insere                                      #
# ---------------------------------------------------------------------------- #

-> insereAluno, insereProfessor, insereProjeto e insereVinculo.

-> Objetivo: localizar o ultimo elemento da lista, criar o elemento e o insere na lista.

# ---------------------------------------------------------------------------- #
#                          Funções busca                                       #
# ---------------------------------------------------------------------------- #

-> buscaAluno, buscaProfessor, buscaProjetoe, buscaVinculo, buscaVinculoAnterior e buscaOrcamentoAtualProjeto.

-> Objetivo: buscar o elemento desejado confome o identificador, percorrendo-a e retorna-lo.

# ---------------------------------------------------------------------------- #
#                          Funções localizaUltimo                              #
# ---------------------------------------------------------------------------- #

-> localizaUltimoAluno, localizaUltimoProfessor, localizaUltimoProjeto e localizaUltimoVinculo.

-> Objetivo: localizar o ultimo elemento inserido na lista, percorrendo-a e retorna-lo.

# ---------------------------------------------------------------------------- #
#                          Funções exclui                                      #
# ---------------------------------------------------------------------------- #

-> excluiVinculo.

-> Objetivo: busca o elemento a ser retirado da lista, o anteriore e o projeto, se o elemento existir, atualiza a lista e o orçamento, e libera o elemento.

# ---------------------------------------------------------------------------- #
#                          Funções imprime                                     #
# ---------------------------------------------------------------------------- #

-> imprimeAlunos, imprimeProfessores, imprimeProjetos e imprimeVinculos.

-> Objetivo: percorrer a lista e imprimir seus elementos.

# ---------------------------------------------------------------------------- #
#                             Relatório                                        #
# ---------------------------------------------------------------------------- #

-> vinculosProjeto

Objetivo: verificar se existem e impimir os alunos vinculados, caso não, a mensagem que não há alunos vinculados no projeto é exibida.

-> imprimirRelatorio

Objetivo: percorrer a lista e imprimir o código do projeto, tipo do projeto, nome do professor coordenador do projeto e orçamento atual disponível para o projeto.
