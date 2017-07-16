#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../camp.h"
inherit LIB_NPC;
int Fighty();

static void create() {
  npc::create();
  SetKeyName("ronin");
  SetShort("a large ronin");
  SetLong("This is a large ronin.  His demeanor suggests "
          "that combat is nothing new to him.");
  SetId( ({ "ronin" }) );
  SetAdjectives( ({ "rough", "large" }) );
  SetGender("male");
  SetRace("human");
  SetClass("fighter");
  SetMorality(-200);
  SetLevel(random(3)+2);
  SetFriends( ({ "ronin" }) );
  
  SetBaseLanguage("Tai");
  SetCurrency("koken",5 + random(70));
  SetInventory( ([
    CAMP_OBJ "katana"    : "wield katana",
    CAMP_OBJ "wakasashi" : "wield wakasashi"
    ]) );
  }

