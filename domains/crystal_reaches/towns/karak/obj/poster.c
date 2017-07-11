// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ITEM;
#include "../wanted.h"

void ReadMe();

static void create() {
  item::create();
  SetKeyName("poster");
  SetId( ({ "poster" }) );
  SetAdjectives( ({ "wanted", "karak" }) );
  SetShort("a wanted poster");
  SetLong(
    "This is a poster listing the names and crimes of all "
    "people wanted in Karak. One could read it."
  );
  SetMass(450);
  SetRead("default", (: ReadMe :) );
  SetPreventGet("The wanted poster is nailed firmly to the wall.");
}

void ReadMe() {
  foreach(string person in Wanted) {
    this_player()->eventPrint(capitalize(person) + " is wanted for " +
    Crimes[person] + ".");
  }
}
