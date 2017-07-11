//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("in front of a shabby building");
  SetLong(
    "Here before the road stands a very shabby building pieced "
    "together from scraps of old rotting wood, deeply scratched "
    "in places by the claws of those who nailed it together. "
    "There appears to be a sign before the establishment, with "
    "scrawled, barely legible words worn by the elements carved "
    "onto it. "
    );
  SetSmell("The entire village smells of offal. ");
  SetListen("The village is unreasonably loud.");
  SetItems( ([
    ({ "road", "highway", "area", "path" }) :
       (: GetLong :),
    ({ "shop", "riesin's", "building" }) :
    "The building is small, though extremely tall for some reason.",
    "sign" : "One could try to read it.",
    ({ "scraps", "wood" }) : "The wood is old and almost ruined.",
    ]) );
  SetItemAdjectives( ([
    "building" : ({ "shabby" }),
    "wood" : ({ "old", "rotting", "scratched" })
    ]) );
  SetInventory( ([
    U_OBJ "shopsign" : 1,
  ]) );
  SetEnters( ([
   "shop" : U_ROOM + "shop",
    ]) );
  SetExits( ([
    "north" : U_ROOM + "road06",
    "west" : U_ROOM + "road10",
    "south" : U_ROOM + "road08",
    ]) );
  }
