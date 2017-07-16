#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_READ;

void UnlearnLanguage();
object me;
int OldLearnedLevel;
string lang;
int used = 0;

static void create() {
   read::create();
   item::create();
   SetKeyName("scroll");
   SetShort("an enchanted scroll");
   SetId( ({ "scroll" }) );
   SetAdjectives( ({ "enchanted" }) );
   SetLong("The scroll is made of new parchment carefully rolled up and tied with a "
           "ribbon.  There is a lot of writting on it.");
   SetMass(1);
   SetValue(9500);
   SetVendorType(VT_MAGIC);
   SetDamagePoints(1);
   if(used) {
   SetProperty("magic","The magic of this scroll allows one to use it to learn barian, "
               "drakem, marin, or blaodric.  It has been used and is waiting to close "
               "the enchantment before dissolving.");
   }
   SetProperty("magic","The magic of this scroll allows one to use it to learn Barian, "
               "Drakem, Marin, or Blaodric.");
   SetRead("The writting on the scroll appears to be some magic chant.");
}

eventUse(object me, string args) {
   string what;
   if(!args) {
      message("scroll","Use the scroll to learn what language?",me);
      return 1;
   }
   sscanf(args, "%s %s", what, lang);
   if(!what || !(what == "learn")) {
      message("scroll","Use the scroll to learn what language?",me);
      return 1;
   }
   if(!lang) {
      message("scroll","Use the scroll to learn what language?",me);
      return 1;
   }
   if(capitalize(lang) != "Barian" &&
      capitalize(lang) != "Drakem" &&
      capitalize(lang) != "Marin" &&
      capitalize(lang) != "Blaodric") {
      message("scroll",capitalize(lang) + " is not a language option with this "
              "scroll.",me);
      return 1;
   }
   send_messages("use","$agent_name $agent_verb a scroll.",me, 0, environment(me));
   send_messages("","You feel more knowledgable now.",me,0,0);
   OldLearnedLevel = me->GetLanguageLevel(capitalize(lang));
   me->SetLanguage(capitalize(lang),100);
   used = 1;
   call_out((:UnlearnLanguage :), 100);
   return 1;
}

void UnlearnLanguage() {
   message("scroll","Your knowledge seems to fade slightly.",me);
   me->SetLanguage(capitalize(lang),OldLearnedLevel);
   send_messages("dissolve","$agent_name $agent_verb.",this_object(),0,
                 environment(this_object()) );
   eventDestruct();
   return;
}