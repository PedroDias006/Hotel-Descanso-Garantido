# 🧾 **REQUISITOS_FINAIS.md**

## Checklist de Requisitos – Hotel Descanso Garantido

| Requisito                | Descrição                                | Status |
| ------------------------ | ---------------------------------------- | ------ |
| Cadastro de hóspedes     | Permite adicionar hóspedes com CPF único | ✅      |
| Consulta de hóspedes     | Lista hóspedes ativos e ordenados        | ✅      |
| Alteração de hóspedes    | Edita nome e telefone                    | ✅      |
| Exclusão de hóspedes     | Exclusão lógica (ativo = 0)              | ✅      |
| Cadastro de quartos      | Número, tipo e diária                    | ✅      |
| Consulta de quartos      | Exibe quartos livres e ocupados          | ✅      |
| Alteração de quartos     | Altera tipo/diária                       | ✅      |
| Exclusão de quartos      | Exclusão lógica (ativo = 0)              | ✅      |
| Cadastro de reserva      | Valida hóspede + quarto livre + dias     | ✅      |
| Cancelamento de reserva  | Libera o quarto automaticamente          | ✅      |
| Consulta de reservas     | Lista reservas ativas                    | ✅      |
| Início de estadia        | Check-in realizado com reserva válida    | ✅      |
| Finalização de estadia   | Check-out com cálculo correto            | ✅      |
| Liberação de quarto      | Automática no check-out                  | ✅      |
| Persistência em arquivos | Salvamento e carregamento completo       | ✅      |
| Menus organizados        | Quartos, hóspedes, reservas, estadias    | ✅      |
| Funções auxiliares       | Buffer, pausa, validações                | ✅      |


---


# 📦 **BACKLOG DO PRODUTO – Hotel Descanso Garantido**

## Épico 1 – Gestão de Hóspedes

* [x] Cadastrar hóspede
* [x] Consultar hóspedes
* [x] Alterar hóspede
* [x] Excluir hóspede (lógica)
* [x] Validação de CPF único

## Épico 2 – Gestão de Quartos

* [x] Cadastrar quarto
* [x] Alterar quarto
* [x] Consultar quartos
* [x] Excluir quarto
* [x] Controle de disponibilidade

## Épico 3 – Reservas

* [x] Criar reserva
* [x] Cancelar reserva
* [x] Calcular valor da reserva
* [x] Listar reservas ativas

## Épico 4 – Estadia (Check-in / Check-out)

* [x] Iniciar estadia
* [x] Finalizar estadia
* [x] Calcular valor final
* [x] Liberar quarto automaticamente

## Épico 5 – Persistência

* [x] Carregar dados de arquivos
* [x] Salvar dados de arquivos
* [x] Salvamento geral na saída

**Total de itens:** 22
**Concluídos:** 22 (100%)

---
