// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("citizen");
  SetId( ({ "karak citizen", "citizen", "karak_wander", "orc"}) );
  SetShort("a citizen of Karak");
  SetLong(
    "This unremarkable orc is an average citizen of Karak and usually "
    "is found walking on his way to one errand or another. He is simply "
    "clothed and, as with most orcs, never leaves his home unarmed. Although "
    "a simple citizen, he is a reasonable opponent for a beginning adventurer."
  );
  SetRace("orc");
  SetClass("fighter");
  SetGender("male");
  SetLevel(10);  
  SetReligion("Saahagoth");
  SetMorality(-150);
  SetInventory( ([
    STD_HACK + "battle_axe.c" : "wield axe",
    STD_CLOTHING + "lg_shirt.c" : "wear shirt",
    STD_CLOTHING + "lg_shoes.c" : "wear shoes",
    STD_CLOTHING + "lg_pants.c" : "wear pants",
  ]) );
  SetWander(15);
}
