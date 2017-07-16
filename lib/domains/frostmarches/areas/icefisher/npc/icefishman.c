#include <lib.h>
#include "../ice.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("m'rov");
   SetShort("M'rov the goden fisherman");
   SetId( ({"mrov", "man", "fisherman"}) );
   SetAdjectives( ({ "fisher", "fish", "slender", "ice", }) );
   SetLong(
        "M'rov is a slender buff-colored goden, with eyes the "
        "color of the sea after a storm.  In his adventuring years, "
        "he gained a reputation of being rather an odd fellow, due "
        "to his love of water and fishing. Now returned to the "
        "mountains of his birth, M'rov still enjoys fishing "
	      "at every possible opportunity. He is armed not only with "
	      "his own natural set of razor-sharp claws, but also with a "
				"wickedly keen double-bladed knife, and he certainly looks "
				"as though he knows how to use every weapon at his disposal. "
				);
   SetGender("male");
   SetRace("goden");
   SetClass("merchant");
   SetTown("all");
   SetTrainingSkills( ({ 
			"fishing", 
			"knife combat", 
		  }) );
	 SetLevel(35);
   SetCurrency("senones",random(20)+10);
   SetMorality(-75);
   SetLimit(1);
   SetInventory( ([
	      ICE_OBJ + "/vest" : "wear vest",
        ICE_OBJ + "/pants" : "wear pants",
        ICE_OBJ + "/fur_cloak" : "wear cloak",
        ICE_OBJ + "/knife" : "wield knife",
	      ICE_OBJ + "/pole" : "wield pole",
        ]) );
   SetAction(10, ({ 
	      "!fish with pole",
        "!speak Here... oh fish, oh fish, oh fishy, oOOoohh!",
        "!emote examines his pole.",
        "!speak Fishing is so relaxing... would you like to learn?"
	}) );
   SetCombatAction(15, ({
	      "!speak Why are you attacking me? Go drill your own fishing hole "
        "in the ice!", 
	      "!speak Stop that!",
        "!speak Get away!  Leave me alone!",
        "!speak Hey, I'm trying to fish here!",
        "!speak What are you doing?",
        "!speak Fool!  Idiot!",
	      "!speak Think of the years I've spent training to be so good at "
        "fishing! There's a lot I could teach you, fool!",
        "!speak Get away!  Stop that!",
        "!speak Help! Help!", 
	      "!yell Help! Help me!", 
	      "!yell Someone's trying to kill an innocent fisherman!", 
        "!speak You stay away from my pole! It's a good one!  Cost me a "
	      "lot of money, it did!", 
        }) );
}

/** Approved by Laoise at Fri Jul  9 20:21:49 2004. **/
