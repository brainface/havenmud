/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>
#include "../gurthlad.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("human");
  SetId( ({ "human", "explorer", "human explorer" }) );
  SetShort("a human explorer");
  SetLong("A tall lean human. His skin is brown from many weeks under the sun "
          "and his eyes are set in a perpetual squint. He looks ready for anything. "
          "This human is a member of the advance exploration team that is in "
          "this area to survey for a possible orcish threat.");
  SetRace("human");
  SetClass("fighter");
  SetSkill("projectile combat",1,1);
  SetLevel(6);
  SetGender("male");
  SetMorality(50);
  SetAction(2, ({ 
  				"!speak Those squealing things taste mighty good roasted up, "
          "if you can get em out of their shell.",
          "!speak Have you seen any orcs around here? If you do, report them "
          "immediatly.",
          "!speak I hate orcs, I really really  hate orcs. Smelly, slimy, green "
          "skinned, sons of ........."}) );
  SetCombatAction(10, ({
  				"!speak Get him boys, he must be with the orcs!",
          "The human stands his ground.",
          "!speak Die you dirty orc lover!"}) );
  if(random(10) > 5) {
  SetInventory( ([ G_OBJ + "/long_sword" : "wield sword in right hand",
                   G_OBJ + "/good_leather" : "wear armour" ]) );
  }
  else {
  SetInventory( ([ G_OBJ + "/long_bow" : "wield bow",
                   G_OBJ + "/good_leather" : "wear armour" ]) );
  }
  SetCurrency("imperials", 3+ random(5));
  }
