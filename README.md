# Jantar dos Filósofos

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

Este é um projeto implementado em C como parte do currículo da escola 42 (ou outro contexto educacional), que simula o problema clássico do "Jantar dos Filósofos" usando threads e semáforos.

## Descrição

O "Jantar dos Filósofos" é um problema clássico da computação concorrente, que desafia a sincronização de múltiplas threads que compartilham recursos em um ambiente onde cada filósofo precisa pegar dois garfos para comer, mas os garfos são compartilhados entre eles.

Este projeto tem como objetivo demonstrar sua capacidade de implementar soluções eficientes para problemas de sincronização e concorrência, bem como seu conhecimento em programação em C.

## Funcionalidades

- Implementação do problema clássico do Jantar dos Filósofos.
- Uso de threads para representar os filósofos.
- Uso de semáforos para garantir a sincronização e evitar deadlock.
- Medição do tempo gasto pela simulação.

## Pré-requisitos

- Compilador C (e.g., GCC)
- Sistema operacional Unix/Linux (ou equivalente)
- Biblioteca padrão do C

## Como usar

1. Clone o repositório:

```bash
git clone https://github.com/tonnytg/42_philosophers.git
make
./philo [número_de_filósofos] [tempo_para_morrer] [tempo_para_comer] [tempo_para_dormir] [número_de_refeições]
```

## Exemplo

```
./philo 5 800 200 200 10
```
