#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

int DoWear();
int CheckWorn();
int pullcloak();
int ReVis();

static void create()
{
  armour::create();
  SetKeyName("dark cloak");
  SetId( ({"cloak","dark cloak","shadowy cloak","dark shadowy cloak"}) );
  SetShort("a dark shadowy cloak");
  SetLong("This cloak is black and appears to waver in and out of the "
    "shadows.  The inside is lined with a quilted liner and the outside "
    "is made of a slick material of an unknown type.");
  SetAdjectives( ({"shadowy","dark"}) );
  SetMass(500);
  SetValue(25000);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(1000);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_CLOTHING | VT_MAGIC);
  SetProperty("magic", "The cloak feels almost insubstantial, like a "
    "shadow filtering in and out of existance.");
  SetProperty("history", "The history of this item is almost lost in "
    "time.  The only known fact is that it is made from the skin of "
    "a pit fiend who was skinned alive by a powerful warrior of old.");
//  SetWear( (: DoWear :) );
  // SetProtection(SLASH, 10);
  // SetProtection(PIERCE, 10);
  // SetProtection(BLUNT, 10);
  // SetProtection(MAGIC, 50);
  // SetProtection(HEAT, 35);
  // SetProtection(COLD, 35);
  SetMaterial( ({"leather","textile"}) );
  SetWarmth(25);
  SetRepairSkills( ([ 
                        "leather working" : 35,
        "textile working" : 15,
        ]) );
  SetRepairDifficulty(75);
}

void init() {
        add_action("pullcloak", "pullcloak");
}

int pullcloak() {
        int time, reload, mp;
        
        time = 5;
        time += (this_player()->GetLevel())/10;
   if (time > 15) time = 15;
  reload = time * 2;
        mp = this_player()->GetMaxMagicPoints();
        if (mp > 50) mp = mp/4;
        
        /* Checks */
        if (this_player()->GetMagicPoints() < mp) {
                  this_player()->eventPrint("You do not have enough mana to use the cloak");
                  return 0;
                }
        if (this_player()->GetReligion() != "Soirin") {
                this_player()->eventPrint("You pull the cloak and nothing happens.");
                return 0;
        }
        this_player()->eventPrint("Yay, something happened for you.");
        call_out( (: ReVis :), 1);
        this_player()->SetInvis(1);
        this_player()->AddMagicPoints(-mp);
        return 1;
}

int ReVis(object who){
   who->SetInvis(0);
   send_messages("flash","$agent_name $agent_verb into visibility.", who, 0,environment(who));
   return 1;
}
