// Western Road
// Kresh Village
//  Urien 110613 - Added Day/Night Long
//  Climate, Town, Domain, Items, Adjectives

#include <lib.h>
#include <domains.h>
#include "../goblins.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Southern Coast");
  SetTown("Kresh");
  SetShort("a tent from the main path");
  SetDayLong("This alleyway isolated away from the main path "
     "of Kresh, leads to a secluded tent in a barren field. "
     "Some shrubbery tries to exist in the hard packed "
     "soil however, it is devoid of life. The black tent "
     "sits virtually isolated.");
  SetNightLong("The alleyway from the main path to the east "
     "leads to this black tent. Some shrubbery reflects "
     "the night shade along the flat ground in this barren "
     "field. This tent far from the path has a humble, "
     "isolated quality to it in the darkness.");
  SetItems( ([
    "tent": "The tent is small and black, with no "
      "discernible markings along the outside. The alleyway "
      "path leads directly through the entrance. Its "
      "peak has been decorated with a madded fur that "
      "sways softly from the wind.",
    "ground": "The ground is normal, packed soil which "
      "stretches as far as the eye can see. It has "
      "some shrubbery which has grown along the surface "
      "stretches across the Southern Coast.",
    "shrubbery": "Some dead and dried out shrubbery "
      "pokes out of the ground. It looks as if it has "
      "seen too much damage from the sun and not "
      "enough nourishment in this desolate environment.",
    "alleyway": "The alleyway of Kresh ends, leading to "
      "the entrance of a tent. The pathway leads off east "
      "to join with the main path.",
    "path": "The main path lies east away from this "
      "Goblin alleyway in Kresh.",
    "soil": "Hard, packed soil leaves little nourishment "
      "for life in the ground. Shrubbery that once "
      "lived, now lay in ruin from the nomad lifestyle.",
    "field": "The field is barren and plain. Dried "
      "shrubbery litters the surface of the soil but "
      "yields no life. The alleyway leads east to the "
      "main path of Kresh.",
  ]) );
  SetItemAdjectives( ([
   "tent": ({ "small","black" }),
   "shrubbery": ({ "dead","dried" }),
   "path": ({ "main" }),
   "soil": ({ "hard","packed" }),
   "field": ({ "barren","plain" }),
  ]) );
  SetInventory( ([
     GOBLIN_NPC + "valk" : random(3) + 2,
      ]) );
  SetEnters( ([
     "tent" : GOBLIN_TENT + "valkyr",
  ]) );
  SetListen( ([
     "default" : "The barren field ebbs in silence.",
  ]) );
  SetSmell( ([
     "default" : "It smells rather pleasant.",
  ]) );
  SetObviousExits("east");
  SetExits( ([
    "east" : GOBLIN_ROOM + "m_2",
    ]) );
}