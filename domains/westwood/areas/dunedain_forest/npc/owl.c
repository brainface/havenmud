#include <lib.h>
#include "../forest.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("owl");  
  SetId( ({ "great horned owl","horned owl","great owl","owl" }) );
  SetShort("a great horned owl");
  SetLong("The owl has a foreboding appearance.  It's kind has been known "
          "to inhabit areas where evil dwells. ");
  SetRace("bird");  
  SetClass("animal");
  SetGender("female");
  SetLevel(5);
  SetInventory( ([
    			]) );
  SetCorpseItems( ([
  	 			F_OBJ "beak" : 1
         	]) );
         
}
