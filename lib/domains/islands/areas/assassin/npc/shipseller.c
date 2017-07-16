#include <lib.h>
#include <domains.h>
#include <vehicle.h>
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("Scurvy Willem");
  SetShort("Scurvy Willem");
  SetId( ({ "willem", "scurvy" }) );
  SetAdjectives( ({ "scurvy" }) );
  SetLong(
    "Scurvy Willem was shipwrecked many years ago and washed up "
    "on Assassin Isle like so much flotsam. He quickly realized "
    "that his pirating days were at an end, but is content and "
    "pleased to serve the Lord of Assassin Isle."
  );
  SetRace("human");
  SetGender("male");
  SetLocalCurrency("imperials");
  SetWharf(ISLANDS_AREAS "assassin/room/bay");
  SetClass("rogue");
  SetClass("sailor");
  SetMorality(-250);
  SetLevel(25);
  SetLimit(1);
  SetLargestShip(0);
  SetSalvageModifier(0.1);
}
