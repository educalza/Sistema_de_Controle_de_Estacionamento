# [cite_start]Trabalho Prático: Sistema de Controle de Estacionamento [cite: 4, 5]

[cite_start]**Formato:** Individual [cite: 6]
[cite_start]**Plataforma:** Wokwi ou Tinkercad [cite: 14]

---

## 📌 Sobre o Projeto

[cite_start]Este projeto consiste em atuar como engenheiro de software para desenvolver o sistema de controle completo de um estacionamento universitário com capacidade para 20 vagas[cite: 8].

[cite_start]O sistema desenvolvido em Arduino tem como objetivos principais[cite: 12]:
* [cite_start]Controlar fisicamente a cancela de entrada[cite: 9].
* [cite_start]Registrar a movimentação de veículos e gerenciar as vagas disponíveis em tempo real[cite: 9].
* [cite_start]Informar ao operador, a qualquer momento, a quantidade de vagas ocupadas e livres[cite: 10].
* [cite_start]Bloquear a entrada automaticamente quando o estacionamento estiver lotado[cite: 11].

---

## 🛠️ Hardware e Circuito

[cite_start]O circuito deve ser montado utilizando um Arduino, controlando a seguinte lista de componentes[cite: 12, 14]:

| Componente | Pino | Função |
| :--- | :--- | :--- |
| **LED verde** | 9 | [cite_start]Indica cancela ABERTA[cite: 15]. |
| **LED vermelho** | 10 | [cite_start]Indica cancela FECHADA[cite: 15]. |
| **Resistor 220 Ω (×2)** | - | [cite_start]Proteção para cada LED[cite: 15]. |
| **Botão (Pushbutton) ENTRADA** | 2 | [cite_start]Abre a cancela (veículo entra)[cite: 15]. |
| **Botão (Pushbutton) SAÍDA** | 3 | [cite_start]Fecha a cancela (veículo entrou)[cite: 15]. |

**Observações de Montagem:**
* [cite_start]O ânodo de cada LED (perna longa, +) deve ser conectado ao respectivo pino do Arduino[cite: 16].
* [cite_start]O cátodo (perna curta, -) deve ser conectado ao GND através de um resistor de 220 Ω[cite: 17].
* [cite_start]Cada botão possui um terminal conectado ao pino designado e o outro conectado ao GND[cite: 18].

---

## ⚙️ Regras de Negócio e Funcionalidades

### 1. Estado Inicial
* [cite_start]Ao iniciar, o sistema deve manter a cancela fechada, com o LED vermelho aceso e o LED verde apagado[cite: 21, 22, 23].

### 2. Controle da Cancela
* [cite_start]**Botão ENTRADA (Abertura):** Ao ser pressionado, o LED verde acende e o vermelho apaga, abrindo a cancela[cite: 20]. [cite_start]O sistema deve verificar a disponibilidade de vagas; se não houver vagas, a cancela não abre[cite: 20].
* [cite_start]**Botão SAÍDA (Fechamento):** Indica que o veículo entrou[cite: 20]. [cite_start]A cancela deve ser baixada, acendendo o LED vermelho e apagando o LED verde[cite: 20].
* [cite_start]**Estado Persistente:** O estado da cancela é mantido entre as ações[cite: 20]. [cite_start]Se estiver aberta sem interação nos botões, ela permanece aberta até que o botão de saída seja acionado[cite: 20].

### 3. Contador e Controle de Vagas
* [cite_start]A capacidade máxima do estacionamento é de 20 vagas, o que deve ser definido no código através de uma constante (`#define`) para facilitar manutenções[cite: 23].
* [cite_start]Cada vez que a cancela for aberta para a entrada de um veículo, o contador de vagas ocupadas deve ser incrementado[cite: 23].
* [cite_start]As vagas disponíveis são calculadas automaticamente pela fórmula: `disponíveis = total - ocupadas`[cite: 23].
* [cite_start]**Estacionamento Lotado:** Quando as vagas disponíveis chegarem a zero, a abertura da cancela é bloqueada[cite: 23]. [cite_start]O sistema deve fazer o LED vermelho piscar 3 vezes rapidamente e exibir 'LOTADO' no Serial Monitor[cite: 23].

---

## 🖥️ Log no Serial Monitor

[cite_start]O sistema se comunica via Serial Monitor a uma taxa de **9600 baud**[cite: 23]. [cite_start]É obrigatório que as ações nos botões gerem a mensagem apenas uma vez a cada clique, sem repetição enquanto o botão é mantido pressionado[cite: 24].

**Mensagens esperadas:**
* **Ao ligar o sistema:** `'SISTEMA INICIADO | Capacidade: 20 vagas | Vagas disponíveis: 20'`[cite: 23].
* **Ao abrir a cancela:** `'ENTRADA registrada | Vagas ocupadas: X | Vagas disponíveis: Y'`[cite: 23].
* [cite_start]**Ao fechar a cancela:** `'CANCELA FECHADA'`[cite: 23].
* **Ao tentar entrar lotado:** `'ESTACIONAMENTO LOTADO entrada bloqueada | [cite_start]Vagas: 0/20'`[cite: 23].

---

## ✅ Critérios de Avaliação

[cite_start]Verifique os itens abaixo antes de enviar o link do projeto[cite: 26]:

- [ ] [cite_start]Circuito correto no Wokwi ou Tinkercad com todos os componentes nos pinos indicados[cite: 27].
- [ ] [cite_start]Botão de entrada abre a cancela (LED verde acende, LED vermelho apaga)[cite: 28].
- [ ] [cite_start]Botão de saída fecha a cancela (LED vermelho acende, LED verde apaga)[cite: 29].
- [ ] [cite_start]Estado da cancela persiste após soltar o botão[cite: 30].
- [ ] [cite_start]Sistema inicia com LED vermelho aceso e mensagem de inicialização no Serial Monitor[cite: 31].
- [ ] [cite_start]Contador de vagas ocupadas incrementa corretamente a cada entrada[cite: 32].
- [ ] [cite_start]Vagas disponíveis são calculadas e exibidas corretamente no Serial Monitor[cite: 34].
- [ ] [cite_start]Sistema bloqueia entrada quando lotado cancela não abre[cite: 37].
- [ ] [cite_start]LED vermelho pisca 3 vezes e exibe 'LOTADO' quando bloqueado[cite: 38].
- [ ] [cite_start]Cada ação gera apenas uma mensagem no Serial Monitor (sem repetição)[cite: 39].
- [ ] [cite_start]Código organizado com `#define` para os pinos e para a capacidade máxima[cite: 39].
