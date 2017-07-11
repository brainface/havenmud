/*  A citizen of Haven Town */
#include <lib.h>
#include "haven.h"
inherit LIB_SENTIENT;
int CheckWanted();
#include "../wanted.h"

static void create() {
  sentient::create();
  SetKeyName("citizen");
  SetShort("a citizen of Haven Town");
  SetId( ({ "citizen", "haven_wander" }) );
  SetAdjectives( ({ }) );
  SetRace("elf");
  SetClass("fighter");
  SetLevel(random(5)+1);
  SetMorality(10+random(500));
  SetCurrency("imperials", random(30));
  SetLong("This is a citizen of Haven Town. He looks like he has pressing "
          "business in the city and is not to be disturbed.");
  SetGender("male");
  SetAction(6, ({
      "!speak I hear there is a camp of bandits outside of town!",
      "!speak The Templars of the Church take good care of the town.",
      "!speak I just got back from a vacation at Platypus Bay.",
      "!speak I long for the Wilder Days...",
      }) );
  SetWander(5);
  SetFriends( ({ "town guard" }) );
  SetTalkResponses( ([
      ({ "bay", "platypus bay" }) : "It is a good place with lots "
         "of relaxing animals. It is about 20 pacheki west "
         "of town and then south to the coast.",
      ({ "bandit", "bandit camp", "camp", "bandits" }) : 
         "Rumors fly that it is just west of town.",
      ({ "grove", "tower", "mage tower" }) : "That evil place is a hideous "
         "area that bodes evil for Haven Town. Only the bravest "
         "of mages should go there.",
      ({ "cemetary" }) : "That is a place of death and old evil.",
      ({ "church", "kylin", "templar" }) : "Duuk's faith is a pillar that "
         "supports the town.",
      ]) );
  SetEncounter( (: CheckWanted :) );
  SetLimit(4);
}

int CheckWanted() {
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
    eventForce("yell A criminal!");
    return 0;
    }
  return 0;
  }
