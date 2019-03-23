# fracoes.c
Estava fazendo um programa em C para classificar e calcular as soluções de sistemas lineares como uma forma de revisar o conteúdo e 
percebi que pelas aproximações decimais da linguagem, os erros, às vezes, se acumulavam a ponto de resultarem em valores bem distantes da
realidade. Então criei esse arquivo de C com funções sobre frações para, quem sabe, assim obter resultados mais precisos.

O arquivo conta com as quatro funções matemáticas elementares aplicadas a função (adição, substração, multiplicação e divisão). Ainda não
pensei em usos para outras possíveis usos.

Além dessas quatro operações, principalmente devido às operações de adição e subtração, também conta com operações para determinar o MMC 
de dois números e a fatoração de um número em seus primos, que foram usadas nessas outras funções. A leitura de frações pode funcionar de 
duas formas, uma vez que criei duas funções para tal.
Existe a "stof", ou seja, "string to fraction", que lê uma string, separa-a pela "/" e usa a estrutura fração criada no arquivo para 
separar seu numerador e seu denominador. Existe também a possibilidade de ler do teclado uma fração, com a "leitura", que lê no formado 
scanf("%d/%d") e atribui os dois numerais ao numerador e ao denominador, respectivamente.
Criei, também, uma função de escrita padronizada das frações. Que analisa o sinal dela e se o denominador é 1. Seu nome é "escreve" (sim, 
sou bem criativo com nomes).
Por último, existe a função "simplificação" que, dada uma fração, simplifica ao máximo seus valores. Ela é chamada também nas funções de 
leitura, soma, subtração, multiplicação e divisão, de modo que a resposta seja sempre a forma mais simplificada da fração.

Realizei alguns diversos testes já em suas funções e os erros que encontrei foram corrigidos. Porém, não duvido que ainda tenham 
permanecido erros, inconscistências e cenários não previstos por mim. Então estou disposto a revisar frequentemente seus cenários e 
aplicar em outros programas a fim de descobrir mais facilmente qualquer defeito.

Não sei quanto a uma real necessidade de ter criado essas funções para realizar operações com frações, porém pelo que procurei no Google,
não achei nenhuma outra função pré-pronta para operar com frações e os erros de aproximações da sexta casa nos floats estava me 
incomodando e atrapalhando a precisão de meus programas. Espero, agora, poder aplicar essas funções e obter valores mais precisos.

Creio que este seja meu primeiro programa real no GitHub. Então qualquer erro ou má prática, ficaria agradecido de ser avisado.

Por fim, acho que é isso por enquanto. Se houverem atualizações, farei o commit delas aqui.
