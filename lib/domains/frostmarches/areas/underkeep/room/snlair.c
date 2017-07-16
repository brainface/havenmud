
#include <lib.h>
#include "main.h"

inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("underground");
  SetAmbientLight(1);
  SetShort("in the lair of the serpents");
  SetLong("This is a pit which has been bored through the solid"
    " earth by the mother of all snakes. The walls have been"
    " abrazed over time by its passage. Bones and rotting clothing"
    " cover the floor of the lair in a tapestry of terror,"
    " giving mute testimony of the deadliness of its inhabitant.");
  SetItems( ([
    ({"lair","pit"}) : (:GetLong:),
    ({"wall","walls", "moisture","excretion"}) :
      "The walls are sticky to the touch, and are saturated by some "
      "kind of slimy excretion.",
    ("ceiling") :
      "The pit extends up beyond sight.",
    ({"bones","clothing","floor","bone"}) :
      "The debris of the creature's previous meals lie scattered over "
      "the floor.",
    "earth" : "The earthen walls are smooth and covered with moisture."
    ]) );
  SetItemAdjectives( ([
    "walls" : "sticky",
    "excretion" : "slimy",
    "earth" : "solid",
    ]) );
  SetSmell( ([
    "default" :
      "The fetid odour of decay fills the air.",
    ({"bones" , "clothing"}) :
      "The scent of rot and mildew is prevalent.",
    ]) );
  SetListen( ([
    "default" :
      "The hiss of a horde of snakes is here.",
    ]) );
  SetInventory( ([
    RNQ_NPC + "icklesnake" : 6,
    RNQ_OBJ + "rusty_sword" : 3,
    RNQ_NPC + "longsn" : 3,
    RNQ_OBJ + "obsidian_key" : 1,
    RNQ_NPC + "bigsnake" : 1,
    ]) );
  SetExits( ([
    "up" : RNQ_RM + "snakepit",
    ]) );
}
