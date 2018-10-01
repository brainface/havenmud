#include <lib.h>
#include "../goblins.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("goblin warrior");
  SetShort("a thin goblin warrior");
  SetRace("goblin");
  SetClass("fighter");
  SetGender("male");
  SetSkill("pierce combat",1,2);
  SetLevel(10);
  SetMorality(-50);
  SetInventory( ([
    GOBLIN_OBJ "spear" : "wield spear",
    GOBLIN_OBJ "vest"  : "wear vest",
    ]) );
  SetId( ({ "goblin", "warrior" }) );
  SetAdjectives( ({ "thin", "goblin" }) );
  SetLong(
    "This goblin seems to be thinner and taller than the others.  Perhaps "
    "his is a duller life of random guard duty."
    );
}
