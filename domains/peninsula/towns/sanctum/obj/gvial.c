#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

string BlahRead();

static void create() {
   ::create();
   SetKeyName("glowing vial");
   SetShort("a glowing vial");
   SetId( ({ "vial" }) );
   SetAdjectives( ({ "glowing" }) );
   SetLong("This black vial contains only the residue of some pale "
     "liquid. A label is stuck to the outside of it. The glass has a "
     "design carved into it, shaped as a skull."
   );
   SetMass(5);
   SetValue(2500);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetRead( (: BlahRead :) );
   SetDamagePoints(50);
}

mixed eventUse(object me, string args) {
   string who, what;
   int dmg;
   object victim;

   if(me->GetClass() != "rogue" && me->GetClass() != "assassin") {
      message("vial","The vial explodes!",me);
      me->eventReceiveDamage(this_object(), POISON, 500, 0,
                                  this_player()->GetWieldingLimbs() );
      eventDestruct();
      return 0;
   }
   if(!args) {
      message("vial","Use the vial to do what?",me);
      return 1;
   }
   sscanf(args, "%s %s", what, who);
   if(!what || !(what == "coat")) {
      message("vial","Use the vial to do what?",me);
      return 1;
   }
   if(!who) {
      message("vial","Use the vial to do what to what?",me);
      return 1;
   }
   if(!(victim = present(who, environment()))) {
      message("vial","Use the vial on what?",me);
      return 1;
   }
   if (victim->GetProperty("glowing_vial")){
        message("vial", "That weapon has already been coated!", who);
        return 0;
    }
    if (!(victim->GetVendorType() & VT_WEAPON)){
        message("vial", "You cannot use that on something that isn't a weapon!", who);
        return 0;
    }
   dmg = victim->GetDamageType();
   victim->SetDamageType(WATER|dmg);
   send_messages("coat","$agent_name $agent_verb $target_name with the glowing vial. The liquid melts into the weapon causing it to glow.",
                 me, victim, environment(me));
   eventDestruct();
   return;
}

string BlahRead() {
   object who = this_player();
   if(who->GetSkillLevel("stealth") > 100) {
      who->eventPrint("The label on the vial reads:\n"
             "The liquid when used on a weapon will greatly enhance the weapons "
             "ability for damage. It is coated on weapons, proper use of the vial "
             "would be <use vial to coat weapon>.");
      return "";
   }
   who->eventPrint("You can't seem to understand what the label says.");
   return "";
}
