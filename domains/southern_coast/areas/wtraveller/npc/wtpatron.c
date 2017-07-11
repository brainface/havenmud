#include <lib.h>
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("patron");
  SetShort("a patron of the inn");
  SetId( ({"patron","frequent patron","man","patron of the inn","a patron of the inn"}) );
  SetLong("This frequent patron of the Weary Traveler Inn sits at one of the tables "
          "near the fireplace.  He is dressed in old, much worn clothes and has a bit "
          "of stubble growing on his chin.  He stares out the windows idly.");
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetLevel(2);
  SetCurrency("imperials", random(20) );
   // Above line added by Duuk  -- 071597
}
