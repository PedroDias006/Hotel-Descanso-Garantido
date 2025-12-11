#include "../include/cliente.h"
#include "../include/quarto.h"
#include "../include/estadia.h"
#include <munit.h>

// =============================================================
// TESTE 01 — CADASTRO DE CLIENTE
// =============================================================
static MunitResult test_cadastro_cliente(const MunitParameter params[], void* data) {
    Cliente c = {0};
    c.codigo = cliente_gerar_codigo();
    strcpy(c.nome, "Teste Cliente");
    strcpy(c.telefone, "31999999999");
    strcpy(c.endereco, "Rua X, 123");

    int ok = cliente_salvar(c);
    munit_assert_int(ok, ==, 1);

    Cliente buscado;
    int encontrou = cliente_buscar_por_codigo(c.codigo, &buscado);

    munit_assert_int(encontrou, ==, 1);
    munit_assert_string_equal(buscado.nome, "Teste Cliente");

    return MUNIT_OK;
}

// =============================================================
// TESTE 02 — CADASTRO DE QUARTO
// =============================================================
static MunitResult test_cadastro_quarto(const MunitParameter params[], void* data) {
    Quarto q;
    q.numero = 101;
    q.capacidade = 2;
    q.valor_diaria = 150.0;
    q.ocupado = 0;

    int ok = quarto_salvar(q);
    munit_assert_int(ok, ==, 1);

    Quarto buscado;
    int encontrou = quarto_buscar(101, &buscado);

    munit_assert_int(encontrou, ==, 1);
    munit_assert_int(buscado.capacidade, ==, 2);

    return MUNIT_OK;
}

// =============================================================
// TESTE 03 — ERRO DE CAPACIDADE (ESPERADO)
// =============================================================
static MunitResult test_estadia_acima_capacidade(const MunitParameter params[], void* data) {
    Estadia e;
    e.codigo_cliente = 1;
    e.numero_quarto = 101;
    e.qtd_hospedes = 5; // maior que capacidade = 2

    // Esperado: falhar
    int ok = registrar_estadia(e);
    munit_assert_int(ok, ==, 0);

    return MUNIT_OK;
}

// =============================================================
// TESTE 04 — CONFLITO DE DATAS
// =============================================================
static MunitResult test_conflito_estadia(const MunitParameter params[], void* data) {
    Estadia e1 = {0}, e2 = {0};

    // Primeira estadia
    e1.codigo_cliente = 1;
    e1.numero_quarto = 101;
    e1.dia_entrada = 1; e1.mes_entrada = 1; e1.ano_entrada = 2025;
    e1.dia_saida   = 5; e1.mes_saida   = 1; e1.ano_saida   = 2025;
    e1.qtd_hospedes = 1;
    registrar_estadia(e1);

    // Segunda estadia — conflito
    e2.codigo_cliente = 1;
    e2.numero_quarto = 101;
    e2.dia_entrada = 3; e2.mes_entrada = 1; e2.ano_entrada = 2025;
    e2.dia_saida   = 7; e2.mes_saida   = 1; e2.ano_saida   = 2025;
    e2.qtd_hospedes = 1;

    int ok = registrar_estadia(e2);

    // Esperado: não permitir
    munit_assert_int(ok, ==, 0);

    return MUNIT_OK;
}

// =============================================================
// TESTE 05 — BAIXA DE ESTADIA (LIBERA QUARTO + SOMA PONTOS)
// =============================================================
static MunitResult test_baixa_estadia(const MunitParameter params[], void* data) {
    Estadia e = {0};
    e.codigo_cliente = 1;
    e.numero_quarto = 101;
    e.dia_entrada = 10; e.mes_entrada = 1; e.ano_entrada = 2025;
    e.dia_saida   = 15; e.mes_saida   = 1; e.ano_saida   = 2025;
    e.qtd_hospedes = 1;

    registrar_estadia(e);

    int ok = baixa_estadia(102); // exemplo
    munit_assert_int(ok, ==, 1);

    Cliente c;
    cliente_buscar_por_codigo(1, &c);

    // 5 dias * 10 pontos = 50
    munit_assert_int(c.pontos, >=, 50);

    return MUNIT_OK;
}

// =============================================================
// SUÍTE DE TESTES
// =============================================================
static MunitTest tests[] = {
    { "/cadastro-cliente", test_cadastro_cliente, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastro-quarto", test_cadastro_quarto, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/capacidade-excedida", test_estadia_acima_capacidade, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/conflito-estadia", test_conflito_estadia, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/baixa-estadia", test_baixa_estadia, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    "/hotel-tests",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
