/* Oh look a halo */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

int CheckAlignment(object who);
int Resize(object who);

static void create() {
  ::create();
  SetKeyName("radiant halo");
  SetArmourType(A_HELMET);
  SetShort("a radiant halo");
  SetLong(
    "This halo is a finger's width of solid mithril. Its gleaming "
    "surface is smooth and unmarred."
  );
  SetDamagePoints(1500);
  SetDestroyOnSell(1); 
  SetId( ({ "halo" }) );
  SetAdjectives( ({ "radiant", }) );
  SetArmourClass(ARMOUR_CHAIN);
  SetMass(20);
  SetMaterials( ({ "mithril" }) );
  SetPreventGet( (:Resize:) );
  SetProperty(
    "magic" , "This holy artifact of good reflects the light "
              "of its wearer's purity."
  );
  SetProperty(
    "history" , "Halos such as these are granted to Duuk's "
                "angel servants, and occasionally worthy "
                "saints. Evil creatures have been known "
                "to wear them in mockery of Duuk's plans."
  );
  SetRadiantLight(0);
  SetRepairDifficulty(40);
  SetSize(SIZE_MEDIUM);
  SetValue(2500);
  SetWarmth(0);
  SetWear( (: CheckAlignment :) );
}

// corrupts the halo if 
// you're not a good special person.
// also a good mood ring.
int CheckAlignment(object who) {
  if (who->GetMorality() >= 1000) {
    SetRadiantLight(15);
    SetShort("a radiant halo");
    SetLong(
      "This halo is a finger's width of solid mithril. "
      "Its gleaming surface is smooth and unmarred."
    );
    send_messages( 
      ({ "wear" }),
      "The halo %^YELLOW%^shines with brilliance%^RESET%^ "
      "as $agent_name $agent_verb it!",
      who, 0, environment(who)
    );
  } else if (who->GetMorality() <= -1000) {
    SetRadiantLight(15);
    SetShort("a shadowy halo");
    SetLong(
      "This halo is a finger's width of solid mithril. "
      "Its darkened surface is sharp and jagged."
    );
    send_messages( 
      ({ "wear" }),
      "The halo %^MAGENTA%^darkens with corruption%^RESET%^ "
      "as $agent_name $agent_verb it!",
      who, 0, environment(who)
    );
  } else {
    SetRadiantLight(0);
    SetShort("a rusty halo");
    SetLong(
      "This halo is a finger's width of solid mithril. "
      "Its surface is pitted with rust and scuffmarks."
    );
    send_messages( 
      ({ "wear" }),
      "The halo %^RED%^rusts%^RESET%^ "
      "as $agent_name $agent_verb it!",
      who, 0, environment(who)
    );
  }
  return 1;
}

//Resize to fit whoever picks it up
// if it was large, and they aren't large
// tell them it got smaller, so they know
// it's wearable.
int Resize(object who) {
  if (who->GetSize() != GetSize() ) {
    SetSize(who->GetSize());
    if (who->GetSize() != SIZE_LARGE ) {
      send_messages( 
        ({ "grasp" }),
        "The halo shrinks slightly "
        "as $agent_name $agent_verb it.",
        who, 0, environment(who)
      );
    }
  }
  return 1;
}

