#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

int DoWear();
int CheckWorn();

static void create()
{
  armour::create();
  SetKeyName("diamond pendant");
  SetId(( { "diamond pendant","pendant","necklace"} ));
  SetShort("a diamond pendant");
  SetLong("A beautiful diamond dangles in a delicate looking gold mounting "
          "on a tiny gold chain");
  SetMass(5);
  SetWarmth(0);
  SetArmourClass(ARMOUR_PLATE);
SetProperty("laoise_flag", 1);
  SetMaterial("mithril");
  SetValue(1000);
  SetDamagePoints(200);
  
  SetArmourType(A_AMULET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  
  SetProperty("magic", "The pendant feels very lucky.");
  SetProperty("history", "Dwarven smiths lovingly crafted this beautiful " +
                         "pendant for an ancient high priest of the Kyfho " +
                         "religion.  Recognizing the devotion the smiths " +
                         "had exhibited - Balishae the patron of the " +
                         "Kyfho religion and the God of Luck, breathed " +
                         "upon the diamond, giving it life and extra good " +
                         "luck to whomever wears the treasure.");
  
  SetWear( (: DoWear :) );
}

int DoWear()
{
    this_player()->AddStatBonus("luck", (: CheckWorn :) );
    write("An intangible glow of good fortune surrounds you.");
    say((string)this_player()->GetName() + " wears a diamond pendant.");
    return 1;
}

int CheckWorn()
{
    if( !GetWorn() ) {
        previous_object()->RemoveStatBonus("luck", this_object());
        return 0;
    }
    else return 15;
}
