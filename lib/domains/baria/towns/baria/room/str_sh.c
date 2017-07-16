#include <lib.h>
#include "../jungle.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
                  "/domains/baria/towns/baria/obj/club" : 4,
                  "/std/obj/light/torch" : 6,
                  BARIA_OBJ + "longbow" : 4,
                  "/std/weapon/blunt/femur" : 2,
                   ]) );
  SetPurgeInterval(3);
 }

