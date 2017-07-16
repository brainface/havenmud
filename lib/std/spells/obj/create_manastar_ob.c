/* ----------------------------------------------------------------------- */
// Area Title: None
// Filename: manastar.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Jan 23rd, 1999
// Abstract: The Magildan Manastar :)
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

mixed eventUse(object me, string args);

static void create() {
  item::create();
  SetKeyName("manastar");
  SetAdjectives("manastar");
  SetShort("a manastar");
  SetLong("The manastar is the symbol of the Magildan belief and "
           "is said to have wonderous powers. It is forged from pure "
           "rupie and is an eight pointed star created by two "
           "overlapping squares.");
  SetProperty("history", "The manastar is one of the ultimate gifts of "
         "Dylanthalus and thus only he and his mystics can create them.",);
  SetProperty("magic", "The manastar can be used to heal someone's "
         "magical state of being bringing them more magic and relieving "
         "them of the fatigue from previously casted spells.",);
  SetMass(1);
  SetValue(0);
  SetVendorType(VT_MAGIC);
  SetMaterial("metal");
}

/* This section coded by Duuktsaryth@Haven with modifications for use
   by Dylanthalus@Haven
 */

mixed eventUse(object me, string args) {
   string who, what;
   object victim;
   if(!args) {
      message("manastar","Use the manastar to do what to whom?",me);
      return 1;
   }
   sscanf(args, "%s %s", what, who);
   if(!what || !(what == "heal")) {
      message("manastar","Use the manastar to do what?",me);
      return 1;
   }
   if(!who) {
      message("manastar ","Use the manastar to do what to whom?",me);
      return 1;
   }
   if(!(victim = present(who, environment(me)))) {
      message("manastar","Use the manastar on whom?",me);
      return 1;
   }
  if (victim->GetReligion() != "Magildan" ) { 
      message("manastar","Use the manastar on someone who is not "
             "a Magildan?",me);
      return 1;
  }
   send_messages("use","$agent_name $agent_verb a manastar "
                 "to heal $target_name.",me, victim, environment(me));
   victim->AddMagicPoints(random(500)+250);
   send_messages("cease","$agent_name $agent_verb to exist.",
                 this_object(),0,environment(this_object()) );
   eventDestruct();
   return 1;
}
