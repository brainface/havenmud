/*  
 * Arcanith necro robe.
 * -mel 2019-02-01 
 */

#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

int WearMe();

static void create() {
  armour::create();
  SetKeyName("black robe");
  SetId( ({ "robe" }) );
  SetAdjectives( ({ "black", "hooded" }) );
  SetShort("a hooded black robe");
  SetLong("This robe is made of a dark black material that resembles"
          " the canopy between the stars on a moonless night. It is"
          " soft to the touch with long flaring sleeves and a deep"
          " hood that drapes down the back even when erect. The bottom"
          " flares slightly outward allowing ease of mobility and is"
          " much thicker and heavier to help prevent normal wear and"
          " tear should it scrape the ground.");
  SetProperty( "history", "This robe was fashioned by the Lamrani masters"
                          " of necromancy to aid in their works.");
  SetProperty( "magic", "When worn by a practitioner of necromancy, this"
                        " robe will provide a boost to their magical"
                        " resevoir. Additionally, it has been enchanted"
                        " to magically adjust its size based on the"
                        " wearer.");

  SetMass(60);
  SetValue(4000);
  SetVendorType(VT_ARMOUR | VT_TREASURE | VT_MAGIC);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(550);
  SetArmourType(A_BODY_ARMOUR);
  SetMaterial( ({ "textile" }) );
  SetWarmth(20);
  SetSize(SIZE_SMALL);
  SetWear((: WearMe :));
  SetRepairDifficulty(100); /* make it hard to repair */
}

int WearMe() {
  object who = this_player();
  if(who->GetSkillLevel("necromancy")) {
    SetMagicBonus(250);
    send_messages( ({"shimmer", "put" }), "The robe $agent_verb as $agent_name $agent_verb it on.",
                   who, 0, environment(who));
  } else {
    message("system", "You wear a hooded black robe.", who);
  }
  return 1;
}


int GetSize() {
  object e;
  if (living(e = environment()))
     return e->GetSize();
     return SIZE_MEDIUM;
}

varargs int eventRepair(object who, object room, int auto) {
  if (who->GetSkillLevel("necromancy") > 75) {
    return ::eventRepair(who, room, auto);
  } else {
    message("system", "You do not know enough about necromancy to attempt this.", who);
    return 1;
  }
} 
