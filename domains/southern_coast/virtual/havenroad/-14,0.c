#include <lib.h>
#include <domains.h>
#include "/domains/southern_coast/areas/platemailstore/store.h"
inherit SOUTHERN_COAST_VIRTUAL "havenroad";

static void create(int x, int y) {
  ::create(-14, 0);
  SetupRoom(-14,0);
  SetExits( ([
    "west" : __DIR__ + "-15,0",
    "east" : __DIR__ + "-13,0",
    ]) );
  AddItem("store", "There is a store here with a sign displaying metal armour.");
  AddItemAdjectives("store", ({ "small", "armour", "metal" }) );
  SetEnters( ([ 
    "store" : STORE_DIR "kelansstore",
  ]) );
  SetLong(GetLong() + " There is a small store just north of the road here.");  
  SetSmell("A strong smell of burning charcoal comes from the armour store.");   
}