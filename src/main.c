#include <stdio.h>
#include <string.h>

#include "../include/cliente.h"
#include "../include/funcionario.h"
#include "../include/quarto.h"
#include "../include/estadia.h"

// ============================================================
// MENU CLIENTES
// ============================================================
void menu_clientes() {
    int opcao;

    do {
        printf("\n===== MÓDULO DE CLIENTES =====\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente por código\n");
        printf("4 - Buscar cliente por nome\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            Cliente c;
            c.codigo = cliente_gerar_codigo();

            printf("\n--- Cadastro de Cliente ---\n");

            printf("Nome: ");
            fgets(c.nome, sizeof(c.nome), stdin);
            c.nome[strcspn(c.nome, "\n")] = '\0';

            printf("Telefone: ");
            fgets(c.telefone, sizeof(c.telefone), stdin);
            c.telefone[strcspn(c.telefone, "\n")] = '\0';

            printf("Endereço: ");
            fgets(c.endereco, sizeof(c.endereco), stdin);
            c.endereco[strcspn(c.endereco, "\n")] = '\0';

            if (cliente_salvar(c))
                printf("\nCliente cadastrado com sucesso! Código: %d\n", c.codigo);
            else
                printf("\nErro ao cadastrar cliente.\n");
        }

        else if (opcao == 2) {
            cliente_listar();
        }

        else if (opcao == 3) {
            int codigo;
            Cliente achado;

            printf("\nDigite o código do cliente: ");
            scanf("%d", &codigo);
            getchar();

            if (cliente_buscar_por_codigo(codigo, &achado)) {
                printf("\nCliente encontrado:\n");
                printf("Código  : %d\n", achado.codigo);
                printf("Nome    : %s\n", achado.nome);
                printf("Telefone: %s\n", achado.telefone);
                printf("Endereço: %s\n", achado.endereco);
            } else {
                printf("\nNenhum cliente com esse código.\n");
            }
        }

        else if (opcao == 4) {
            char nome[80];
            Cliente achado;

            printf("\nDigite parte do nome do cliente: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            if (cliente_buscar_por_nome(nome, &achado)) {
                printf("\nCliente encontrado:\n");
                printf("Código  : %d\n", achado.codigo);
                printf("Nome    : %s\n", achado.nome);
                printf("Telefone: %s\n", achado.telefone);
                printf("Endereço: %s\n", achado.endereco);
            } else {
                printf("\nNenhum cliente com esse nome encontrado.\n");
            }
        }

        else if (opcao != 0) {
            printf("\nOpção inválida.\n");
        }

    } while (opcao != 0);
}


// ============================================================
// MENU FUNCIONÁRIOS
// ============================================================
void menu_funcionarios() {
    int opcao;

    do {
        printf("\n===== MÓDULO FUNCIONÁRIOS =====\n");
        printf("1 - Cadastrar funcionário\n");
        printf("2 - Listar funcionários\n");
        printf("3 - Buscar por código\n");
        printf("4 - Buscar por nome\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            Funcionario f;
            f.codigo = funcionario_gerar_codigo();

            printf("Nome: ");
            fgets(f.nome, 80, stdin);
            f.nome[strcspn(f.nome, "\n")] = '\0';

            printf("Telefone: ");
            fgets(f.telefone, 20, stdin);
            f.telefone[strcspn(f.telefone, "\n")] = '\0';

            printf("Cargo: ");
            fgets(f.cargo, 40, stdin);
            f.cargo[strcspn(f.cargo, "\n")] = '\0';

            printf("Salário: ");
            scanf("%f", &f.salario);
            getchar();

            if (funcionario_salvar(f))
                printf("Funcionário cadastrado! Código: %d\n", f.codigo);
            else
                printf("Erro ao cadastrar funcionário.\n");
        }

        else if (opcao == 2) {
            funcionario_listar();
        }

        else if (opcao == 3) {
            int cod;
            Funcionario temp;

            printf("Código: ");
            scanf("%d", &cod);
            getchar();

            if (funcionario_buscar_por_codigo(cod, &temp)) {
                printf("\nFuncionário encontrado:\n");
                printf("Código  : %d\n", temp.codigo);
                printf("Nome    : %s\n", temp.nome);
                printf("Telefone: %s\n", temp.telefone);
                printf("Cargo   : %s\n", temp.cargo);
                printf("Salário : %.2f\n", temp.salario);
            } else {
                printf("\nNenhum funcionário com esse código.\n");
            }
        }

        else if (opcao == 4) {
            char nome[80];
            Funcionario temp;

            printf("Nome: ");
            fgets(nome, 80, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            if (funcionario_buscar_por_nome(nome, &temp)) {
                printf("\nFuncionário encontrado:\n");
                printf("Código  : %d\n", temp.codigo);
                printf("Nome    : %s\n", temp.nome);
                printf("Telefone: %s\n", temp.telefone);
                printf("Cargo   : %s\n", temp.cargo);
                printf("Salário : %.2f\n", temp.salario);
            } else {
                printf("\nNenhum funcionário encontrado.\n");
            }
        }

        else if (opcao != 0) {
            printf("\nOpção inválida.\n");
        }

    } while (opcao != 0);
}



// ============================================================
// MENU QUARTOS
// ============================================================
void menu_quartos() {
    int opcao;

    do {
        printf("\n===== MÓDULO QUARTOS =====\n");
        printf("1 - Cadastrar quarto\n");
        printf("2 - Listar quartos\n");
        printf("3 - Buscar por número\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            Quarto q;

            printf("Número do quarto: ");
            scanf("%d", &q.numero);
            getchar();

            printf("Capacidade: ");
            scanf("%d", &q.capacidade);
            getchar();

            printf("Valor da diária: ");
            scanf("%f", &q.valor_diaria);
            getchar();

            q.ocupado = 0;

            quarto_salvar(q);
        }

        else if (opcao == 2) {
            quarto_listar();
        }

        else if (opcao == 3) {
            int n;
            Quarto q;

            printf("Número do quarto: ");
            scanf("%d", &n);
            getchar();

            if (quarto_buscar(n, &q)) {
                printf("\nQuarto encontrado:\n");
                printf("Número      : %d\n", q.numero);
                printf("Capacidade  : %d\n", q.capacidade);
                printf("Valor diária: %.2f\n", q.valor_diaria);
                printf("Status      : %s\n", q.ocupado ? "Ocupado" : "Desocupado");
            } else {
                printf("Quarto não encontrado.\n");
            }
        }

        else if (opcao != 0) {
            printf("\nOpção inválida.\n");
        }

    } while (opcao != 0);
}



// ============================================================
// MENU ESTADIAS (ATUALIZADO 100%)
// ============================================================
void menu_estadias() {
    int op;

    do {
        printf("\n===== MÓDULO ESTADIAS =====\n");
        printf("1 - Registrar estadia\n");
        printf("2 - Listar estadias\n");
        printf("3 - Dar baixa em estadia\n");
        printf("4 - Listar estadias por cliente\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &op);
        getchar();

        if (op == 1) {
            Estadia e;
            Cliente c;
            Quarto q;

            e.codigo_estadia = gerar_codigo_estadia();

            printf("Código do cliente: ");
            scanf("%d", &e.codigo_cliente);
            getchar();

            if (!cliente_buscar_por_codigo(e.codigo_cliente, &c)) {
                printf("\nErro: Cliente não encontrado.\n");
                continue;
            }

            printf("Número do quarto: ");
            scanf("%d", &e.numero_quarto);
            getchar();

            if (!quarto_buscar(e.numero_quarto, &q)) {
                printf("\nErro: Quarto não existe.\n");
                continue;
            }

            printf("Quantidade de hóspedes: ");
            scanf("%d", &e.qtd_hospedes);
            getchar();

            if (e.qtd_hospedes > q.capacidade) {
                printf("\nErro: Quarto suporta no máximo %d hóspedes.\n", q.capacidade);
                continue;
            }

            printf("Data de entrada (dd mm aaaa): ");
            scanf("%d %d %d", &e.dia_entrada, &e.mes_entrada, &e.ano_entrada);

            printf("Data de saída (dd mm aaaa): ");
            scanf("%d %d %d", &e.dia_saida, &e.mes_saida, &e.ano_saida);

            if (!validar_datas(
                e.dia_entrada, e.mes_entrada, e.ano_entrada,
                e.dia_saida, e.mes_saida, e.ano_saida
            )) {
                printf("\nDatas inválidas. Saída deve ser depois da entrada.\n");
                continue;
            }

            if (quarto_ocupado_no_periodo(e.numero_quarto, e)) {
                printf("\nErro: Já existe uma estadia neste quarto nesse período.\n");
                continue;
            }

            e.qtd_diarias = calcular_diarias(
                e.dia_entrada, e.mes_entrada, e.ano_entrada,
                e.dia_saida, e.mes_saida, e.ano_saida
            );

            e.ativa = 1;

            if (registrar_estadia(e)) {
                printf("\nEstadia registrada com sucesso! Código: %d\n", e.codigo_estadia);
            }
        }

        else if (op == 2) {
            listar_estadias();
        }

        else if (op == 3) {
            int cod;

            printf("Código da estadia para baixa: ");
            scanf("%d", &cod);
            getchar();

            baixa_estadia(cod);
        }

        else if (op == 4) {
            int cod;
            printf("Código do cliente: ");
            scanf("%d", &cod);
            getchar();

            listar_estadias_por_cliente(cod);
        }

    } while (op != 0);
}



// ============================================================
// MENU PRINCIPAL
// ============================================================
int main() {
    int opcao;

    do {
        printf("\n========== HOTEL DESCANSO GARANTIDO ==========\n");
        printf("1 - Gerenciar clientes\n");
        printf("2 - Gerenciar funcionários\n");
        printf("3 - Gerenciar quartos\n");
        printf("4 - Gerenciar estadias\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                menu_clientes();
                break;

            case 2:
                menu_funcionarios();
                break;

            case 3:
                menu_quartos();
                break;

            case 4:
                menu_estadias();
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
