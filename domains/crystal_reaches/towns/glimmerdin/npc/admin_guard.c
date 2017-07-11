#include <lib.h>
#include "../path.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("keep guard");
  SetId( ({ "guard", "glim_wander" }) );
  SetAdjectives( ({ "elite", "keep", }) );
  SetShort("an elite keep guard");
  SetLong(
    "This soldier seems to be of a moderately high rank. His stern "
    "demeanor makes him appear to be a formidible warrior."
    );
  SetMorality(random(200));
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(35);
  SetTown("Glimmerdin");
  SetGender("male");
  SetInventory( ([ 
    G_OBJ "chainmail" : "wear chainmail",
    G_OBJ "axe"       : "wield axe",
    G_OBJ "breeches"  : "wear breeches",
    G_OBJ "boots"     : "wear boots",
    ]) );
  SetFriends( ({ "glim_wander", "dwarf"}) );
}
