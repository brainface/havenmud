#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetShort("a storage room");
  SetLong("GET THE FRACK OUGHTA HERE!");
  SetInventory( ([
    LLORYK "obj/smoke/cigar" : 5,
    LLORYK "obj/smoke/chaileaf" : 5,
    LLORYK "obj/smoke/lpipe" : 5,
    LLORYK "obj/smoke/vodka" : 5,
  ]) );
 }
