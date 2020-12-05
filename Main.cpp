/**
 * File: Main.h
 * Description: 
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 */

// std libraries:
#include <fstream>

// project headers:
#include "Table.h"

using namespace std;

int main() {
    Table* table = new Table("Clancy", "Skye");
    cout << *table;
};