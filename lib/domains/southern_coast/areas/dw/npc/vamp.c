/*  A new and improved vampire object */
#include <lib.h>
#include "../newbie.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("Philia Ravenhair");
  SetMorality(-350);
  SetId( ({ "vampire", "woman", "ravenhair", "philia" }) );
  SetAdjectives( ({ "timeless", "beautiful" }) );
  SetShort("a beautiful woman of timeless quality");
  SetLong("This woman is the single most beautiful creature on Kailie. "
          "Her name is Philia Ravenhair, and she is descended from one "
          "of the most regal of all the human lines. "
          "Her pale white skin heightens the true effect and awe with "
          "which her dark eyes captivate men. Her luscious neckline "
          "begs to be kissed by any human male with a pulse. Her "
          "long and flowing black hair seems to be reacting to a "
          "light and refreshing breeze that only she can feel.");
  SetRace("human");
  SetUndead(1);
  SetUndeadType("vampire");
  SetClass("evoker");
  //SetSkill("chaos magic", GetLevel() * 3, 1);
  SetLevel(12);
  SetGender("female");
  SetInventory( ([
      NEWBIE_OBJ + "/dagger" : "wield dagger",
      NEWBIE_OBJ + "/dress"  : "wear dress",
    ]) );
  SetSpellBook( ([
      "shock"        : 20,
      "capsule"      : 100,
      "ice ball"     : 80,
      ]) );
  SetCombatAction(70, ({
     "!cast shock",
     "!cast ice ball",
     "!cast capsule",
     }) );
  RemoveLanguage("Enlan");
  SetLanguage("Eltherian", 100, 1);
  SetLanguage("Archaic", 100);
  }

void eventEnemyDied(object deadboy) {
  object newvamp;

  newvamp = new(__DIR__ + "vamp_corpse");
  newvamp->SetRace(deadboy->GetRace());
  newvamp->SetLevel(deadboy->GetLevel());
  newvamp->SetClass(deadboy->GetClass());
  newvamp->SetShort(deadboy->GetFullShort() + " (vampire)");
  newvamp->SetLong(deadboy->GetRawLong());
  newvamp->SetId(deadboy->GetId() + ({ "vampyre" }) );
  newvamp->SetGender(deadboy->GetGender());
  newvamp->SetProperty("invader", 1);
  if (present("corpse", environment())) {
    present("corpse", environment())->eventDestruct();
   }
  message("system", deadboy->GetCapName() + " rises from the dead!",
     environment() );
  newvamp->eventMove(environment());
  newvamp->eventForce("get all");
  newvamp->eventForce("wear all");
  foreach(object thing in all_inventory(newvamp)) {
     if (!(thing->GetWorn()))
        newvamp->eventForce("wield " + (string)thing->GetKeyName());
    }
  newvamp->eventForce("follow vampire");
  eventForce("lead vampyre");
  sentient::eventEnemyDied(deadboy);
  }

