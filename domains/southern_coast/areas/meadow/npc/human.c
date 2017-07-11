// A human chillin in the bay
// For Platypus Bay
// Urien@Haven 06JUL08


#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../meadow.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("vacationer");
  SetShort("human vacationer");
  SetId( ({ "human", "vacationer" }) );
  SetAdjectives( ({ "human", "old" }) );
  SetRace("human");
  SetTown("Haven");
  SetBaseLanguage("Eltherian");
  SetClass("sailor");
  SetLevel(2);
  SetLong(
    "This human has short blonde hair which is spiked and his broad nose rests in between "
    "his tiny brown eyes. His face is buried underneath a rugged dark brown beard and his "
    "skin has a dark brown tan to it as if hes spent much time in the sun."
    );
  SetGender("male");
  SetInventory( ([
    MEADOW_OBJ "oldpole" : "wield pole"
    ]) );
  SetAction(10, ({ "!fish with first pole",
    "!say I enjoy Platypus bay, it's so lovely.",
    "!say Would you care to fish with me and tell me of your travels?"
  }) );
    
}

