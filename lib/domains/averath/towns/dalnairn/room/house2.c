// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in an abandoned home");
  SetLong(
    "This disused house is empty and obviously forgotten. Someday, should the "
    "city government choose, it will be for sale to the citizens of the city. "
    "For now though, it sits idle and forlorn."
  );    
  SetExits( ([
    "out" : DAL_ROOM "road9",
  ]) );  
}
