# Trabalho Prático: Sistema de Controle de Estacionamento

**Formato:** Individual
**Plataforma:** Wokwi ou Tinkercad

---

## 📌 Sobre o Projeto

Este projeto consiste em atuar como engenheiro de software para desenvolver o sistema de controle completo de um estacionamento universitário com capacidade para 20 vagas.

O sistema desenvolvido em Arduino tem como objetivos principais:
* Controlar fisicamente a cancela de entrada.
* Registrar a movimentação de veículos e gerenciar as vagas disponíveis em tempo real.
* Informar ao operador, a qualquer momento, a quantidade de vagas ocupadas e livres.
* Bloquear a entrada automaticamente quando o estacionamento estiver lotado.

---

## 🛠️ Hardware e Circuito

O circuito deve ser montado utilizando um Arduino, controlando a seguinte lista de componentes:

| Componente | Pino | Função |
| :--- | :--- | :--- |
| **LED verde** | 9 | Indica cancela ABERTA. |
| **LED vermelho** | 10 | Indica cancela FECHADA. |
| **Resistor 220 Ω (×2)** | - | Proteção para cada LED. |
| **Botão (Pushbutton) ENTRADA** | 2 | Abre a cancela (veículo entra). |
| **Botão (Pushbutton) SAÍDA** | 3 | Fecha a cancela (veículo entrou). |

**Observações de Montagem:**
* O ânodo de cada LED (perna longa, +) deve ser conectado ao respectivo pino do Arduino.
* O cátodo (perna curta, -) deve ser conectado ao GND através de um resistor de 220 Ω.
* Cada botão possui um terminal conectado ao pino designado e o outro conectado ao GND.

---

## ⚙️ Regras de Negócio e Funcionalidades

### 1. Estado Inicial
* Ao iniciar, o sistema deve manter a cancela fechada, com o LED vermelho aceso e o LED verde apagado.

### 2. Controle da Cancela
* **Botão ENTRADA (Abertura):** Ao ser pressionado, o LED verde acende e o vermelho apaga, abrindo a cancela. O sistema deve verificar a disponibilidade de vagas; se não houver vagas, a cancela não abre.
* **Botão SAÍDA (Fechamento):** Indica que o veículo entrou. A cancela deve ser baixada, acendendo o LED vermelho e apagando o LED verde.
* **Estado Persistente:** O estado da cancela é mantido entre as ações. Se estiver aberta sem interação nos botões, ela permanece aberta até que o botão de saída seja acionado.

### 3. Contador e Controle de Vagas
* A capacidade máxima do estacionamento é de 20 vagas, o que deve ser definido no código através de uma constante (`#define`) para facilitar manutenções.
* Cada vez que a cancela for aberta para a entrada de um veículo, o contador de vagas ocupadas deve ser incrementado.
* As vagas disponíveis são calculadas automaticamente pela fórmula: `disponíveis = total - ocupadas`.
* **Estacionamento Lotado:** Quando as vagas disponíveis chegarem a zero, a abertura da cancela é bloqueada. O sistema deve fazer o LED vermelho piscar 3 vezes rapidamente e exibir 'LOTADO' no Serial Monitor.

---

## 🖥️ Log no Serial Monitor

O sistema se comunica via Serial Monitor a uma taxa de **9600 baud**. É obrigatório que as ações nos botões gerem a mensagem apenas uma vez a cada clique, sem repetição enquanto o botão é mantido pressionado.

**Mensagens esperadas:**
* **Ao ligar o sistema:** `'SISTEMA INICIADO | Capacidade: 20 vagas | Vagas disponíveis: 20'`.
* **Ao abrir a cancela:** `'ENTRADA registrada | Vagas ocupadas: X | Vagas disponíveis: Y'`.
* **Ao fechar a cancela:** `'CANCELA FECHADA'`.
* **Ao tentar entrar lotado:** `'ESTACIONAMENTO LOTADO entrada bloqueada | Vagas: 0/20'`.

---

## ✅ Critérios de Avaliação

Verifique os itens abaixo antes de enviar o link do projeto:

- [ ] Circuito correto no Wokwi ou Tinkercad com todos os componentes nos pinos indicados.
- [ ] Botão de entrada abre a cancela (LED verde acende, LED vermelho apaga).
- [ ] Botão de saída fecha a cancela (LED vermelho acende, LED verde apaga).
- [ ] Estado da cancela persiste após soltar o botão.
- [ ] Sistema inicia com LED vermelho aceso e mensagem de inicialização no Serial Monitor.
- [ ] Contador de vagas ocupadas incrementa corretamente a cada entrada.
- [ ] Vagas disponíveis são calculadas e exibidas corretamente no Serial Monitor.
- [ ] Sistema bloqueia entrada quando lotado cancela não abre.
- [ ] LED vermelho pisca 3 vezes e exibe 'LOTADO' quando bloqueado.
- [ ] Cada ação gera apenas uma mensagem no Serial Monitor (sem repetição).
- [ ] Código organizado com `#define` para os pinos e para a capacidade máxima.
