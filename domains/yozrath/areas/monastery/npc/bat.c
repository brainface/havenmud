// Monastery
// Aerelus
// 07/05/2006

#include <lib.h>
#include "../monastery.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("bat");
  SetShort("an angry bat");
  SetId( ({ "bat" }) );
  SetAdjectives( ({"angry"}) );
  SetLong(
    "This poor bat doesn't get to eat much. He is always on the lookout "
    "for any mice that might appear in the belfry. He hisses now and "
    "then, exclaiming his anger at the lack of food to his bat friends."
  );  
  SetRace("rodent");
  SetClass("animal");
  SetLevel(10);
  SetGender("male");
  SetAction(6, ({
    "!emote flaps around the belfry looking for food.",
  }) );
  SetCombatAction(10, ({
    "!emote hisses with rage.",
  }) );
 }