//Selket@Haven
//2006
#include <lib.h>
#include "../mastaba.h"
#include <std.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetTown("Lisht");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetGender("male");
  SetClass("rogue");
  SetLevel(30);
  SetKeyName("graverobber");
  SetId( ({"graverobber", "robber"}) );
  SetShort("a graverobber");
  SetLong(
    "This panting graverobber seems frightened of the tomb "
    "he has risked so much for to enter. He continually peers "
    "down into the antechamber, fear overtaking his greed.");
  SetAction(5, ({
    "!say There are much fiercer things down there than I.",
    "!emote peers down into the antechamber warily.",
    "!say You go first.",
    }) );
  SetMorality(-200);
  SetCurrency("deben",500 + random(300) );
  SetInventory( ([
    STD_WEAPON "knife/stiletto" : "wield knife",
    MASTABA_OBJ + "bl_cloak2.c" : "wear cloak",
    ]) );
  }
