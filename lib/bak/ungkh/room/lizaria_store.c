#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetNoClean(1);

  SetInventory( ([
    "/std/armour/shirt/" + "breastplate" : 2,
    "/std/armour/helmet/" + "l_helm_open" : 3,
    ]) );

}
