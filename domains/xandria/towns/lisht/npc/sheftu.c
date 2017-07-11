//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("sheftu");
  SetShort("Sheftu the Scribe");
  SetId( ({ "sheftu", "scribe" }) );
  SetRace("gnoll");
  SetTown("Lisht");
  SetLong(
    "Sheftu is a young, but altogether gifted gnoll. His hands are "
    "stained with the ink of writing many scrolls for those less "
    "fortunate. He could probably teach someone a thing or two about "
    "languages."
  );
  SetGender("male");
  SetClass("evoker");
  SetSpellBook( ([
   "shock" : 100,
  ]) );
  SetLevel(30);
  SetCombatAction(15, ({ 
    "!cast shock",
  }) );
  SetTaughtLanguages( ({ "Alatherian", "Rehshai" }) );
  SetBaseLanguage("Rehshai");
  SetLocalCurrency("deben");
  SetCharge(2000);
  SetAction(10, ({
    "!say I could teach you how to speak correctly.",
    "!emote mutters gibberish to himself thoughtfully.",
    "!emote chatters with himself.",
  }) );
  SetInventory( ([
    LISHT_OBJ "shenti" : "wear shenti",
  ]) );
}
