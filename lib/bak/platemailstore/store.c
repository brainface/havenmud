#include <lib.h>
#include <domains.h>
#include "store.h"
inherit LIB_ROOM;

static void create() {
  ::create();

  SetInventory( ([
     STORE_DIR "steelbreastplate" : 2,     
     STORE_DIR "steelhelm" : 2,     
     STORE_DIR "steelgauntlet" : 4,     
     STORE_DIR "steelboots" : 2,     
     STORE_DIR "steelcuisse" : 2,     
     STORE_DIR "hsteelbreastplate" : 2,     
     STORE_DIR "hsteelhelm" : 2,     
     STORE_DIR "hsteelgauntlet" : 4,     
     STORE_DIR "hsteelboots" : 2,     
     STORE_DIR "hsteelcuisse" : 2,    
     STORE_DIR "chainvest" : 2,     
     STORE_DIR "chainhelm" : 2,     
     STORE_DIR "chaingauntlet" : 4,     
     STORE_DIR "chainboots" : 2,     
     STORE_DIR "chaincuisse" : 2,        
  ]) );
}
