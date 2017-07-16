#include <lib.h>
#include <domains.h>
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("pugachik");
  SetShort("Pugachik of the Shire, Reknowned Shipwright");
  SetId( ({ "pugachik", "shipwright", "pug" }) );
  SetAdjectives( ({ "reknowned" }) );
  SetLong("Pugachik is the Master Shipwright of Lloryk.  His business "
          "is the one profitable enterprise in the entire Shire.  Selling "
          "ships to outsiders makes him an immense amount of currency for "
          "the good of the Shire.");
  SetRace("halfling");
  SetGender("male");
  SetLocalCurrency("rounds");
  SetWharf(CRYSTAL_REACHES_TOWNS "lloryk/room/wharf");
  SetClass("rogue");
  SetMorality(-1000);
  SetLevel(90);
  SetLimit(1);
  SetCombatAction(20, ({
  	"!disarm",
  	"!disorient",
    }) );
}
