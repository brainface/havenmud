#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sceptre");
   SetShort("a decorated sceptre");
   SetId( ({ "sceptre","scepter" }) );
   SetAdjectives( ({ "decorated","rose","beautiful" }) );
   SetLong("The sceptre is beautifully decorated; "
           "it flourishes into gorgeous roses "
           "at the tip, with jewels hiding in "
           "the curves, placed to catch the light "
           "at odd angles.  Gold stems decorate "
           "the rest of the sceptre, with small "
           "thorns coming off them.");
   SetMass(100);
   SetValue(1100);
   SetVendorType(VT_WEAPON | VT_TREASURE | VT_MAGIC);
   SetDamagePoints(700);
   SetClass(15);
   SetWeaponType("blunt");
   SetDamageType(BLUNT|PIERCE);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(40);
   SetRepairSkills( ([
                       "metal working" : 4,
                       "weapon smithing" : 1,
                  ]) );
   SetProperty("history","This sceptre was created by a talented "
               "smith, given to an ancient king's daughter.  "
               "The sceptre was passed down throughout history "
               "through a number of bloody wars, and was at "
               "time blessed.");
   SetProperty("magic","The thorns occasionally snake out of "
               "the sceptre and strike the opponent; this "
               "magic comes from a powerful blessing put upon "
               "the sceptre ages ago.");
}

int eventStrike(object target) {
   object who = environment(this_object());
   if(who->GetMorality() > 100) {
      if(!random(7)) {
         who->SetMorality(who->GetMorality() + 5);
         send_messages("","The %^YELLOW%^golden thorns%^RESET%^ "
                       "suddenly unravel from the "
                       "stem of $agent_possessive_noun rose "
                       "sceptre, viciously attacking "
                       "$target_name.",who,target,environment(target));
         return item::eventStrike(target) + 10 + random(10);
      }
   }
   return item::eventStrike(target);
}
