# 42_philosophers

Esse é um problema clássico conhecido como o "Problema dos Filósofos Jantando" ou "Dining Philosophers Problem". O objetivo desse problema é encontrar uma solução que permita que os filósofos compartilhem os garfos e evitem bloqueios (deadlocks) enquanto satisfazem suas necessidades de comer, pensar e dormir. Aqui está a lógica básica do algoritmo para resolver esse problema:

Cada filósofo é modelado como uma thread (ou processo) separada, e os garfos são compartilhados recursos entre essas threads.

Cada filósofo alterna entre três estados: "comendo", "pensando" e "dormindo". Para evitar conflitos, os filósofos devem garantir que nenhum outro filósofo esteja usando os garfos adjacentes (à esquerda e à direita) ao mesmo tempo.

Um filósofo só pode comer se ambos os garfos adjacentes estiverem disponíveis. Caso contrário, eles precisam esperar até que possam pegar ambos os garfos.

Para evitar deadlock, cada filósofo pode pegar os garfos na ordem inversa em relação aos outros. Por exemplo, um filósofo pega primeiro o garfo à sua direita e depois o garfo à sua esquerda (ou vice-versa).

Se um filósofo não consegue pegar ambos os garfos, eles colocam o(s) garfo(s) que eles pegaram de volta na mesa e entram em estado de espera.

Um filósofo só pode comer quando ambos os garfos estão disponíveis. Após comer, eles colocam os garfos de volta na mesa e entram no estado de sono.

Após acordar do sono, um filósofo entra no estado de pensamento, e o ciclo recomeça.

O algoritmo continua até que algum filósofo morra de inanição (não consiga pegar os garfos para comer).

A ideia principal é garantir que os filósofos possam comer de forma segura, sem bloqueios, evitando que dois filósofos vizinhos tentem pegar os mesmos garfos ao mesmo tempo. Isso é conseguido através de uma estratégia de pegar garfos em ordens diferentes para cada filósofo, garantindo assim que pelo menos um deles possa comer.
