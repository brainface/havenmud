/*  A Barky Dog */
// mahkefel 2021! 11 years!
#include <lib.h>
#include <std.h>
#include "../planes.h"
#include <armour_types.h>
#include <damage_types.h>

inherit LIB_NPC;
int eventThing();

static void create() {
  npc::create();
  SetKeyName("bark dog");
  SetShort("a bark dog");
  SetId( ({ "dog" }) );
  SetAdjectives( ({ "bark" }) );
  SetLong(
    "Clearly no average dog, this hound's fur is a rough and wooly bark "
    "around a core of living oaken limbs.");
  SetGender("male");
  SetRace("dog", "bark dog");
  SetClass("ranger");
  SetLevel(40);
  SetFirstCommands( ({ "cast thicken skin", "cast barkskin" }) );
  SetCombatAction(6, (: eventThing :) );
  SetMorality(100); // all dogs are good dogs
  SetResistance(SOUND,"medium");
  SetResistance(ALL_PHYSICAL,"medium");
  SetResistance(HEAT,"vulnerable");
  SetNoCorpse("The bark dog shatters into so many splinters");
  SetInventory( ([
		  STD_POLE "stick" : "wield stick",
		  ]) );
  SetAction(20, ({    
		  "!emote rolls into a pile of leaves and is suddenly slightly larger.",
		  "!emote barks at you, how unexpected.",
		  "!emote 's stick of a tail wags back and forth, scattering leaves everywhere.",
		    }) );
}

int eventThing() {
  if (GetCurrentEnemy()) {
     send_messages("bark", "$agent_name $agent_verb%^BOLD%^ furiously at $target_name, showering "
		   "$target_objective with %^BOLD%^GREEN%^splinters!%^RESET%^.",
       this_object(),  GetCurrentEnemy(), environment() );
     GetCurrentEnemy()->eventReceiveDamage(this_object(), SOUND|PIERCE, GetHealthPoints() ); 
     return 1;
  }
  return 0;
}

