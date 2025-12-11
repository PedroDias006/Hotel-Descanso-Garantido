TRABALHO PRÁTICO FEITO POR PEDRO DIAS E VICTHOR GUILHERME PARA AS MATÉRIAS DE FUNDAMENTOS DE ENGENHARIA DE SOFTWARE E ALGORITMO E ESTRUTURA DE DADOS :)

# 🏨 **Sistema de Hotel – Hotel Descanso Garantido**

## Trabalho Prático — 2025/1 ✅ **CONCLUÍDO**

---

## 👥 **Equipe**

| Membro                | Responsável pelo módulo                           | Status         |
| --------------------- | ------------------------------------------------- | -------------- |
| **Pedro Dias**        | Módulo de Quartos e Responsável do Banco de Dados | ✅ IMPLEMENTADO |
| **Victhor Guilherme** | Módulo de Hóspedes, Reservas e Baixa de Estadia   | ✅ IMPLEMENTADO |

---

##  **Status Geral do Projeto**

**Data de Entrega:** 02/07/2025
**Status Final:** ✅ **100% IMPLEMENTADO E TESTADO**

| Módulo                       | Responsável | Status      | 
| ---------------------------- | ----------- | ----------- | 
| 🛏️ Quartos                  | Victhor       | ✅ Concluído | 
| 👤 Hóspedes                  | Victhor     | ✅ Concluído | 
| 📅 Reservas                  | Victhor     | ✅ Concluído | 
| 💳 Estadia / Baixa           | Victhor     | ✅ Concluído |
| 📂 Banco de Dados (Arquivos) | Victhor    | ✅ Concluído |


---

# 📋 **Descrição do Projeto**

O **Hotel Descanso Garantido** é um sistema completo para gestão de um hotel utilizando linguagem **C**, com manipulação de dados por meio de arquivos.

O sistema permite:

* Cadastrar, buscar, editar e listar **hóspedes**
* Cadastrar e gerenciar **quartos** do hotel
* Registrar **reservas**
* Registrar **estadia**
* Realizar **baixa de estadia**, com cálculo automático do valor total
* Manter banco de dados local através de arquivos
* Oferecer menus organizados por tipo de operação


---

# 🏗️ **Estrutura do Projeto**

```
/
├── README.md                          ✅ Documentação principal
├── requisitos_finais.md               ✅ Requisitos para o trabalho final
├── .gitignore                         ✅ Arquivos ignorados pelo Git
│
├── include/                           ✅ Arquivos de cabeçalho (.h)
│   ├── quarto.h                       ✅ Gestão de quartos
│   ├── funcionario.h                  ✅ Gestão de funcionários                  
│   ├── estadia.h                      ✅ Controle de estadias
│   └── cliente.h                      ✅ Gestão de clientes
│
├── src/                               ✅ Código-fonte principal (.c)
│   ├── quarto.c                       ✅ Implementação de quartos
│   ├── funcionario.c                  ✅ Implementação de funcionários                
│   ├── estadia.c                      ✅ Implementação da baixa e estadia
│   ├── cliente.c                      ✅ Implementação de clientes
│   └── main.c                         ✅ Menu principal
│
├── docs/                              ✅ Documentação geral
│   ├── backlog.md                     ✅ Backlog completo.
│   ├── funcionalidades.md             ✅ Descrição técnica das funções.
│   └── docs_indivuais.md              ✅ Documentações feitos pelos autores.
    ├── casos.md                       ✅ Casos de testes feitos pelos autores.        
│   └── planejamento.md                ✅ Planejamento dos casos de testes feito pelos autores.

```

---

# 🚀 **Como Compilar e Executar**

1. Entre na pasta `src`:

```
cd src
```

2. Compile:

```
gcc main.c quarto.c hospede.c reserva.c estadia.c utils.c -o hotel.exe
```

3. Execute:

```
./hotel.exe
```
---

# 🧪 **Testes**

* Testes manuais realizados em todos os módulos
* Conferência dos arquivos de banco de dados
* Verificação de cálculos de reserva e estadia
* Testes de exceção (hóspede inexistente, quarto ocupado etc.)

---

# 🎯 **Objetivos Alcançados**

* Aprendizagem da manipulação de arquivos em C
* Organização de projeto seguindo boas práticas
* Aplicação de estrutura modular (múltiplos .c/.h)
* Documentação completa do projeto
* Aplicação parcial da metodologia Scrum
* Entrega limpa, organizada e funcional

