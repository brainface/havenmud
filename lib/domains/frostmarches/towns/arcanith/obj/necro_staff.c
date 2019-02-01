/*
 * Necro staff, stolen and modified from below credits
 *  - mel 2018-01-31
 */
/*  a mageling staff
 *  filename: mageling_staff.c
 *  idea: A staff that crackles when wielded by a mage
 *  By Sardonas@Haven (a.k.a Robert Kehrer)
 *  Coded: 11/10/1998
 */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

int WieldMe();

static void create() {
  item::create();
  SetKeyName("bone staff");
  SetId( ({ "staff" }) );
  SetShort("a ancient bone staff");
  SetAdjectives( ({ "bone", "ancient" }) );
  SetLong("Around six feet long, this staff was clearly made from the"
          " bones of a monsterous creature. The shaft is roughly two inches"
          " in diameter everywhere except the ends. The top flares into"
          " a wide knobbed structure presumably where the joint was. The"
          " bottom has been whittled into a dull, rounded point. The bone"
          " is strangely non-porous and every now and then an unnatural"
          " shimmer emanates from the top down.");
  SetProperty( "history", "This staff was crafted by Rocklock the Bone Caster"
                          " during his early years. The bone it is carved"
                          " from is said to be from a giant Demon he attempted"
                          " to summon from the Lower Plains.");
  SetProperty( "magic", "The mystical nature of this staff holds special"
                        " properties for necromancers only. When wielded"
                        " by one of appropriate skill level the staff is"
                        " imbued with additional properties to cause"
                        " additional elemental damage and increase its"
                        " effectiveness as a weapon."
                        );
  SetMass(150);
  SetValue(4500);
  SetVendorType(VT_WEAPON | VT_TREASURE | VT_MAGIC);
  SetDamagePoints(1000);
  SetWeaponType("pole");
  SetDamageType(BLUNT||SHOCK);
  SetClass(13);
  SetMaterial( ({ "wood" }) );
  SetWield((: WieldMe :));
  SetHands(2);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(75);
}

int WieldMe() {
  object who = this_player();
  int my_class = 13;
  int skill = who->GetSkillLevel("necromancy");
  string msg = "You wield an ancient bone staff.";
  string color = "white";
  string intensity = "briefly";

  if(skill > 100) {
    if(who->GetSkillLevel("fire magic")) {
       SetDamageType(BLUNT|HEAT);
       msg = "The staff feels warm in your hands.";
       color = "%^RED%^red%^RESET%^";
    } else if (who->GetSkillLevel("ice magic")) {
       SetDamageType(BLUNT|COLD);
       msg = "The staff feels cold in your hands.";
       color = "%^BLUE%^blue%^RESET%^";
    } else if (who->GetSkillLevel("poison magic")) {
       SetDamageType(BLUNT|POISON);
       msg = "The staff feels slimy in your hands.";
       color = "%^GREEN%^green%^RESET%^";
    } else if (who->GetSkillLevel("shock magic")) {
       SetDamageType(BLUNT|SHOCK);
       msg = "The staff feels tingly in your hands.";
       color = "%^YELLOW%^yellow%^RESET%^";
    } else { /* default to just magic */
       SetDamageType(BLUNT|MAGIC);
       msg = "The staff feels comfortable in your hands.";
       color = "%^CYAN%^cyan%^RESET%^";
    }
  }
  switch(skill) {
    case 1..50: /* nub -> HM */
          my_class = 15;
          intensity = "quickly";
          break;
    case 51..100:   /* HM -> Legend */
          my_class = 20;
          intensity = "quickly";
          break;
    case 101..200:  /* Legend -> Avatar */
          my_class = 25;
          intensity = "intensely";
          break;
    case 201..350:
          my_class = 30;
          intensity = "intensely";
          break;
    case 351..5000: /* I don't know how high player skills really get */
          my_class = 40;
          intensity = "continuously";
          break;
  }
  SetClass(my_class);
  message("system", msg, who);
  send_messages("wield", "The ancient bone staff shimmers " + color +
                " " + intensity + " when $agent_name $agent_verb it.",
                who, 0, environment(who));
  return 1;
 
}

mixed eventUnequip(object who) {
 SetClass(13);
 SetDamageType(BLUNT);
 send_messages("unwield", "The ancient bone staff returns to normal as"
               " $agent_name $agent_verb it.", who, 0, environment(who));
 item:: eventUnequip(who);
}
