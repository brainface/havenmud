#include <lib.h>
#include "/realms/torak/torak.h"

inherit LIB_STORAGE;
inherit LIB_ENTER;

static void create() {

  ::create();
  SetOpacity(0);
  SetShort("a bamboo grove");
  SetLong("Many individual stalks of bamboo shoot up out "
    "of the ground forming this grove. The yellow stalks grow "
    "straight and tall, seperated by thin grey rings "
    "between sections.");
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
    TORAK_OBJ + "bamboo_shaft" : random(3) +3,
  ]) );
    room->AddEnter("grove", "/domains/crystal_reaches/towns/gwonish/enclosement");
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
