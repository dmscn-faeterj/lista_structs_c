# lista_structs_c
Lista de exercicios proposta pela faculdade com 3 problemas utlizando structs.
Prof.: José Wilson

## 1º Problema
Utilizando "struct", fazer um programa em C que permita a entrada de nome, email e telefone de 5 pessoas. Em seguida, apresente-os na tela indexados em ordem alfabética pelo campo nome.

## 2º Problema
Fazer um programa para simular uma agenda de telefones. Para acda pessoa devem-se ter os seguintes dados:
* Nome
* E-mail
* Endereço (contendo campos para rua, número, complemento, bairro, cep, cidade, estado, país)
* Telefone (contendo campo para DDD e número)
* Data de Nascimento
* Observações: Uma linha (string) para alguma observação especial

a) Definir a Estrutura acima.

b) Declarar a variável agenda (vetor) com capacidade de agendar até 100 nomes.

c) Escrever uma função que busca por primeiro nome: Imprime os dados do indivíduo com esse nome (se tiver mais de uma pessoa, imprime todas).

d) Escrever uma função que busca por mes de aniversario: Imprime os dados de todos os indivíduos que fazem aniversario nesse mes.

e) Escrever uma função que busca por mes e dia de aniversario: Imprime os dados de todos os indivíduos que fazem aniversario nesse dia e mes.

f) Escrever uma função que insere indivíduo: Insere por ordem alfabética do campo nome.

g) Escrever uma função que remova um indivíduo: Remove o registro do indivíduo e reorganiza o vetor para não deixar buracos.

h) Escrever uma função que imprima toda a agenda com os campos.

* (Resumida) nome, telefone e e-mail
* (Completa) todos os dados

i) O programa deve ter um menu principal oferecendo

* As opções acima solicitadas
* Uma opção de salvar a agenda em um arquivo (o nome do arquivo deve ser solicitado)
* Uma opção de carregar a agenda de um arquivo previamente salvo (o nome do arquivo deve ser solicitado)
* Uma opcão de sair do programa (solicitar confirmação de sair sem salvar)
