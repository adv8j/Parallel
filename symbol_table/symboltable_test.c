#include "symbol_table.c"
#include <assert.h>

int main()
{
    symbol_table* st = symbol_table_init(1e4+9);
    symbol_insert(st, "a", false,"int", 0, 0, 0);
    assert(!search(st, "a") );
}