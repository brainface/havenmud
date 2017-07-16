#include <lib.h>
#include "../path.h"

inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("shire guard");
  SetLimit(6);
  SetId( ({ "halfling", "guard", }) );
  SetAdjectives( ({ "lloryk", "shire" }) );
  SetShort("a Lloryk shire guard");
  SetLong("In spite of his small size the halfling guard looks able to deter "
          "all but the most dangerous of foes.");
  SetRace("halfling");
  SetFriends( ({ "town guard", "josef" }) );
  SetClass("fighter");
  SetLevel(random(30)+25);
  SetTown("Lloryk");
  SetGender("male");
  SetInventory( ([ 
    LLORYK + "obj/chainmail.c" : "wear chainmail",
    LLORYK + "obj/pike.c" : "wield pike",
    LLORYK + "obj/breeches.c" : "wear breeches",
    LLORYK + "obj/helm.c" : "wear helm",
    LLORYK + "obj/boots.c" : "wear boots",
    ]) );
  SetMorality(200);
}

