#include <lib.h>
#include "../ph.h"
#include <damage_types.h>
inherit LIB_NPC;

int timer = 3;

static void create() {
  string long = "";
  ::create();
  SetKeyName("patient");
  SetShort("a recuperating patient");
  SetId( ({ "patient" }) );
  SetAdjectives( ({ "recuperating" }) );
  SetLong(
    "Scratches and gashes mar this patient's face, while the rest of "
    + possessive(this_object()) + " body hides under a crisp sheet.  "
    + capitalize(nominative(this_object())) + " doesnt appear to be "
    "in very good shape." + long
  );
  
  SetRace( ({ 
    "human","human","human","muezzin","gelfling","halfling",
    "elf","dark-elf","nosferatu","sprite","human"})[random(11)]);
  SetClass("rogue");
  SetLevel(1+random(2));   
  SetMeleeAttackString("hands");
  SetMeleeDamageType(BLUNT);
  SetGender(({"male","female"})[random(2)]);
  
// Bases morality and currency on race
  switch(GetRace()) {

      case "human" :
      SetMorality(500+random(650));
      SetCurrency("oros",10+random(30));
      break;

      case "muezzin":
      case "gelfling":
      case "halfling":
      SetMorality(41 + random(1000));
      SetReligion("Eclat","Eclat");
      SetCurrency("cuicui", 10);
      SetCurrency("oros",10);
      break;

      case "elf":
      SetMorality(200+random(400));
      SetReligion("Kylin","Kylin");
      SetCurrency("cuicui", 7);
      SetCurrency("oros",7);
      break;

      case "sprite" :
      SetMorality(150 + random(275));
      SetReligion("Magildan","Magildan");
      SetCurrency("cuicui", 7);
      SetCurrency("oros",7);
      break;

      case "dark-elf":
      SetMorality(-900+random(450));
      SetReligion("Soirin","Soirin");
      SetCurrency("cuicui", 7);
      SetCurrency("oros",7);
      break;
   }
// Adds more information to the Long to suggest the Morality
  if(GetMorality() < -40) {
    long = "  It looks like this individual deserved the "
    "beatings " + nominative(this_object()) + " got.";
  }
  if(GetMorality() > 40) {
    long = "  This individual appears to have been an innocent victim.";
  }
  SetInventory( ([
     PO + "/sheet" : "wear sheet",
  ]) );
  AddHealthPoints(-(GetHealthPoints()*2/4));
  set_heart_beat(5);
  if(!random(5)) {
    RemoveLimb(({"left hand","right hand","left foot","right foot",
                 "left arm","right arm","left leg","right leg"})[random(8)],0);
  }
}

void heart_beat() {
  ::heart_beat();
  timer--;
  if(!timer) {
    timer = 7;
    eventReceiveDamage(0, BLUNT, (GetHealthPoints()/7), 1);
    eventForce(({
      "emote groans.",
      "emote moans.",
      "emote whimpers.",
      "emote gestures for help.",
      "say heal me, please!",
      "emote winces."})[random(6)]);
  }
}
