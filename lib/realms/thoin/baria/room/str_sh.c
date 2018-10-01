#include <lib.h>
#include "../jungle.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
                  "/domains/baria/towns/baria/obj/club" : 4,
                  "/std/obj/light/torch" : 6,
                  BARIA_OBJ + "matchbox" : 5,
                  BARIA_OBJ + "longbow" : 4,
                   ]) );
  SetPurgeInterval(3);
 }
