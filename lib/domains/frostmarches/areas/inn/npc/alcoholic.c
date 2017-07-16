#include <lib.h>
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("alcoholic");
  SetShort("an alcoholic");
  SetId( ({ "alcoholic", "drunkard" }) );
  SetLong("This disgrace of a man seems to have drunken himself into "
          "oblivion.  It is amazing that he is still conscious.");
  SetRace("human");
  SetGender("male");
  SetClass("rogue");
  SetMorality(25);
  SetLevel(random(3)+3);
  SetCurrency("senones", GetLevel()*25 );
  AddAlcohol(GetStatLevel("durability")/2);
}

