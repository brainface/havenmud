#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("wiry bandit");
  SetId( ({ "wiry bandit", "bandit" }) );
  SetRace("human");
  SetShort("a wiry bandit");
  SetGender("male");
  SetClass("rogue");
  SetLevel(random(4)+2);
  SetMorality(-150);
  SetLevel(random(4)+2);
  SetCurrency("imperials",random(30)+20);
  SetInventory( ([
     CAMP_OBJ + "/hcross" : "wield crossbow in right hand",
      ]) );
  SetLong("This is a wiry looking bandit that seems more "
          "reserved than the others.");
  }
