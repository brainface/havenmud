#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

int SetFree();

static void create()
{
  npc::create();
  SetKeyName("Toby Edlingate");
  SetId( ({ "halfling","prisoner","toby","wretch","toby","edlingate"}) );
  SetShort("a wretched prisoner [chained]");
  SetLong("Sorrow radiates from helpless looking halfling before you.");
  
  SetRace("halfling");
  SetClass("evoker");
  SetLevel(3);
  SetGender("male");
  SetMorality(300);
  
  SetProperty("prisoner",1);
  SetAction(7,( {"The prisoner looks up at you and begs, "
                 "'%^CYAN%^Please free me.%^RESET%^'"}));
  
  SetInventory(([ GWONISH+"obj/chains" : 1 ]));
}

int SetFree()
{
  if(GetProperty("prisoner"))
  {
  tell_room(this_object(),"The prisoner has been set free.");
  SetProperty("prisoner",0);
  SetShort("a wretched young halfling.");
  SetLong("A gleam of hope flickers in the halfling's eyes.");
  return 1;
  }
  else
  return 0;
}
