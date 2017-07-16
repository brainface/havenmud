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
   SetSkill("slash combat",220);
   SetStat("durability",70);
   SetStat("strength",70);
   SetLevel(75);
   SetMorality(0);
   SetFriends( ({ "ethereal guard","royal guard","guard","maeralin" }) );
   SetSpellBook( ([ 
   		"bolt" 				 : 100,
      "energy wall"  : 100,
      "disintegrate" : 100, 
      ]) );
   SetAction(5, ({ 
   		"!emote smiles with the eyes of a devil, and the "
      "face of an angel." 
      "!cast eneegy wall",
      }) ); 
   SetCombatAction(45, ({
   		"!cast bolt",
   		"!cast energy wall",
   		"!cast disintegrate",
   		(: eventSummon :),
   		}) );
   SetInventory( ([ 
      PR_OBJ +  "/khopesh" : "wield khopesh sword",
      PR_OBJ +  "/djellabah" : "wear djellabah",
      PR_OBJ +  "/leatherboots" : "wear leather boots" ]) );
}


int eventSummon() {
     if (1) {
     send_messages("envelope",
        "The room shudders as a %^BLUE%^crackling%^RESET%^ "
        "blast of temporal energy leaps from the throne to "
        "defend Maeralin, and %^RED%^envelopes%^RESET%^ "
        "$target_name!", this_object(), 
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
