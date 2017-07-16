// Coded by Zeratul
// 3-28-2000

#include <lib.h>
#include "../vacazar.h"
inherit LIB_SENTIENT;

int type = random(2);
string CheckSetShort();


static void create() {
  sentient::create();
  SetKeyName("citizen");
  SetId( ({"citizen","skaven","skaven citizen","wander"}) );
  SetRace("skaven");
  SetClass("rogue");
  SetLevel(3+random(3));
  SetCurrency("vacari",10+random(25));
  
  
  SetAction(3, ({
     "!yawn",
     "!speak I hear that the bloodriver is bottomless!",
     "!speak Its a good thing I moved here, I prefer to live with my own kind. ",
     "!speak I wonder why I used to live in that Dark-elf town.",
  }) );
  SetCombatAction(6, ({
     "!speak Get away from me!",
     "!speak Help me!",
  }) );

  if (type == 0) {
  SetGender("male");
  SetAdjectives( ({"citizen","male","wander"}) );
  
  SetShort("an average looking citizen");
  SetLong(
     "This average looking citizen wanders about the town, without any sort "
     "of special look on his face. He goes about his daily duties, looking "
     "as average as the next skaven to pass by. "
  );
  SetInventory( ([
  ]) );
  }

  else if (type == 1) {
  SetGender("female");
  SetAdjectives( ({"citizen","female","wander"}) );
  
  SetShort("a short citizen");
  SetLong(
     "This short citizen wanders about the town carrying out her daily "
     "activities. She looks shorter than the average skaven, much shorter, "
     "almost a foot shorter than the average skaven. "
  );
  SetInventory( ([
  ]) );
  }
  }
