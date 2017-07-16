//Illura@haven
//Sept 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("in the city of endless night");
  SetLong(
    "Clouds, limitless clouds, extend over the sky here. The "
    "grass of this meadow rustles underfoot, held eternally in "
    "stasis by a sustaining magic that keeps it both from thriving "
    "or succumbing under the lightless skies. Stretching in every "
    "direction from this place are only broken iron buildings, "
    "a sullen tomb surrounded by the mist of decay and "
    "abandoned by all but apparitions and fireflies."
  );
  SetInventory( ([
  ]) );
  SetListen( ([
    "default" : "The wind keens sorrowfully, full of ancient regret.",
  ]) );
  SetSmell( ([
    "default" : "The air is tangy with rust and sweet, cloying decay.",
  ]) );
}
