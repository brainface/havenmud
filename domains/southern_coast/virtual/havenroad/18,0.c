#include <lib.h>
#include <domains.h>
#include "/domains/southern_coast/areas/leatherstore/store.h"
inherit SOUTHERN_COAST_VIRTUAL "havenroad";

static void create(int x, int y) {
  ::create(18, 0);
  SetupRoom(18,0);
  SetExits( ([
    "west" : __DIR__ + "17,0",
    "east" : __DIR__ + "19,0",
    ]) );
  AddItem("store", "There is a store here with a sign displaying leather goods.");
  AddItemAdjectives("store", ({ "small", "leather" }) );
  SetEnters( ([ 
    "store" : STORE_DIR "leatherstore",
  ]) );
  SetLong(GetLong() + " There is a small store just south of the road here.");  
  SetSmell("A faint smell of meat comes from the leather merchant's store.");  
}