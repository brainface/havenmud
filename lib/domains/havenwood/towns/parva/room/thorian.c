// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include "../parva.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("a Thorian Shrine");
  SetLong("This relatively small Shrine makes up the Thorian influence into "
          "Parva. Though it is relatively simple in decor only containing "
          "a small altar and a couple icons of the Decayed One. The walls "
          "are covered in small little holes and the floor is covered in pieces "
          "of rotted flesh and pools of blood."
          );
  SetItems( ([
    ({ "shrine" }) : (: GetLong :),
    ({ "altar" }) : "The small altar is made from black marble and appears "
                    "to have a small bowl cut out from the top of the marble "
                    "to serve as a collection platter for drippings. On both "
                    "sides of the small bowl rests candles that have nearly burned "
                    "down to nothing.",
    ({ "bowl" }) : "The small bowl is filled with blood and what appears to be "
                   "a hand as well as various other unidentifiable parts.",
    ({ "candle", "candles" }) : "These black candles have been burned almost "
                   "down to nothing, yet continue to burn brightly.",
    ({ "icon", "icons", "decayed one" }) : "The two icons hang just slightly above "
                   "the altar. The first icon depicts a shrouded figure stretching "
                   "out their arm only to expose a skeletal hand. The second icon "
                   "shows a corpse being consumed by rot and decay.",
    ({ "wall", "walls", "hole", "holes" }) : "The walls are covered in small little holes. "
                   "The holes themselves are very small and look to be filled with "
                   "different pieces of rotting body parts from fingers to hearts.",
    ({ "floor", }) : "The floor is covered in both dried and fresh blood as well as "
                   "odd pieces of rotting flesh.",
    ({ "blood", "flesh" }) : "The blood and flesh litter the floor and appear to range "
                   "from months old to just a couple of hours. Some of the pieces of flesh "
                   "are rotting and are obviously disease ridden.",
    ]) );
  SetItemAdjectives( ([
    "shrine" : ({ "small" }),
    "altar" : ({ "small" }),
    "bowl" : ({ "small" }),
    "candle" : ({ "black" }),
    "hole" : ({ "small", "little" }),
    "blood" : ({ "fresh", "dried", "rotting" }),
    ]) );
  SetReligion("Thorian");
  SetListen( ([
    "default" : "Hushed whispers and moans echo within the shrine walls.",
    ]) );
  SetSmell( ([
    "default" : "The smell of rotting flesh and blood permeates through the "
                "shrine.",
    ]) );
  SetInventory( ([
    PARVA_NPC "thorian_cleric" : 1,
    ]) );
  SetExits( ([
    "out" : PARVA_ROOM "cemetery",
    ]) );
}
