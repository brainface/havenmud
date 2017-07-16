#include <lib.h>
inherit LIB_LEADER;
#include "../monastery.h"

void DoSomething();

static void create() {
   leader::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("Payat");
   SetShort("Payat, a divinely joyous druid of Eclat");
   SetId( ({ "payat","druid","druid of eclat" }) );
   SetAdjectives( ({ "divine","divinely joyous","eclat","eclatish" }) );
   SetLong("Payat smiles with a joyous face, looking up at everything "
           "in the world.  He shines with an inner light of joy and "
           "happiness, perking up all believers around him.");
   SetReligion("Eclat","Eclatish");
   SetClass("druid");
   SetTown("Soleil");
   SetSkill("melee combat",1,1);
   SetLevel(75);
   SetGender("male");
   SetRace("muezzin");
   SetInventory( ([
   	M_OBJ + "circlet" : "wear circlet on head",
        ]) );
   SetSpellBook( ([
   	"forest banishment" : 100,
   	"vine wall"         : 100,
   	"soothe"	    : 100,
   	"vermin horde"      : 100,
   	]) );
   SetAction(1,({ 
   	"!speak in oiseau Joy to all!",
   	"!smile",
        "!laugh",
        "!giggle",
        "!emote chuckles merrily.",
        "!emote starts laughing spontaneously." }) );
   SetCombatAction(50, (: DoSomething :) );
   SetMorality(1500);
   SetFirstCommands( ({
   	"cast vine wall",
   	"cast vine wall",
   	"cast vine wall",
   	"cast vine wall",
   	}) );
}

void DoSomething() {
  if ((sizeof(GetMagicProtection()) < 2) ||
     ((!random(3)) && (sizeof(GetMagicProtection()) < 5))) {
    eventForce("cast vine wall");
    return;
  }
  
  if (random(2)) {
    eventForce("cast " + (random(3) ? "vermin horde" : "soothe" ));
    return;
  }
  
  if (random(2)) {
    eventForce("cast forest banishment");
    return;
  }
}
