# Script de Correção #
## Tutorial Rápido ##

Para executar o Script existe uma pasta com um exercício de exemplo, "exercicio_exemplo_soma/".

Dentro desta pasta existem 4 outras pastas: 
  - Casos: esta pasta contem os casos de teste com as entradas e as saídas para cada caso.
  - Gabarito-obj: esta pasta contem os arquivos objetos (.o) do código correto feito pelo professor (não está disponível).
  - Includes: esta pasta contem os arquivos header (.o) do código correto feito pelo professor.
  - Respostas: esta pasta é a pasta que contém a resposta do aluno. Dentro dela tem um exemplo de código do aluno FernandoMoreira.

Copie o script "correcao.sh" que está na pasta raíz do repositório para dentro dessa pasta "exercicio_exemplo_soma/"
Para executar o script rode no terminal:
      ./correcao.sh

Depois que executar, o script irá:
 1 - Verificar se o aluno fez todos os arquivos fonte corretamente com o mesmo nome que foi solicitado.
 2 - Compilar o código do aluno e checkar se tem erros de compilação.
 3 - Linkar os arquivos objetos (.o) com os do professor que estão na pasta "Gabarito-obj/" para checkar se tem erros de linkagem.
 4 - Executar com valgrind o binário gerado pela compilação do código do aluno.
 5 - Checkar se os resultados da execução bateram com os resultados da pasta "Casos/" na raíz do exemplo.
 6 - Checkar se tiveram erros de valgrind, como alocação de memória sem free.
 7 - Dar uma nota final para o aluno gerando um arquivo chamado "Resultado.csv" na rapiz da pasta do exemplo.

Então note que, toda vez que você quiser testar algum código que você fez de algum exercício, faça o seguinte:
 1 - Crie uma pasta para o seu exercício.
 2 - Verifique se vc possui a pasta "Casos/" com os entradas e resultados do exercicio, e copie ela para dentro da pasta para o seu exercício.
 3 - Verifique se vc possui a pasta "Gabarito-obj/" com os objetos (.o) do professor, e copie ela dentro da pastado o seu exercício.
 4 - Verifique se vc possui a pasta "Includes/" com os arquivos header (.h) do professor e copie ela dentro da pastado o seu exercício. (note que não é necessário ter arquivos dentro dessa pasta caso o código do professor não tenha .h)
 5 - Crie uma pasta "Respostas/", e dentro dessa pasta crie outra pasta com o seu nome, sem espaços, por exemplo "Respostas/FernandoMoreira/", como está no exercicio exemplo. 
 6 - Coloque todos os seus arquivos do código fonte dentro dessa pasta com seu nome.
 7 - Copie o script "correcao.sh" para dentro da pasta raíz do seu exercício.
 8 - Execute no terminal: ./correcao.sh

## Explicação Detalhada ##
Este script serve para corrigir exercícios e trabalhos de alunos para a linguagem C.

Para o funcionamento correto do script, dois requisitos precisam ser cumpridos.

 1. O código dos exercícios e dos trabalhos providos pelo professor devem estar corretos e funcionando.
 2. Os casos de teste para os exercícios e os trabalhos devem funcionar corretamente no código do professor, para assim as respostas serem comparadas com as respostas dos alunos.

 Com esses requisitos cumpridos, o script pode ser executado.

 ### Como executar o script

 #### Criando os diretórios

 Primeiramente um diretório deverá ser criado, podemos chamá-lo de 'ScriptCorrecao/', e dentro desse diretório deverão ser criadas pastas da sequinte forma:

    - ScriptCorrecao/
        - Casos/
            - 1/
                entrada_1.txt
            - 2/
                entrada_2.txt
            .
            .
            .

            - x/
                entrada_x.txt    
        - Gabarito-src/
            *.c
            *.h
        - correcao.sh

Onde 'Gabarito-src/' é a pasta onde estará o código fonte provido pelo professor com os arquivos .h e os .c do trabalho ou exercício. 

A pasta 'Casos/', são os casos de teste com entradas que serão usadas para gerar as saídas correspondentes ao caso de teste, ou seja o script fará com que primeiramente o código dentro de 'Gabarito-src/' use os casos para gerarem os resultados.

O arquivo correcao.sh é o script propriamente dito que será executado no terminal.

#### Executando o script

Para executar o script, simplesmente rode: 
 
    ./correcao.sh

O script possui 4 parâmetros de execução:

  1. --professor
    - Ao rodar './correcao.sh --professor', o script irá compilar e executar o código dentro da pasta 'Gabarito-src/' utilizando as entradas dentro da pasta 'Casos/'. Assim todos os resultados dos casos serão gerados em uma pasta 'saida/' dentro de cada caso. Além disso, uma pasta 'Includes/' também será criada e os .h do professor dentro da pasta 'Gabarito-src/' serão copiados para lá. Uma pasta 'Gabarito-obj/' também será criada com os .o e o binário 'prog' gerados pela compilação. Dessa forma, a primeira execução do script deverá ser utilizando o parâmetro '--professor'. Então a hierarquia do diretório ficará da seguinte forma:

            - ScriptCorrecao/
                - Casos/
                    - 1/
                        - saida/
                            out_entrada_1.txt
                        entrada_1.txt
                    - 2/
                        - saida/
                            out_entrada_2.txt
                        entrada_2.txt
                    .
                    .
                    .

                    - x/
                        - saida/
                            out_entrada_x.txt
                        entrada_x.txt    
                - Gabarito-obj/
                    *.o
                    prog
                - Gabarito-src/
                    *.c
                    *.h
                - Includes/
                    *.h
                - correcao.sh

  2. --interfacefixa
    - Ao rodar './correcao.sh --interfacefixa', o script irá verificar se o aluno criou a mesma quantidade de arquivos .c e .h correspontente ao professor, como também se os nomes dos arquivos são os mesmos, assim caso o aluno tenha criado algum .c a mais, ele será desconsiderado na compilação e provavelmente erros de linkagem irão acontecer. Caso o script seja rodado sem esse parâmetro, e se o aluno criou algum .c a mais, então esse arquivo será considerado na compilação, porém se der erro de compilação, erro de valgrind ou erro de resultado, o aluno será penalizado.

  3. --resultados
    - Ao rodar './correcao.sh --resultados', o script irá desconsiderar se o aluno errou algum resultado de output, assim qualquer erro desse tipo não será considerado na nota.

  4. --valgrind
    - Ao rodar './correcao.sh --valgrind', o script irá desconsiderar se o aluno obteve algum erro de alocação de memória ou algo do tipo, assim qualquer erro desse tipo não será considerado na nota.

Após rodar o script com o parâmetro '--professor', a pasta com o código dos alunos deverá ser criada manualmente com o nome 'Respostas/' e dentro dessa pasta, terá as pastas com os nomes os alunos (sem espaço) e o código fonte deles. Assim a hierarquia do diretório ficará da seguinte forma:

    - ScriptCorrecao/
        - Casos/
        - Gabarito-src/
        - Includes/
        - Respostas/
            - Aluno1/
                *.c
                *.h
            - Aluno2/
                *.c
                *.h
            .
            .
            .
            - AlunoX/
                *.c
                *.h
        - correcao.sh

Com a pasta 'Respostas/' criada, o script deverá ser executado sem nenhum parâmetro: ./correcao.sh

Desse jeito, o script compila e roda o código dos alunos utilizando as entradas da pasta 'Casos/', e gerando as respostas dentro da pasta 'Resultados/' que será criada automaticamente na raíz da pasta 'ScriptCorrecao/'.

Dentro dessa pasta 'Resultados/' serão criadas pastas com os nomes dos alunos seguindo a hierarquia parecida com a pasta 'Respostas/', porém dentro de cada pasta do aluno será criada uma pasta para cada nome do .o do professor dentro da pasta 'Gabarito-obj/'. 

Por exemplo, se dentro da pasta 'Gabarito-obj/' existem os arquivos:
 
 - file1.o
 - file2.o
 - file3.o
 - file4.o

 Então dentro da pasta 'Resultados/' terá:

    - Resultados/
        - Aluno1/
            - completo/
            - file1/
            - file2/
            - file3/
            - file4/
        - Aluno2/
            - completo/
            - file1/
            - file2/
            - file3/
            - file4/
        .
        .
        .
        - AlunoX/
            - completo/
            - file1/
            - file2/
            - file3/
            - file4/

A pasta 'completo/' significa que todos os arquivos .c e .h do AlunoX da pasta 'Respostas/' serão copiados para lá, serão compilados e executados com as entradas da pasta 'Casos/', gerando os resultados sem nenhuma interferência do professor.

Já nas outras pastas como a 'file1/' por exemplo, seguirá parecido, todos os arquivos .c e .h do AlunoX na pasta 'Respostas/' serão copiados para lá e serão compilados gerando os .o, porém, os todos os arquivos .o do professor da pasta 'Gabarito-obj/' serão copiados para lá substituindo os .o do aluno gerados na compilação, exceto para o file1.o que permanecerá o do aluno, que é o referente a pasta 'file1/'. Isso fará com que durante a linkagem será verificado se os TAD's do aluno estão sendo feitos da maneira correta, se os .h não tiverem iguais aos do professor, dará erro de linkagem e o binário não será gerado. O mesmo segue para as outras pastas 'file2/', 'file3/' e 'file4/'.

Assim, dentro da pasta 'file1/', caso não tenha erros de linkagem, o binário 'prog' será gerado e com ele os testes serão feitos utilizando valgrind, será gerada uma pasta 'Casos/' dentro da pasta 'file1/' igualzinha a pasta 'Casos/' da raíz, porém agora com o resultado do aluno,       

Resumindo, o script verifica:
 - Se os arquivos .c e .h dos alunos foram enviados corretamente de acordo com os arquivos do professor, com o mesmo nome e quantidade.
 - Compila os arquivos e vê se teve erros de compilação.
 - Linka os objetos para gerar os executaveis, e vê se teve erros de linkagem.
 - Executa com valgrind os binários utilizando as entradas na pasta 'Casos/', verifica erros de valgrind e erros de resultado comparando com as saídas do professor.

Por fim, um arquivo 'Resultado.csv' é gerado no final com o nome de cada aluno e suas respectivas notas para cada quesito.

Assim a hierarquia final do diretório ficará da seguinte forma:

    - ScriptCorrecao/
        - Resultado.csv
        - correcao.sh
        - Casos/
            - 1/
                - saida/
                    out_entrada_1.txt
                entrada_1.txt
            - 2/
                - saida/
                    out_entrada_2.txt
                entrada_2.txt
            .
            .
            .
            - x/
                - saida/
                    out_entrada_x.txt
                entrada_x.txt    
        - Gabarito-obj/
            prog
            file1.o
            file2.o
            file3.o
            file4.o
        - Gabarito-src/
            *.c
            *.h
        - Includes/
            *.h
        - Respostas/
            - Aluno1/
                *.c
                *.h
            - Aluno2/
                *.c
                *.h
            .
            .
            .
            - AlunoX/
                *.c
                *.h
        - Resultados/
            - Aluno1/
                - completo/
                - file1/
                    file1.c
                    file2.c
                    file3.c
                    file4.c
                    file1.h
                    file2.h
                    file3.h
                    file4.h
                    main.c
                    prog
                    - Casos/
                        - 1/
                            - saida/
                                out_entrada_1.txt
                            entrada_1.txt
                        - 2/
                            - saida/
                                out_entrada_2.txt
                            entrada_2.txt
                        .
                        .
                        .
                        - x/
                            - saida/
                                out_entrada_x.txt
                            entrada_x.txt    
                - file2/
                - file3/
                - file4/
            - Aluno2/
                - completo/
                - file1/
                - file2/
                - file3/
                - file4/
            .
            .
            .
            - AlunoX/
                - completo/
                - file1/
                - file2/
                - file3/
                - file4/
