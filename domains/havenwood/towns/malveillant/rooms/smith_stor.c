/*  Portia  10-24-98
   A storeroom for the smithy.
*/

#include <lib.h>
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
      "/std/weapon/knife/pocket_knife" : 3,
      "/std/weapon/knife/stiletto" : 2,
      "/std/weapon/blunt/copper_club" : 1,
      "/std/weapon/slash/sword" : 3,
      "/std/weapon/hack/hand-axe" : 3,
      "/std/weapon/projectile/bola" : 2,
        ]) );
  SetPurgeInterval(3);
  }
