//
// Created by rudri on 9/12/2020.
//
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include "catch.hpp"
#include "redirect_io.h"
#include "P1.h"

using namespace std;

static void test_1() {
    string text = "ESTA*ES**UNA*PRUEBA***";
    vector<char> result = fixed_stack(text, 3);
    copy(begin(result), end(result), ostream_iterator<char>(cout, " "));
}

static void test_2() {
    string text;
    cin >> text;
    deque<char> result = fixed_stack<deque>(text, 4);
    copy(begin(result), end(result), ostream_iterator<char>(cout, " "));
}

TEST_CASE("Question #1_1") {
    execute_test("test_1_1.in", test_1);
}

TEST_CASE("Question #1_2") {
    execute_test("test_1_2.in", test_2);
}