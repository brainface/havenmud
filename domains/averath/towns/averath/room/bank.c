// Aerelus
#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("in the Bank of Averath");
  SetLong(
    "This official building is the First Bank of Averath. While the citizens "
    "of Averath are generally less well off than those of other towns, they "
    "still value the protection the bank offers their finances. A small "
    "wooden counter serves as a place for conducting business, with a little "
    "green plant on top that looks like it hasn't been given water in quite "
    "some time."
  );
  SetItems( ([
    ({ "building", "bank" }) : (: GetLong :),
    ({ "counter" }) : "The counter serves as a place for the owner and any "
    	"customers to conduct business. On top, there is a little green plant.",
    ({ "plant" }) : "This poor plant obviously isn't very well cared for.",    
  ]) );
  SetItemAdjectives( ([
    "building" : ({ "official", }),
    "counter" : ({ "small", "wooden" }),
    "plant" : ({ "little", "green" }),
  ]) );
  SetInventory( ([
    AVERATH_NPC "teller" : 1,   
  ]) );
  SetListen( ([
     "default" : "The sounds of city life drift in from outside.",
  ]) );
  SetSmell( ([
     "default" : "The bank smells similar to money that has been passed "
       "around many hands.",
  ]) );  
  SetExits( ([    
    "out" : AVERATH_ROOM "road5",    
  ]) );    
}