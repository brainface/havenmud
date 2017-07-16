// Proximo@Via Imperialis
// 05/30/2003

#include <lib.h>
#include "../sulumus.h"

inherit LIB_ITEM;

#include "../wanted.h"
void ReadMe();

static void create() {
  item::create();
  SetKeyName("poster");
  SetId( ({ "poster" }) );
  SetAdjectives( ({ "a", "wanted" }) );
  SetShort("a wanted poster");
  SetLong(
     "This piece of paper is a wanted poster of all of those wanted in the "
     "Sulumus Trading Post and their crime listed alongside their name. One "
     "could read it. "
  );
  SetPreventGet("It is firmly attached to the pole. ");
  SetRead("default", (: ReadMe :) );
}

void ReadMe() {
  foreach(string person in Wanted) {
     this_player()->eventPrint(capitalize(person) + " is wanted for " +
         Crimes[person] + ".");
  }
}
