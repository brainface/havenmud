/* Added SetMorality -- Syra */
/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>
#include "../gurthlad.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("orc");
  SetId( ({ "orc", "scout", "orcish scout" }) );
  SetShort("an orcish scout");
  SetLong(" A beady eyed green skinned monstrosity that is recognizable "
         "as a Orc.  It is a rather pathetic example of the race. "
         "This weakling is one assigned to the less than "
         "prestigous position of advance scout.");
  SetRace("orc");
  SetClass("rogue");
  SetLevel(4);
  SetGender("male"); 
  SetMorality(-50);
  SetAction(5, ({
  			 "The orc scout pulls a juicy squig out of its armour and gobbles it down.",
         "The orc scout scans the horizon nervously.", 
         "!speak Don't jeew cauz any truble now, or Ill call da soldiers."
         }) );
  SetCombatAction(20, ({
  	     "!speak HELP, HELP, soldiers, commere boyz, help me out.",
         "The scout looks anxiously for reinforcements."
         }) );
  if(random(10) > 5) {
  SetInventory( ([ G_OBJ + "/ssword" : "wield sword in right hand",
                   G_OBJ + "/raggedleather" : "wear armour" ]) );
  }
  else {
  SetInventory( ([ G_OBJ + "/curved_dagger" : "wield dagger in right hand",
                   G_OBJ + "/raggedleather" : "wear armour" ]) );
  }

  SetCurrency("orcteef", 25);
}
