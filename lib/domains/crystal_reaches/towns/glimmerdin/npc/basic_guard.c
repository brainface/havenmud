#include <lib.h>
#include "../path.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("glimmerdin guard");
  SetId( ({ "guard", "militia", "member", "dwarf", "glim_wander" }) );
  SetAdjectives( ({ "glimmerdin", "member", "of", "the", }) );
  SetShort("a member of the Glimmerdin militia");
  SetLong(
    "The guard appears to be a relatively low ranking soldier, by the "
    "number of stripes on his tunic. His intense gaze seems to be "
    "based more on desire than actual merit."
    );
  SetLimit(5);
  SetWander(5);
  SetMorality(random(200));
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(15);
  SetTown("Glimmerdin");
  SetGender("male");
  SetInventory( ([ 
    G_OBJ "chainmail.c" : "wear chainmail",
    G_OBJ "axe.c" : "wield axe",
    G_OBJ "breeches.c" : "wear breeches",
    G_OBJ "boots.c" : "wear boots",
    ]) );
  SetFriends( ({ "glim_wander", "dwarf" }) );
  SetAction(6, ({
  	"!speak Move along now.  Nothing to see here.",
  	"!speak Loud, obnoxious merchants. Why I outta...",
  	"!mumble",
  	"!mutter",
  	"!sneer 1st vendor",
  	"!mock 1st vendor",
    }) );
  SetCombatAction(3, ({
  	"!yell To arms!",
  	"!yell We are under attack!",
  	}) );
}
