


#  **Planejamento dos Casos de Teste**

Este documento descreve o conjunto de casos de teste planejados para validar todas as funcionalidades do sistema **Hotel Descanso Garantido**, desenvolvido em C.

---

# **1. Casos de Teste — Quartos**

---

### **CT-Q01 — Cadastrar Quarto (sucesso)**

* **Objetivo:** Garantir que o cadastro funcione corretamente
* **Pré-condição:** Quarto 101 ainda não existe
* **Entrada:**

  * Número: 101
  * Tipo: Solteiro
  * Diária: 150.00
* **Procedimento:**

  1. Menu → Quartos → Cadastrar
  2. Informar dados
* **Saída esperada:**

  * “Quarto cadastrado com sucesso.”
  * Quarto aparece na listagem como ativo

---

### **CT-Q02 — Cadastrar Quarto com Número Duplicado**

* **Pré-condição:** Quarto 101 já existe
* **Entrada:**

  * Número: 101
* **Saída esperada:**

  * “Erro: número de quarto já cadastrado.”

---

### **CT-Q03 — Consultar Quartos**

* **Entrada:** nenhuma
* **Saída esperada:**

  * Lista contendo o quarto 101

---

### **CT-Q04 — Alterar Quarto**

* **Entrada:**

  * Número: 101
  * Novo tipo: Casal
* **Saída esperada:**

  * “Quarto alterado com sucesso.”

---

### **CT-Q05 — Excluir Quarto**

* **Entrada:**

  * Número: 101
* **Saída esperada:**

  * “Quarto excluído com sucesso.”
  * Quarto não aparece mais na consulta

---

# **2. Casos de Teste — Hóspedes**

### **CT-H01 — Cadastrar Hóspede**

* **Entrada:**

  * Nome: João Silva
  * CPF: 12345678900
  * Telefone: 31999999999
  * Email: [joao@gmail.com](mailto:joao@gmail.com)
* **Saída esperada:**

  * “Hóspede cadastrado com sucesso.”

---

### **CT-H02 — CPF duplicado**

* **Entrada:** CPF 12345678900
* **Saída esperada:**

  * “Erro: CPF já existe.”

---

### **CT-H03 — Consultar Hóspedes**

* **Saída esperada:** lista contendo João Silva

---

### **CT-H04 — Alterar Hóspede**

* **Entrada:** atualizar e-mail
* **Saída esperada:** “Dados alterados com sucesso.”

---

### **CT-H05 — Excluir Hóspede**

* **Entrada:** CPF 12345678900
* **Saída esperada:**

  * “Hóspede excluído com sucesso.”

---

# **3. Casos de Teste — Reservas**

### **CT-R01 — Criar Reserva (sucesso)**

* **Entrada:**

  * CPF: 12345678900
  * Quarto: 201
  * Entrada: 10/06
  * Saída: 12/06
* **Saída esperada:**

  * “Reserva criada com sucesso.”

---

### **CT-R02 — Datas inválidas**

* **Entrada:**

  * Entrada: 12/06
  * Saída: 10/06
* **Saída esperada:**

  * “Erro: data inválida.”

---

### **CT-R03 — Conflito de reservas**

* **Entrada:** Quarto 201 já reservado
* **Saída esperada:**

  * “Erro: quarto indisponível para o período.”

---

### **CT-R04 — Consultar Reservas**

* **Saída esperada:** lista incluindo reserva

---

### **CT-R05 — Cancelar Reserva**

* **Saída esperada:**

  * “Reserva cancelada.”

---

# **4. Casos de Teste — Estadias**

### **CT-E01 — Check-in (sucesso)**

* **Entrada:** código da reserva
* **Saída esperada:**

  * “Check-in realizado.”

---

### **CT-E02 — Check-in sem reserva**

* **Saída esperada:**

  * “Erro: reserva não encontrada.”

---

### **CT-E03 — Check-out (sucesso)**

* **Saída esperada:**

  * Valor total calculado
  * “Check-out finalizado.”

---

# **5. Persistência em Arquivos**

### **CT-A01 — Salvar Todos os Dados**

* **Saída esperada:**

  * quartos.txt atualizado
  * hospedes.txt atualizado
  * reservas.txt atualizado
  * estadias.txt atualizado

---

### **CT-A02 — Carregar Dados**

* **Procedimento:** reiniciar o programa
* **Saída esperada:**

  * Todos os registros carregados corretamente
