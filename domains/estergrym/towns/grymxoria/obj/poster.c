/*  A wanted poster */
#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ITEM;
#include "../wanted.h"
void ReadMe();

static void create() {
  item::create();
  SetKeyName("poster");
  SetShort("a wanted poster");
  SetLong(
    "This is a poster listing the names and crimes of all "
    "people wanted in Grymxoria. One could read it.");
  SetPreventGet("It is nailed firmly to the wall.");
  SetMass(450);
  SetRead("default", (: ReadMe :) );
}

void ReadMe() {
  foreach(string person in keys(Wanted)) {
    this_player()->eventPrint(capitalize(person) + " is wanted for " +
      Wanted[person] + ".");
  }
}
