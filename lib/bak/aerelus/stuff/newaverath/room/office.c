// Aerelus
#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetTown("Averath");
  SetShort("in the Averath Post Office");
  SetLong(
    "This dull building is the Averath post office, where citizens come to "
    "both receive and send mail by typing <mail>. Once in, simply follow the "
    "instructions."
  );
  SetItems( ([
    ({ "building", "office" }) : (: GetLong :),    
  ]) );
  SetItemAdjectives( ([
    "building" : ({ "dull", }),    
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
     "default" : "Conversation and other sounds of city life come from "
     	"outside.",
  ]) );
  SetSmell( ([
     "default" : "The post office smells of paper and ink.",
  ]) );  
  SetExits( ([    
    "out" : AVERATH_ROOM "road5",    
  ]) );    
}