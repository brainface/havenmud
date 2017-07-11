#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

void DoSomething();

static void create() {
   leader::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Acclima");
   SetShort("Acclima, the Soleil Druid Priest");
   SetId( ({ "acclima","druid","priest" }) );
   SetAdjectives( ({ "acclima","druid","priest","soleil","the" }) );
   SetLong("Acclima smiles happily, having retained the joy of her "
           "race while becoming Druidic by faith.  She loves dealing "
           "with nature and the surrounding world, so has worked "
           "hard at improving her skills.  It appears as if she "
           "has succeeded in many ways.");
   SetRace("muezzin");
   SetGender("female");
   SetReligion("Eclat","Eclat");
   SetClass("druid");
   SetLevel(175);
   SetTown("Soleil");
   SetPlayerTitles( ([
   		  "newbie"      : "the Initiate Druid of Eclat",
        "mortal"      : "the Majestic Soleil Druid Priest",
        "high mortal" : "the Guardian Angel of the WestWood",
        "legend"      : "the Revered and Dreaded Champion of the WestWood",
        "avatar"      : "the Sagacious Master of the WestWood",
        "chorist"     : "the Mellifluous WestWood Chorist",
        "fighter"     : "the WestWood Battle-Axe",
        "paladin"     : "the Chivalrous WestWood Paladin",
        "crusader"    : "the Gallant WestWood Crusader",
        "evangelist"  : "the Gentle Trader of the WestWood",
        ]) );
   SetMorality(1500);
   SetFriends( ({ "knight","guard","Acclima","Trill","Kiee",
  	}) );
   SetTaughtSpheres( ({
    	"natural healing", 
    	"natural enchantment",
    	"natural", 
    	"religion eclat",
    	}) );
   SetSpellBook( ([
        "forest banishment" : 100,
        "soothe"            : 100,
        "prismatic spray"   : 100,
        "wall of wood"      : 100,
        ]) );
   SetCombatAction(90, (: DoSomething :));
   SetFirstCommands( ({
   	"cast wall of wood",
   	"cast wall of wood",
   	"cast wall of wood",
   	"cast wall of wood",
   	}) );
}


void DoSomething() {
  if ((sizeof(GetMagicProtection()) < 2) ||
     ((!random(3)) && (sizeof(GetMagicProtection()) < 5))) {
    eventForce("cast wall of wood");
    return;
  }
  
  if (random(2)) {
    eventForce("cast forest banishment");
    return;
  }
  
  if (random(2)) {
    eventForce("cast " + (random(3) ? "prismatic spray" : "soothe"));
    return;
  }
  


}
