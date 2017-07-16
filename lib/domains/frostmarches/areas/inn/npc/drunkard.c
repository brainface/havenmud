#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("dirty drunkard");
  SetId( ({ "dirty drunkard", "drunkard" }) );
  SetShort("a dirty drunkard");
  SetLong("This man seems to be very dirty and very drunk.  He has a long "
          "dark grey beard which appears to have never been washed and the "
          "lice can almost be seen on his scalp.  This is a very unsavory "
          "person.");
  
  AddAlcohol(GetStatLevel("durability")-5);
  SetRace("human");
  SetClass("rogue");
  SetGender("male");
  SetLevel(3);
  SetMorality(5);
  SetCurrency("senones", 45 );
  SetAction(20, ({
                 "!vomit",
                 "!groan",
                 "!puke"                   
                 }) );
}
