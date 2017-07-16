#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

int timer = 15;

static void create() {
   npc::create();
   SetProperty("noleavehospital",1);
   SetMorality(100);
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
      SetRace("human");
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
   SetClass("valkyr");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(4+random(3));
   SetKeyName("patient");
   SetId( ({ "patient" }) );
   switch(random(8)) {
      case 0:
      SetShort("a plump patient");
      SetAdjectives( ({ "hospital","plump" }) );
      SetLong("The patient is fat; there is little else to it.  " +
              capitalize(nominative(this_object())) + " is obviously "
              "here because of problems involving being so vastly "
              "overweight, and it isn't helping with recovery any, "
              "either.  Somehow, " + nominative(this_object()) + " "
              "has also managed to get hurt in some other way, too, as "
              "there are some obvious scratches and cuts.");
      SetLevel(3);
      break;
      case 1:
      SetShort("a tall patient");
      SetAdjectives( ({ "hospital","tall" }) );
      SetLong("The hospital patient is tall and was once quite strong, "
              "but " + possessive(this_object()) + " stay here in the "
              "hospital has taken its toll.  Before getting admitted, "
              + nominative(this_object()) + " must have been in some "
              "fight, too.");
      SetLevel(6+random(3));
      break;
      case 2..7:
      SetShort("a plain hospital patient");
      SetAdjectives( ({ "plain","hospital" }) );
      SetLong("Little distinguishes this patient from any other, except, "
              "perhaps, the lack of any distinguishing marks.  "
              "A few signs of injury cover " + objective(this_object()) + ", but "
              + nominative(this_object()) + " is in little condition to "
              "do much noticing.");
      SetLevel(2+random(3));
      break;
   }
   AddHealthPoints(-(GetHealthPoints()/2 + random(GetHealthPoints()/4)));
   set_heart_beat(2);
}

void heart_beat() {
   ::heart_beat();
   timer--;
   if(!timer) {
      timer = 10+random(4);
      eventReceiveDamage(0, BLUNT, 30, 1);
      eventForce("!emote groans in pain.");
   }
}

