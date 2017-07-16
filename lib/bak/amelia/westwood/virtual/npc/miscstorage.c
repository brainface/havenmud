#include <lib.h>
inherit LIB_STOREROOM;
#include "../westwood.h"
static void create() 
{
  storeroom::create();
  SetInventory( ([
  ]) );
  SetPurgeInterval(5);
}
