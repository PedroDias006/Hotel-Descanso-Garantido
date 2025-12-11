# **BACKLOG DO PRODUTO – Hotel Descanso Garantido**

## 1 – Gestão de Hóspedes

* [x] Cadastrar hóspede
* [x] Consultar hóspedes
* [x] Alterar hóspede
* [x] Excluir hóspede (lógica)
* [x] Validação de CPF único

## 2 – Gestão de Quartos

* [x] Cadastrar quarto
* [x] Alterar quarto
* [x] Consultar quartos
* [x] Excluir quarto
* [x] Controle de disponibilidade

## 3 – Reservas

* [x] Criar reserva
* [x] Cancelar reserva
* [x] Calcular valor da reserva
* [x] Listar reservas ativas

## 4 – Estadia (Check-in / Check-out)

* [x] Iniciar estadia
* [x] Finalizar estadia
* [x] Calcular valor final
* [x] Liberar quarto automaticamente

## 5 – Persistência

* [x] Carregar dados de arquivos
* [x] Salvar dados de arquivos
* [x] Salvamento geral na saída

**Total de itens:** 22
**Concluídos:** 22 (100%)

---

# **SPRINT 1 – Quartos**

### Objetivo

Implementar módulo básico de quartos com suporte ao restante do sistema.

### Entregas

* Estrutura `Quarto`
* Cadastro, consulta e exclusão
* Validação de número único
* Arquivo `quartos.txt`
* Menu de quartos

### Responsável

Pedro Dias

---

# **SPRINT 2 – Hóspedes**

### Objetivo

Criar módulo de hóspedes completo com validações.

### Entregas

* Estrutura `Hospede`
* CRUD completo
* Consulta ordenada
* Validação de CPF
* Integração com reservas

### Responsável

Victhor Guilherme

---

# **SPRINT 3 – Reservas**

### Objetivo

Criar reserva e vincular hóspede + quarto.

### Entregas

* Estrutura `Reserva`
* Cálculo automático de total
* Quarto marcado como ocupado
* Listagem de reservas
* Cancelamento de reserva

### Responsável

Victhor Guilherme

---

# **SPRINT 4 – Estadia + Finalização**

### Objetivo

Finalizar sistema com check-in e check-out.

### Entregas

* Estrutura `Estadia`
* Início da estadia
* Finalização com valor final
* Liberação do quarto
* Salvamento completo

### Responsáveis

Pedro e Victhor
