#include <lib.h>
#include <vehicle.h>
#include "../tairi.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("Minamoto Omi");
  SetShort("Minamoto Omi the Shipwright");
  SetId( ({ "omi", "minamoto", "shipwright" }) );
  SetAdjectives( ({ "minamoto", }) );
  SetLong(
    "Minamoto Omi, brother to the Daimyo, is the Shipwright for Tairi.  His large ships are "
    "a sight that can be easily recognized for leagues at sea. His work is without the delicate "
    "lines of the elves, and lack the deadly effeciency of the goden, but they suffice."
    );
  SetRace("human");
  SetBaseLanguage("Tai");
  SetGender("male");
  SetLocalCurrency("koken");
  SetWharf(TAI_RI_ROOM "path11");
  SetClass("sailor");
  SetMorality(-250);
  SetLevel(30);
  SetLimit(1);
  SetLargestShip(VS_DREADNAUGHT);
  SetLargestWeapon(VW_DEVASTATING);
}
