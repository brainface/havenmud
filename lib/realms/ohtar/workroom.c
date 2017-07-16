/*  First update on Ohtars workroom.
 */
#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("a workroom");
  SetLong(
    "Here in the center of the room is a desk with several papers "
    "and writing utensils. In front of the desk is a leather chair "
    "with arms and a high back. Just under the right edge of the "
    "desk is a small refridgerator. In the back left corner is a small "
    "toilet that appears to have never been used. "
  );
  SetItems( ([
    ({ "toilet" }) : "A very clean toilet. The inside appears to have a "
                     "abnormally large hole in it. ",
    ({ "hole" }) : "An abnormally large hole. ",
  ]) );
  SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",
    "east" : STD_AREA "room/basic",
  ]) );
  SetEnters( ([ 
      "toilet" : "/realms/urien/workroom",
      "hole" : "/realms/urien/workroom",
   ]) );
}
