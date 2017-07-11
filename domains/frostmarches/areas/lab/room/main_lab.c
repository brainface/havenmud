#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  ::create();
  SetShort("Teras' main laboratory");
  SetLong("A disorderly jumble of chemicals, herbs, and other sundry "
          "items clutters the heart of Teras' lab. Shelves on the east "
          "and west walls of the room house a melange of equipment and "
          "a number of seemingly scientific texts. Spilled reagents "
          "seem to have discoloured the wooden floorboards and the "
          "the two long wooden benches which span the length of the "
          "room.  The laboratory continues to the south.");
  SetSmell( ([
    "default" : "The chemicals exude a very pungent odor."
  ]) );
  SetListen( ([
    "default" :
      "Every little step can be heard in the otherwise dead silence of "
      "the room."
  ]) );
  SetClimate("indoors");
  SetItems( ([
    ({"disorderly jumble","jumble","sundry items","various items",
      "items","item","spilled chemicals","spilled chemical","chemicals",
      "chemical","spilled reagents","spilled reagent","reagents",
      "reagent","herbs","herb","clutter"}) :
      "Various items that Teras uses in her experiments lie scattered "
      "across the floor and on the benches.",
    ({"heart of teras' laboratory","heart of teras' lab",
      "teras' main laboratory","teras' main lab","main laboratory",
      "main lab","teras' laboratory","teras' lab","laboratory","lab",
      "heart","room"}) :
      (: GetLong() :),
    ({"east and west walls","east wall","west wall","shelves","walls",
      "wall"}) :
      "A medley of various utensils and books lie on the shelves that "
      "have been carved into the east and west walls.",
    ({"melange of equipment","melange","medley","equipment",
      "various utensils","utensils","utensil","oddly-shaped tools",
      "oddly-shaped tool","tools","tool"}) :
      "This equipment is a rarity; no discernable purpose can be "
      "attached to these oddly-shaped tools.",
    ({"scientific texts","texts","text","books","book","diagrams",
      "diagram"}) :
      "The shelved books are written in a foreign tongue.  From the "
      "diagrams, it seems they elaborate upon some scientific procedure.",
    ({"discoloured wooden floorboards","discoloured wooden floorboards",
      "discoloured floorboards","discoloured floorboard",
      "wooden floorboards","wooden floorboard","floorboards",
      "floorboard", "floor","handsome veneer","veneer","radiance"}) :
      "The floorboards may at one time have been made gilded with a "
      "handsome veneer, but spilled chemicals have long since destroyed "
      "any touch of radiance that could have emanated from these "
      "now discoloured floorboards.",
    ({"two long wooden benches","long wooden benches","long wooden bench",
      "long benches","long bench","wooden benches","wooden bench","benches",
      "bench","length of the room","length of room","length",
      "spartan benches","spartan bench","sturdy benches","sturdy bench",
      "spartan sturdy benches","spartan sturdy bench","center of the room",
      "center"}) :
      "The benches that lie in the center of the room have no claim to "
      "beauty.  These benches are spartan, sturdy benches and, though "
      "subjected to abuse and mistreatment, have not lost their function.",
    ({"south"}) :
      "The laboratory continues to the south.",
  ]) );
  SetAmbientLight(40);
  SetExits( ([
    "south" : L_ROOM "/south_lab",
  ]) );
  SetInventory( ([
    L_NPC "/teras" : 1,
    L_OBJ "/shard" : 1,
  ]) );
}
