// Karak Rewrite
// Laoise
// 2007

#include "../karak.h"
#include <lib.h>
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("Karak armoury too");
  SetInventory( ([
    KARAK_OBJ + "leatherpants" : 1,     
    KARAK_OBJ + "leathervest" : 1,     
    KARAK_OBJ + "leatherglove" : 2,     
    KARAK_OBJ + "leatherboots" : 1,     
    KARAK_OBJ + "leatherhelmet" : 1,
    KARAK_OBJ + "clothpants" : 1,     
    KARAK_OBJ + "clothshirt" : 1,     
    KARAK_OBJ + "clothrobe" : 1,
    KARAK_OBJ + "clothglove" : 2,     
    KARAK_OBJ + "clothsock" : 2,     
    KARAK_OBJ + "clothhelmet" : 1, 
    KARAK_OBJ + "clothbelt" : 1,  	
  ]) );
}
