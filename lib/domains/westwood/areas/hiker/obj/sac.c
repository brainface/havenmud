#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_SMELL;
inherit LIB_TOUCH;
inherit LIB_LISTEN;

static void create() {
   item::create();
   SetKeyName("poison sac");
   SetShort("a poison sac");
   SetId( ({ "poison","sac" }) );
   SetAdjectives( ({ "spider","poison","small","sac of","potent" }) );
   SetLong("The small sac of poison is thin and fragile, and "
           "the outer layer holding the poison inside would "
           "probably disintegrate upon use.  It is about "
           "one milliliter of poison, and has a strange "
           "smell to it.");
   SetMass(2);
   SetSmell("The poison smells sharp and acidic.");
   SetTouch("The sac is smooth on the outside, but heat can be "
            "felt radiating from it.");
   SetListen("The poison sounds like it's fizzing.");
   SetValue(400);
   SetVendorType(VT_TREASURE|VT_MAGIC);
   SetDamagePoints(1);
   SetMaterial( ({ "natural" }) );
}

mixed eventUse(object me, string args) {
   string what;
   object victim;
   if(!args) { 
      message("other","Use the sac to do what?",me);
      return;
   }
   sscanf(args, "poison %s", what);
   if(!what) {
      message("other","Use the sac to poison what?",me);
      return;
   }
   if(!(victim = present(what, me))) {
      message("other","Use the sac to poison what?",me);
      return;
   }
   send_messages("use",
      "$agent_name $agent_verb a sac to poison $target_name.",
      me, victim, environment(me) );
   if(victim->GetMealType()) {
      victim->SetMealType(MEAL_POISON);
      victim->SetStrength(victim->GetStrength() + 5 + random(10));
      find_living("amelia")->eventPrint("poisoned");
      victim->SetLong(victim->GetLong() + "  There is a strange tinge to "
                                          "it.");
   }
   else {
      send_messages("","The sac fails to poison it.",this_object(),0,me);
   }
   eventDestruct();
   return 1;
}
mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}

string GetListen(string str) {
   return listen::GetListen(str);
}