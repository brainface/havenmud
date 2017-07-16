//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the Hypostyle Hall");
  SetLong(
    "This is the entrance to the temple of Lisht. Here, rows of elegant "
    "painted marble columns soar effortlessly to the ceiling, depicting "
    "victories and rituals of Selket, the Giver and Taker of life. The floor "
    "is a mosaic of brightly colored miniscule tiles laid in fantastical "
    "patterns and pastoral views of Lisht. Sunbeams filter in from the "
    "entrance as well as an opening in the roof above. Here stands a "
    "cool, clear pool, where one may wash dirt and cares away. Another "
    "doorway leads gracefully into a shrine to the south, and a door "
    "toward the west goes into a hospital area."
  );
  SetItems( ([
    ({ "temple", "church", "building" }) : (: GetLong :),
    ({ "wall", "walls" }) :
        "Even the walls are decorated, with paint and precious stones.",
    ({ "column", "columns" }) :
        "There must be nearly a hundred columns here, each painted "
        "beautifully by talented hands.",
    ({ "sunbeams", "opening", "light", "lights", "central opening" }) :
        "The natural light bathes the hall in a simple, yet astonishingly "
        "beautiful glow.",
    ({ "floor", "mosaic", "tiles" }) :
        "The floor is a whirl of designs and aesthetically laid out scenes "
        "of Lisht, Xandria, and Selket herself.",
    ({ "pool", "central pool", "water" }) : 
        "The pool is for rituals, bathing one's hands, or contemplation.",
    ({ "doorway" }) : 
        "The door to the south is edged in silver and brilliant nacre.",
  ]) );
  SetItemAdjectives( ([
    "hall" : ({ "hypostyle" }),
    "column" : ({ "painted", "soaring" }),
    "building" : ({ "graceful" }),
    "floor" : ({ "tiled" }),
    "light" : ({ "glowing" }),
  ]) );
  SetSmell( ([
    "default" : "The air smells sweet, but not overpoweringly so.",
  ]) );
  SetListen( ([
    "default" : "A well-hidden choir praises their deity with constant "
    "song, barely above a whisper.",
    ]) );
  SetInventory( ([
    LISHT_NPC "irenakhty" :1,
  ]) );
  SetExits( ([
  "out" : LISHT_ROOM "gnoll/tr3",
    "south" : "temple2",
    "west" : "hospital1",
    ]) );
}
