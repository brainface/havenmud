/*  The unicorns horn.
 *  Duuktsaryth@Haven
 *  Fixed by Amelia@Haven
 *  Modified by Gaby@Haven
 *  for Rook
 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("horn");
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetShort("%^WHITE%^BOLD%^a dragon's horn%^RESET%^");
  SetId( ({ "horn" }) );
  SetAdjectives( ({ "dragon", "dragon's" }) );
  SetLong("This is a long curved horn from the great dragon Rook.  "
    "It is silver in color and smoothed by age.");
  SetProperty("magic", "Use this horn to heal people.");
  SetValue(12500);
  SetMass(300);
  SetClass(12);
  SetVendorType(VT_MAGIC);
  SetMaterial( ({ "natural" }) );
  SetUnique(1);
  }
 
mixed eventUse(object me, string args) {
   string who, what;
   object victim;
   if(!args) {
      message("dragon","Use the horn to do what to whom?",me);
      return 1;
   }
   sscanf(args, "%s %s", what, who);
   if(!what || !(what == "heal")) {
      message("dragon","Use the horn to do what?",me);
      return 1;
   }
   if(!who) {
      message("dragon","Use the horn to do what to whom?",me);
      return 1;
   }
   if(!(victim = present(who, environment(me)))) {
      message("dragon","Use the horn on whom?",me);
      return 1;
   }
   send_messages("use","$agent_name $agent_verb a dragon's horn "
                 "to heal $target_name.",me, victim, environment(me));
   victim->eventCompleteHeal(2000);
   send_messages("dissolve","$agent_name $agent_verb.",this_object(),0,
                 environment(this_object()) );
   eventDestruct();
   return 1;
}
