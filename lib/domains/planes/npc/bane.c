/*  A Bane Devil */
// mahkefel 2010 mar 18 
// added armour & weapons
// mahk 2018: added tails to all devils, changed resistances
#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;
int eventThing();

static void create() {
  npc::create();
  SetKeyName("bane devil");
  SetShort("a bane devil");
  SetId( ({ "devil" }) );
  SetAdjectives( ({ "bane" }) );
  SetLong("This bane devil is a short and stocky creature with pure "
          "evil written on his face. His horrible hooked tail "
          "looks sharp and viscious.");
  SetGender("male");
  SetRace("devil");
  SetClass("rogue");
  SetLevel(100);
  SetFearType("devil fear");
  SetResistLevel(24);
  SetFearLength(10);
  SetFirstCommands( ({ "wield scourges" }) );
  SetInventory( ([
     PLANE_OBJ + "bone_armour" : "wear armour",
     PLANE_OBJ + "scourge" : 2,
     PLANE_OBJ + "sapphire" : random(5),
    ]) );
  SetCombatAction(6, (: eventThing :) );
  SetEncounter(101);
  SetMorality(-1000);
  SetResistance(POISON,"immune");
  SetResistance(GAS,"immune");
   }

int eventThing() {
  if (GetCurrentEnemy()) {
     send_messages("sting", "$agent_name $agent_verb%^RED%^BOLD%^ $target_name "  "%^RESET%^with " "$agent_possessive tail!",
       this_object(),  GetCurrentEnemy(), environment() );
     GetCurrentEnemy()->eventReceiveDamage(this_object(), POISON, GetHealthPoints() ); 
     return 1;
  }
  return 0;
}

void init() {
  fear::init();
  npc::init();
}

