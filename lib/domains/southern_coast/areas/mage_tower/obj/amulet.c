#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;
int WearFun(object who);
int CheckWorn();

static void create() {
  ::create();
  SetKeyName("mithril amulet");
  SetShort("a stunning mithril amulet");
  SetId( ({ "amulet" }) );
  SetAdjectives( ({ "stunning", "mithril" }) );
  SetMaterial( ({ "mithril" }) );
  SetWear( (: WearFun :) );
  SetDamagePoints(2500);
  // SetProtection(ALL_DAMAGE, 100);
  SetArmourType(A_AMULET);
  SetProperty("laoise_flag", 1);
  SetArmourClass(ARMOUR_PLATE);
  SetValue(7500);
  SetPreventDrop("The amulet refuses to part with you.");
  SetDestroyOnSell(1);
  SetLong("This amulet appears to be a mithril material and "
          "is really quite pretty.  It would make "
          "a statement of taste nearly anywhere.");
  SetMass(20);
  SetProperty("history", "This amulet comes from the evil "
                   "tower in the grove of Haven Town.");
  SetProperty("magic", "This amulet bestows additional "
             "magical ability and intelligence on the wearer.");
  SetMagicBonus(200);
}


int WearFun(object who) {
  send_messages( ({ "wear" }),
    "The amulet %^YELLOW%^glows%^RESET%^ as $agent_name "
    "$agent_verb it.", who, 0, environment(who) );
  return 1;
}

int CheckWorn() {
  if (GetWorn()) return 20;
  else return 0;
}

int GetSize() {
  object e;
  if (living(e = environment()))
     return e->GetSize();
     return SIZE_MEDIUM;
}
