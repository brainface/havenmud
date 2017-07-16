#include <lib.h>
inherit LIB_NPC;
#include "../monastery.h"

static void create() {
   npc::create();
   SetTown("Soleil");
   SetKeyName("musician");
   SetShort("a happy musician");
   SetId( ({ "musician" }) );
   SetAdjectives( ({ "happy" }) );
   SetLong("The musician smiles happily, playing " +
           possessive(this_object()) + " instrument with "
           "great gusto and ferver.");
   
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetRace("muezzin");
   SetClass("bard");
   SetLevel(20);
   switch(random(3)) {
      case 0:
      SetInventory( ([
           M_OBJ + "flute" : 1,
			     M_OBJ + "knife_b" : "wield knife in left hand",
           ]) );
      break;
      case 1:
      SetInventory( ([
           M_OBJ + "clarinet" : 1,
			     M_OBJ + "knife_b" : "wield knife in left hand",
           ]) );
      break;
      case 2:
      SetInventory( ([
           M_OBJ + "guitar" : 1,
			     M_OBJ + "knife_b" : "wield knife in right hand",
           ]) );
      break;
   }
   SetMorality(150);
   SetAction(1,({ 
   		"!emote begs for some money.",
   		"!emote switches tunes.",
      "!dance",
      "!smile",
      "!giggle" 
      }) );
   SetSongBook( ([
			"glory of the mage" : 100,
			"ballad of summer"  : 100,
			"staccato"          : 100,
			"song of sorrow"    : 100,
		]) );
   SetCombatAction(50, ({ 
   		"!sing glory of the mage",
   		"!sing ballad of summer",
   		"!sing staccato",
			"!sing song of sorrow" 
			}) );
}