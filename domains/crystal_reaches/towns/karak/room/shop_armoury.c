// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(30);
  SetShort("the Karak Armoury");
  SetLong(
    "The plain wooden interior of the Karak armoury opens to a forge further "
    "inside, which is shared with the smithy to the south. Wooden racks and "
    "various bins line the walls of this building, seeming to hold armour in "
    "different stages of completion. An open area in the middle appears "
    "intended for customers to try on their armour and test its ease of "
    "motion. Doorways are cut in the north and south walls of the building, "
    "allowing access to the other sections of the marketplace. To the east "
    "lies more of the Armoury."
  );
  SetItems( ([
    ({ "building", "armoury" }) : (: GetLong :),
    ({ "interior", "wood", "walls" }) : "The Karak armoury is formed of "
    "simple and plain wood, which has nontheless been well-constructed and "
    "appears durable. The armoury entrance is to the west while openings to "
    "the north and south connect to the rest of the marketplace. To the east "
    "an opening leads to a large forge.",
    ({ "racks", "rack", "bins", "bin" }) : "Bins along the walls hold pieces "
    "of incomplete armour, while large wooden racks have more finished pieces "
    "hanging from them.",
    ({ "area", "open", "middle" }) : "This open space has been left in the "
    "center of the room and seems intended for customers to try their new "
    "armour out by moving around freely and testing the feel of their newest "
    "aquisition.",
    ({ "doorways", "door", "doors" }) : "Matched doorways are cut in to the "
    "north and south walls, connecting to the rest of the Karak marketplace.",
  ]) );
  SetItemAdjectives( ([
    "building" : ({ "karak" }),
    "interior" : ({ "plain", "wooden", "armoury", }),
    "forge" : ({ "large", "shared" }),
    "racks" : ({ "wooden", "various", "lining", "armour" }),
    "area" : ({ "open", "middle" }),
    "doorways" : ({ "north", "south" }),
  ]) );
  SetListen( ([
    "default" : "The clang of hammer on anvil echos from the east.",
  ]) );
  SetSmell( ([
    "default" : "There is a faint odor of leather and a stronger smell of "
    "smoke.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "shop_armour" : 1,
    KARAK_NPC + "shop_free" : 1,
  ]) ); 
  SetExits( ([
    "north" : KARAK_ROOM + "shop_general",
    "south" : KARAK_ROOM + "shop_smithy",
    "east"  : KARAK_ROOM + "shop_armoury2",
    "out"   : KARAK_ROOM + "rd4",
  ]) );
}
