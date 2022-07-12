//
// Created by rudri on 9/12/2020.
//
#include <iostream>
#include "catch.hpp"
#include "redirect_io.h"
#include "P2.h"
using namespace std;

static void test_1() {
    vector<address_t> vec = {
            {"Javier Prado Este 123", -12.092052, -77.033073},
            {"Medrano Silva 165", -12.135661, -77.022590},
            {"Plaza Mayor de Lima", -12.045680, -77.030144},
            {"Plaza San Martin", -12.051566, -77.035015},
            {"Parque Universitario", -12.054063, -77.031614},
            {"Estadio Nacional", -12.0672501, -77.0336725}
    };

    auto addresses = hash_addresses(vec);
    auto iter = addresses.find({"Plaza Mayor de Lima", 0, 0});
    if (iter != end(addresses))
        cout << *iter << endl;
    else
        cout << "Not found\n";
}

static void test_2() {
    auto addresses = hash_addresses({
                                            {"Javier Prado Este 123", -12.092052, -77.033073},
                                            {"Medrano Silva 165", -12.135661, -77.022590},
                                            {"Plaza Mayor de Lima", -12.045680, -77.030144},
                                            {"Plaza San Martin", -12.051566, -77.035015},
                                            {"Parque Universitario", -12.054063, -77.031614},
                                            {"Estadio Nacional", -12.0672501, -77.0336725}
                                    });

    auto iter = addresses.find({"Palacio de Justicia", 0, 0});    // Se busca utilizando un objeto address_t que
    // solo contiene el valor de reference,
    // latitud y longitud tiene 0, 0 al buscarlo
    if (iter != end(addresses))
        cout << *iter << endl;
    else
        cout << "Not found\n";
}

static void test_3() {
    auto addresses = hash_addresses({
                                            {"Javier Prado Este 123", -12.092052, -77.033073},
                                            {"Medrano Silva 165", -12.135661, -77.022590},
                                            {"Plaza Mayor de Lima", -12.045680, -77.030144},
                                            {"Plaza San Martin", -12.051566, -77.035015},
                                            {"Parque Universitario", -12.054063, -77.031614},
                                            {"Estadio Nacional", -12.0672501, -77.0336725}
                                    });

    auto iter = addresses.find({"Plaza San Martin", 10, 20});     // Se busca utilizando un objeto address_t que
    // solo contiene el valor de reference,
    // latitud y longitud tiene 0, 0 al buscarlo
    if (iter != end(addresses))
        cout << *iter << endl;
    else
        cout << "Not found\n";
}

TEST_CASE("Question #2_1") {
    execute_test("test_2_1.in", test_1);
}

TEST_CASE("Question #2_2") {
    execute_test("test_2_2.in", test_2);
}

TEST_CASE("Question #2_3") {
    execute_test("test_2_3.in", test_3);
}