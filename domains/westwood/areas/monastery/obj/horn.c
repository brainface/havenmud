/*  The unicorns horn.
 *  Duuktsaryth@Haven
 *  Fixed by Amelia@Haven
 *  Fucked by Gaby@Haven
 *  Fixed, again, by Amelia@Haven
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
  SetShort("a unicorn's horn");
  SetId( ({ "horn" }) );
  SetAdjectives( ({ "unicorn", "unicorn's" }) );
  SetLong("This is a horn from a unicorn. It is approximately 8 inches in "
          "length, with a sharp pointed end.  It has a faint glimmer to it.");
  SetProperty("magic", "Use this horn to heal people.");
  SetValue(1200);
  SetMass(30);
  SetClass(8);
  SetVendorType(VT_MAGIC);
  SetMaterial( ({ "natural" }) );
  SetUnique(1);
  }
 
mixed eventUse(object me, string args) {
   string who, what;
   object victim;
   
   if(!args) {
      message("unicorn","Use the horn to do what to whom?",me);
      return 1;
   }
   sscanf(args, "%s %s", what, who);
   if(!what || !(what == "heal")) {
      message("unicorn","Use the horn to do what?",me);
      return 1;
   }
   if(!who) {
      message("unicorn","Use the horn to do what to whom?",me);
      return 1;
   }
   if(!(victim = present(who, environment(me)))) {
      message("unicorn","Use the horn on whom?",me);
      return 1;
   }
   victim->eventCompleteHeal(500);
   send_messages("use","$agent_name $agent_verb a unicorn's horn "
     "to heal $target_name.",me, victim, environment(me));
   send_messages("dissolve","$agent_name $agent_verb.",this_object(),0,
     environment(this_object()) );
   eventDestruct();
   return 1;
}
