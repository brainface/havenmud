#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
inherit LIB_TOUCH;

static void create() {
   armour::create();
   SetSize(SIZE_SMALL);
   SetKeyName("polka-dot pajamas");
   SetShort("a set of polka-dot pajamas");
   SetId( ({ "set","pajama","pajamas","pj","pjs" }) );
   SetAdjectives( ({ "set of","polka","dot","polka-dot","soft",
                     "fuzzy","white" }) );
   SetLong("The pajamas are white with multi-color polka-dots all "
           "over them.  They are soft and very fuzzy.");
   SetTouch("The pajamas are fuzzy to the touch, and seem like "
            "they'd be soft enough to wrap around a baby or some "
            "wounds.");
   SetMass(40);
   SetValue(100);
   SetVendorType(VT_ARMOUR|VT_TREASURE);
   SetArmourType(A_BODY_ARMOUR);
   SetDamagePoints(250);
   SetProtection(BLUNT,1);
   SetProtection(SLASH,1);
   SetProtection(PIERCE,1);
   SetProtection(HEAT,1);
   SetProtection(COLD,10);
   SetWear("The pajamas feel really nice as they go on.");
   SetMaterial( ({ "textile" }) );
  SetWarmth(25);
   SetRepairDifficulty(18);
   SetRepairSkills( ([
                       "textile working" : 1,
                       "armour smithing" : 1,
                  ]) );
}

mixed eventUse(object me, string args) {
   string who, what;
   object victim;
   if(!args) { return "Use the pajamas to do what to whom?"; }
   sscanf(args, "%s %s", what, who);
   if(!what) { return "Use the pajamas to do what?"; }
   if(!who) { return "Use the pajamas to do what to whom?"; }
   if (!(what == "heal")) { return "Use the pajamas to do what?"; }
   if(!(victim = present(who, environment(me)))) {
      return "Use the pajamas on whom?"; }
   send_messages("use",
      "$agent_name $agent_verb a set of pajamas to help heal $target_name.",
      me, victim, environment(me) );
   victim->eventCompleteHeal(30);
   eventDestruct();
   return 1;
}
