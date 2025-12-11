# 🏨 **Documentação das Funcionalidades – Hotel Descanso Garantido**

## 📋 Visão Geral

Sistema de gerenciamento de hotel desenvolvido em C, permitindo controlar hóspedes, reservas, quartos e estadias, com operações completas de cadastro, edição, consulta, exclusão e baixa de estadia.

O sistema utiliza armazenamento em arquivos, menus organizados e rotinas auxiliares para facilitar o fluxo de operação.

---

# Estruturas de Dados

## 🛏️ Quarto

```c
typedef struct {
    int numero;              // Número do quarto
    char tipo[MAX_STRING];   // Tipo do quarto (solteiro, casal, luxo)
    float diaria;            // Valor da diária
    int ocupado;             // 0 = livre | 1 = reservado/ocupado
    int ativo;               // 1 = ativo | 0 = removido (exclusão lógica)
} Quarto;
```

## 👤 Hóspede

```c
typedef struct {
    int codigo;              // Código único do hóspede
    char nome[MAX_STRING];   // Nome completo
    char cpf[15];            // CPF único
    char telefone[20];       // Telefone
    int ativo;               // Status (1=ativo, 0=removido)
} Hospede;
```

## 📅 Reserva

```c
typedef struct {
    int codigo;              // Código único da reserva
    int codigo_hospede;      // Código do hóspede
    int numero_quarto;       // Número do quarto reservado
    int dias;                // Quantidade de dias
    float valor_total;       // Valor total calculado
    int ativa;               // Status da reserva (1=ativa, 0=cancelada)
} Reserva;
```

## 🧾 Estadia

```c
typedef struct {
    int codigo_estadia;      // Código único da estadia
    int codigo_reserva;      // Reserva associada
    char data_entrada[20];   // Data de check-in
    char data_saida[20];     // Data de check-out
    float valor_final;       // Valor calculado na baixa
    int ativa;               // 1=ativa | 0=finalizada
} Estadia;
```

---

# **Módulo de Quartos – Responsável: Pedro Dias**

## int buscar_quarto_por_numero(int numero)

**Propósito:** localizar um quarto pelo número.
**Entrada:** número do quarto
**Saída:** índice no array ou -1
**Responsável:** Pedro

---

## void cadastrar_quarto()

Propósito: cadastrar um novo quarto no hotel.
Entrada:

* Número do quarto
* Tipo (solteiro, casal, luxo)
* Valor da diária

Saída: nenhum
Funcionalidades:

* Verificação de duplicidade
* Validação de dados obrigatórios
* Salvamento no arquivo
  Responsável: Pedro

---

## void consultar_quartos()

Propósito: listar todos os quartos ativos.
Saída:

* Número
* Tipo
* Diária
* Status (livre/ocupado)

Funcionalidades:

* Ordenação crescente por número
* Exibição de apenas quartos ativos
  Responsável: Pedro

---

## void alterar_quarto()

Propósito: alterar informações de um quarto.
Entrada:

* Número do quarto
* Novo tipo ou nova diária

Funcionalidades:

* Busca por número
* Alteração seletiva
  Responsável: Pedro

---

## void excluir_quarto()

Propósito: remover um quarto (exclusão lógica).
Entrada:

* Número do quarto
* Confirmação do usuário

Funcionalidades:

* Marcar quarto como inativo
  Responsável: Pedro

---

# **Módulo de Hóspedes – Responsável: Victhor Guilherme**

## int buscar_hospede_por_cpf(char *cpf)

Propósito: localizar um hóspede pelo CPF.
Entrada: CPF
Saída: índice no array ou -1
Responsável: Victhor

---

## void cadastrar_hospede()

Propósito: cadastrar um novo hóspede.
Entrada:

* Nome
* CPF
* Telefone

Funcionalidades:

* Validação de CPF único
* Código gerado automaticamente
* Salvamento em arquivo
  Responsável: Victhor

---

## void consultar_hospedes()

Propósito: listar hóspedes ativos.
Saída:

* Código
* Nome
* CPF
* Telefone

Funcionalidades:

* Ordenação alfabética por nome
  Responsável: Victhor

---

## void alterar_hospede()

Propósito: alterar dados de um hóspede.
Entrada:

* CPF do hóspede
* Novos dados (nome e/ou telefone)

Regras:

* CPF NÃO é alterado
  Responsável: Victhor

---

## void excluir_hospede()

Propósito: remover hóspede (exclusão lógica).
Entrada: CPF
Saída: confirmação
Funcionalidades:

* Marcação do campo `ativo = 0`
  Responsável: Victhor

---

# 📅 **Módulo de Reservas – Responsável: Victhor Guilherme**

## int buscar_reserva_por_codigo(int codigo)

Propósito: localizar uma reserva.
Entrada: código
Saída: índice no array ou -1
Responsável: Victhor

---

## void cadastrar_reserva()

Propósito: criar uma reserva.
Entrada:

* CPF do hóspede
* Número do quarto
* Quantidade de dias

Funcionalidades:

* Validação de hóspede
* Validação de quarto livre
* Cálculo automático da diária
* Código gerado automaticamente
  Responsável: Victhor

---

## void consultar_reservas()

Propósito: listar reservas ativas.
Saída:

* Código
* Hóspede
* Quarto
* Dias
* Total

Responsável: Victhor

---

## void cancelar_reserva()

Propósito: cancelar uma reserva.
Entrada: código da reserva
Funcionalidades:

* Atualiza quarto para "livre"
* Marca reserva como inativa
  Responsável: Victhor

---

# *Módulo de Estadia – Responsável: Victhor Guilherme**

## void iniciar_estadia()

Propósito: converter uma reserva em estadia (check-in).
Entrada:

* Código da reserva
* Data de entrada

Regras:

* Reserva precisa estar ativa
  Responsável: Victhor

---

## void finalizar_estadia()

Propósito: realizar o check-out.
Entrada:

* Código da estadia
* Data de saída

Funcionalidades:

* Cálculo automático do valor final (diária × dias)
* Liberação do quarto
* Marcar estadia como finalizada
  Responsável: Victhor

---

# **Módulo de Arquivos – Responsável: Pedro Dias**

Funções de salvar e carregar:

* salvar_quartos()
* salvar_hospedes()
* salvar_reservas()
* salvar_estadias()
* carregar_quartos()
* carregar_hospedes()
* carregar_reservas()
* carregar_estadias()

Propósito: persistência dos dados.
Saída: arquivos `.txt` atualizados.
Responsável: Pedro

---

# Funções Auxiliares do Sistema

* limpar_buffer()
* pausar()
* ler_opcao_valida(min, max)
* formatar_data()

Responsáveis: **Pedro e Victhor**

---

# 📱 Funções de Interface e Navegação

* menu_principal()
* menu_quartos()
* menu_hospedes()
* menu_reservas()
* menu_estadias()

Controlam toda a navegação do sistema.
Responsáveis:

* Quartos – Pedro
* Hóspedes, Reservas, Estadia – Victhor

---

# 📊 Constantes do Sistema

```
MAX_QUARTOS = 50
MAX_HOSPEDES = 100
MAX_RESERVAS = 100
MAX_ESTADIAS = 200
MAX_STRING = 100
```

---

# 🔄 Fluxos Principais

## Fluxo de Reserva

1. Validar hóspede
2. Validar quarto livre
3. Registrar reserva
4. Atualizar quarto para “ocupado”

---

## Fluxo de Estadia (Check-in → Check-out)

1. Validar reserva ativa
2. Registrar entrada
3. Registrar saída
4. Calcular valor
5. Liberar quarto

---

# Regras de Negócio

* CPF e número do quarto são únicos
* Exclusões são lógicas (ativo = 0)
* Quarto só pode ter uma reserva ativa
* Estadia só pode existir com reserva
* Quarto é liberado automaticamente no check-out

---
