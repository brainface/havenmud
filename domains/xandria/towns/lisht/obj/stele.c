//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_ITEM;
#include "../wanted.h"
void ReadMe();

static void create() {
  item::create();
  SetKeyName("stele");
  SetId( ({"stele"}) );
  SetAdjectives( ({"wanted"}) );
  SetPreventGet("It weighs more than you and a pack of dragons.");
  SetMass(9000);
  SetShort("a wanted stele");
  SetLong("This stele lists the criminals and the transgressions "
          "of those wanted in Lisht. One could read it.");
  SetRead("default", (: ReadMe :) );
  }

void ReadMe() {
  foreach(string person in keys(Crimes)) {
     this_player()->eventPrint(capitalize(person) + " is wanted for " +
         Crimes[person] + ".");
      }
  }
