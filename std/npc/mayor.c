#include <lib.h>
inherit LIB_MAYOR;
static void create(){
    mayor::create();
    SetKeyName("mayor");
    SetId("mayor");
    SetLong("This is a mayor.");
    SetShort("a mayor");
    SetRace("human");
    SetGender("male");
    SetClass("fighter");
    SetLevel(16);
    SetTown("Balzash");
    SetLocalCurrency("marks");
    SetTax(10);
}
