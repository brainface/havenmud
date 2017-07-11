// mahkefel 2011:
// harpy flute
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("flute");
   SetShort("a bone flute");
   SetId( ({ "flute","bard_instrument" }) );
   SetAdjectives( ({ "bone" }) );
   SetLong(
     "This long, delicate-looking instrument is carved of ivory white bone and "
     "marked with primal looking sigils that seem to shimmer faintly. A "
     "lanaird looped near the mouthpiece is festooned with bright feathers "
     "likely collected from a multitude of birds."
   );
   SetMass(20);
   SetVendorType(VT_INSTRUMENT);
   SetValue(1000);
   SetDamagePoints(1500);
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(30);
   SetClass(25);
   SetHands(1);
   SetWeaponType("pole");
   SetDamageType(BLUNT|SOUND);
   SetProperty("history",
     "Though delicate looking, the flute is clearly formed from the nearly "
     "indestructible bone of a furry thing, a strange and straightforward "
     "named creature found on other worlds. Carving them is nearly impossible, "
     "so whatever went to the trouble was likely nearly so magical itself.");
   SetProperty("magic",
     "An enchantment to dazzle and placate the audience has been laid upon "
     "this instrument."
   );
}

// do elemental damage if player deserves it.
int eventStrike(object who) {
  int amount = 0;

  if ( !random(7) && this_player()->GetSkillLevel("instrumental music") ) {
      amount = random(20);
      send_messages( ({"hold","sound"}), "$agent_name $agent_verb the trumpet to $agent_possessive "
        "lips and%^BOLD%^WHITE%^ $agent_verb%^RESET%^ an echoing challenge "
        "that rattles $target_name!",
        this_player(), who, environment(who) );
      who->AddRecoveryTime(random(25));
      return (item::eventStrike(who) + amount);
  }
      return (item::eventStrike(who));
}

