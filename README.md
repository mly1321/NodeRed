# NodeRed
Atividade de Tópicos da Industria 4.0

Este projeto teve como inspiração um sistema de sinalização de ruído dentro de uma biblioteca. Ele coleta dados de ruído e retorna um sinal luminoso que representa os níveis de ruído onde o verde significa que o ambiente está em silêncio, o amarelo que as pessoas devem reduzir o ruído e vermelho que indica ambiente com muito barulho. 
Quando a sinalização vermelha aciona, junto dela é acionado um servo motor que movimenta de forma a acionar um sino para que as pessoas se atentem ao silêncio.

A troca de dados do sistema será feita usando a comunicação serial e comunicação http, ela será feita entre um raspberry e um arduído usando nodered.

