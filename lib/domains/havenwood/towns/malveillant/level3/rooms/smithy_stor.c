//  Portia  10-24-98
//  A storeroom for the smithy.
//  Updated by Alessandra 2009

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();

  SetInventory( ([
     STD_KNIFE + "pocket_knife" : 3,
     STD_PIERCE + "epee" : 2,
     STD_KNIFE + "stiletto" : 2,
     STD_BLUNT + "copper_club" : 1,
     STD_SLASH + "sword" : 3,
     STD_HACK + "hand-axe" : 3,
     STD_PROJECTILE + "bola" : 2,
     ]) );
  SetPurgeInterval(3);
 
}
