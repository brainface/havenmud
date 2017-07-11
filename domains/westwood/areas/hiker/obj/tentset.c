#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
#include "../hiker.h"

static void create() {
   item::create();
   SetKeyName("tent set");
   SetShort("a tent set");
   SetId( ({ "tent","set","tent set" }) );
   SetAdjectives( ({ "man","two","two-man" }) );
   SetLong("The tent set is all ready to be used for building a "
           "cozy two-man tent.  The material is a gray-brown "
           "color, and it seems durable.");
   SetMass(500);
   SetValue(5500);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(450);
   SetMaterial( ({ "textile" }) );
}

mixed eventUse(object me, string args) {
   string what;
   object blah;
   object hrmph;
   if(!args) { 
      send_messages("","Use the tent set to do what",this_object(),
                    0,me);
      return 1;
   }
   sscanf(args, "%s", what);
   if(!what) { 
      send_messages("","Use the tent set to do what?",this_object(),0,
                    me);
      return 1;

   }
   if (!(what == "build tent")) { 
      send_messages("","Use the tent set to do what?",this_object(),0,
                    me);
      return 1;
   }
   if(environment(me)->GetClimate()=="indoors") {
      send_messages("","You can't build a tent inside!",this_object(),0,
                    me);
      return 1;
   }
   if(!(environment(me)->GetTown()=="Wilderness")) {
      send_messages("","You can't build a tent in a town!",this_object(),0,
                    me);
      return 1;
   }
   if(environment(me)->GetProperty("hiker_tent_here") == 1) {
      send_messages("","There are already too many tents in this area.",
                    this_object(),0,me);
      return 1;
   }
   send_messages("use",
      "$agent_name $agent_verb a tent set to build a tent.",
      me, 0, environment(me));
   environment(me)->SetProperty("hiker_tent_here",1);

   blah = new(H_OBJ + "tentmade");
   blah->eventMove(environment(me));
   hrmph = new(H_OBJ + "lantern");
   hrmph->eventMove(blah);
   eventDestruct();
   return 1;
}
