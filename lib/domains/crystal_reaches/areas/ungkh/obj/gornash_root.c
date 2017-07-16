//--  used code from unicorn horn by duuk  --//
//-- recoded similiar to new horns by Gaby --//
//-- upped the weight to prevent people    --//
//-- from carrying 300+ of them            --//

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("root");
  SetShort("a piece of gornash root");
  SetId( ({ "root" }) );
  SetAdjectives( ({ "piece", "of", "gornash" }) );
  SetLong("Grown in the herb gardens of Ugnkh, this root is known to "
    "have certain healing powers.  It is a long, slender brown root "
    "with spikes protruding from it.  the surface is dry and soft.");
  SetProperty("magic", "This root can be used to heal people.");
  SetValue(30);
  SetMass((random(40)+60));
  SetVendorType(VT_HERB);  
}
 
mixed eventUse(object me, string args) {
  int type = random(100);
  string who, what;
  object victim;
  if(!args) {
    message("root","Use the root to do what to whom?",me);
    return 1;
  }
  sscanf(args, "%s %s", what, who);
  if(!what || !(what == "heal")) {
    message("root","Use the root to do what?",me);
    return 1;
  }
  if(!who) {
    message("root","Use the root to do what to whom?",me);
    return 1;
  }
  if(!(victim = present(who, environment(me)))) {
    message("root","Use the root on whom?",me);
    return 1;
   }
   if (type >= 0 && type <=32) {
     victim->AddHitPoints(250 + random(250));
   }
   else if(type >= 33 && type <=65) {
     victim->AddStaminaPoints(250 + random(250));
   }
   else if(type >= 66 && type <=98) {
     victim->AddMagicPoints(250 + random(250));
   }
   else if(type == 99) {
     victim->eventCompleteHeal(250 + random(250));
   }
   send_messages("use","$agent_name $agent_verb a piece of gornash root "
                 "to heal $target_name.",me, victim, environment(me));
   send_messages("crumble","$agent_name $agent_verb.",this_object(),0,
                 environment(this_object()) );
   eventDestruct();
   return 1;
}
