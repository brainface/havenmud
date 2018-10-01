//
// Summary: kickass bow for alkor
// Created by: Rhakz@Haven -- Angel Cazares
// For: Baria
// Date: 28/05/99
//
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

int DoWield();

static void create() {
  item::create();
  SetKeyName("junglewind");
  SetId( ({ "bow" }) );
  SetAdjectives( ({ "reddish", "junglewind" }) );
  SetShort("a reddish junglewind bow");
  SetLong("This is the legendary Junglewind bow. It is made of a very "
          "rare reddish wood not found anymore in the Jungle, and the "
          "string comes from a dragon's gut. Also, the wood has "
          "intricate carvings of Kutharian symbols, remarking its "
          "uniqueness. It is truly a magnificent weapon. "
  );
  SetHands(2);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(4800);
  SetClass(26);
  SetValue(2900);
  SetMass(900);
  SetWeaponType("projectile");
  SetMaterial( ({"natural"}) );
  SetDestroyOnSell(1);
  SetRepairSkills( ([
                     "natural working" : 40
  ]) );
  SetWield( (: DoWield :) );
  SetRepairDifficulty(60);
  SetDamageType(MAGIC|PIERCE);
  SetProperty("magic", "The Junglewind has been imbued with the "
                       "magical power of the crafter's Ancestors."
  );
  SetProperty("history", "The bow was crafted from a rare tree that "
                         "once grew in the Barian Jungle, but that is "
                         "extinct now. And the delicate string comes "
                         "from the guts of a dead dragon. How it was "
                         "crafted cannot be known."
  );
}

int eventStrike(object target) {
  send_messages("", "%^CYAN%^A magical arrow forms in the Junglewind "
                    "and sails directly towards $target_name...%^RESET%^",
                    this_player(), target, environment(this_player()));
  return item::eventStrike(target);
// removed +random(250) from previous line; Vanyel 8:26:04
}

int DoWield() {
  if ( (this_player()->GetReligion() == "Kuthar") && (this_player()->GetLevel() >= 25) ) {
   send_messages( ({"grin","wield"}), "$agent_name $agent_verb as "
                    "$agent_nominative $agent_verb the Junglewind.",
                    this_player(),0,environment(this_player()) );
    return 1;
  }
  else {
    this_player()->eventPrint("You are not worthy of the power of the Ancients.");
    return 0;
  }
}
