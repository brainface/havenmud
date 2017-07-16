#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetNoClean(1);

  SetInventory( ([

  "/std/weapon/blunt/war-hammer" : 2,
  "/std/weapon/blunt/mace" : 2,
  "/std/weapon/hack/battle_axe" : 2,
  "/std/weapon/hack/stone_axe" : 2,
    ]) );

}
