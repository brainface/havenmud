/*  A full suit of laced leather/metal/cloth armour */
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("oyoroi");
  SetShort("a crimson oyoroi");
  SetId( ({ "oyoroi" }) );
  SetAdjectives( ({ "crimson" }) );
  SetLong("This worn oyoroi is a suit of armour composed of "
    "metal plates painted crimson and laced together over an "
    "inner layer of leather and cloth. Intricate designs on "
    "the surface of the armor are now lost and ruined from the "
    "many mortal blows it has prevented."
  );
  SetMaterials( ({ "metal", "leather", "textile" }) );
  SetWarmth(10);
  SetRepairDifficulty(65);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_REINFORCED);
  SetValue(10000);
  SetMass(1200);
  SetDamagePoints(10000);
  SetArmourType(A_BODY_ARMOUR);

  SetProperty("history",
    "This is a suit of armour stolen from the Akoma household by "
    "the ronin Kofumi, and the reason for her exile from Tai Ri."
  );
  SetProperty("magic",
    "This suit of armour is said to house the spirit of an oni, "
    "said to hunger for war. Possessing at least some intelligence, "
    "it empowers its wearer whenever it feels its existance threatened."
  );

}

// magical robe ignores electrical deterioration
void eventDeteriorate(int DamageType) {
  object env = environment();
  object room;

  if (!env) return;
  if ( !environment(env) ) return;
 
  room = environment(env);


  if ( env->is_living() ) {  
    send_messages("Power seems to %^RED%^flow%^RESET%^ into $agent_name "
    "as $agent_possessive armour cracks from the blow!",
     env, 0, room );
    env->AddStaminaPoints( random(50) + 50);
    env->eventDisplayStatus();
  }
  return armour::eventDeteriorate(DamageType);
}

