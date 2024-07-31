# Script de Correção #

Este repositório contém o script :shipit: de correção dos exercícios e trabalhos da disciplina de Programação II. O script foi desenvolvido para funcionar com a linguagem de programação C e a idea é que todos tenham acesso e o utilizem para correção de todas as atividades realizadas ao longo da disciplina.

Este README é dividido em duas partes. A primeira explica de forma detalhada como o script deve ser utilizado para correção dos exercícios e trabalhos. A segunda parte é um tutorial de como o script funciona e como professores e monitores devem utilizá-lo para gerar as atividades.

___
:construction: **Nota:** o script de correção está em constante desenvolvimento. Por isso, é importante que você sempre atualize o repositório antes de utilizá-lo. Para isso, basta executar o comando `git pull` dentro da pasta do script. Além disso, caso encontre algum problema ou bug, reporte aos professores e/ou monitores
___

## Tutorial rápido de utilização ##

Para facilitar a explicação neste tutorial, este repositório possui uma pasta com um exercício de exemplo chamada `exercicio_exemplo_soma/`. É ela que será utilizada para explicar os principais pontos de atualização.

___
:movie_camera: **Vídeo:** caso você prefira, existe um tutorial em vídeo explicando a utilização do script para os alunos da disciplina. [Para acessar o vídeo clique aqui](https://drive.google.com/file/d/16ocpaWpCtXL1DWVhtOPikc7QPd-tLe8T/view).
___

Dentro desta pasta existem 4 outras pastas: 
  - `Casos`: contém os casos de teste com as entradas e as saídas para cada caso.
  - `Gabarito-obj`: contém os arquivos objetos (`.o`) do código correto feito pelo professor (não está disponível). O utilizador não precisa se preocupar  com ela.
  - `Includes`: contém os arquivos header (`.h`) do código correto feito pelo professor.
  - `Respostas`: contém a resposta do aluno. Dentro dela tem um exemplo de código do aluno FernandoMoreira.
    - Em um caso real de exercício, essa pasta não existe. Você precisa criar `Respostas/NomeAluno/` e colocar o código resposta do exercício dentro dela. Não utilize espaço, caracteres especiais ou acentos no nome do aluno.

Uma vez que você tenha preparado o diretório do exercício, copie o script `correcao.sh`, que está na pasta raíz deste repositório, para dentro da pasta do exercício, que neste exemplo é a pasta `exercicio_exemplo_soma/`.

Agora, abra um terminal na pasta do exercício e execute o script com o comando

```bash
./correcao.sh
```

:red_circle: **Importante:** caso seja exibido um erro de permissão, você deve executar o comando `chmod +x correcao.sh` para dar permissão de execução ao script.

Depois que executar, o script irá fazer o seguinte:

 1. Verificar se o aluno criou todos os arquivos fontes corretamente com o mesmo nome que foi solicitado.
 2. Compilar o código do aluno e verificar se existe erro de compilação.
 3. Linkar os arquivos objetos (`.o`) com os do professor que estão na pasta `Gabarito-obj/` para verificar se existe algum erro de linkagem.
 4. Executar com valgrind o binário gerado pela compilação do código do aluno.
 5. Verificar se os resultados da execução estão de acordo com os resultados da pasta `Casos/` na raíz da pasta do exercício.
 6. Verificar se houveram erros no valgrind, como vazamento de memória ou erro de gerenciamento de memória.
 7. Dar uma nota final para o aluno gerando um arquivo chamado `Resultado.csv` na raíz da pasta do exercício.

Então note que, toda vez que você quiser testar algum código que você fez de algum exercício, faça o seguinte:

 1. Crie uma pasta para o exercício (se ela não existir)


 2. Garanta que dentro da pasta do exercício, exista:   
    - A pasta `Casos/` com as entradas e saídas do exercicio
    - A pasta `Gabarito-obj/` com os objetos (`.o`) do professor
    - A pasta `Includes/` com os arquivos header (`.h`) do professor (note que não é necessário ter arquivos dentro dessa pasta caso o exercício não exija `.h`)
  
 
 3. Crie uma pasta `Respostas/`, e dentro dessa pasta crie outra pasta com o seu nome, sem espaços ou caracteres especiais, por exemplo `Respostas/FernandoMoreira/`, como está no exercicio exemplo. 
 4. Coloque todos os seus arquivos do código fonte dentro dessa pasta com seu nome.
 5. Copie o script `correcao.sh` para dentro da pasta raíz do seu exercício.
 6.  Execute o script no terminal com o comando `./correcao.sh`

## Explicação Detalhada

Para o funcionamento correto do script, três requisitos precisam ser cumpridos.

 1. O código dos exercícios e dos trabalhos providos pelos monitores e professores devem estar correto e funcionando.
 2. Os casos de teste para os exercícios e os trabalhos devem funcionar corretamente no código do professor, para assim as respostas serem comparadas com as respostas dos alunos.
 3. A organização do diretório do exercício deve seguir o padrão esperado pelo script (ver seções a seguir)

 Com esses requisitos cumpridos, o script pode ser executado.

 ### Como executar o script

 #### Criando os diretórios

 Primeiramente, um diretório deverá ser criado. Podemos chamá-lo de `ScriptCorrecao/`, e dentro desse diretório deverão ser criadas pastas da sequinte forma:

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
        - configuracoes

Na qual:

- `Gabarito-src/` é a pasta onde estará o código fonte provido pelo professor com os arquivos `.h` e os `.c` do trabalho ou exercício. 

- A pasta `Casos/`, são os casos de teste com entradas que serão usadas para gerar as saídas correspondentes ao caso de teste, ou seja, o script fará com que primeiramente o código dentro de `Gabarito-src/` use os casos para gerarem os resultados.

- O arquivo `correcao.sh` é o script propriamente dito que deve ser executado no terminal.

- O arquivo `configuracoes` é um arquivo de configuração que pode ser utilizado para definir algumas variáveis que o script utiliza. Por exemplo, quais arquivos devem ser usados para avaliação, qual o peso de cada arquivo, limite de tempo de execução, etc. Para mais informações, consulte os comentários disponíveis no arquivo `configuracoes` deste repositório.

____
**Importante:**
- Se for atribuído pontuação para opção `main` dentro do arquivo de `configuracao`, o script irá verificar se a `main` do aluno funciona corretamente junto com o código do professor.
- Se for atribuído pontuação para opção `completo` dentro do arquivo de `configuracao`, o script irá verificar se o código do aluno funciona independente do código do professor. Em outras palavras, ele apenas verifica se o código do aluno está correto e se ele passa nos testes.
____

 

#### Executando o script

Como já descrito anteriormente, para executar o script, basta abrir um terminal na pasta do exercício e executar o comando: `./correcao.sh`

O script possui 4 parâmetros de execução:

  1. **`--professor`:**  de maneira geral, essa opção deve ser utilizada para gerar todos os fontes do exercício. Normalmente, quem usa é o professor ou monitor. Ao executar `./correcao.sh --professor`, o script irá compilar e executar o código dentro da pasta `Gabarito-src/` utilizando as entradas dentro da pasta `Casos/`. Assim todos os resultados dos casos serão gerados em uma pasta `saida/` dentro de cada caso. Além disso, uma pasta `Includes/` também será criada e os `.h` do professor dentro da pasta `Gabarito-src/` serão copiados para lá. Uma pasta `Gabarito-obj/` também será criada com os `.o` e o binário `prog` gerados pela compilação. **Dessa forma, a primeira execução do script deverá ser utilizando o parâmetro `--professor`.** Então a hierarquia do diretório ficará da seguinte forma:

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
                - configuracoes

  3. **`--interfacefixa`:**
    Ao executar `./correcao.sh --interfacefixa`, o script irá verificar se o aluno criou a mesma quantidade de arquivos `.c` e `.h` correspontente ao professor, como também se os nomes dos arquivos são os mesmos, assim caso o aluno tenha criado algum `.c` a mais, ele será desconsiderado na compilação e provavelmente erros de linkagem irão acontecer. Caso o script seja rodado sem esse parâmetro, e se o aluno criou algum `.c` a mais, então esse arquivo será considerado na compilação, porém se der erro de compilação, erro de valgrind ou erro de resultado, o aluno será penalizado.

  4. **`--resultados`:**
    - Ao executar `./correcao.sh --resultados`, o script irá desconsiderar se o aluno errou algum resultado de output, assim qualquer erro desse tipo não será considerado na nota.

  5. **`--valgrind`:**
    - Ao rodar `./correcao.sh --valgrind`, o script irá desconsiderar se o aluno obteve algum erro de alocação de memória ou algo do tipo, assim qualquer erro desse tipo não será considerado na nota.

Após executar o script com o parâmetro `--professor`, a pasta com o código dos alunos deverá ser criada manualmente com o nome `Respostas/` e dentro dessa pasta, terá as pastas com os nomes os alunos (sem espaço) e o código fonte deles. Assim a hierarquia do diretório ficará da seguinte forma:

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

Com a pasta `Respostas/` criada, o script deverá ser executado sem nenhum parâmetro: `./correcao.sh`

Dessa maneira, o script compila e roda o código dos alunos utilizando as entradas da pasta `Casos/`, e gerando as respostas dentro da pasta `Resultados/` que será criada automaticamente na raíz da pasta `ScriptCorrecao/`.

Dentro dessa pasta 'Resultados/' serão criadas pastas com os nomes dos alunos seguindo a hierarquia parecida com a pasta 'Respostas/', porém dentro de cada pasta do aluno será criada uma pasta para cada nome do .o do professor dentro da pasta 'Gabarito-obj/'. 

Por exemplo, se dentro da pasta `Gabarito-obj/` existem os arquivos:
 
 - `file1.o`
 - `file2.o`
 - `file3.o`
 - `file4.o`

 Então dentro da pasta `Resultados/` terá:

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

A pasta `completo/` significa que todos os arquivos `.c` e `.h` do AlunoX da pasta `Respostas/` serão copiados para lá, serão compilados e executados com as entradas da pasta `Casos/`, gerando os resultados sem nenhuma interferência do professor.

Já nas outras pastas como a `file1/` por exemplo, seguirá parecido, todos os arquivos `.c` e `.h` do AlunoX na pasta `Respostas/` serão copiados para lá e serão compilados gerando os `.o`, porém, os todos os arquivos `.o` do professor da pasta `Gabarito-obj/` serão copiados para lá substituindo os `.o` do aluno gerados na compilação, exceto para o `file1.o` que permanecerá o do aluno, que é o referente a pasta `file1/`. Isso fará com que durante a linkagem será verificado se os TAD's do aluno estão sendo feitos da maneira correta, se os `.h` não tiverem iguais aos do professor, dará erro de linkagem e o binário não será gerado. O mesmo segue para as outras pastas `file2/`, `file3/` e `file4/`.

Assim, dentro da pasta `file1/`, caso não tenha erros de linkagem, o binário `prog` será gerado e com ele os testes serão feitos utilizando valgrind, será gerada uma pasta `Casos/` dentro da pasta `file1/` identica a pasta `Casos/` da raíz, porém agora com o resultado do aluno.    

Resumindo, o script verifica:
 - Se os arquivos `.c` e `.h` dos alunos foram enviados corretamente de acordo com os arquivos do professor, com o mesmo nome e quantidade.
 - Compila os arquivos e vê se teve erros de compilação.
 - Linka os objetos para gerar os executaveis, e vê se teve erros de linkagem.
 - Executa com valgrind os binários utilizando as entradas na pasta `Casos/`, verifica erros de valgrind e erros de resultado comparando com as saídas do professor.


Por fim, um arquivo `Resultado.csv` é gerado no final com o nome de cada aluno e suas respectivas notas para cada quesito.

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
