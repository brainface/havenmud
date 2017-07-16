#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("bandage");
   SetShort("a simple bandage");
   SetId( ({ "bandage","cloth","strip" }) );
   SetAdjectives( ({ "simple","sterile","white" }) );
   SetLong("This strip of sterile white cloth can be used to heal someone.");
   SetMass(1);
   SetValue(5);
   SetDamagePoints(120);
   SetMaterial( ({ "textile" }) );
   SetProperty("history","This bandage is standard issue in hospitals, particularly "
               "the Eclatish Hospital near Parva.");
   SetProperty("magic","This strip of cloth was blessed by a young Eclatish priest, "
               "giving it healing properties.");
}

mixed eventUse(object me, string args) {
   string who, what;
   object victim;
   if(!args) {
      message("bandage","Use the bandage to do what to whom?",me);
      return 1;
   }
   sscanf(args, "%s %s", what, who);
   if(!what || !(what == "heal")) {
      message("bandage","Use the bandage to do what?",me);
      return 1;
   }
   if(!who) {
      message("bandage","Use the bandage to do what to whom?",me);
      return 1;
   }
   if(!(victim = present(who, environment(me)))) {
      message("bandage","Use the bandage on whom?",me);
      return 1;
   }
   victim->eventHealDamage(5);
   send_messages("use","$agent_name $agent_verb a bandage to heal $target_name.  The "
                 "bandage dissolves.",
                 me, victim, environment(me));
   eventDestruct();
   return;
}
