#include <lib.h>
#include "../ph.h"
inherit LIB_NPC;
int timer = 5;
static void create() {
  ::create();
  SetKeyName("patient");
  SetShort("a poisoned patient");
  SetId( ({ "patient" }) );
  SetAdjectives( ({ "poisoned" }) );
  SetGender( ({ "male","female" })[random(2)]);
  SetLong(
     "Shaken with the effects of poison, this ashen-faced individual "
     "attempts to ride out the deadly substance.  Still slightly young, and "
     "new at adventuring, " + nominative(this_object()) + " probably "
     "stumbled into a large spider."
  );
  SetRace(({
    "human","muezzin","nosferatu","human","elf","dark-elf",
    "gelfling"})[random(7)]);
  SetClass("rogue");
  SetLevel(2);
  SetCurrency("oros", random(20) + 1);        
// Setting morality and currency based on race
   switch(GetRace()) {
      case "human":
      SetCurrency("oros",10);
      SetMorality(-400+random(500));
      break;
      case "muezzin":
      case "gelfling":
      SetCurrency("cuicui",10);
      SetMorality(300+random(400));
      SetReligion("Eclat","Eclat");
      break;
      case "elf":
      SetCurrency("imperials",10);
      SetReligion("Kylin","Kylin");
      break;
      case "nosferatu":
      SetCurrency("bloodgems",10);
      SetMorality(-300-random(400));
      SetReligion("Aberach","Aberach"); // sp?
      case "dark elf":
      SetCurrency("roni",10);
      SetMorality(-300-random(400));
      SetReligion("Soirin","Soirin"); 
      break;
   }
// Adds information to setlong to suggest the morality
   if(GetMorality()<-50) {
      SetLong(GetLong() + "  Cold, dark eyes peer from " 
      + possessive(this_object()) + " head.");
   }
   if(GetMorality()>50) {
      SetLong(GetLong() + "  A slight sense of goodness seems to "
      "come from " + nominative(this_object()) );
//      "come from this person.");
   }
  SetAction(1, ({ 
    "!say Someone, please get rid of this poison!" 
  }) );
  SetCombatAction(2, ({ "!say Help, please, no, I'm too weak!" }) );
  AddPoison(30); // Good amt?
  set_heart_beat(4);
}

void heart_beat() {
   ::heart_beat();
   timer--;
   if(!timer) {
      AddPoison(20);
      timer = 10;
      eventForce("!emote shakes uncontrollably.");
   }
   SetStat("durability",150,1); // To keep it from dying.
}
