//Selket@Haven
//2006
#include <lib.h>
#include "../../lisht.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the scriptorium");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetExits( ([
      "east" : "lib2",
      "up" : "lib3",
      "out" : "sa1",
   ]) );
  SetLong(
    "This is an ancient room that leads into the Great Library of Lisht. "
    "Here, a group of student scribes meticulously copy old scrolls. The "
    "floor is littered with pieces of stylus and spilled drops of ink, "
    "but also with the results of failed spells. The scroll-lined walls "
    "are elegantly painted, perhaps by one of the educated souls here. "
    "Light shines in from tall, rose-stained windows, casting a pink "
    "glow on the entire scriptorium. A staircase leads up and there is "
    "an imposing archway just to the east.");
   SetNewsgroups( ({ "magic.ideas", "magic.announcements", "magic.general" })
);
  SetItems( ([
    ({ "group", "scribes", "scribe", "student" }) :
        "These men appear to be no ordinary scribes, but magic-users "
        "as well. They are hard at work.",
    ({ "necromancer", "necromancers", "evokers", "evoker" }) :
        "The specialized halls seem to be upstairs.",
    ({ "floor", "pieces", "ink", "stylus", "results" }) :
        "A stylus with a snapped tip, droplets of black and red ink, "
        "and what appear to be small piles of soot clutter the floor.",
    ({ "archway", "arch", "door" }) :
        "The doorway leads into a room to the east.",
    ({ "window", "windows", "glow", "light" }) :
        "The light source of this room comes from pink tinted windows "
        "and the occasional oil lamp.",
    ({ "staircase", "stairs" }) :
    "A sturdy-looking staircase leads to the specialized halls.",
    ({ "wall", "walls", "scrolls" }) :
        "The walls are painted colorfully with fantastical landscapes "
        "and poetry written in ancient, faded pictograms. There are "
        "also many scrolls here.",
  ]) );
  SetItemAdjectives( ([
    "window" : ({ "rose", "rose-colored" }),
    "scribe" : "student",
    "ink" : ({ "drop", "drops" }),
    "wall" : ({ "scroll-lined", "painted" }),
    "archway" : ({ "imposing" }),
  ]) );
  SetSmell( ([
    "default" : "It smells of paper and ink here.",
  ]) );
  SetListen( ([
    "default" : "Large blasts sound occasionally overhead, cutting "
    "through the monotony of scribbling.",
   ]) );
  SetInventory( ([
    LISHT_NPC + "thoth" : 1,
   ]) );
}
