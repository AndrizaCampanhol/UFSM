# ---------------------------------------------------------------------------- #
#                          Funcionalidades Construídas                         #
# ---------------------------------------------------------------------------- #

-> Foram construídas todas as funcionalidades solicitadas no trabalho

# ---------------------------------------------------------------------------- #
#                            Organização do Programa                           #
# ---------------------------------------------------------------------------- #

-> Em escopo global, especificamos a struct de Municipios, definindo os tipos de dados.

-> Ao iniciar o programa, criamos um vetor de Municipios, recebemos o número de municípios e o número de dias por meio do input do usuário e alocamos um espaço de memória para armazenar os dados. 

-> Após, chamamos a função menu, que irá controlar toda a interação com o usuário. Para ela, passamos como parâmetros o vetor de municípios, o número de municípios e o número de dias.

-> Por fim, a função menu imprime um "Menu Inicial", onde são apresentadas as opções de ações para o usuário, e de acordo com o input chama cada um das funções, passando por parâmetro os dados necessários.

# ---------------------------------------------------------------------------- #
#                                Função preenche                               #
# ---------------------------------------------------------------------------- #

-> Objetivo: Preencher o vetor de municípios.

- Nessa função, ocorre a alocação de memória para o vetor nome, em seguida recebendo e armazenando seu conteúdo a partir do input do usuário.

- Após, ocorre a alocação de memória para a matriz de dados, percorrendo-a para receber e armazenar seu conteúdo.

# ---------------------------------------------------------------------------- #
#                                Função imprimir                               #
# ---------------------------------------------------------------------------- #

-> Objetivo: Imprimir os dados epidemiológicos gerais.

- Nessa função, percorre-se o vetor de municípios, calculando os dados epidemiológicos de cada um e imprimindo-os em seguida.

# ---------------------------------------------------------------------------- #
#                                 Função buscar                                #
# ---------------------------------------------------------------------------- #

-> Objetivo: Buscar e imprimir os dados de um município específico indicado pelo usuário.

- Nessa função, recebe-se o nome de um município a partir do input do usuário e percorre-se o vetor, identificando sua posição.

- Após, são impressos os dados do município especificado.

