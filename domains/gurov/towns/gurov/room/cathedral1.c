#include <lib.h>
#include "../gurov.h"
inherit LIB_CHAPEL;
inherit LIB_TOUCH;

static void create() {
  ::create();
  SetExits( ([
    "west"  : GUROV_ROOM "cathedral3",
    ]) );
  SetShort("the Kylin Church in Gurov");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetListen("The breeze whispers around the shrine.");
  SetTouch("A sense of justice and righteous fury fills the church.");
  SetSmell("The breeze keeps the church smelling fresh and inviting.");
  SetLong(
    "The Kylin Church in Gurov resides in a large, vaulted part of "
    "the Cathedral of Three Gods. White columns hold the ceiling, "
    "which seems to be much higher than in other parts of the Cathedral. "
    "To the west lies the main foyer. A large white marble altar sits at "
    "the extreme east of the shrine, dominating the entire wall."
    );
  SetItems( ([
    ({ "column", "columns" }) : "White marble columns rise to the ceiling.",
    "ceiling" : "The ceiling is vaulted and very far above ground.",
    "altar" : "The altar is a pure white marble creation that is enscribed "
              "with runes of power and faith.",
    ({ "rune", "runes" }) : "The runes are written in Eltherian and seem to "
                            "be chants for the Kylin faith.",
    ]) );
  SetItemAdjectives( ([
    "column" : ({ "white", "marble" }),
    "ceiling" : ({ "vaulted", "high" }),
    "altar"  : ({ "white", "marble" }),
    "rune"  : ({ "enscribed" }),
    ]) );
  SetInventory( ([
    GUROV_NPC "kylin_priest" : 1,
    ]) );
  SetReligion( ({ "Kylin" }) );
  SetClasses( ({ "cleric" }) );
}

void heart_beat() {
  ::heart_beat();
  foreach(object u in all_inventory(this_object())) {
    if (random(4)) continue;
    switch(random(4)) {
      case 0:
        u->eventPrint("A feeling of peace briefly overwhelms you.");
        u->AddParalyzed(1);
        break;
      case 1:
        u->eventPrint("%^WHITE%^A male voice echoes in your mind, calling you to glory.%^RESET%^");
        break;
      case 2:
        u->eventPrint("A brief sparkle of the light brightens the chapel.");
        break;
      case 3:
        u->eventPrint("A warm breeze flows through the shrine.");
        break;
      }
    }
}
