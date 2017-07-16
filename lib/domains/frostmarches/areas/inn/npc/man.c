#include <lib.h>
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("man");
  SetShort("a skinny, little man");
  SetId( ({ "skinny little man", "little man", "man" }) );
  SetLong("Thin, frail arms and visible ribs testify to the poverty of this "
          "poor man's life.  He appears to be only in his mid 20's but he "
          "is already balding from lack of nutrition.  Whether it is his "
          "own fault or circumstances are to blame, this is a highly "
          "pitiable person.");
  SetClass("rogue");
  SetRace("human");
  SetLevel(4);
  SetGender("male");
  SetCurrency("senones", random(30)+1 );
  SetMorality(250);

}

