# Sistema mais Avançado e Completo

# 🚗 Sistema de Controle de Estacionamento com Arduino

Este projeto implementa um sistema de controle automatizado para um estacionamento com capacidade para 20 vagas utilizando Arduino. O sistema gerencia a abertura e fechamento de uma cancela (controlada por um servo motor), monitora a disponibilidade de vagas em tempo real via display LCD e envia logs detalhados para o Serial Monitor.

---

## 📸 Demonstração do Projeto

![Imagem do Circuito do Estacionamento](imagemTinkerCad.png)

*Circuito montado e simulado com sucesso.*

---

## 🛠️ Hardware e Pinagem

Abaixo está o mapeamento dos componentes utilizados no projeto e suas respectivas conexões no Arduino:

| Componente | Pino(s) Arduino | Função no Sistema |
| :--- | :--- | :--- |
| **Botão ENTRADA** | `2` | Solicita a abertura da cancela (entrada do veículo). |
| **Botão SAÍDA** | `3` | Fecha a cancela após a passagem do veículo. |
| **Servo Motor** | `4` | Atua como a cancela/catraca física do estacionamento. |
| **LED Vermelho** | `5` | Indica que a cancela está FECHADA ou que o estacionamento está LOTADO. |
| **LED Verde** | `6` | Indica que a cancela está ABERTA. |
| **Display LCD (16x2)** | `12, 11, 10, 9, 7, 8` | Exibe o status da cancela e o número de vagas disponíveis. |

---

## ⚙️ Funcionalidades e Regras do Sistema

* **Monitoramento em Tempo Real:** O display LCD exibe constantemente o status da cancela (`FECHADO` ou `ABERTO :D`) e o número atualizado de vagas disponíveis.
* **Controle de Acesso:** * Ao pressionar o **Botão de Entrada**, se houver vagas, a cancela abre (Servo em 0°), o LED verde acende, a vaga é contabilizada e o sistema emite um aviso no Serial Monitor.
  * Ao pressionar o **Botão de Saída**, a cancela fecha (Servo em 90°), o LED vermelho acende e o status retorna para fechado.
* **Bloqueio de Lotação:** A capacidade máxima está definida em **20 vagas**. Quando o limite é atingido:
  * A entrada é bloqueada automaticamente (a cancela não abre).
  * O LED vermelho pisca 3 vezes rapidamente como alerta visual.
  * O Serial Monitor exibe a mensagem de `ESTACIONAMENTO LOTADO`.
* **Tratamento de Debounce Visual:** Os botões possuem verificação de estado atual e anterior para garantir que ações repetidas ou prolongadas enviem o comando apenas uma vez.

---

## 📚 Bibliotecas Utilizadas

Para que o código funcione corretamente, certifique-se de incluir as seguintes bibliotecas padrão do Arduino:
* `<Servo.h>`: Para o controle do motor da cancela.
* `<LiquidCrystal.h>`: Para o controle do display LCD.

---

## 🖥️ Monitor Serial

O sistema foi programado para se comunicar a uma velocidade de **9600 baud**. Ao iniciar ou interagir com o sistema, as seguintes mensagens poderão ser visualizadas no Monitor Serial:

* **Início:** `SISTEMA INICIADO | Capacidade: 20 vagas`
* **Entrada:** `'ENTRADA registrada | Vagas ocupadas: [X] | Vagas disponíveis: [Y]`
* **Fechamento:** `'CANCELA FECHADA'`
* **Lotação:** `'ESTACIONAMENTO LOTADO — entrada bloqueada | Vagas:0/20'`<img width="1292" height="592" alt="image" src="https://github.com/user-attachments/assets/6312a8e6-1663-4fbe-a57c-c4a69cd7f285" />
