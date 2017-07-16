#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include <std.h>
#include "../camp.h"
inherit LIB_NPC;
int Fighty();

static void create() {
  npc::create();
  SetKeyName("ronin swordsman");
  SetId( ({ "ronin", "swordsman" }) );
  SetAdjectives( ({ "ronin", "swordsman" }) );
  SetShort("a ronin swordsman");
  SetLong(
    "This ronin was obviously samurai for some house before being dishonored. "
    "His equipment suggests that he has fallen on very hard times."
    );
  
  SetRace("human");
  SetGender("male");
  SetClass("cavalier");
  SetLevel(random(5)+3);
  
  SetMorality(-200);
  
  SetBaseLanguage("Tai");
  SetCurrency("koken",10 + random(100));
  SetInventory( ([
    CAMP_OBJ "katana" : "wield katana",
    ]) );
  SetFirstCommands( ({ "guard northeast" }) );
  }
