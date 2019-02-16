#include <lib.h>
#include <std.h>
#include "../vesta.h"
inherit LIB_MULE_SELLER;

static void create() {
  ::create();
  SetKeyName("Galo");
  SetShort("Galo the Seller of Steeds");
  SetLong(
    "Galo is short, stocky human with a perpetual frown on his face. "
    "He sells horses for those with enough imperials to buy them. "
    "<greet galo> to see the cost he would charge you."
    );
  SetRace("human");
  SetGender("male");
  SetId( ({ "galo", "seller" }) );
  SetAdjectives( ({ "steeds" }) );
  SetTown("Sanctum");
  SetCostModifier(1.0);
  SetClass("merchant");
  SetLevel(10);
  SetMorality(150);
  
  SetMule(VESTA_NPC "draft_horse");
}
