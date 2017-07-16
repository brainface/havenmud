#include <lib.h>
#include "prasanna.h"
#include <damage_types.h>
inherit LIB_NPC;

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
           "equal only in the stars. Her body is a fluid structure of grace "
           "and power.");
   SetLevel(50);
   SetMorality(0);
   SetGender("female");
   SetRace("human");
   SetClass("evoker");
   SetFriends( ({ "ethereal guard","royal guard","guard" }) );
   SetSpellBook( ([ "fireball" : 75,
                    "elemental protection" : 100,
                    "enhanced fireball" : 75,
                    "disintegrate" : 65, ]) );
   SetAction(5, ({ "!emote smiles with the eyes of a devil, and the "
                   "face of an angel." }) ); 
   SetCombatAction(25, ({ "!cast elemental protection", 
                          "!cast enhanced fireball",
                          "!cast disintegrate" }));
   SetInventory( ([ 
            PR_OBJ +  "/khopesh" : "wield khopesh sword",
            PR_OBJ +  "/djellabah" : "wear djellabah",
            PR_OBJ +  "/leatherboots" : "wear leather boots" ]) );
}
