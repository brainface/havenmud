#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass);


static void create()
{
  npc::create();
  SetKeyName("jungle cat");
  SetId( ({"cat"}) );
  SetAdjectives( ({"jungle", "small"}) );
  SetShort("a jungle cat");
  SetLong(
    "This small jungle cat has a slender build "
    "with long legs and a short tail. His coat "
    "is a grey color with reddish tones mixed in, "
    "especially in the legs where faint stripes "
    "are visible. Black tufts stick up from the "
    "top of his rounded ears. This jungle cat's "
    "small stature suggests he would not be an "
    "especially fierce opponent."
  );
  SetLevel(2);
  SetRace("cat");
  SetClass("animal");
  SetGender("male");
  SetAction(7,({ 
    "The jungle cat arches his back.",
    "The jungle cat makes a strange barking sound."
  }) );

  SetSkinVars("pelt",90,20,10);
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



