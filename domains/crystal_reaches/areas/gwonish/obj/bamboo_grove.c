// torak 10/27/12
#include <lib.h>
#include "../path.h"

inherit LIB_STORAGE;

static void create() {

  ::create();
  SetOpacity(0);
  SetShort("a bamboo grove");
  SetLong("Many individual stalks of bamboo shoot up out "
    "of the ground forming this grove. The yellow stalks grow "
    "straight and tall, seperated by thin grey rings "
    "between columnar sections.");
  SetId( ({
    "bamboo", "grove"
    }) );
  SetAdjectives( ({
    "bamboo"
    }) );
  SetKeyName("grove");
  SetPreventGet("You can not pick up the entire grove!");
  SetMaxCarry(300);
  SetInventory( ([ 
    GWONISH + "obj/bamboo_shaft" : random(3) +3,
  ]) );
  }

int inventory_visible() {
  return 1;
  }

string GetExternalDesc() {
  string desc;
  desc = ::GetExternalDesc();
  desc += ::GetInternalDesc();
  return desc;
  }
