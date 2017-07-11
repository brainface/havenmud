/*  A wanted poster */
#include <lib.h>
inherit LIB_ITEM;
#include "../../wanted.h"
void ReadMe();

static void create() {
  item::create();
  SetKeyName("poster");
  SetMaterials( ({ "wood" }) );
  SetId( ({"poster"}) );
  SetAdjectives( ({"wanted"}) );
  SetPreventGet("It is nailed firmly to the wall.");
  SetMass(450);
  SetShort("a wanted poster");
  SetLong("This is a poster listing the names and crimes of all "
          "people wanted in Malveillant. One could read it.");
  SetRead("default", (: ReadMe :) );
  }

void ReadMe() {
  foreach(string person in keys(Crimes)) {
     this_player()->eventPrint(capitalize(person) + " is wanted for " +
         Crimes[person] + ".");
      }
  }
