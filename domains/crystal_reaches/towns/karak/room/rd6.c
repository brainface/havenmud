// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Karak Road");
  SetLong(
    "A pair of small buildings stand to the east while a larger single "
    "building stands to the west. The eastern buildings are plain, simple "
    "wooden buildings, one seems to be the building of the local moneylender "
    "and the other appears to be Karak's pub. The larger building to the "
    "west is more elaborate, constructed of a darker wood which has been "
    "stained to an almost black color. Above its entrance are a pair of "
    "twisted demon horns, suggesting that it is a church."
  );
  SetItems( ([
    ({ "pair", "buildings" }) : "To the east are a pair of buildings which "
    "appear to be the local pub and moneylender, while that to the west "
    "is a large church.",
    ({ "bank", "moneylender" }) : "This is one of a pair of "
    "smaller buildings to the east. It appears to be Karak's bank and is "
    "a very plain structure made of wood. While lacking in frills, it appears "
    "sturdy and ready for decades of hard use.",
    ({ "pub" }) : "This small building on the eastern side of the "
    "road appears to the local pub, where both food and drink are avaliable. "
    "It is a durable building fashioned from local wood. Its only decorative "
    "touch is a stamped outline of a beer stein above the door.",
    ({ "stein", "outline", "stamp" }) : "The stamped outline of a beer mug "
    "decorates the entrance to the local pub.",
    ({ "church" }) : "Constructed of a different wood than the rest "
    "of Karak, the exterior of the church is an almost black color. Mounted "
    "above its entrance are a pair of demon horns.",
    ({ "horns", "horn", "entrance" }) : "These are a pair of horns from a "
    "larger denizen of the lower plains. They are black and twisted and cure "
    "outwards over the entrance to the SaahaGoth church.",
  ]) );
  SetItemAdjectives( ([
    "pair" : ({ "east", "of", "buildings", "small", "smaller" }),
    "bank" : ({ "east", "eastern", "paired", "small", "plain", "simple" }),
    "pub" : ({ "east", "eastern", "paired", "small", "plain", "simple" }),
    "church" : ({ "large", "larger", "west", "dark", "black", "wood" }),
    "horns" : ({ "paired", "demon", "twisted", "large", "displayed", "church", 
    "pair", "of", "entrance", "saahagoth" }),
  ]) );
  SetSmell( ([
    "default" : "The smell of food and drink wafts in from the pub.",
  ]) );
  SetListen( ([
    "default" : "From the south comes the rumble and crash of the ocean.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "citizen2" : 2,
  ]) );
  SetExits( ([
    "north" : KARAK_ROOM + "rd5",
    "south" : KARAK_ROOM + "rd7",
  ]) );
  SetEnters( ([
    "bank"   : KARAK_ROOM + "bank",
    "pub"    : KARAK_ROOM + "pub",
    "church" : KARAK_ROOM + "church",
  ]) );
}
