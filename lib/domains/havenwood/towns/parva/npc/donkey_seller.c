#include <lib.h>
inherit LIB_MULE_SELLER;

static void create() {
  ::create();
  SetKeyName("hoetee");
  SetShort("Hoetee the Donkey Seller");
  SetLong(
    "Hoetee is a middle-aged man who has spent his life in the stables."
    " He once had grand dreams of fighting dragons and saving the princess,"
    " but reality over came him and now he has settled into the life of"
    " a measly donkey seller. He looks extremely depressed."
    );
  SetRace("human");
  SetGender("male");
  SetId( ({ "hoetee", "seller" }) );
  SetAdjectives( ({ "donkey" }) );
  SetTown("Parva");
  SetCostModifier(1.0);
  SetMule("/std/npc/donkey");
  SetClass("merchant");
  SetLevel(10);
  SetMorality(0);
}
