# Hotel Descanso Garantido

Trabalho Interdisciplinar – Fundamentos de Engenharia de Software e Algoritmos e Estruturas de Dados I  
PUC Minas – 2025

## Integrantes
- Pedro Henrique Dias Pereira  
- Victhor Guilherme Santos Loiola  

---

## Descrição Geral

O sistema Hotel Descanso Garantido foi desenvolvido em linguagem C com o objetivo de informatizar o controle de clientes, funcionários, quartos e estadias do hotel, substituindo planilhas manuais e reduzindo erros operacionais.

O projeto utiliza modularização, arquivos binários para persistência de dados e testes automatizados com a biblioteca MUnit.

---

## Estrutura do Projeto

---

# Funcionalidades Implementadas

## 1. Módulo de Clientes

Permite:
- Cadastro de clientes  
- Listagem geral  
- Busca por nome  
- Busca por código  

Armazenamento: `clientes.dat`  
Regras:  
- Código único para cada cliente  

---

## 2. Módulo de Funcionários

Permite:
- Cadastro  
- Listagem  
- Busca por nome  
- Busca por código  

Armazenamento: `funcionarios.dat`  
Regras:
- Código único  
- Salário válido  

---

## 3. Módulo de Quartos

Permite:
- Cadastro de quartos  
- Consulta por número  
- Listagem  
- Controle de disponibilidade (ocupado/desocupado)

Armazenamento: `quartos.dat`  
Regras:
- Não permite números de quarto duplicados  
- Novo quarto sempre inicia como desocupado  

---

## 4. Módulo de Estadias

### Registro de estadias

Inclui:
- Verificação de cliente existente  
- Verificação de quarto existente  
- Validação de disponibilidade  
- Validação de datas  
- Prevenção de conflitos com outras estadias  
- Cálculo automático da quantidade de diárias  
- Marcação do quarto como ocupado  

### Baixa de estadias

Inclui:
- Cálculo do valor total  
- Liberação do quarto  
- Finalização da estadia  
- Acúmulo de pontos de fidelidade  
- Atualização dos arquivos binários  

Armazenamento: `estadias.dat`

---

# Testes Automatizados

Foram desenvolvidos testes utilizando a biblioteca MUnit.  
Abrangência dos testes:

- Geração de códigos  
- Validação de datas  
- Cálculo de diárias  
- Verificação de existência de quarto

