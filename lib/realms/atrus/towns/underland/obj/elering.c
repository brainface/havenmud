#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;
int CheckWorn();
int WearMsg(object who);

static void create() {
  ::create();
  SetKeyName("ring");
  SetShort("a perfect emerald ring");
  SetId( ({ "ring" }) );
  SetAdjectives( ({ "stunning", "mithril" }) );
  SetMaterial( ({ "mithril" }) );
  SetWear( (: WearMsg :) );
  SetDamagePoints(2500);
  SetArmourType(A_RING);
  SetArmourClass(ARMOUR_PLATE);
  SetValue(7500);
  SetPreventDrop("The ring refuses to leave you.");
  SetDestroyOnSell(1);
  SetLong("Adorned with a very large and perfectly cut emerald, this mithril "
          "band is inlaid with small mystical patterns which glow with a soft "
          "green light. The jewel is held to the band by small overlapping "
          "gears which claw around the edges.");
  SetMass(20);
  SetProperty("history", "This ring was used as an illusionists control "
                         "object to impress his will upon a Centurion of " 
                         "Underland.");
  SetProperty("magic", "This amulet bestows additional wisdom on the wearer.");
  SetMagicBonus(200);
}


int WearMsg(object who) {
  send_messages( ({ "wear" }),
    "%^GREEN%^The ring %^GREEN%^%^BOLD%^glows%^GREEN%^ as $agent_name "
    "$agent_verb it.%^RESET%^", who, 0, environment(who) );
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
