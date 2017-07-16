// Hacked apart from Bal's original random npcs
 
#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass);


static void create()
{
  npc::create();
  SetKeyName("anaconda");
  SetId( ({"snake", "anaconda"}) );
  SetAdjectives( ({"baby", "anaconda"}) );
  SetShort("a baby anaconda");
  SetLong(
    "The anaconda's scales form patterns of dark "
    "brown islands, surrounded by a lighter brown "
    "background. This coloration allows her to "
    "blend more easily into the surrounding vegetation, "
    "which is a crucial protective mechanism this "
    "early in her young life. Hidden in the shadows "
    "she waits for any unsuspecting prey which is small "
    "enough for her to handle."
  );
  SetLevel(2);
  SetRace("snake");
  SetClass("animal"); 
  SetGender("female");
  SetAction(7,({ 
    "The anaconda slides slowly through the vegetation.",
    "The anaconda flicks its tongue out to test the air.",
  } ));
  SetCombatAction(7, ({
    "The anaconda attempts to wrap herself around your throat!",
  }) );
      
  SetSkinVars("skin",80,25,15);
}

varargs int eventDie(object target)
{
  object ob;
  ob=new(GWONISH+"obj/generic_skin");

  ob->SetKeyName(GetKeyName()+" "+GetProperty("skin_type"));
  ob->SetDamagePoints(GetProperty("durability"));
  ob->SetShort("a "+GetKeyName()+" "+GetProperty("skin_type"));
  ob->SetLong("This is a "+
        GetProperty("skin_type")+" from a " +
        GetKeyName()+".");
  ob->SetID( ( {
    GetProperty("skin_type"),
    GetKeyName()+" "+GetProperty("skin_type")
      }) );
  ob->SetValue(GetProperty("skin_value"));
  ob->SetMass(GetProperty("skin_mass"));

  ob->eventMove(environment(this_object()));

  npc::eventDie(target);
}

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass)
{
  SetProperty("skin_type",skin_type);
  SetProperty("durability",durability);
  SetProperty("skin_value",skin_value);
  SetProperty("skin_mass",skin_mass);
}
