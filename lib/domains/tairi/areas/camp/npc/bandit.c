#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../camp.h"
inherit LIB_NPC;
int Fighty();

static void create() {
  npc::create();
  SetKeyName("ronin");
  SetShort("a rough looking ronin");
  SetLong("This is a large rough looking ronin. His demeanor suggests "
          "that combat is nothing new to him.");
  SetId( ({ "ronin" }) );
  SetAdjectives( ({ "rough", "looking" }) );
  SetProperty("no bump", 1);
  SetClass("fighter");
  SetMorality(-200);
  SetLevel(random(2)+1);
  SetFriends( ({ "ronin" }) );
  SetGender("male");
  SetRace("human");
  SetBaseLanguage("Tai");
  SetCurrency("koken", 50 + random(50));
  SetInventory( ([
    CAMP_OBJ + "shield" : "wear shield on right arm",
    CAMP_OBJ + "katana" : "wield katana",
    ]) );
}

