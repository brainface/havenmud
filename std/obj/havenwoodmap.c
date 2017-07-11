// havenwood map as an object
// mahkefel 2011

#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("map");
  SetShort("a map of the Havenwood");
  SetId(({ "map" }));
  SetAdjectives( ({ "map","havenwood","Havenwood" }) );
  SetLong(
    "This rolled up parchment shows much wear along its ragged edges, and ink "
    "smudges along the middle where many hands have held it. Green and blue "
    "lines marking the boundaries of the Havenwood run along the surface. "
    "Perhaps you could 'read' it?"
  );
  SetRead("default",
"            The Havenwood\n"
"       To\n"
"   Malveillant           B = Barracks\n"
"        ^                C = Council Area\n"
"  H     |   P-C          c = Cemetery\n"
"  a     |   |      To    G = General Store\n"
"  v     |   t-G-R  Parva P = Post Office\n"
"  e R   |    /| |  /     R = Revellers' Hall\n"
"T n o <-*---*-+-B-*      S = Eclat Shrine\n"
"o w a        \\| | |      T = Tannery\n"
"  o d         T-S To     t = Gnome's Treehouse\n"
"  o             | Beach\n"
"  d             c\n"
  );
}
