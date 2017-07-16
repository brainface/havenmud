#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("ronin");
  SetId( ({ "ronin" }) );
  SetAdjectives( ({ "thin" }) );
  SetRace("human");
  SetBaseLanguage("Tai");
  SetShort("a thin ronin");
  SetGender("male");
  SetClass("rogue");
  SetLevel(random(4)+2);
  SetMorality(-150);
  SetLevel(random(4)+2);
  SetCurrency("koken",10 + random(30));
  SetInventory( ([
     CAMP_OBJ + "wakasashi" : "wield wakasashi",
      ]) );
  SetLong("This is a thin, wiry looking ronin that seems more "
          "reserved than the others.");
  SetFirstCommands( ({ "guard southeast" }) );
  }
