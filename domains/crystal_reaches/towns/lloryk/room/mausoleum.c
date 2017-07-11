#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("a tomb deep under the Eclat Temple");
  SetLong("Arrayed along the walls of the tomb are various drawers "
          "which seem to contain the remains of the halfling legends "
          "of the past.  Stone facings and small inscriptions tell "
          "the deeds of the Heroes of the Shire.  Burned into the floor "
          "is a large rune meaning, \"History Remembers.\" Smaller urns "
          "are placed on shelves made of less impressive materials. A "
          "stairway leads back up to the Temple."
     );
  SetAmbientLight(40);
  SetProperty("no attack", 1);
 SetProperty("no magic", 1);
  SetProperty("no bump", 1);
  SetTown("Lloryk");
  SetItems( ([
               ({ "urn","urns" }) : "The urns are sealed tightly and marked "
                                    "with the names of the dead.",
               ({"drawer","drawers"}) : "The drawers are sealed tightly and "
                                        "bear the names of the dead, such as "
                                        "Lenist and Inalin.",
               ({ "facing", "facings" }) : "These are simple stone images of "
                                        "the dead buried within.",
               ({ "inscription", "inscriptions" }) : "These list the name "
                                        "and date of the buried's life.",
               ({ "rune" }) : "It reads, 'History Remembers'.",                                                                 
               "stairway" : "The stairway leads up to the church above.",
                ]) );
  SetItemAdjectives( ([
    "facing" : ({ "stone" }),
    "inscriptions" : ({ "small" }),
    "rune" : ({ "large" }),
    "urn" : ({ "small", "smaller" }),
    ]) );
  SetExits( ([ 
    "up" : LLORYK + "room/church",
    ]) );
  SetSmell( ([
    "default" : "Dust mixes with decay to form a less than pleasing scent.",
    ]) );
  SetListen( ([
    "default" : "The tomb is absolutely still and quiet.",
    ]) );
  SetInventory( ([
    STD_OBJ "reztotem" :1,
    LLORYK "npc/healer" : 1,
    ]) );
}
