#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_STORAGE;
int eventDestroyCase(object);

static void create()
{
::create();
SetKeyName("scroll case");
SetId( ({ "scroll case","tube","case" }) );
SetAdjectives( ({ "scroll","tubular" }) );
SetShort("%^WHITE%^an ivory scroll case%^RESET%^");
SetLong("This is an ivory scroll case.  It is engraved with symbols "
  "of dragons coiled about it and end caps that are made of the "
  "purest mithril.");
SetMass(20);
SetValue(1500);
SetCanClose(1);
SetClosed(1);
SetMaxCarry(1);
SetMaterial( ({ "natural","mithril" }) );
SetRepairSkills( ([ "natural working" : 1 ]) );
SetRepairDifficulty(2);
SetVendorType(VT_TREASURE);
}


varargs mixed eventOpen(object who, string id, object tool) {
  object box = this_object();
  switch(random(100)) {  
    case 1..25 :
       AddInventory(R_OBJ + "scroll", 1);
      break;
    case 26..50 :
      break;
    default:
      break;
  }

  call_out( (: eventDestroyCase, who, box :), 5);

  ::eventOpen(who, id, tool);
}


int eventDestroyCase(object who, object box) {

  send_messages( ({ "open" }),
    "The case crumbles in "
    "$agent_possessive hands.", who, 0, environment(who) );
  box->eventDestruct();
  
        return 1;
}
