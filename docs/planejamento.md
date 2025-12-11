**1. Módulo de Quartos**

### **CT-Q01 — Cadastrar Quarto (sucesso)**

* **Entrada:**

  * Número: 101
  * Tipo: “Solteiro”
  * Diária: 150.00
* **Procedimento:**

  1. Acessar menu de quartos
  2. Selecionar “Cadastrar quarto”
  3. Informar dados acima
* **Saída Esperada:**

  * “Quarto cadastrado com sucesso.”
  * Quarto aparece como ativo na consulta.
* **Resultado:** *Aguardando execução*

---

### **CT-Q02 — Cadastrar Quarto com número duplicado (erro)**

* **Entrada:**

  * Número: 101 (já cadastrado)
* **Procedimento:**

  1. Tentar cadastrar novo quarto usando o número existente
* **Saída Esperada:**

  * “Erro: número de quarto já cadastrado.”
* **Resultado:** *Aguardando execução*

---

### **CT-Q03 — Consultar Quartos (lista não vazia)**

* **Entrada:** nenhuma
* **Procedimento:**

  1. Abrir menu de quartos
  2. Selecionar “Consultar”
* **Saída Esperada:**
  Lista contendo pelo menos o quarto 101.
* **Resultado:** *Aguardando execução*

---

### **CT-Q04 — Alterar Tipo do Quarto**

* **Entrada:**

  * Número: 101
  * Novo Tipo: “Casal”
* **Procedimento:**

  1. Acessar “Alterar quarto”
  2. Inserir número
  3. Alterar tipo
* **Saída Esperada:**

  * “Quarto alterado com sucesso.”
  * Consulta exibe tipo atualizado.
* **Resultado:** *Aguardando execução*

---

### **CT-Q05 — Excluir Quarto (exclusão lógica)**

* **Entrada:**

  * Número: 101
* **Procedimento:**

  1. Acessar “Excluir quarto”
  2. Confirmar
* **Saída Esperada:**

  * “Quarto excluído com sucesso.”
  * Consulta não mostra 101.
* **Resultado:** *Aguardando execução*

---

---

**2. Módulo de Hóspedes**

### **CT-H01 — Cadastrar Hóspede (sucesso)**

* **Entrada:**

  * Nome: João Silva
  * CPF: 12345678900
  * Telefone: 31999999999
  * Email: [joao@gmail.com](mailto:joao@gmail.com)
* **Procedimento:**

  1. Menu hóspedes → cadastrar
  2. Inserir dados
* **Saída Esperada:**

  * “Hóspede cadastrado com sucesso.”
* **Resultado:** *Aguardando execução*

---

### **CT-H02 — Cadastrar Hóspede com CPF duplicado**

* **Entrada:**

  * CPF já cadastrado: 12345678900
* **Procedimento:**

  1. Tentar cadastrar novo hóspede com o mesmo CPF
* **Saída Esperada:**

  * “Erro: CPF já existe no sistema.”
* **Resultado:** *Aguardando execução*

---

### **CT-H03 — Consultar Hóspedes**

* **Entrada:** nenhuma
* **Procedimento:**

  1. Menu de hóspedes → consultar
* **Saída Esperada:**
  Lista contendo João Silva.
* **Resultado:** *Aguardando execução*

---

### **CT-H04 — Alterar Hóspede**

* **Entrada:**

  * CPF: 12345678900
  * Novo email: [joaosilva@gmail.com](mailto:joaosilva@gmail.com)
* **Procedimento:**

  1. Acessar “Alterar hóspede”
  2. Selecionar campo e atualizar
* **Saída Esperada:**

  * “Dados alterados com sucesso.”
* **Resultado:** *Aguardando execução*

---

### **CT-H05 — Excluir Hóspede**

* **Entrada:**

  * CPF: 12345678900
* **Procedimento:**

  1. Acionar “Excluir hóspede”
* **Saída Esperada:**

  * “Hóspede excluído com sucesso.”
  * Consulta não mostra mais João Silva
* **Resultado:** *Aguardando execução*

---

---

**3. Módulo de Reservas**

### **CT-R01 — Criar Reserva (sucesso)**

* **Entrada:**

  * CPF: 12345678900
  * Quarto: 201
  * Entrada: 10/06
  * Saída: 12/06
* **Procedimento:**

  1. Menu reservas → criar
  2. Inserir dados
* **Saída Esperada:**

  * “Reserva criada com sucesso.”
  * Quarto 201 marcado como reservado
* **Resultado:** *Aguardando execução*

---

### **CT-R02 — Criar Reserva com data inválida**

* **Entrada:**

  * Entrada: 12/06
  * Saída: 10/06
* **Procedimento:**

  1. Criar reserva
* **Saída Esperada:**

  * “Erro: data de saída deve ser posterior à data de entrada.”
* **Resultado:** *Aguardando execução*

---

### **CT-R03 — Criar Reserva em Quarto Ocupado**

* **Entrada:**

  * Quarto 201 já reservado
* **Procedimento:**

  1. Tentar reservar mesmo quarto no mesmo período
* **Saída Esperada:**

  * “Erro: quarto indisponível no período selecionado.”
* **Resultado:** *Aguardando execução*

---

### **CT-R04 — Consultar Reservas**

* **Entrada:** nenhuma
* **Procedimento:** menu → consultar reservas
* **Saída Esperada:** lista incluindo reserva válida
* **Resultado:** *Aguardando execução*

---

### **CT-R05 — Cancelar Reserva**

* **Entrada:** código da reserva
* **Procedimento:**

  1. Menu reservas → cancelar
* **Saída Esperada:**

  * “Reserva cancelada.”
  * Quarto marcado como disponível
* **Resultado:** *Aguardando execução*

---

---

**4. Módulo de Estadias (Check-in e Check-out)**

### **CT-E01 — Check-in válido**

* **Entrada:**

  * Código da reserva válida
* **Procedimento:**

  1. Menu estadia → check-in
* **Saída Esperada:**

  * “Check-in realizado.”
  * Reserva vira estadia
  * Quarto marcado como ocupado
* **Resultado:** *Aguardando execução*

---

### **CT-E02 — Check-in sem reserva**

* **Entrada:** reserva inexistente
* **Saída Esperada:**

  * “Erro: reserva não encontrada.”
* **Resultado:** *Aguardando execução*

---

### **CT-E03 — Check-out válido**

* **Entrada:** código de estadia ativa
* **Procedimento:**

  1. Estadia → check-out
* **Saída Esperada:**

  * “Check-out concluído.”
  * Valor total exibido
  * Quarto liberado
* **Resultado:** *Aguardando execução*

---

---

**5. Persistência em Arquivos**

### **CT-A01 — Salvar Todos os Dados**

* **Procedimento:**

  1. Cadastrar dados
  2. Sair do sistema
* **Saída Esperada:**

  * Arquivos atualizados:

    * quartos.txt
    * hospedes.txt
    * reservas.txt
    * estadias.txt
* **Resultado:** *Aguardando execução*

### **CT-A02 — Carregar Todos os Dados na Inicialização**

* **Procedimento:**

  1. Abrir o programa após salvar dados
* **Saída Esperada:**

  * Sistema carrega todas as informações previamente salvas
* **Resultado:** *Aguardando execução*



# **RELATÓRIO DE EXECUÇÃO DOS TESTES**

**Data:** 10/12/2025
**Responsáveis:** Pedro Dias e Victhor Guilherme
**Versão do Sistema:** 1.0
