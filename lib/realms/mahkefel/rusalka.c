// mahkefel@haven
// 2014 sometime
// trying to make lagoon not goddamned boring

#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("rusalka");
  SetId( ({ "maiden", "rusalka" }) );
  SetAdjectives( ({ "red", "haired" }) );
  SetShort("a red-haired maiden");
  SetLong(
    "This little girl looks a bit waifish, and her clothes are soaking wet, "
    "but that has clearly done nothing to diminish her attitude, judging "
    "by the girlish giggles. Unfortunately, she also has no eyes, so the "
    "laughter's probably at your expense."
  );
  SetClass("bard");
  SetLevel(110);
  SetGender("female");
  SetRace("human");
  SetUndead(1);
  SetUndeadType("rusalka");
  
  SetAction(5, ({
  })  );
  SetSongBook( ([
   
  ]) );
  SetCombatAction(50, ({
    "!cast the wind and rain",
    "!cast sonic barrier",
    "!cast ballad of winter",
    "!cast ballad of the seasons",
    }) );
  SetInventory( ([
    TAIGA_OBJ "staff" : "wield staff",
      ]) );
  //SetDie("A distant star crashes into the ocean as the ancient falls.");
  SetFirstCommands( ({
    "cast sonic barrier",
    "cast sonic barrier",
    "cast sonic barrier",    
  }) );
}
