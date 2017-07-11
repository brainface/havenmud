#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetProperty("magic",
       "This sword is a magical creation that can assist in battle.");
  SetShort("a gleaming longsword");
  SetId( ({ "longsword", "gleaming longsword" }) );
  SetAdjectives( ({ "gleaming" }) );
  SetLong("This finely crafted longsword is of the variety used by \n"
          "Rath Khan's guards and soldiers as standard issue.  It \n"
          "gives off a faint heat which seems to indicate magic.");
  SetDamagePoints(2500);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMass(100);
  SetValue(random(500)+1500);
  SetClass(20);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(20);
}

int eventStrike(object target) {
  int amt;
  amt = random(3) + 2;
  if (!(random(5))) {
    switch (amt) {
      case 1:
        send_messages("",
        "$agent_possessive_noun longsword %^YELLOW%^glitters%^RESET%^ slightly in the light as it hits $target_name.",
        environment(), target, environment(target));
        break;
      case 2:
        send_messages("",
        "$agent_possessive_noun longsword %^BLUE%^gleams%^RESET%^ with a dark light as it strikes $target_name.",
         environment(), target, environment(target));
         break;
      case 3:
        send_messages("",
        "$agent_possessive_noun longsword %^RED%^glistens%^RESET%^ with a deadly glow as it slices $target_name.",
        environment(), target, environment(target));
        break;
    }
    return item::eventStrike(target) * amt;
  }
  return item::eventStrike(target);
}
