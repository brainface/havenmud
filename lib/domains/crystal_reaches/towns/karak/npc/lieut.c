// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lieutenant");
  SetId( ({ "an orc lieutenant", "lieutenant", "orc" }) );
  SetShort("an orc lieutenant");
  SetLong(
    "This lieutenant of the orcish horde has risen up through the "
    "ranks by way of valor, skill in battle, and, most likely, stabbing "
    "his commander in the back while he wasn't looking. He looks rather "
    "uneasy and seems to keep as much of his concentration focused upon "
    "other guards as upon strangers in the town. Given his race and his "
    "previous engagements in battle, he would likely be a moderately "
    "skills opponent."
  );
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetLevel(30);  
  SetReligion("Saahagoth");
  SetMorality(-250);
  SetInventory( ([
    KARAK_OBJ + "helm" : "wear helm",
  ]) );
}
