#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("first aid kit");
   SetShort("a first aid kit");
   SetId( ({ "kit","box" }) );
   SetAdjectives( ({ "first","aid","small","white" }) );
   SetLong("The kit is a small white box with a symbol of healing "
           "scratched into the cover.  It is not very large, but "
           "it could probably help heal someone.");
   SetMass(20);
   SetValue(300);
   SetVendorType(VT_TREASURE|VT_MAGIC);
   SetDamagePoints(1);
   SetMaterial( ({ "natural" }) );
   SetProperty("magic","The kit has been magical given a healing "
               "property by the Gods.");
   SetProperty("history","In the past, the kit was blessed by the Gods.");
}

mixed eventUse(object me, string args) {
   string who, what;
   object victim;
   if(!args) { return "Use the kit to do what to whom?"; }
   sscanf(args, "%s %s", what, who);
   if(!what) { return "Use the kit to do what?"; }
   if(!who) { return "Use the kit to do what to whom?"; }
   if (!(what == "heal")) { return "Use the kit to do what?"; }
   if(!(victim = present(who, environment(me)))) {
      return "Use the kit on whom?"; }
   send_messages("use",
      "$agent_name $agent_verb a first aid kit to help heal $target_name.",
      me, victim, environment(me) );
   victim->eventCompleteHeal(50+random(20));
   eventDestruct();
   return 1;
}
