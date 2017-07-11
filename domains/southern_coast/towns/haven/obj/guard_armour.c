/*  Armour for the Haven Town Guard */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

int CheckGuard();
int BonusCheck();

static void create() {
  ::create();
  SetKeyName("armour");
  SetArmourType(A_BODY_ARMOUR);
  SetShort("a suit of elfin chainmail");
  SetLong("This is a full-body suit of elfin chain mail "
          "of the type worn by the Haven Town Guard.");
  SetValue(4500);
  SetMass(200);
  SetWarmth(0);
  SetDamagePoints(2000);
  SetId( ({ "suit", "chainmail" }) );
  SetAdjectives( ({ "elfin", "elven" }) );
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_CHAIN);
  SetProtectionBonus(MAGIC, 20);
  SetProtectionBonus(SLASH, 15);
  SetProtectionBonus(BLUNT, 15);
  SetWear( (: CheckGuard :) );
  SetProperty("magic", "This suit of armour was crafted for the "
                       "Haven Town Guard, and can be worn by no other.");
 }

int CheckGuard() {
  if ( this_player()->GetRace() == "elf" && !userp(this_player()) ||
  	   this_player()->GetKeyName() == "damon" || 
  	   (this_player()->GetTestChar()) ) {
     this_player()->AddStatBonus("strength", (: BonusCheck :) );
     this_player()->AddStatBonus("durability", (: BonusCheck :) );
     this_player()->eventCompleteHeal(1000);
  send_messages( ({ "wear" }),
      "$agent_name $agent_verb $target_name.",
       this_player(), this_object(), environment(this_player()) );
  return 1;
  }
  send_messages( ({ "wear" }),
      "$agent_name $agent_verb $target_name.",
       this_player(), this_object(), environment(this_player()) );
  return 1;
 }

int BonusCheck() {
  if (!userp(environment())) return 75;
  return 0;
}
