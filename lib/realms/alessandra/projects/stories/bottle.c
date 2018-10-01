#include <lib.h>
#include <std.h>
#include <vendor_types.h>
inherit LIB_STORAGE;

mixed CanPutInto(object who, object item);
static void create() {
  ::create();
  SetKeyName("bottle");
  SetId( ({ "bottle","glass" }) );
  SetAdjectives( ({ "glass", "dirty" }) );
  SetShort("a dirty glass bottle");
  SetLong("This is a dirty, glass bottle. It has a few chips and cracks around the"
          " rim, but otherwise looks fairly intact.");
  SetMass(50);
  SetValue(50);
  SetClosed(0);
  SetCanClose(0);
  SetDamagePoints(5);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(20);
  SetMaxCarry(250);
  SetInventory( ([
        STD_READ "note" : 1,
  ]) );
/* In case we wanted to get fancy at some point
   Random inventory generation....  */
/*
  switch(random(2)) {
        case 0:
        SetInventory( ([
                "random_Stuff" : 1,
        ]) );
        break;
        case 1:
        SetInventory( ([
                "random_Stuff" : 1,
        ]) );
        break;
   } 
*/ 
}
  
mixed CanPutInto(object who, object what) {
    object env;
    
    if( what == this_object() ) {
        return "#You cannot change the laws of physics.";
    }
    if( (what->GetKeyName() != "note") && (what->GetKeyName() != "paper") &&
         (what->GetKeyName() != "key")  ) {
                  return capitalize(what->GetShort()) + " cannot be put into "
                  + GetShort() + ".";
                } 
    env = environment();
    if( env != this_player() && env != environment(this_player()) ) {
        return "It is not within reach.";
    }
//    return ::eventReceiveObject();
        return 1;
}

// append internal desc to external desc
//  (so display case is "transparent")
string GetExternalDesc() {
  string desc;
  desc = ::GetExternalDesc();
  desc += ::GetInternalDesc();
  return desc;
}
