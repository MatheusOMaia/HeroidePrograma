Herói de programa
Feito por: Matheus Maia 31583709 e Henrique Rios 29131481

Introdução: Herói de programa é um jogo baseado nos RPGs de mesa criados pelo mestre Henrique, o RPG A Arte do Bilau Online: o Inimigo agora é outro o RPG
e o RPG Bilau:Saga do Shopping. O jogo é jogado em turnos diferentes que alternam entre você e o seu inimigo, no seu turno você poderá utilizar de 3 artifícios para alcançar sua vitória ou sua queda:

Ataque: Avança no seu inimigo com toda sua força;
Habilidades: Utiliza-se de uma de 3 habilidades poderosas;
Item: Usa um artefato poderoso guardado em seu bolso;

Inimigo: o Inimigo tem um leque de opções o Agredir,Habilidadee o Ataque Especial.

Extra: O jogo contêm um conteúdo extra, o qual é um simulador de dados. Ele simula dados.



Resultados: O jogo começa com um Menu feito em um grande Switch Case com cada case sendo uma das opções do menu ao escolher Jogar, Você entra em um case desenvolvido com dentro laços de repetições(turnos) e switch cases(ações e opções dentro das ações) os status dos personagens são criados em uma struct e depois têm seus valores atribuidos na main. Na batalha os status são aumentados ou diminuidos com base no que cada ataque, habilidade e item faz. A vida de um dos combatentes deve zerar para o loop da batalha terminar.
Escolhendo o simulador de dados você entra num loop que dentro possui outro case, o qual usa a função dado para escolher o dado que irá utilizar podendo repetir até digitar um número diferente de 1. 
Escolhendo sair o programa Fecha utilizando Return 0.

Problemas encontrados: 
1- Encontrar uma função de tornar aleatório os ataques do inimigo e os dados, a solução foi utilizar de uma função pseudoaleatória para fazer o trabalho
2- Scanf pegando o Enter fazendo com que a função continue de forma indesejada, a solução foi utilizar da função fflush






