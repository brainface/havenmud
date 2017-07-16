#include <lib.h>
inherit LIB_NPC;

int timer;

static void create() {
   npc::create();
   SetMorality(100);
   SetProperty("noleavehospital",1);
   switch(random(6)) {
      case 0:
      SetRace("muezzin");
      SetReligion("Eclat","Eclatish");
      break;
      case 1:
      SetRace("halfling");
      break;
      case 2:
      SetRace("elf");
      break;
      case 3:
      SetRace("gelfling");
      break;
      case 4:
      SetRace("halfling");
      break;
      case 5:
      SetRace("dwarf");
      break;
   }
   switch(random(2)) {
      case 0:
      SetGender("female");
      break;
      case 1:
      SetGender("male");
      break;
   }
   SetKeyName("poisoned patient");
   SetShort("a poisoned patient");
   SetId( ({ "patient" }) );
   SetAdjectives( ({ "poisoned" }) );
   SetLong("The patient is sickened unto deliriousness, and can't " 
           "focus on the world around " + objective(this_object()) + ".  "
           "Sweat runs down " + possessive(this_object()) + " face and "
           + nominative(this_object()) + " looks cold and clammy.  "
           + capitalize(nominative(this_object())) + " is very sick.");
   AddPoison(55);
   timer = 20;
   SetClass("valkyr");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(1);
   AddHealthPoints(-(GetHealthPoints()/2) );
   set_heart_beat(4);
}

void heart_beat() {
   ::heart_beat();
   timer--;
   if(!timer) {
      AddPoison(30);
      timer = 10;
      eventForce("!emote 's eyes close in pain.");
   }
}

