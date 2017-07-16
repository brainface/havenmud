#include <lib.h>
#include <std.h>
#include "../rome.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("marcus");
  SetShort("Marcus Crassus, Legionnaire General of Sanctum ");
  SetAdjectives( ({ "of sanctum", "legionnaire" }) );
  SetId( ({ "marcus", "general", "crassus" }) );
  SetRace("human");
  SetClass("fighter");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetLong("Marcus Crassus is the General of the Sanctum Legionnaires. "
          "Though he is young he appears to be a formitable foe and a "
          "capable leader. Many have followed him to their deaths and many "
          "have returned alive with glory in hand.");
  SetGender("male");
  SetLevel(130);
  SetInventory( ([
    STD_WEAPON + "slash/longsword" : "wield longsword",
    ]) );
  SetAction(5, ({
    "!speak Join and become a Legionnaire!",
    "!speak If you seek to become a Legionnaire, you have come to the right place.",
    }) );
  SetCombatAction(10, ({
  	"!disarm",
  	"!disorient",
    }) );
  SetLimit(1);
  SetPlayerTitles( ([
    "newbie" : "the Optio of the Sanctum Legion",
    "mortal" : "the Tesserarius of the Sanctum Legion",
    "hm"     : "the Centurion of the Sanctum Legion",
    "legend" : "the Primus Pilus of the Sanctum Legion",
    "avatar" : "Legatus Legionis $N the Commander of the Sanctum Legion",
    ]) );
  SetFreeEquipment( ([
    STD_WEAPON "sword" : 1,
    ]) );
}
