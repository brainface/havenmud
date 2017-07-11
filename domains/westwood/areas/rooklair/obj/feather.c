#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("feather");
  SetShort("a fiery feather");
  SetId( ({"feather"}) );
  SetAdjectives( ({"fiery"}) );
  SetLong("This appears to be a legendary phoenix feather.  The phoenix "
    "said to represent rebirth and their feathers are highly prized by "
    "most people of the world.  It is a fiery red in colour and the "
    "shades of red seem to dance about as you look the feather over.");
  SetProperty("magic", "Use this feather to resurrect.");
  SetValue(10000);
  SetMass(5);
  SetVendorType(VT_MAGIC);
  SetMaterial( ({ "natural" }) );
  SetUnique(1);
  }
 
mixed eventUse(object me, string args) {
   string who, what;
   object victim;
   if(!args) {
      message("feather","Use the feather to do what to whom?",me);
      return 1;
   }
   sscanf(args, "%s %s", what, who);
   if(!what || !(what == "resurrect")) {
      message("feather","Use the feather to do what?",me);
      return 1;
   }
   if(!who) {
      message("feather","Use the feather to do what to whom?",me);
      return 1;
   }
   if(!(victim = present(who, environment(me)))) {
      message("feather","Use the feather on whom?",me);
      return 1;
   }
   send_messages("use","$agent_name $agent_verb a feather to "
     "resurrect $target_name.",me, victim, environment(me));
   victim->SetUndead(0);
   send_messages("flame","$agent_name $agent_verb away into ash.",
     this_object(),0,environment(this_object()) );
   eventDestruct();
   return 1;
}
