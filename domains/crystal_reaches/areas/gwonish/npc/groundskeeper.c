#include <lib.h>
#include "../path.h"

inherit LIB_NPC;


static void create()
{
  npc::create();
  SetKeyName("Perigan Vinwine");
  SetId( ({ "halfling","groundskeeper","keeper","perigan","vinwine"}) );
  SetShort("a busy groundskeeper");
  SetLong("Grass stains and mud cover the grounds keeper from the knees "
          "down.  While quite friendly, he never stops his working, even "
          "when greeting you.");
  
  SetRace("halfling");
  SetClass("priest");
  SetSkill("pole combat",1,2);
  SetLevel(3);
  SetGender("male");
  SetMorality(1000);
  
  SetCurrency("rounds", random(30) );
  SetAction(7,( {"The groundskeeper grimaces as he picks up another piece "
                 "of trash."}));
  SetAction(7,( {"The groundskeeper hoes at a weed then tosses it to a "
                 "pile to pick up later."}));

  SetCombatAction(15,({"!whimper"}));
  SetCombatAction(12,({"The grounds keeper groans, 'I seek no trouble with "
                      "yee."}));
  
  SetInventory(([ GWONISH+"obj/hoe": "wield hoe",
                  GWONISH+"obj/overalls" : "wear overalls",
                  GWONISH+"obj/cabinkey" : 1
              ]));
}
