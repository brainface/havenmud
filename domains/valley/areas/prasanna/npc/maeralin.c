#include <lib.h>
#include "prasanna.h"
#include <damage_types.h>
inherit LIB_NPC;
int eventSummon();

static void create() {
   npc::create();
   SetKeyName("Maeralin");
   SetId( ({ "Maeralin" }) );
   SetAdjectives( ({ "Maeralin" }) );
   SetShort("Maeralin bint Tariq al-Ishraq");
   SetLong("The foremost resident of Prasanna, respected equally for her "
           "beauty, strength, and wisdom. Curly raven hair falls down past "
           "her shoulders, and frames the picturesque features that have "
           "been the undoing of countless men. Her movements are those of a "
           "dancer and a fighter, and the gleam in her black eyes finds "
           "equal only in the stars. ");
   
   SetGender("female");
   SetRace("human");
   SetClass("evoker");
   SetSkill("slash combat",1,1);
   SetLevel(50);
   SetMorality(0);
   
   SetFriends( ({ "ethereal guard","royal guard","guard" }) );
   SetSpellBook( ([ 
   		"fireball"        : 100,
      "energy field"    : 100,
      "chain lightning" : 100,
      ]) );
   SetAction(5, ({ 
   		"!emote smiles with the eyes of a devil, and the "
      "face of an angel.",
      "!cast energy field",
      }) ); 
   SetCombatAction(60, ({
   		(: eventSummon :),
   		"!cast energy field",
   		"!cast fireball",
   		"!cast chain lightning", 
   	  }) );
   SetInventory( ([ 
      PR_OBJ +  "/khopesh" : "wield khopesh sword",
      PR_OBJ +  "/djellabah" : "wear djellabah",
      PR_OBJ +  "/leatherboots" : "wear leather boots" 
      ]) );
}


int eventSummon() {
     if (1) {
     send_messages("summon",
        "$agent_name $agent_verb a %^BLUE%^shimmering%^RESET%^ "
        "spirit from the temporal planes to call the anger of "
        "%^RED%^Jagra %^RESET%^upon $target_name!", this_object(), 
         GetCurrentEnemy(), environment() );
      GetCurrentEnemy()->eventReceiveDamage(this_object(), MAGIC,
              300, 0); 
    return 1;
        }
  return 0;
  }

void init() {
  npc::init();
  }
